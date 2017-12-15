#include <SFML/Graphics.hpp>
#include "Window.h"
#include "State.h"
#include "StateManager.h"
#include "StatePlay.h"

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
    while (Window::instance().getWindow()->isOpen())
    {
        state->update();
        state->render();
    }
    return 0;
}
