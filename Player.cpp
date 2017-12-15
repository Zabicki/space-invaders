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

void Player::update(sf::Event event)
{
    if (event.type == sf::Event::EventType::KeyPressed && event.key.code == sf::Keyboard::Left)
        cannon.move(-5,0);
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        cannon.move(5,0);
    std::cout << "Player position: " << cannon.getPosition().x << " " << cannon.getPosition().y << "\n";
}
