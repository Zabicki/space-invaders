#include "Enemy1.h"

Enemy1::Enemy1()
{
    //fixed values used for testing purpouses
    rect.setSize({30.f, 30.f});
    rect.setFillColor(sf::Color::Red);
    rect.setOrigin(rect.getSize().x / 2, rect.getSize().y / 2);
    rect.setPosition(Window::instance().getWindow()->getSize().x / 2, 300);
    direction = left;
    speed = -200;
}

Enemy1::~Enemy1()
{

}

void Enemy1::move(float dt)
{
    rect.move(speed * dt, 0);
}

void Enemy1::shoot()
{

}

void Enemy1::update(float dt)
{
    checkSideCollision();
    move(dt);
}

bool Enemy1::checkCollision()
{

}

void Enemy1::checkBulletCollision()
{

}

sf::RectangleShape* Enemy1::getSprite()
{
    return &rect;
}

void Enemy1::checkSideCollision()
{
    if (rect.getPosition().x <= 0 && direction == left)
    {
        speed = -speed;
        direction = right;
    }
    else if (rect.getPosition().x >= Window::instance().getWindow()->getSize().x && direction == right)
    {
        speed = -speed;
        direction = left;
    }
}

void Enemy1::destroy()
{
    rect.setFillColor(sf::Color::Yellow);
}
