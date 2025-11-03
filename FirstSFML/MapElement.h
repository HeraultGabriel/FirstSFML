#pragma once

#include "GameObject.h"

class MapElement : public GameObject
{
	sf::Texture texture;
	sf::RectangleShape shape;

public:
	MapElement() : GameObject()
	{
		shape = sf::RectangleShape(sf::Vector2f(50, 50));
	}
	MapElement(sf::Vector2f _size, sf::Vector2f _pos) : GameObject()
	{
		shape = sf::RectangleShape(_size);
		shape.setPosition(_pos);
	}
	MapElement(const std::string& _fileName, sf::Vector2f _size, sf::Vector2f _pos, int _angle = 0, bool _repeat = true) : GameObject()
	{
		shape = sf::RectangleShape(_size);
		shape.setPosition(_pos);
		shape.setRotation(sf::degrees(_angle));
		if (texture.loadFromFile(_fileName))
		{
			shape.setTexture(&texture);
		}
		texture.setRepeated(_repeat);
	}

	MapElement(sf::Texture& _texture, sf::Vector2f _size, sf::Vector2f _pos, int _angle = 0, bool _repeat = true) : GameObject()
	{
		shape = sf::RectangleShape(_size);
		shape.setPosition(_pos);
		shape.setRotation(sf::degrees(_angle));
		texture = _texture;
		shape.setTexture(&texture);
		texture.setRepeated(_repeat);
	}

	MapElement(sf::Texture& _texture, sf::Vector2f _size, sf::Vector2f _pos, sf::Vector2i _posSheet, sf::Vector2i _sizeSheet, int _angle = 0, bool _repeat = true) : GameObject()
	{
		shape = sf::RectangleShape(_size);
		shape.setPosition(_pos);
		shape.setRotation(sf::degrees(_angle));
		texture = _texture;
		shape.setTexture(&texture);
		shape.setTextureRect(sf::IntRect(_posSheet, _sizeSheet));
		texture.setRepeated(_repeat);
	}

public:
	virtual void Draw(sf::RenderWindow& _window) override;
};

