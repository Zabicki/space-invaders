#include <SFML/Graphics.hpp>
#include "Window.h"

/*
TODO
[]State mechanism similar to the Flashcards project but upgraded and fixed
[]Firstly only game state, latter states (menu, options etc) in the end of the project
[]Fixed step loop targeted at 60 fps (physics mostly)
[]main loop simple look:
    while (window->isOpen())
    {
        state->getInput(); <--not necessary
        state->update();
        state->render();
        //handle 60 fps
    }
*/

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
