#include "Player.h"

Player::Player()
{
    cannon.setFillColor(sf::Color::Green);
    cannon.setSize({10,30});
    cannon.setOrigin(cannon.getSize().x / 2, cannon.getSize().y /2);
    cannon.setPosition(Window::instance().getWindow()->getSize().x / 2, Window::instance().getWindow()->getSize().y - 35);
}

Player::~Player()
{

}

sf::RectangleShape Player::getCannon()
{
    return cannon;
}
