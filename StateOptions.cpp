#include "StateOptions.h"

StateOptions::StateOptions()
:
soundtrackButton({Window::instance().getWindow()->getSize().x / 4, Window::instance().getWindow()->getSize().y / 3},""),
soundButton({3 * Window::instance().getWindow()->getSize().x / 4, Window::instance().getWindow()->getSize().y / 3},"")
{

}

StateOptions::~StateOptions()
{

}

void StateOptions::update(float dt)
{

}

int StateOptions::handleInput()
{
    return pollEvent();
}

void StateOptions::render()
{
    Window::instance().getWindow()->clear();
    Window::instance().getWindow()->draw(sprite_background);
    Window::instance().getWindow()->draw(*soundtrackButton.getSprite());
    Window::instance().getWindow()->draw(*soundButton.getSprite());
    Window::instance().getWindow()->display();
}

int StateOptions::pollEvent()
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

void StateOptions::prepare()
{

}
