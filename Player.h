#pragma once
#include <SFML/Graphics.hpp>
#include "Window.h"
#include "Bullet.h"
#include "Enemy.h"
#include "Points.h"
#include <iostream>

enum Direction
{
    NONE,
    LEFT,
    RIGHT
};

class Player
{
public:
    Player();
    ~Player();
    sf::Sprite* getSprite();
    void update(float dt);
    void handleInput(sf::Event);
    bool shoot();
    void checkKeyboardKeys();
    Points* getPoints();
    void damage();
    void destroy();
    bool isAlive();
    void move(float dt);
    sf::Text getLivesText();
    sf::Sprite* getLivesSprite();
    Direction direction;
    sf::Color getColor();
    void reset();
    void kill();
private:
    bool alive;
    int lives;
    sf::Texture texture;
    sf::Sprite sprite;
    sf::Sprite lives_sprite;
    bool canShoot;
    bool substract;
    float reloadTime;
    float timer; //timer to control shooting speed
    const float movingSpeed; //constant, helps the 'speed' variable to set it's proper value
    float speed; //changed whether the direction changes
    Points points;
    //drawing lives
    sf::Text lives_text;
    sf::Font lives_font;
};
