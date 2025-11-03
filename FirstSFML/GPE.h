#pragma once

#include "GameObject.h"

class GPE : public GameObject
{
	sf::Texture texture;
	sf::RectangleShape shapeGPE;

public:
	GPE() : GameObject()
	{
		shapeGPE = sf::RectangleShape(sf::Vector2f(50, 50));
	}
	GPE(const std::string& _fileName, sf::Vector2f _size, sf::Vector2f _pos, int _angle = 0, bool _repeat = true) : GameObject()
	{
		shapeGPE = sf::RectangleShape(_size);
		shapeGPE.setPosition(_pos);
		shapeGPE.setRotation(sf::degrees(_angle));
		if (texture.loadFromFile(_fileName))
		{
			shapeGPE.setTexture(&texture);
		}
		texture.setRepeated(_repeat);
	}

	GPE(sf::Texture& _texture, sf::Vector2f _size, sf::Vector2f _pos, int _angle = 0, bool _repeat = true) : GameObject()
	{
		shapeGPE = sf::RectangleShape(_size);
		shapeGPE.setPosition(_pos);
		shapeGPE.setRotation(sf::degrees(_angle));
		texture = _texture;
		shapeGPE.setTexture(&texture);
		texture.setRepeated(_repeat);
	}

public:
	virtual void Draw(sf::RenderWindow& _window) override;
};

