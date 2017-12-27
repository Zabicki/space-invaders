#include "Enemy.h"

Enemy::Enemy()
{
    texture.loadFromFile("resources/enemy1_1.png");
    sprite.setTexture(texture);
    animationTimer = 1.f;
    img1 = true;
    img2 = false;
}

Enemy::~Enemy()
{

}

float Enemy::speed = -100;
Dir Enemy::direction = left;
unsigned int Enemy::shotChance = 10;
unsigned int Enemy::set = 100000;

sf::Sprite* Enemy::getSprite()
{
    return &sprite;
}

void Enemy::destroy()
{

}

void Enemy::moveDown()
{
    sprite.move(0, 20);
}


bool Enemy::random()
{
    if (rand() % set <= shotChance)
        return true;
    return false;
}

void Enemy::move(float dt)
{
    sprite.move(speed * dt, 0);
}

bool Enemy::shoot()
{
    if (random())
        return true;
    return false;
}
