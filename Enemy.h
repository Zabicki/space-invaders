#pragma once
#include <SFML/Graphics.hpp>
#include "Bullet.h"
#include "Window.h"

//TODO change all enums to class enums
enum Dir
{
    left,
    right
};

class Enemy
{
public:
    Enemy();
    virtual ~Enemy();
    virtual void move(float) = 0;
    virtual void shoot() = 0;
    virtual void update(float) = 0;
    virtual bool checkCollision() = 0;
    virtual sf::RectangleShape* getSprite() = 0;
    virtual void checkBulletCollision() = 0;
    virtual void checkSideCollision() = 0;
    virtual void destroy() = 0;
protected:
    sf::RectangleShape rect; //later switched to sf::Texture
    float speed; //make this static
    float fireRate;
    Dir direction;
};
