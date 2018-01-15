#include "Enemy.h"

Enemy::Enemy()
{
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
    if (speed < 0)
        speed -= 10;
    else
        speed += 10;
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

void Enemy::move2(float dt)
{
    sprite.move(0, speed2 * dt);
}

bool Enemy::shoot()
{
    if (random())
        return true;
    return false;
}

void Enemy::setSpeed2(float s) { speed2 = s; }

void Enemy::setPosition(sf::Vector2f pos) { sprite.setPosition(pos); }
