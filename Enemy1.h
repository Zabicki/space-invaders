#pragma once
#include "Enemy.h"
#include <random>
#include "Player.h"

class Enemy1 : public Enemy
{
public:
    Enemy1();
    Enemy1(sf::Vector2f, int);
    ~Enemy1();
    virtual void update(float);
private:
};
