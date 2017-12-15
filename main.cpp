#include <SFML/Graphics.hpp>
#include "Window.h"

int main()
{
    auto* window = Window::instance().getWindow();

    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window->isOpen())
    {
        sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window->close();
        }

        window->clear();
        window->draw(shape);
        window->display();
    }

    return 0;
}
