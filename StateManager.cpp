#include "StateManager.h"

StateManager::StateManager()
{
    statePlay = new StatePlay();
    stateMenu = new StateMenu();
    stateScores = new StateScores();
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
        currentState = PLAY;
        return statePlay;
    }

    else if (newState == MENU && currentState != MENU)
    {
        stateMenu->prepare();
        currentState = MENU;
        return stateMenu;
    }
    else if (newState == SCORES && currentState != SCORES)
    {
        stateScores->prepare();
        currentState = SCORES;
        return stateScores;
    }

    /*
    else if (newState = OPTIONS && currentState != OPTIONS)
    {
        stateOptions->prepare();
        currentState = OPTIONS;
        return stateOptions;
    }
    */
    currentState = newState;
}
