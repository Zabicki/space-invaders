#include "StatePlay.h"

StatePlay::StatePlay()
{
    spawnEnemies(55);
}

void StatePlay::update(float timeStep)
{
    player.update(timeStep);
    player.checkBulletCollision(&enemies);
    if (checkSideCollision())
    {
        for(std::vector<Enemy*>::iterator it = enemies.begin(); it != enemies.end(); ++it)
        {
            (*it)->moveDown();
        }
    }

    for(std::vector<Enemy*>::iterator it = enemies.begin(); it != enemies.end(); ++it)
    {
        (*it)->update(timeStep);
    }

    for (std::vector<Enemy*>::iterator it = enemies.begin(); it != enemies.end(); ++it)
    {
        (*it)->checkBulletCollision(&player);
    }
}

void StatePlay::render()
{
    Window::instance().getWindow()->clear();
    Window::instance().getWindow()->draw(sprite_background);
    Window::instance().getWindow()->draw(player.getCannon());
    for (std::vector<Enemy*>::iterator it = enemies.begin(); it != enemies.end(); ++it)
    {
        Window::instance().getWindow()->draw(*(*it)->getSprite());
    }

    std::vector<Bullet*> v = player.getBullets();
    for (std::vector<Bullet*>::iterator it = v.begin(); it != v.end(); ++it)
    {
        Window::instance().getWindow()->draw(*(*it)->getSprite());
    }
    std::vector<Bullet*> u;
    for (std::vector<Enemy*>::iterator it = enemies.begin(); it != enemies.end(); ++it)
    {
        u = (*it)->getBullets();
        for (std::vector<Bullet*>::iterator it = u.begin(); it != u.end(); ++it)
        {
            Window::instance().getWindow()->draw(*(*it)->getSprite());
        }
    }

    Window::instance().getWindow()->draw(player.getPoints().getText());
    Window::instance().getWindow()->display();
}

void StatePlay::pollEvent()
{
    sf::Event event;
    player.checkKeyboardKeys();
    while (Window::instance().getWindow()->pollEvent(event))
    {
        if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            Window::instance().getWindow()->close();
        player.handleInput(event);
    }
}

void StatePlay::handleInput()
{
    pollEvent();
}

void StatePlay::spawnEnemies(int amount)
{
    sf::Vector2f enemyPosition = {200, 115};
    for (int i = 1; i <= amount; ++i)
    {
        enemies.push_back(new Enemy1(enemyPosition));
        if (i % 11 == 0)
        {
            enemyPosition.x = 200;
            enemyPosition.y += 40;
        }
        else
        {
            enemyPosition.x += 40;
        }
    }
}

bool StatePlay::checkSideCollision()
{
    for (std::vector<Enemy*>::iterator it = enemies.begin(); it != enemies.end(); ++it)
    {
        if (Enemy::direction == right)
        {
            if ((*it)->getSprite()->getPosition().x + 15 >= Window::instance().getWindow()->getSize().x)
            {
                Enemy::direction = left;
                Enemy::speed = -Enemy::speed;
                return true;
            }
        }
        else
        {
            if ((*it)->getSprite()->getPosition().x - 15 <= 0)
            {
                Enemy::direction = right;
                Enemy::speed = -Enemy::speed;
                return true;
            }
        }
    }
    return false;
}
