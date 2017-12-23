#include "StatePlay.h"

StatePlay::StatePlay()
{
    rect.setFillColor(sf::Color::Red);
    rect.setSize({800.f, 20.f});
    rect.setOrigin(rect.getSize().x / 2, rect.getSize().y /2);
    rect.setPosition({400,590});
    enemy = new Enemy1();
}

void StatePlay::update(float timeStep)
{
    player.update(timeStep);
    player.checkBulletCollision(enemy);
    enemy->update(timeStep);
}

void StatePlay::render()
{
    Window::instance().getWindow()->clear();
    Window::instance().getWindow()->draw(sprite_background);
    Window::instance().getWindow()->draw(rect);
    Window::instance().getWindow()->draw(player.getCannon());
    Window::instance().getWindow()->draw(*enemy->getSprite());
    std::vector<Bullet*> v = player.getBullets();
    for(std::vector<Bullet*>::iterator it = v.begin(); it != v.end(); ++it)
    {
        Window::instance().getWindow()->draw(*(*it)->getSprite());
    }
    Window::instance().getWindow()->display();
}

void StatePlay::pollEvent()
{
    sf::Event event;
    player.checkKeyboardKeys();
    while (Window::instance().getWindow()->pollEvent(event))
    {
        if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            Window::instance().getWindow()->close();
        player.handleInput(event);
    }
}

void StatePlay::handleInput()
{
    pollEvent();
}
