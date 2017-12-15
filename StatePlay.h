#pragma once
#include "State.h"
#include "Player.h"

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
    Player player;
};
