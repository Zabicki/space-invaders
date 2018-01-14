#include "Enemy1.h"

Enemy1::Enemy1()
{

}

Enemy1::Enemy1(sf::Vector2f position, int id, std::string str1, std::string str2, sf::Color color, bool sideMovement)
{
    this->str1 = str1;
    this->str2 = str2;
    this->sideMovement = sideMovement;
    texture.loadFromFile(str1);
    sprite.setTexture(texture);
    sprite.setOrigin(sprite.getGlobalBounds().width / 2, sprite.getGlobalBounds().height / 2);
    sprite.setPosition(position);
    sprite.setScale({3,3});
    sprite.setColor(color);
    ID = id;
}

Enemy1::~Enemy1()
{

}

void Enemy1::update(float dt)
{
    if (animationTimer <= 0)
    {
        if (img1)
        {
            texture.loadFromFile(str1);
            sprite.setTexture(texture);
            animationTimer = 1.f;
            img1 = false;
            img2 = true;
        }
        else if (img2)
        {
            texture.loadFromFile(str2);
            sprite.setTexture(texture);
            animationTimer = 1.f;
            img1 = true;
            img2 = false;
        }
    }
    else
        animationTimer -= dt;
    if (sideMovement)
        move(dt);
}

sf::Color Enemy1::getColor() { return sprite.getColor(); }
