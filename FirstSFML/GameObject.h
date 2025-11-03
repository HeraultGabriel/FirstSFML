#pragma once

#include <SFML/Graphics.hpp>

#include "CollisionSystem.h"

class GameObject : public CollisionSystem
{
public : 
	GameObject() {}
	virtual ~GameObject() {}

public : 
	virtual void Draw(sf::RenderWindow& _window) {}
};

