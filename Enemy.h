#pragma once
#include <SFML/Graphics.hpp>
#include "Bullet.h"
#include "Window.h"

class Player;

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
    virtual void checkBulletCollision(Player*) = 0;
    virtual void checkSideCollision() = 0;
    virtual void destroy() = 0;
    static Dir direction;
    static float speed;
    static unsigned int shotChance;
    static unsigned int set; //numbers from 0 to set, random number will be drawn and compared to shotChance
    virtual void moveDown() = 0;
    virtual bool random() = 0;
    virtual std::vector<Bullet*>& getBullets() = 0;
protected:
    sf::RectangleShape rect; //later switched to sf::Texture
    std::vector <Bullet*> bullets;
    float fireRate;
};
