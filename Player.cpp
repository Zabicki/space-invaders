#include "Player.h"

/*
TODO
[] smth wrong with the collision system, check this
[X]Program crashed in some bullet situations, has to be fixed asap (return code 134(0x86)
  When the last fired bulet is colliding with enemy, program crashes
[]Fix the transparency
*/

Player::Player()
:movingSpeed(400)
{
    texture.loadFromFile("resources/player.png");
    sprite.setTexture(texture);
    sprite.setOrigin(sprite.getGlobalBounds().width / 2, sprite.getGlobalBounds().height /2);
    sprite.setPosition(Window::instance().getWindow()->getSize().x / 2, Window::instance().getWindow()->getSize().y - 60);
    sprite.setScale({3.f, 3.f});
    sprite.setColor(sf::Color::Green);
    lives_sprite = sprite;
    lives_sprite.setPosition(Window::instance().getWindow()->getSize().x - 60,Window::instance().getWindow()->getSize().y - 23);
    lives_sprite.setColor(sf::Color(255,255,255,50));
    lives_sprite.setColor(sf::Color::Green);
    speed = 0;
    direction = NONE;
    canShoot = true;
    substract = false;
    reloadTime = 0.5f;
    timer = reloadTime;
    lives = 3;
    alive = true;

    lives_font.loadFromFile("resources/space_font.ttf");
    lives_text.setFont(lives_font);
    lives_text.setCharacterSize(30);
    lives_text.setFillColor(sf::Color::White);
    lives_text.setFillColor(sf::Color(255,255,255,150));
    lives_text.setPosition(Window::instance().getWindow()->getSize().x - 30, Window::instance().getWindow()->getSize().y - 40);
    lives_text.setString(std::to_string(lives));
}

Player::~Player()
{

}

sf::Sprite* Player::getSprite()
{
    return &sprite;
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
    lives_text.setString(std::to_string(lives));
    if (lives == 0)
        destroy();
}

void Player::destroy()
{
    alive = false;
    //add explosion animation and sound
}

bool Player::isAlive()
{
    return alive;
}

void Player::move(float dt)
{
    if (direction != NONE)
        sprite.move(speed * dt, 0);
}

sf::Text Player::getLivesText()
{
    return lives_text;
}

sf::Sprite* Player::getLivesSprite()
{
    return &lives_sprite;
}
