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
    virtual void move(float dt);
    virtual void move2(float dt);
    virtual bool shoot();
    virtual void update(float dt) = 0;
    virtual sf::Sprite* getSprite();
    virtual void destroy(int);
    static Dir direction;
    static float speed;
    static unsigned int shotChance;
    static unsigned int set; //numbers from 0 to set, random number will be drawn and compared to shotChance
    virtual void moveDown();
    virtual bool random();
    virtual void setPosition(sf::Vector2f pos);
    void setSpeed2(float);
protected:
    sf::Sprite sprite; //later switched to sf::Texture
    sf::Texture texture;
    float fireRate;
    float speed2;
    unsigned int ID;
    float animationTimer;
    bool img1;
    bool img2;
};
