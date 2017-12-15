#pragma once
#include "Window.h"

class State
{
public:
    State() {};
    virtual ~State() {};
    virtual void update() = 0;
    virtual void render() = 0;
private:
    //background texture
    //background sprite
};
