#pragma once

#include "GameObject.h"
#include "GameDataLoader.h"

#include <SFML/Graphics.hpp>

class Coin : public GameObject
{
    sf::Texture texture;
    sf::RectangleShape coin;

private:
    float frame = 0;  
    float animationSpeed = 2.0f;  

public:
    Coin() {}
    Coin(sf::Vector2f _position, float _deltaTime)
    {
        coin = sf::RectangleShape({ 64, 64 });
        coin.setPosition(_position);
        texture = GameDataLoader::allTextures[1];
        coin.setTexture(&texture);
        coin.setTextureRect(sf::IntRect({ 253, 225 }, { 16, 16 }));
    }

public:
    virtual sf::FloatRect GetColliderSize() override { return coin.getGlobalBounds(); };
    virtual void Draw(sf::RenderWindow& _window) override;

    void Update(float _deltaTime);
};

