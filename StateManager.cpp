#include "StateManager.h"

StateManager::StateManager()
{
    statePlay = new StatePlay();
    currentState = NOT_SET;
}

StateManager::~StateManager()
{

}

State* StateManager::changeState(STATE newState)
{
    if (newState == PLAY && currentState != PLAY)
        return statePlay;
    /*
    else if (newState == MENU && currentState != MENU)
        //statePointer = &(*stateMenu);
    else if (newState = OPTIONS && currentState != OPTIONS)
        //statePointer = &(*stateOptions);
    else if (newState = SCORES && currentState != SCORES)
        //statePointer = &(*stateScores);
    */
    currentState = newState;
}
