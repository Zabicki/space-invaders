#pragma once
#include "State.h"
#include "StatePlay.h"

enum STATE
{
    NOT_SET = 0,
    MENU,
    PLAY,
    OPTIONS,
    SCORES
};

class StateManager
{
public:
    StateManager();
    ~StateManager();
    State* changeState(STATE);
private:
    State* statePlay;
    STATE currentState;
    //stateMenu
    //stateOptions
    //stateScores
};
