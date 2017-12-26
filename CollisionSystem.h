#pragma once
#include "Bullet.h"
#include "Player.h"
#include "Enemy.h"
#include "Window.h"

class CollisionSystem
{
public:
    CollisionSystem();
    ~CollisionSystem();
    bool checkPlayerHit(Player* player,std::vector<Bullet*>* enemyBullets);
    bool checkEnemiesHit(std::vector<Enemy*>* enemies,std::vector<Bullet*>* playerBullets, Player* player);
    bool checkBulletsCollision(std::vector<Bullet*>* bullets1, std::vector<Bullet*>* bullets2);
    bool checkBulletsInBounds(std::vector<Bullet*>* playerBullets,std::vector<Bullet*>* enemyBullets);
    bool checkPlayerSideCollision(Player* player);
    bool checkEnemySideCollision(std::vector<Enemy*>* enemies);
private:
};
