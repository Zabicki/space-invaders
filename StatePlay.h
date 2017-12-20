#pragma once
#include "State.h"
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"
#include "Enemy1.h"

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
    Enemy* enemy;
};
