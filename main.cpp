#include <SFML/Graphics.hpp>
#include "Window.h"
#include "State.h"
#include "StateManager.h"
#include "Player.h"
#include "Bullet.h"
#include "Sound.h"

int main()
{
    StateManager* stateManager = new StateManager();
    State* state;
    state = stateManager->changeState(MENU);
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    int tmp = 0;
    Sound::instance().playSoundtrack();
    while (Window::instance().getWindow()->isOpen())
    {
        tmp = state->handleInput();
        if (tmp != 0)
            state = stateManager->changeState((STATE)tmp);

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
