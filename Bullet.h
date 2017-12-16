#pragma once
#include <SFML/Graphics.hpp>
#include "Window.h"
#include <iostream>

class Bullet
{
public:
    Bullet();
    Bullet(sf::Vector2f position, float speed);
    ~Bullet();
    void move(float);
    bool checkCollision();
    void setFireDirection(int);
    void setSpeed(float);
    sf::RectangleShape getSprite();
    void showInfo();
private:
    sf::RectangleShape bullet;
    float speed;
};
