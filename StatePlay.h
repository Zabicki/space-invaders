#pragma once
#include "State.h"
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"
#include "Enemy1.h"
#include "CollisionSystem.h"
#include "Ufo.h"

class StatePlay : public State
{
public:
    StatePlay();
    ~StatePlay() {};
    virtual void update(float);
    virtual void render();
    virtual void handleInput();
    void pollEvent();
    void spawnEnemies(int amount);
private:
    Player player;
    CollisionSystem cs;
    std::vector<Bullet*> playerBullets;
    std::vector<Bullet*> enemyBullets;
    std::vector <Enemy*> enemies;
    Ufo* ufo;
    float movingCooldown;
    bool substract;
    int i;
};
