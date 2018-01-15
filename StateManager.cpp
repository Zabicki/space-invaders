#include "StateManager.h"

StateManager::StateManager()
{
    statePlay = new StatePlay();
    stateMenu = new StateMenu();
    stateScores = new StateScores();
    stateOptions = new StateOptions();
    currentState = NOT_SET;
}

StateManager::~StateManager()
{

}

State* StateManager::changeState(STATE newState)
{
    if (newState == PLAY && currentState != PLAY)
    {
        statePlay->prepare();
        return statePlay;
    }

    else if (newState == MENU && currentState != MENU)
    {
        stateMenu->prepare();
        return stateMenu;
    }
    else if (newState == SCORES && currentState != SCORES)
    {
        stateScores->prepare();
        return stateScores;
    }
    else if (newState == OPTIONS && currentState != OPTIONS)
    {
        stateOptions->prepare();
        return stateOptions;
    }
    currentState = newState;
}
