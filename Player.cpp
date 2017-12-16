#include "Player.h"

Player::Player()
:movingSpeed(400)
{
    cannon.setFillColor(sf::Color::Green);
    cannon.setSize({10,30});
    cannon.setOrigin(cannon.getSize().x / 2, cannon.getSize().y /2);
    cannon.setPosition(Window::instance().getWindow()->getSize().x / 10, Window::instance().getWindow()->getSize().y - 35);
    speed = 0;
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
    if (!sideCollision() && direction != NONE)
        cannon.move(speed * dt, 0);
}

void Player::handleInput(sf::Event event)
{
    if (event.type == sf::Event::KeyReleased)
    {
        if (event.key.code == sf::Keyboard::Left || event.key.code == sf::Keyboard::Right)
            direction = NONE;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && direction != LEFT)
    {
        direction = LEFT;
        speed = -movingSpeed;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && direction != RIGHT)
    {
        direction = RIGHT;
        speed = movingSpeed;
    }
}

//returns true if player crosses screen's boundaries
bool Player::sideCollision()
{
    if (cannon.getPosition().x < (0 + cannon.getSize().x) && direction == LEFT ||
        cannon.getPosition().x > (Window::instance().getWindow()->getSize().x - cannon.getSize().x) && direction == RIGHT)
            return true;
    return false;
}
