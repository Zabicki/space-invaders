#include "StateMenu.h"
#include<iostream>
#include <time.h>

StateMenu::StateMenu()
:
buttonStart({Window::instance().getWindow()->getSize().x / 2, 110}, "start"),
buttonScores({Window::instance().getWindow()->getSize().x / 2, 240}, "high scores"),
buttonOptions({Window::instance().getWindow()->getSize().x / 2, 370}, "options"),
buttonExit({Window::instance().getWindow()->getSize().x / 2, 500}, "exit")
{
    srand(time(NULL));
    float speed;
    std::string paths1[10] = {"resources/enemy1_1.png",
                             "resources/enemy2_1.png",
                             "resources/enemy3_1.png",
                             "resources/enemy1_1.png",
                             "resources/enemy2_1.png",
                             "resources/enemy3_1.png",
                             "resources/enemy1_1.png",
                             "resources/enemy2_1.png",
                             "resources/enemy3_1.png",
                             "resources/enemy1_1.png"};
    std::string paths2[10] = {"resources/enemy1_2.png",
                             "resources/enemy2_2.png",
                             "resources/enemy3_2.png",
                             "resources/enemy1_2.png",
                             "resources/enemy2_2.png",
                             "resources/enemy3_2.png",
                             "resources/enemy1_2.png",
                             "resources/enemy2_2.png",
                             "resources/enemy3_2.png",
                             "resources/enemy1_2.png"};
    sf::Color colors[10] = {sf::Color::Red,
                            sf::Color::Yellow,
                            sf::Color::Green,
                            sf::Color::Blue,
                            sf::Color::Magenta,
                            sf::Color::Cyan,
                            sf::Color::White,
                            sf::Color::Red,
                            sf::Color::Yellow,
                            sf::Color::Green };

    for (int i = 0; i < 10; i++)
    {
        speed = rand() % 50 + 50;
        if (rand() % 2 == 0)
        {
            speed = -speed;
            if (i < 5)
                enemies[i] = new Enemy1({(rand() % 200 + 10), 650}, i, paths1[i], paths2[i], colors[i], false);
            else
                enemies[i] = new Enemy1({(rand() % 200 + 550), 650}, i, paths1[i], paths2[i], colors[i], false);

        }
        else
        {
            if (i < 5)
                enemies[i] = new Enemy1({(rand() % 200 + 10), -50}, i, paths1[i], paths2[i], colors[i], false);
            else
                enemies[i] = new Enemy1({(rand() % 200 + 550), -50}, i, paths1[i], paths2[i], colors[i], false);
        }
        enemies[i]->setSpeed2(speed);
        enemies[i]->getSprite()->setColor(colors[rand() % 10]);
    }
}

StateMenu::~StateMenu()
{

}

void StateMenu::update(float dt)
{
    sf::Color colors[10] = {sf::Color::Red,
                            sf::Color::Yellow,
                            sf::Color::Green,
                            sf::Color::Blue,
                            sf::Color::Magenta,
                            sf::Color::Cyan,
                            sf::Color::White,
                            sf::Color::Red,
                            sf::Color::Yellow,
                            sf::Color::Green };
    float speed;
    for (int i = 0; i < 10; i++)
    {
        if(enemyOutOfBounds(enemies[i]))
        {
            speed = rand() % 50 + 50;
            if (rand() % 2 == 0)
            {
                speed = -speed;
                if (i < 5)
                    enemies[i]->setPosition({rand() % 200 + 10, 650});
                else
                    enemies[i]->setPosition({rand() % 200 + 550, 650});
            }
            else
            {
                if (i < 5)
                    enemies[i]->setPosition({rand() % 200 + 10, -50});
                else
                    enemies[i]->setPosition({rand() % 200 + 550, -50});
            }
            enemies[i]->setSpeed2(speed);
            enemies[i]->getSprite()->setColor(colors[rand() % 10]);
        }
        enemies[i]->update(dt);
        enemies[i]->move2(dt);
    }
}

void StateMenu::render()
{
    Window::instance().getWindow()->clear();
    Window::instance().getWindow()->draw(sprite_background);
    Window::instance().getWindow()->draw(*buttonStart.getSprite());
    Window::instance().getWindow()->draw(*buttonScores.getSprite());
    Window::instance().getWindow()->draw(*buttonOptions.getSprite());
    Window::instance().getWindow()->draw(*buttonExit.getSprite());
    Window::instance().getWindow()->draw(*buttonStart.getText());
    Window::instance().getWindow()->draw(*buttonScores.getText());
    Window::instance().getWindow()->draw(*buttonOptions.getText());
    Window::instance().getWindow()->draw(*buttonExit.getText());

    for (int i = 0; i < 10; i++)
    {
        Window::instance().getWindow()->draw(*(enemies[i]->getSprite()));
    }
    Window::instance().getWindow()->display();
}

int StateMenu::handleInput()
{
    return pollEvent();
}

int StateMenu::pollEvent()
{
    sf::Event event;
    while (Window::instance().getWindow()->pollEvent(event))
    {
        if (event.type == sf::Event::Closed || buttonExit.checkMouseInput(event))
            Window::instance().getWindow()->close();
        if (buttonStart.checkMouseInput(event))
        {
            Sound::instance().playButtonSound();
            return 2;
        }
        if (buttonScores.checkMouseInput(event))
        {
            Sound::instance().playButtonSound();
            return 3;
        }
        buttonOptions.checkMouseInput(event);
    }
}

void StateMenu::prepare()
{
    //empty event queue
    sf::Event event;
    while (Window::instance().getWindow()->pollEvent(event)) {}
}

bool StateMenu::enemyOutOfBounds(Enemy* enemy)
{
    if (enemy->getSprite()->getPosition().y >= 700 ||
        enemy->getSprite()->getPosition().y <= -100)
        return true;
    return false;
}
