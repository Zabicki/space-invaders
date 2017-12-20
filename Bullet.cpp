#include "Bullet.h"

Bullet::Bullet()
{

}

Bullet::Bullet(sf::Vector2f position, float speed)
{
    bullet.setFillColor(sf::Color::Yellow);
    bullet.setSize({5.f, 5.f});
    bullet.setOrigin(bullet.getSize().x / 2, bullet.getSize().y /2);
    this->speed = speed;
    bullet.setPosition(position);
}

Bullet::~Bullet()
{

}

void Bullet::move(float dt) //deltaTime
{
    bullet.move(0, speed * dt);
}

void Bullet::setSpeed(float v)
{
    speed = v;
}

sf::RectangleShape* Bullet::getSprite()
{
    return &bullet;
}

void Bullet::showInfo()
{
    std::cout << "\nPosition: " << bullet.getPosition().x << " " << bullet.getPosition().y <<
                 "\nSize: " << bullet.getSize().x << " " << bullet.getSize().y <<
                 "\nSpeed: " << speed << "\n";
}
