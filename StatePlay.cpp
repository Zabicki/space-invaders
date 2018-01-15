#include "StatePlay.h"

StatePlay::StatePlay()
:message("Highscore! Enter your name", 400, 100, "resources/space_font.ttf"),
nickCaption("", 400, 150, "resources/space_font.ttf"),
levelCaption("", 400, 300, "resources/space_font.ttf")
{
    ufo = new Ufo();
    movingCooldown = 0.1f;
    substract = false;
    i = 1;
    pause = false;
    font.loadFromFile("resources/space_font.ttf");
    gameOverText.setFont(font);
    gameOverText.setCharacterSize(150);
    gameOverText.setString("game over");
    gameOverText.setOrigin(gameOverText.getGlobalBounds().width / 2, gameOverText.getGlobalBounds().height / 2);
    gameOverText.setPosition({400,300});
    tryAgainText.setFont(font);
    tryAgainText.setCharacterSize(60);
    tryAgainText.setString("Try again? [y/n]");
    tryAgainText.setOrigin(tryAgainText.getGlobalBounds().width / 2, tryAgainText.getGlobalBounds().height / 2);
    tryAgainText.setPosition({400,450});
    float sp = -100;
    level[0].amount = 33;
    level[0].id = 0;
    level[0].speed = sp;
    sp -= 20;
    level[1].amount = 44;
    level[1].id = 1;
    level[1].speed = sp;
    sp -= 20;
    for (int i = 2; i < 10; i++)
    {
        level[i].amount = 55;
        level[i].id = i;
        level[i].speed = sp;
        sp -= 20;
    }
    currentLevel = 0;
    spawnEnemies(level[currentLevel]);
    enemyAmount = level[currentLevel].amount;
    ufoCooldown = 20.f;
    file.open("resources/data.txt", std::ios::in);
    for (int i = 0; i < 10; i++)
    {
        file >> records[i].score;
        file >> records[i].nick;
    }
    enterName = false;
    file.close();
    for (int i = 0; i < 10; i++)
    {
        std::cout << records[i].score << std::endl;
        std::cout << records[i].nick << std::endl;
    }
    printLevel = false;
    levelCaptionTimer = 2.0f;
    levelPause = 1.0f;
}

void StatePlay::update(float timeStep)
{
    if (pause)
    {
        return;
    }
    if (substract)
        movingCooldown -= timeStep;

    if (ufoCooldown > 0)
        ufoCooldown -= timeStep;
    else
    {
        ufoCooldown = 20.f;
        delete ufo;
        ufo = new Ufo();
    }

    if (!player.isAlive())
    {
        pause = true;
        if (player.getPoints()->getScore() >= records[9].score)
            enterName = true;
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
    {
        playerBullets.push_back(new Bullet({player.getSprite()->getPosition().x, player.getSprite()->getPosition().y - player.getSprite()->getGlobalBounds().height / 2}, -600.f, player.getSprite()->getColor()));
        Sound::instance().playShotSound();
    }

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
    cs.checkEnemiesHit(&enemies, &playerBullets, &player, &explosions, enemyAmount);

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

    if (enemyAmount == 0)
    {
        levelPause -= timeStep;
        if (levelPause <= 0)
        {
            currentLevel++;
            int points = player.getPoints()->getScore();
            prepare();
            player.getPoints()->add(points);
            levelPause = 1.0f;
        }

    }

    if (printLevel && levelCaptionTimer > 0)
    {
        levelCaptionTimer -= timeStep;
    }
    else
    {
        printLevel = false;
        levelCaptionTimer = 3.0f;
    }

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

    if (pause)
    {
        Window::instance().getWindow()->draw(gameOverText);
        Window::instance().getWindow()->draw(tryAgainText);
    }


    if (enterName && pause)
    {
        Window::instance().getWindow()->draw(nickCaption.getText());
        Window::instance().getWindow()->draw(message.getText());
    }
    if (printLevel)
    {
        Window::instance().getWindow()->draw(levelCaption.getText());
    }

    Window::instance().getWindow()->display();
}

int StatePlay::pollEvent()
{
    sf::Event event;
    while (Window::instance().getWindow()->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            Window::instance().getWindow()->close();
            return 0; //not set
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            currentLevel = 0;
            return 1; //menu
        }
        if (pause)
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::N))
            {
                currentLevel = 0;
                prepare();
                return 1;

            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y))
            {
                prepare();
                return 0;
            }
        }
        if (enterName)
        {
            if (event.type == sf::Event::TextEntered)
            {
                if (event.text.unicode < 128)
                {
                    if (event.text.unicode == 13)
                    {
                        int it = 0;
                        std::string tmp;
                        for (it = 9; player.getPoints()->getScore() > records[it-1].score || it > 0; it--)
                        {
                            records[it-1].nick = tmp;
                            records[it].nick = tmp;
                            records[it].score = records[it - 1].score;
                        }
                        records[it].score = player.getPoints()->getScore();
                        records[it].nick = nickCaption.getString();
                        //saveToFile();
                        enterName = false;
                        nickCaption.setString("");
                    }
                    else if (event.text.unicode == 8)
                        nickCaption.escape();
                    else
                    {
                        nickCaption.add(event);
                    }
                }
            }
        }
        player.handleInput(event);
    }
    return 0;
}

int StatePlay::handleInput()
{
    return pollEvent();
}

void StatePlay::spawnEnemies(struct Level level)
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
    for (int i = 0; i < level.amount; ++i)
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

void StatePlay::prepare()
{
    //empty event queue
    sf::Event event;
    while (Window::instance().getWindow()->pollEvent(event)) {}
    delete ufo;
    ufo = new Ufo();
    pause = false;
    player.reset();
    playerBullets.clear();
    enemyBullets.clear();
    explosions.clear();
    enemies.clear();
    spawnEnemies(level[currentLevel]);
    enemyAmount = level[currentLevel].amount;
    Enemy::speed = level[currentLevel].speed;
    Enemy::direction = left;
    Enemy::shotChance = 10;
    Enemy::set = 100000;
    std::string tmp = "Level " + std::to_string(level[currentLevel].id + 1);
    levelCaption.setString(tmp);
    printLevel = true;
}

void StatePlay::saveToFile()
{
    file.open("resources/data.txt", std::ios::out);

    for (int i = 0; i < 10; i++)
    {
        std::cout << records[i].score << std::endl;
        std::cout << records[i].nick << std::endl;
    }
    for (int i = 0; i < 10; i++)
    {
        file << records[i].score;
        file << " ";
        file << records[i].nick;
        file << "\n";
    }
}
