#pragma once

#include <SFML/Graphics.hpp>

#include "GameObject.h"

class Score : public GameObject
{
	sf::RectangleShape shape;

public: 
	Score() : GameObject() {}

public:
	virtual void Draw(sf::RenderWindow& _window) override;
};

