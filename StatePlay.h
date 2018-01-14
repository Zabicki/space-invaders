#pragma once
#include "State.h"
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"
#include "Enemy1.h"
#include "CollisionSystem.h"
#include "Ufo.h"
#include "Explosion.h"

class StatePlay : public State
{
public:
    StatePlay();
    ~StatePlay() {};
    virtual void update(float);
    virtual void render();
    virtual int handleInput(); //returns nr of state if change is needed
    int pollEvent();
    void spawnEnemies(int amount);
    virtual void prepare();
private:
    Player player;
    CollisionSystem cs;
    std::vector<Bullet*> playerBullets;
    std::vector<Bullet*> enemyBullets;
    std::vector<Enemy*> enemies;
    std::vector<Explosion*> explosions;
    Ufo* ufo;
    float movingCooldown;
    bool substract;
    int i;
};
