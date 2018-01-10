#include "Ufo.h"

Ufo::Ufo()
{
    //rect.setFillColor(sf::Color(255,255,255,200));
    texture.loadFromFile("resources/ufo1.png");
    sprite.setTexture(texture);
    sprite.setScale({3,3});
    sprite.setOrigin(sprite.getGlobalBounds().width / 2, sprite.getGlobalBounds().height / 2);
    sprite.setPosition(30,30);
}

Ufo::~Ufo()
{
    std::cout << "Delete ufo\n";
}

void Ufo::update(float dt)
{

}

void Ufo::move(float dt)
{
    sprite.move(200 * dt, 0);
}
