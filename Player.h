#pragma once
#include <SFML/Graphics.hpp>
#include "Window.h"
#include <iostream>

class Player
{
public:
    Player();
    ~Player();
    sf::RectangleShape getCannon();
    void update(sf::Event);
private:
    sf::RectangleShape cannon;
};
