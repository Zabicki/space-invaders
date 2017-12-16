#pragma once
#include <SFML/Graphics.hpp>
#include "Window.h"
#include "Bullet.h"
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
    std::vector<Bullet>& getBullets();
    void update(float);
    void handleInput(sf::Event);
    bool sideCollision();
    void fire(); //fire a bullet
private:
    sf::RectangleShape cannon;
    bool flag;
    sf::Clock timer; //timer to control shooting speed
    const float movingSpeed; //constant, helps the 'speed' variable to set it's proper value
    float speed; //changed whether the direction changes
    Direction direction;
    std::vector <Bullet> bullets;
    Bullet* bullet;
};
