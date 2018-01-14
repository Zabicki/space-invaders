#pragma once
#include <SFML/Graphics.hpp>
#include "State.h"
#include "Button.h"
#include "Enemy.h"
#include "Enemy1.h"

class StateMenu : public State
{
public:
    StateMenu();
    ~StateMenu();
    virtual void update(float);
    virtual void render();
    virtual int handleInput();
    int pollEvent();
    virtual void prepare();
    bool enemyOutOfBounds(Enemy*);
private:
    Button buttonStart;
    Button buttonScores;
    Button buttonOptions;
    Button buttonExit;
    Enemy* enemies[10];
};
