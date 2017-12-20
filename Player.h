#pragma once
#include <SFML/Graphics.hpp>
#include "Window.h"
#include "Bullet.h"
#include "Enemy.h"
#include <iostream>

/*
TODO
[X]Fix shooting bug when changing direction (delay)

*/

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
    std::vector<Bullet*>& getBullets();
    void update(float);
    void handleInput(sf::Event);
    bool sideCollision();
    void fire(); //fire a bullet
    bool checkBulletCollision(Enemy* enemy); //TODO: add std::vector<Enemies*> enemies vector to function's parameters
    void checkKeyboardKeys();
private:
    sf::RectangleShape cannon;
    bool canShoot;
    bool substract;
    float reloadTime;
    float timer; //timer to control shooting speed
    const float movingSpeed; //constant, helps the 'speed' variable to set it's proper value
    float speed; //changed whether the direction changes
    Direction direction;
    std::vector <Bullet*> bullets;
};
