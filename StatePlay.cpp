#include "StatePlay.h"

/*
TODO
[]Wektor eksplozji, odejmowanie czasu, sprawdzanie czy czas minal, jak tak to usuwany z wektora

*/

StatePlay::StatePlay()
{
    spawnEnemies(55);
    ufo = new Ufo();
    movingCooldown = 0.1f;
    substract = false;
    i = 1;
}

void StatePlay::update(float timeStep)
{
    if (substract)
        movingCooldown -= timeStep;

    if (!player.isAlive())
    {
        Window::instance().getWindow()->close();
        return;
        //change insights of the if to question if the player wants to play again
        //while the question shows up, the game ought to be frozen
        //until the user decides if they want to play or quit to the menu
    }

    if (ufo != NULL)
    {
        if (!cs.checkUfoSideCollision(ufo))
        {
            ufo->move(timeStep);
        }
        else
        {
            explosions.push_back(new Explosion(ufo->getSprite()->getPosition()));
            delete ufo;
            ufo = NULL;
        }
        if (ufo != NULL)
        {
            if (cs.checkUfoCollision(ufo, &playerBullets, &explosions))
            {
                ufo = NULL;
                player.getPoints()->add(500);
            }
        }

    }

    if (!cs.checkPlayerSideCollision(&player))
        player.move(timeStep);

    for(std::vector<Enemy*>::iterator it = enemies.begin(); it != enemies.end(); ++it)
    {
        if ((*it)->shoot())
            enemyBullets.push_back(new Bullet({(*it)->getSprite()->getPosition().x, (*it)->getSprite()->getPosition().y - (*it)->getSprite()->getGlobalBounds().height / 2}, 200.f, (*it)->getSprite()->getColor()));
    }

    if (player.shoot())
        playerBullets.push_back(new Bullet({player.getSprite()->getPosition().x, player.getSprite()->getPosition().y - player.getSprite()->getGlobalBounds().height / 2}, -600.f, player.getSprite()->getColor()));

    //move bullets
    for (std::vector<Bullet*>::iterator it = enemyBullets.begin(); it != enemyBullets.end(); ++it)
    {
        (*it)->move(timeStep);
    }

    for (std::vector<Bullet*>::iterator it = playerBullets.begin(); it != playerBullets.end(); ++it)
    {
        (*it)->move(timeStep);
    }

    //update player
    player.update(timeStep);

    //checks if enemies get hit with player's bullets
    cs.checkEnemiesHit(&enemies, &playerBullets, &player, &explosions);

    //check collision between enemy's and player's bullets
    cs.checkBulletsCollision(&enemyBullets, &playerBullets);

    //checks if enemy collides with a wall
    if (cs.checkEnemySideCollision(&enemies))
    {
        for(std::vector<Enemy*>::iterator it = enemies.begin(); it != enemies.end(); ++it)
        {
            (*it)->moveDown();
        }
    }

    //update enemies
    for(std::vector<Enemy*>::iterator it = enemies.begin(); it != enemies.end(); ++it)
    {
        if (i % 11 == 0)
            substract = true;
        (*it)->update(timeStep);
        ++i;
    }

    //updating explosions' time
    for (std::vector<Explosion*>::iterator it = explosions.begin(); it != explosions.end();)
    {
        if ((*it)->getTotalTime() <= 0)
        {
            delete *it;
            explosions.erase(it);
            continue;
        }
        else
        {
            (*it)->update(timeStep);
            ++it;
        }
    }

    //check if player is hit with enemy's bullets
    cs.checkPlayerHit(&player, &enemyBullets);
}

void StatePlay::render()
{
    Window::instance().getWindow()->clear();
    Window::instance().getWindow()->draw(sprite_background);
    Window::instance().getWindow()->draw(*player.getSprite());

    if (ufo != NULL)
    {
        Window::instance().getWindow()->draw(*ufo->getSprite());
    }

    for (std::vector<Enemy*>::iterator it = enemies.begin(); it != enemies.end(); ++it)
    {
        Window::instance().getWindow()->draw(*(*it)->getSprite());
    }

    for (std::vector<Bullet*>::iterator it = playerBullets.begin(); it != playerBullets.end(); ++it)
    {
        Window::instance().getWindow()->draw(*(*it)->getSprite());
    }

    for (std::vector<Bullet*>::iterator it = enemyBullets.begin(); it != enemyBullets.end(); ++it)
    {
        Window::instance().getWindow()->draw(*(*it)->getSprite());
    }

    for (std::vector<Explosion*>::iterator it = explosions.begin(); it != explosions.end(); ++it)
    {
        Window::instance().getWindow()->draw(*(*it)->getSprite());
    }

    Window::instance().getWindow()->draw(player.getPoints()->getText());
    Window::instance().getWindow()->draw(*player.getLivesSprite());
    Window::instance().getWindow()->draw(player.getLivesText());
    Window::instance().getWindow()->display();
}

void StatePlay::pollEvent()
{
    sf::Event event;
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
    int tex = 0;
    int col = 0;
    sf::Color colors[5] = { sf::Color::Red,
                            sf::Color::Green,
                            sf::Color::Blue,
                            sf::Color::Yellow,
                            sf::Color::Cyan};
    std::string textures[10] = {"resources/enemy1_1.png",
                                "resources/enemy1_2.png",
                                "resources/enemy2_1.png",
                                "resources/enemy2_2.png",
                                "resources/enemy3_1.png",
                                "resources/enemy3_2.png",
                                "resources/enemy1_1.png",
                                "resources/enemy1_2.png",
                                "resources/enemy2_1.png",
                                "resources/enemy2_2.png"};
    for (int i = 0; i < amount; ++i)
    {
        if (i % 11 == 0 && i != 0)
        {
            tex += 2;
            col++;
        }
        if (i % 11 == 0)
        {
            enemyPosition.x = 200;
            enemyPosition.y += 40;
        }
        else
        {
            enemyPosition.x += 40;
        }
        enemies.push_back(new Enemy1(enemyPosition, i, textures[tex], textures[tex+1], colors[col]));
    }
}
