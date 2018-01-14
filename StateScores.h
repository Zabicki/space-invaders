#pragma once
#include "State.h"
#include <SFML/Graphics.hpp>
#include <fstream>

class StateScores : public State
{
public:
    StateScores();
    ~StateScores() {};
    virtual void update(float dt);
    virtual void render();
    virtual int handleInput();
    virtual void prepare();
    int pollEvent();
private:
    std::fstream file;
    sf::Text score[11];
    sf::Font font;
    sf::Text nick[11];
    //time played, level
};
