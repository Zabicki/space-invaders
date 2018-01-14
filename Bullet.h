#pragma once
#include <SFML/Graphics.hpp>
#include "Window.h"
#include <iostream>

class Bullet
{
public:
    Bullet();
    Bullet(sf::Vector2f position, float speed, sf::Color);
    ~Bullet();
    void move(float);
    bool checkCollision();
    void setFireDirection(int);
    void setSpeed(float);
    sf::Sprite* getSprite();
private:
    sf::Sprite sprite;
    sf::Texture texture;
    float time;
    float speed;
    bool t1; //true if texture 1 is active
    std::string str1;
    std::string str2;
};
