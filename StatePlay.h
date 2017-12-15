#pragma once
#include "State.h"

class StatePlay : public State
{
public:
    StatePlay();
    ~StatePlay() {};
    virtual void update();
    virtual void render();
    void pollEvent();
private:
    sf::RectangleShape rect;
};
