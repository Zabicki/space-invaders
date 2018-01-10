#pragma once
#include "Enemy.h"
#include <random>
#include "Player.h"

class Enemy1 : public Enemy
{
public:
    Enemy1();
    Enemy1(sf::Vector2f, int, std::string str1 = "resources/enemy1_1.png", std::string str2 = "resources/enemy1_2.png");
    ~Enemy1();
    virtual void update(float);
private:
    std::string str1;
    std::string str2;
};
