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
    cannon.setFillColor(sf::Color::Green);
    cannon.setSize({10,30});
    cannon.setOrigin(cannon.getSize().x / 2, cannon.getSize().y /2);
    cannon.setPosition(Window::instance().getWindow()->getSize().x / 2, Window::instance().getWindow()->getSize().y - 35);
    speed = 0;
    direction = NONE;
    canShoot = true;
    substract = false;
    reloadTime = 0.2f;
    timer = reloadTime;
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

    for(std::vector<Bullet*>::iterator it = bullets.begin(); it != bullets.end(); ++it)
    {
        (*it)->move(dt);
    }

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

//returns true if player crosses screen's boundaries
bool Player::sideCollision()
{
    if ((cannon.getPosition().x < (0 + cannon.getSize().x) && direction == LEFT) ||
        (cannon.getPosition().x > (Window::instance().getWindow()->getSize().x - cannon.getSize().x) && direction == RIGHT))
            return true;
    return false;
}

void Player::fire()
{bullets.push_back(new Bullet({cannon.getPosition().x, cannon.getPosition().y - cannon.getSize().y / 2}, -600.f));
    std::cout << "Bullets: " << bullets.size() << "\n";
    substract = true;
    canShoot = false;
}
std::vector<Bullet*>& Player::getBullets()
{
    return bullets;
}

//additional function, using it outside the event loop in StatePlay reduces annoying delay caused by event to 0.
void Player::checkKeyboardKeys()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && canShoot)
    {
        fire();
        canShoot = false;
    }
}

bool Player::checkBulletCollision(std::vector<Enemy*>* enemies)
{
    bool flag;
    for(std::vector<Bullet*>::iterator it = bullets.begin(); it != bullets.end();)
    {
        flag = false;
        for(std::vector<Enemy*>::iterator i = (*enemies).begin(); i != (*enemies).end();)
        {
            if ((*it)->getSprite()->getGlobalBounds().intersects((*i)->getSprite()->getGlobalBounds()))
            {
                //destroy bullet
                delete *it;
                bullets.erase(it);
                //destroy enemy
                (*i)->destroy();
                delete *i;
                enemies->erase(i);

                //add points
                points.add();

                //flag set to avoid std::vector<>::iterator issues
                flag = true;
                break;
            }
            else
                ++i;
        }
        if (!flag)
            ++it;
    }

    for(std::vector<Bullet*>::iterator it = bullets.begin(); it != bullets.end(); ++it)
    {
        if ((*it)->getSprite()->getPosition().y < 0)
        {
            delete *it;
            bullets.erase(it);
            std::cout << "Bullets: " << bullets.size() << "\n";
            if (bullets.size() == 0)
                break;
        }
    }
}

Points Player::getPoints()
{
    return points;
}
