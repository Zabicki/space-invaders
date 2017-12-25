#pragma once
#include "Enemy.h"

class Enemy1 : public Enemy
{
public:
    Enemy1();
    Enemy1(sf::Vector2f);
    ~Enemy1();
    virtual void move(float);
    virtual void shoot();
    virtual void update(float);
    virtual bool checkCollision();
    virtual void checkBulletCollision();
    virtual sf::RectangleShape* getSprite();
    virtual void checkSideCollision();
    virtual void destroy();
    virtual void moveDown();
private:

};
