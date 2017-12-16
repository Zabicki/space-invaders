#pragma once
#include <SFML/Graphics.hpp>
#include "Window.h"
#include <iostream>

enum Direction
{
    NONE,
    LEFT,
    RIGHT
};

class Player
{
public:
    Player();
    ~Player();
    sf::RectangleShape getCannon();
    void update(float);
    void handleInput(sf::Event);
    bool sideCollision();
private:
    sf::RectangleShape cannon;
    const float movingSpeed; //constant, helps the 'speed' variable to set it's proper value
    float speed; //changed whether the direction changes
    Direction direction;
};
