#include "Bullet.h"

Bullet::Bullet()
{
    bullet.setFillColor(sf::Color::Yellow);
    bullet.setSize({50.f, 50.f});
    bullet.setOrigin(bullet.getSize().x / 2, bullet.getSize().y /2);
    std::cout << "Bullet constructor\n";
}

Bullet::Bullet(sf::Vector2f position, float speed)
{
    Bullet();
    this->speed = speed;
    bullet.setPosition(position);
    std::cout << "Bullet position: " << bullet.getPosition().x << " " << bullet.getPosition().y << "\n";
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
