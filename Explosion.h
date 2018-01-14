#pragma once
#include <SFML/Graphics.hpp>

class Explosion
{
public:
    Explosion(sf::Vector2f position);
    ~Explosion();
    float getTime();
    float getTotalTime();
    void update(float dt);
    sf::Sprite* getSprite();
private:
    void changeSprite();
    void updateTime(float dt);
    sf::Texture texture;
    sf::Sprite sprite;
    float time;
    float totalTime;
    sf::IntRect rectSourceSprite;
};
