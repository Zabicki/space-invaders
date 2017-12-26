#include "Enemy1.h"

Enemy1::Enemy1()
{
    sprite.setOrigin(sprite.getGlobalBounds().width / 2, sprite.getGlobalBounds().height / 2);
    srand(time(NULL));
}

Enemy1::Enemy1(sf::Vector2f position)
{
    //rect.setFillColor(sf::Color(255,255,255,50));
    sprite.setScale({3,3});
    sprite.setOrigin(sprite.getGlobalBounds().width / 2, sprite.getGlobalBounds().height / 2);
    sprite.setPosition(position);

}

Enemy1::~Enemy1()
{

}

void Enemy1::update(float dt)
{
    move(dt);
}
