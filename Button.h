#pragma once
#include <SFML/Graphics.hpp>
#include "Window.h"

class Button
{
public:
    Button() {};
    Button(sf::Vector2f position, std::string caption);
    Button(sf::Vector2f position, std::string caption, std::string tex1, std::string tex2);
    ~Button();
    bool checkMouseInput(sf::Event);
    bool clickOnButton();
    sf::Sprite* getSprite();
    sf::Text* getText();
private:
    std::string strNormal;
    std::string strHover;
    std::string strClick;
    sf::Sprite sprite;
    sf::Texture texture;
    bool toChange;
    bool leftClick;
    bool normal;
    bool hover;
    bool soundButton;
    sf::Vector2i clickCoords;
    sf::Text text;
    sf::Font font;
};
