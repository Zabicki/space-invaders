#include "StatePlay.h"

StatePlay::StatePlay()
{

}

void StatePlay::update()
{
    pollEvent();
}

void StatePlay::render()
{
    Window::instance().getWindow()->clear();
    Window::instance().getWindow()->draw(sprite_background);
    Window::instance().getWindow()->display();
}

void StatePlay::pollEvent()
{
    while (Window::instance().getWindow()->isOpen())
    {
        sf::Event event;
        while (Window::instance().getWindow()->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                Window::instance().getWindow()->close();
        }
    }
}
