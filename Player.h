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
private:
    sf::RectangleShape cannon;
    float movingSpeed;
    Direction direction;
};
