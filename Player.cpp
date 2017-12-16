#include "Player.h"

/*
TODO
[] smth wrong with the collision system, check this

*/

Player::Player()
:movingSpeed(400)
{
    cannon.setFillColor(sf::Color::Green);
    cannon.setSize({10,30});
    cannon.setOrigin(cannon.getSize().x / 2, cannon.getSize().y /2);
    cannon.setPosition(Window::instance().getWindow()->getSize().x / 10, Window::instance().getWindow()->getSize().y - 35);
    speed = 0;
    direction = NONE;
    flag = true;
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
    //moving player
    if (!sideCollision() && direction != NONE)
        cannon.move(speed * dt, 0);

    //moving player's bullets
    for(std::vector<Bullet>::iterator it = bullets.begin(); it != bullets.end(); ++it)
    {
        it->move(dt);
        it->showInfo();
    }
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
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        fire();
}

//returns true if player crosses screen's boundaries
bool Player::sideCollision()
{
    if ((cannon.getPosition().x < (0 + cannon.getSize().x) && direction == LEFT) ||
        (cannon.getPosition().x > (Window::instance().getWindow()->getSize().x - cannon.getSize().x) && direction == RIGHT))
            return true;
    return false;
}

void Player::fire()
{
    if (flag)
    {
        bullets.push_back(Bullet(cannon.getPosition(), 0.f));
        flag = false;
    }
}
std::vector<Bullet>& Player::getBullets()
{
    return bullets;
}
