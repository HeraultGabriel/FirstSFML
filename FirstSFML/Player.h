#pragma once
#include "GameObject.h"

class Player : public GameObject
{
    sf::RectangleShape playerShape;
    sf::Texture playerTexture;

    float speed = 100;
    float frame = 0;
    float animationSpeed = 2.0f;

public:
    Player() : GameObject()
    {
        playerShape = sf::RectangleShape({ 40,64 });
        playerShape.setOrigin(sf::Vector2f(playerShape.getGeometricCenter().x, 64));

        if (playerTexture.loadFromFile("Graphics\\HolySheet.png"))
            playerShape.setTexture(&playerTexture);
        playerShape.setTextureRect(sf::IntRect({ 148, 87 }, {20, 32}));
    }
    Player(sf::Texture& _texture) : GameObject()
    {
        playerShape = sf::RectangleShape({ 80,128 });
        playerShape.setOrigin(sf::Vector2f(playerShape.getGeometricCenter().x, 128));
        playerTexture = _texture;
        playerShape.setTexture(&playerTexture);
        playerShape.setTextureRect(sf::IntRect({ 148, 87 }, { 20, 32 }));
    }
    ~Player() {}

public:
    sf::RectangleShape& GetPlayerShape() { return playerShape; }

    virtual sf::FloatRect GetColliderSize() override { return playerShape.getGlobalBounds(); };
    virtual void Draw(sf::RenderWindow& _window) override;

    void MovePlayer(float _speed, float _deltaTime);
    void MovePlayer(float _deltaTime);
    void Update(float _deltaTime);
    void SetPlayerPosition(sf::Vector2f _pos);
    void SetPlayerTextureDirection(float _direction);
};

