#include "Enemy1.h"

Enemy1::Enemy1()
{
    sprite.setOrigin(sprite.getGlobalBounds().width / 2, sprite.getGlobalBounds().height / 2);
    srand(time(NULL));
}

Enemy1::Enemy1(sf::Vector2f position, int id)
{
    //rect.setFillColor(sf::Color(255,255,255,50));
    sprite.setOrigin(sprite.getGlobalBounds().width / 2, sprite.getGlobalBounds().height / 2);
    sprite.setPosition(position);
    sprite.setScale({3,3});
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
            texture.loadFromFile("resources/enemy1_2.png");
            sprite.setTexture(texture);
            animationTimer = 1.f;
            img1 = false;
            img2 = true;
        }
        else if (img2)
        {
            texture.loadFromFile("resources/enemy1_1.png");
            sprite.setTexture(texture);
            animationTimer = 1.f;
            img1 = true;
            img2 = false;
        }
    }
    else
        animationTimer -= dt;

    move(dt);
}
