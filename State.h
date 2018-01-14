#pragma once
#include <SFML/Graphics.hpp>
#include "Window.h"
#include <iostream>
#include "Sound.h"

class State
{
public:
    State();
    virtual ~State() {};
    virtual void update(float) = 0;
    virtual void render() = 0;
    virtual int handleInput() = 0;
    virtual void prepare() = 0; //empty event queue etc, used before switching states to prevent bugs
protected:
    sf::Texture texture_background;
    sf::Sprite sprite_background;
};
