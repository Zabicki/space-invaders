#include "StateScores.h"

StateScores::StateScores()
{
    sf::Vector2f pos1 = {Window::instance().getWindow()->getSize().x / 4, 50};
    sf::Vector2f pos2 = {3 * Window::instance().getWindow()->getSize().x / 4, 50};
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
    font.loadFromFile("resources/space_font.ttf");

    std::string tmp_punkty[11];
    std::string tmp_nick[11];
    tmp_punkty[0] = "SCORE";
    tmp_nick[0] = "PLAYER";
    score[0].setString(tmp_punkty[0]);
    score[0].setFont(font);
    score[0].setCharacterSize(50);
    score[0].setOrigin(score[0].getGlobalBounds().width / 2, score[0].getGlobalBounds().height / 2);
    score[0].setPosition(pos1);
    score[0].setColor(colors[0]);
    nick[0].setString(tmp_nick[0]);
    nick[0].setFont(font);
    nick[0].setCharacterSize(50);
    nick[0].setOrigin(nick[0].getGlobalBounds().width / 2, nick[0].getGlobalBounds().height / 2);
    nick[0].setPosition(pos2);
    nick[0].setColor(colors[0]);

    pos1.y += 70;
    pos2.y += 70;

    file.open("resources/data.txt", std::ios::in);

    for (int i = 1; i < 11; i++)
    {
        file >> tmp_punkty[i];
        file >> tmp_nick[i];
    }
    for (int i = 1; i < 11; i++)
    {
        score[i].setString(tmp_punkty[i]);
        score[i].setFont(font);
        score[i].setCharacterSize(30);
        score[i].setOrigin(score[i].getGlobalBounds().width / 2, score[i].getGlobalBounds().height / 2);
        score[i].setPosition(pos1);
        score[i].setColor(colors[i]);
        nick[i].setString(tmp_nick[i]);
        nick[i].setFont(font);
        nick[i].setCharacterSize(30);
        nick[i].setOrigin(nick[i].getGlobalBounds().width / 2, nick[i].getGlobalBounds().height / 2);
        nick[i].setPosition(pos2);
        nick[i].setColor(colors[i]);

        pos1.y += 50;
        pos2.y += 50;
    }
}

void StateScores::update(float dt)
{

}

void StateScores::render()
{
    Window::instance().getWindow()->clear();
    Window::instance().getWindow()->draw(sprite_background);
    for (int i = 0; i < 11; i++)
    {
        Window::instance().getWindow()->draw(score[i]);
        Window::instance().getWindow()->draw(nick[i]);
    }
    Window::instance().getWindow()->display();
}

int StateScores::handleInput()
{
    return pollEvent();
}

int StateScores::pollEvent()
{
    sf::Event event;
    while (Window::instance().getWindow()->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            Window::instance().getWindow()->close();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            Sound::instance().playEscapeSound();
            return 1;
        }
    }
}

void StateScores::prepare()
{
    //empty event queue
    sf::Event event;
    while (Window::instance().getWindow()->pollEvent(event)) {}
}
