#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

class CollisionSystem
{
public: 
	CollisionSystem() {}
	~CollisionSystem() {}

public: 
	virtual sf::FloatRect GetColliderSize() { return sf::FloatRect(); }
	virtual bool Check(class GameObject& _other);
};

