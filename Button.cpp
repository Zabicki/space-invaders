#include "Button.h"
#include <iostream>
/*
TODO
[]FIx the caption centralization problem

*/

Button::Button(sf::Vector2f position, std::string caption)
{
    strNormal = "resources/button_click.png";
    strHover = "resources/button_hover.png";
    texture.loadFromFile(strNormal);
    texture.setSmooth(true);
    sprite.setTexture(texture);
    sprite.setPosition(position);
    sprite.setScale(0.25, 0.25);
    sprite.setOrigin(texture.getSize().x / 2, texture.getSize().y / 2);
    leftClick = false;
    hover = false;
    normal = true;
    toChange = false;
    clickCoords = { -5, -5};

    font.loadFromFile("resources/space_font.ttf");
    text.setFont(font);
    text.setCharacterSize(35);
    text.setFillColor(sf::Color::White);
    text.setFillColor(sf::Color(255,255,255,200));
    text.setString(caption);
    text.setOrigin(text.getGlobalBounds().width / 2, text.getGlobalBounds().height / 2);
    text.setPosition(position);
}

Button::~Button()
{

}

bool Button::checkMouseInput(sf::Event event)
{
    sf::Vector2i mousePos= sf::Mouse::getPosition(*(Window::instance().getWindow()));
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !leftClick)
    {
        leftClick = true;
        clickCoords = mousePos;
        if (clickOnButton())
        {
            normal = false;
            hover = false;
            toChange = true;
        }
    }
    if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)
    {
        leftClick = false;
        if (clickOnButton() && sprite.getGlobalBounds().contains(sf::Vector2f(mousePos)))
        {
            clickCoords = {-5, -5};
            return true;
        }
        else
        {
            texture.loadFromFile(strNormal);
            sprite.setTexture(texture);
        }
    }

    if (sprite.getGlobalBounds().contains(sf::Vector2f(mousePos)) && !hover)
    {
        toChange = true;
        normal = false;
        hover = true;
    }
    else if (!sprite.getGlobalBounds().contains(sf::Vector2f(mousePos)) && !normal)
    {
        toChange = true;
        hover = false;
        normal = true;
    }

    if (toChange)
    {
        if (hover)
        {
            texture.loadFromFile(strHover);
            sprite.setTexture(texture);
            toChange = false;
        }
        else if (normal)
        {
            texture.loadFromFile(strNormal);
            sprite.setTexture(texture);
            toChange = false;
        }
    }
    return false;
}

bool Button::clickOnButton()
{
    if (sprite.getGlobalBounds().contains(sf::Vector2f(clickCoords)))
        return true;
    return false;
}

sf::Sprite* Button::getSprite() { return &sprite; }

sf::Text* Button::getText() { return &text; }
