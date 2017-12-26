#pragma once
#include "Enemy.h"
#include <random>
#include "Player.h"

class Enemy1 : public Enemy
{
public:
    Enemy1();
    Enemy1(sf::Vector2f);
    ~Enemy1();
    virtual void move(float);
    virtual bool shoot();
    virtual void update(float);
    virtual sf::RectangleShape* getSprite();
    virtual void destroy();
    virtual void moveDown();
    virtual bool random();
private:
};
