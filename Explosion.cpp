#include "Explosion.h"

Explosion::Explosion(sf::Vector2f position)
{
    texture.loadFromFile("resources/explosion.png");
    sprite.setTexture(texture);
    rectSourceSprite = sf::IntRect(0,0,64,64);
    sprite.setTextureRect(rectSourceSprite);
    sprite.setOrigin(sprite.getGlobalBounds().width / 2, sprite.getGlobalBounds().height / 2);
    sprite.setPosition(position.x, position.y);

    time = 1/32.f;
    totalTime = 0.5f;
}

Explosion::~Explosion()
{

}

float Explosion::getTotalTime() { return totalTime; }

void Explosion::updateTime(float dt) { time -= dt; }

void Explosion::changeSprite()
{
    if (rectSourceSprite.left == 128)
    {
        rectSourceSprite.left = 0;
        rectSourceSprite.top += 64;
    }
    else
        rectSourceSprite.left += 64;
    sprite.setTextureRect(rectSourceSprite);
}

void Explosion::update(float dt)
{
    updateTime(dt);
    if (time < 0)
    {
        changeSprite();
        time = 1/32.f;
        totalTime -= 1/32.f;
    }
}

sf::Sprite* Explosion::getSprite() { return &sprite; }
