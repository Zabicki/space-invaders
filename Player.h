#pragma once
#include <SFML/Graphics.hpp>
#include "Window.h"

class Player
{
public:
    Player();
    ~Player();
    sf::RectangleShape getCannon();
private:
    sf::RectangleShape cannon;
};
