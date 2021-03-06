#pragma once
#include "State.h"
#include "StatePlay.h"
#include "StateMenu.h"
#include "StateScores.h"

enum STATE
{
    NOT_SET = 0,
    MENU,
    PLAY,
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
    State* stateMenu;
    State* stateScores;
};
