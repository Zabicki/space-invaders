#include "Points.h"

Points::Points()
{
    font.loadFromFile("resources/space_font.ttf");
    text.setFont(font);
    text.setCharacterSize(30);
    text.setFillColor(sf::Color::White);
    text.setFillColor(sf::Color(255,255,255,155));
    text.setPosition(10,560);
    score = 0;
    setString();
}

Points::~Points()
{

}

sf::Text Points::getText()
{
    return text;
}

//default amount is 100, the amount of points for killing casual enemy
//while killing an ufo, other value can be passed into funcion (f.e. 300)
void Points::add(int amount)
{
    score += amount;
    setString();
}

void Points::setString()
{
    text.setString("score: " + std::to_string(score));
}

void Points::reset()
{
    score = 0;
    setString();
}
