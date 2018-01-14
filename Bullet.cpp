#include "Bullet.h"

Bullet::Bullet()
{

}

Bullet::Bullet(sf::Vector2f position, float speed, sf::Color color)
{
    str1 = "resources/bullet1.png";
    str2 = "resources/bullet2.png";
    texture.loadFromFile(str1);
    sprite.setTexture(texture);
    sprite.setOrigin(texture.getSize().x / 2, texture.getSize().y / 2);
    sprite.setPosition(position);
    sprite.setColor(color);
    time = 0.3f;
    this->speed = speed;
    t1 = true;
}

Bullet::~Bullet()
{

}

void Bullet::move(float dt) //deltaTime
{
    time -= dt;
    if (time <= 0)
    {
        if (t1)
        {
            texture.loadFromFile(str2);
            t1 = false;
        }
        else
        {
            texture.loadFromFile(str1);
            t1 = true;
        }
        sprite.setTexture(texture);
        time = 0.3f;
    }
    sprite.move(0, speed * dt);
}

void Bullet::setSpeed(float v)
{
    speed = v;
}

sf::Sprite* Bullet::getSprite()
{
    return &sprite;
}
