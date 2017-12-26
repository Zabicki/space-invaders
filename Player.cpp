#include "Player.h"

/*
TODO
[] smth wrong with the collision system, check this
[]Program crashed in some bullet situations, has to be fixed asap (return code 134(0x86)
  When the last fired bulet is colliding with enemy, program crashes
*/

Player::Player()
:movingSpeed(400)
{
    rect.setFillColor(sf::Color::Green);
    rect.setSize({10,30});
    rect.setOrigin(rect.getSize().x / 2, rect.getSize().y /2);
    rect.setPosition(Window::instance().getWindow()->getSize().x / 2, Window::instance().getWindow()->getSize().y - 35);
    speed = 0;
    direction = NONE;
    canShoot = true;
    substract = false;
    reloadTime = 0.2f;
    timer = reloadTime;
    lives = 3;
    alive = true;
}

Player::~Player()
{

}

sf::RectangleShape Player::getSprite()
{
    return rect;
}

void Player::update(float dt) //dt == deltaTime
{
    if (substract)
        timer -= dt;

    if (timer <= 0)
    {
        timer = reloadTime;
        substract = false;
        canShoot = true;
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
}

bool Player::shoot()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && canShoot)
    {
        std::cout << "Shooting\n";
        canShoot = false;
        substract = true;
        return true;
    }
    return false;
}

Points* Player::getPoints()
{
    return &points;
}

void Player::damage()
{
    lives--;
    std::cout << lives << std::endl;
    if (lives == 0)
        destroy();
}

void Player::destroy()
{
    alive = false;
    rect.setFillColor(sf::Color(255,255,255,50));
    //add explosion animation and sound
}

bool Player::isAlive()
{
    return alive;
}

void Player::move(float dt)
{
    if (direction != NONE)
        rect.move(speed * dt, 0);
}
