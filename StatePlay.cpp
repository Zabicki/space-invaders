#include "StatePlay.h"

StatePlay::StatePlay()
{
    rect.setFillColor(sf::Color::Blue);
    rect.setSize({100.f, 50.f});
    rect.setPosition({300.f, 350.f});
}

void StatePlay::update()
{
    pollEvent();
}

void StatePlay::render()
{
    std::cout << "Calling render method\n";
    Window::instance().getWindow()->clear();
    Window::instance().getWindow()->draw(sprite_background);
    Window::instance().getWindow()->draw(rect);
    Window::instance().getWindow()->display();
}

void StatePlay::pollEvent()
{
    sf::Event event;
    while (Window::instance().getWindow()->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            Window::instance().getWindow()->close();
    }
}
