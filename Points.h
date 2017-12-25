#pragma once
#include <SFML/Graphics.hpp>
#include "Window.h"
#include <iostream>
#include <string>

class Points
{
public:
    Points();
    ~Points();
    sf::Text getText();
    void add(int amount = 100);
    void setString();
private:
    int score;
    sf::Font font;
    sf::Text text;
};
