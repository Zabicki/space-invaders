#include "Player.h"

Player::Player()
{
    cannon.setFillColor(sf::Color::Green);
    cannon.setSize({10,30});
    cannon.setOrigin(cannon.getSize().x / 2, cannon.getSize().y /2);
    cannon.setPosition(Window::instance().getWindow()->getSize().x / 2, Window::instance().getWindow()->getSize().y - 35);
    movingSpeed = 400;
    direction = NONE;
}

Player::~Player()
{

}

sf::RectangleShape Player::getCannon()
{
    return cannon;
}

void Player::update(float dt) //dt == deltaTime
{
    if (direction == LEFT)
        cannon.move(-movingSpeed * dt, 0);
    else if (direction == RIGHT)
        cannon.move(movingSpeed * dt, 0);
}

void Player::handleInput(sf::Event event)
{
    if (event.type == sf::Event::KeyReleased)
    {
        if (event.key.code == sf::Keyboard::Left || event.key.code == sf::Keyboard::Right)
            direction = NONE;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && direction != LEFT)
        direction = LEFT;
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && direction != RIGHT)
        direction = RIGHT;
}
