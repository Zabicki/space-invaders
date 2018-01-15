#include "CollisionSystem.h"

CollisionSystem::CollisionSystem()
{

}

CollisionSystem::~CollisionSystem()
{

}

bool CollisionSystem::checkPlayerHit(Player* player,std::vector<Bullet*>* enemyBullets)
{
    for(std::vector<Bullet*>::iterator it = enemyBullets->begin(); it != enemyBullets->end();)
    {
        if ((*it)->getSprite()->getGlobalBounds().intersects(player->getSprite()->getGlobalBounds()))
        {
            //destroy bullet
            delete *it;
            enemyBullets->erase(it);

            player->damage();
            break;
        }
        else
            ++it;
    }
}

bool CollisionSystem::checkEnemiesHit(std::vector<Enemy*>* enemies,std::vector<Bullet*>* playerBullets, Player* player, std::vector<Explosion*>* explosions, int &enemyAmount)
{
    bool flag;
    for(std::vector<Bullet*>::iterator it = playerBullets->begin(); it != playerBullets->end();)
    {
        flag = false;
        for(std::vector<Enemy*>::iterator i = enemies->begin(); i != enemies->end();)
        {
            if (player->getSprite()->getGlobalBounds().intersects((*i)->getSprite()->getGlobalBounds()))
            {
                player->kill();
            }
            else if ((*i)->getSprite()->getPosition().y >= 600)
                player->kill();
            if ((*it)->getSprite()->getGlobalBounds().intersects((*i)->getSprite()->getGlobalBounds()))
            {
                //destroy bullet
                delete *it;
                playerBullets->erase(it);
                //destroy enemy
                (*i)->destroy(enemyAmount);
                explosions->push_back(new Explosion((*i)->getSprite()->getPosition()));
                delete *i;
                enemies->erase(i);



                //add points
                player->getPoints()->add();

                //increase a chance for enemies to shoot

                //flag set to avoid std::vector<>::iterator issues

                enemyAmount -= 1;

                flag = true;
                break;
            }
            else
                ++i;
        }
        if (!flag)
            ++it;
    }
}

bool CollisionSystem::checkBulletsCollision(std::vector<Bullet*>* bullets1, std::vector<Bullet*>* bullets2)
{
    bool flag;

    for(std::vector<Bullet*>::iterator it = bullets1->begin(); it != bullets1->end();)
    {
    flag = false;
        for(std::vector<Bullet*>::iterator i = bullets2->begin(); i != bullets2->end();)
        {
            if ((*it)->getSprite()->getGlobalBounds().intersects((*i)->getSprite()->getGlobalBounds()))
            {
                //destroy bullet
                delete *it;
                bullets1->erase(it);
                //destroy enemy
                delete *i;
                bullets2->erase(i);
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
}

bool CollisionSystem::checkBulletsInBounds(std::vector<Bullet*>* playerBullets,std::vector<Bullet*>* enemyBullets)
{
    //player bullets
    for(std::vector<Bullet*>::iterator it = playerBullets->begin(); it != playerBullets->end();)
    {
        if ((*it)->getSprite()->getPosition().y < 0)
        {
            delete *it;
            playerBullets->erase(it);
            std::cout << "Bullets: " << playerBullets->size() << "\n";
        }
        else
            ++it;
    }

    //enemy bullets
    for(std::vector<Bullet*>::iterator it = enemyBullets->begin(); it != enemyBullets->end();)
    {
        if ((*it)->getSprite()->getPosition().y > 600)
        {
            delete *it;
            enemyBullets->erase(it);
            std::cout << "Bullets: " << enemyBullets->size() << "\n";
        }
        else
            ++it;
    }
}

bool CollisionSystem::checkPlayerSideCollision(Player* player)
{
    if ((player->getSprite()->getPosition().x < (0 + player->getSprite()->getGlobalBounds().width) && player->direction == LEFT) ||
        (player->getSprite()->getPosition().x > (Window::instance().getWindow()->getSize().x - player->getSprite()->getGlobalBounds().width) && player->direction == RIGHT))
            return true;
    return false;
}

bool CollisionSystem::checkEnemySideCollision(std::vector<Enemy*>* enemies)
{
    for (std::vector<Enemy*>::iterator it = enemies->begin(); it != enemies->end(); ++it)
    {
        if (Enemy::direction == right)
        {
            if ((*it)->getSprite()->getPosition().x + (*it)->getSprite()->getGlobalBounds().width / 2 >= Window::instance().getWindow()->getSize().x)
            {
                Enemy::direction = left;
                Enemy::speed = -Enemy::speed;
                return true;
            }
        }
        else
        {
            if ((*it)->getSprite()->getPosition().x - (*it)->getSprite()->getGlobalBounds().width / 2 <= 0)
            {
                Enemy::direction = right;
                Enemy::speed = -Enemy::speed;
                return true;
            }
        }
    }
    return false;
}

bool CollisionSystem::checkUfoCollision(Ufo* ufo, std::vector<Bullet*>* playerBullets, std::vector<Explosion*>* explosions)
{
    for(std::vector<Bullet*>::iterator it = playerBullets->begin(); it != playerBullets->end();)
    {
        if ((*it)->getSprite()->getGlobalBounds().intersects(ufo->getSprite()->getGlobalBounds()))
        {
            //destroy bullet
            delete *it;
            playerBullets->erase(it);
            explosions->push_back(new Explosion(ufo->getSprite()->getPosition()));
            delete ufo;
            ufo = NULL;
            break;
        }
        else
            ++it;
    }
}

bool CollisionSystem::checkUfoSideCollision(Ufo* ufo)
{
    if (ufo->getSprite()->getGlobalBounds().width > (Window::instance().getWindow()->getSize().x + ufo->getSprite()->getGlobalBounds().width))
            return true;
    return false;
}
