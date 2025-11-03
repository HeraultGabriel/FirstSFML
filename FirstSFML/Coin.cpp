#include "Coin.h"
#include "Game.h"

void Coin::Draw(sf::RenderWindow& _window)
{
    Update(Game::DeltaTime());
    _window.draw(coin);
}

void Coin::Update(float _deltaTime)
{
    int currentFrame = frame;
    int posX = 253 + (int(currentFrame) * 17);

    frame = frame + _deltaTime < 4.0f ? frame + _deltaTime * animationSpeed : 0;  
    coin.setTextureRect(sf::IntRect({ posX, 225 }, { 16, 16 }));
}