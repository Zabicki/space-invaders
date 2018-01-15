#pragma once
#include "State.h"
#include <SFML/Graphics.hpp>
#include "Window.h"
#include "Sound.h"
#include "Button.h"

class StateOptions : public State
{
public:
    StateOptions();
    ~StateOptions();
    virtual void render();
    virtual void update(float dt);
    virtual int handleInput();
    int pollEvent();
    virtual void prepare();
private:
    Button soundtrackButton;
    Button soundButton;
    bool soundActivated;
    bool soundtrackActivated;
};
