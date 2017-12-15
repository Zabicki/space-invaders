#pragma once
#include <SFML/Graphics.hpp>
#include "Window.h"
#include <iostream>

class State
{
public:
    State();
    virtual ~State() {};
    virtual void update() = 0;
    virtual void render() = 0;
protected:
    sf::Texture texture_background;
    sf::Sprite sprite_background;
};
