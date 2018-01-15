#pragma once
#include "Window.h"
#include "Enemy.h"

class Ufo : public Enemy
{
public:
    Ufo();
    ~Ufo();
    virtual void update(float dt);
    virtual void move(float dt);
private:
};
