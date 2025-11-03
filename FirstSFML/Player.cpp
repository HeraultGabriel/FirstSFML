#include "Player.h"
#include "Game.h"

void Player::Draw(sf::RenderWindow& _window)
{
    _window.draw(playerShape);

    if (playerShape.getPosition().x < 107)
    {
        playerShape.setPosition(Vector2f(107, playerShape.getPosition().y));
    }
    if (playerShape.getPosition().x > _window.getSize().x - 108)
    {
        playerShape.setPosition(Vector2f(_window.getSize().x - 108, playerShape.getPosition().y));
    }
    if (playerShape.getPosition().y < 100)
    {
        playerShape.setPosition(Vector2f(playerShape.getPosition().x, 36 + playerShape.getSize().y / 2));
    }
    if (playerShape.getPosition().y >= _window.getSize().y - 100)
    {
        playerShape.setPosition(Vector2f(playerShape.getPosition().x, _window.getSize().y - 101));
    }
}

void Player::MovePlayer(float _deltaTime)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Left))
    {
        SetPlayerTextureDirection(-1);
        Update(Game::DeltaTime());
        playerShape.move({ -speed * _deltaTime, 0.f });
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Right))
    {
        SetPlayerTextureDirection(1);
        Update(Game::DeltaTime());
        playerShape.move({ speed * _deltaTime, 0.f });
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Up))
    {
        Update(Game::DeltaTime());
        playerShape.move({ 0.f, -speed * _deltaTime });
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Down))
    {
        Update(Game::DeltaTime());
        playerShape.move({ 0.f, speed * _deltaTime });
    }
}

void Player::MovePlayer(float _speed, float _deltaTime)
{
    speed = _speed;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Left))
    {
        SetPlayerTextureDirection(-1);
        Update(Game::DeltaTime());
        playerShape.move({ -speed * _deltaTime, 0.f });
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Right))
    {
        SetPlayerTextureDirection(1);
        Update(Game::DeltaTime());
        playerShape.move({ speed * _deltaTime, 0.f });
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Up))
    {
        Update(Game::DeltaTime());
        playerShape.move({ 0.f, -speed * _deltaTime });
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Down))
    {
        Update(Game::DeltaTime());
        playerShape.move({ 0.f, speed * _deltaTime });
    }
}

void Player::Update(float _deltaTime)
{
    int currentFrame = frame;
    int posX = 169 - (int(currentFrame) * 21);

    frame = frame + _deltaTime < 3.0f ? frame + _deltaTime * animationSpeed : 0;
    playerShape.setTextureRect(sf::IntRect({ posX, 120 }, { 20, 32 }));
}

void Player::SetPlayerPosition(sf::Vector2f _pos)
{
    playerShape.setPosition(_pos);
}

void Player::SetPlayerTextureDirection(float _direction)
{
    playerShape.setScale({ _direction, 1.f });
}