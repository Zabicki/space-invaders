#pragma once
#include "State.h"
#include "Player.h"

class StatePlay : public State
{
public:
    StatePlay();
    ~StatePlay() {};
    virtual void update(float);
    virtual void render();
    virtual void handleInput();
    void pollEvent();
private:
    sf::RectangleShape rect;
    Player player;
};
