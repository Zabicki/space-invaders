#include <SFML/Graphics.hpp>
#include "Window.h"
#include "State.h"
#include "StateManager.h"
#include "StatePlay.h"
#include "Player.h"
#include "Bullet.h"

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
    std::cout << "Game start\n";
    State* state = new StatePlay();
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    while (Window::instance().getWindow()->isOpen())
    {
        state->handleInput();
        timeSinceLastUpdate += clock.restart();
        while (timeSinceLastUpdate > sf::seconds(1.f / 60.f))
        {
            timeSinceLastUpdate -= sf::seconds(1.f / 60.f);
            state->handleInput();
            state->update(1/60.f);
        }
        state->render();
    }
    return 0;
}
