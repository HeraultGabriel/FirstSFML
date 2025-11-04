#include "GameContent.h"
#include "Game.h"

void GameContent::AddMapElement(MapElement* _gameObject)
{
	mapElement.push_back(_gameObject);
}

void GameContent::AddGPElement(GameObject* _gameObject)
{
	gpeElement.push_back(_gameObject);
}

void GameContent::RemoveGPElement(int _toRemove)
{
	GameObject* _pointerToRemove = gpeElement.at( _toRemove);
	gpeElement.erase(gpeElement.begin() + _toRemove);
	delete _pointerToRemove;
}

void GameContent::CreateMap(sf::RenderWindow& _window)
{
	//BACKGROUND
	AddMapElement(new MapElement(GameDataLoader::allTextures[5], sf::Vector2f(_window.getSize().x, _window.getSize().y), sf::Vector2f(0, 0), sf::Vector2i(604, 287), sf::Vector2i(10, 10)));
	AddMapElement(new MapElement(sf::Vector2f(200,50), sf::Vector2f(_window.getSize().x * 0.85, _window.getSize().y * 0.02)));

	//AddMapElement(new MapElement("Graphics\\Egypt\\Bg\\Sky_Bg", sf::Vector2f(_window.getSize().x, _window.getSize().y), sf::Vector2f(0, 0), sf::Vector2i(604, 287), sf::Vector2i(10, 10)));

	//WALL
	for(int _i = 0; _i < 30; _i++)
	{
		AddMapElement(new MapElement(GameDataLoader::allTextures[5], sf::Vector2f(64, 64), sf::Vector2f(0, 64 * _i), sf::Vector2i(270, 429), sf::Vector2i(16, 16)));
		AddMapElement(new MapElement(GameDataLoader::allTextures[5], sf::Vector2f(64, 64), sf::Vector2f(_window.getSize().x - 64, 64 * _i), sf::Vector2i(270, 429), sf::Vector2i(16, 16)));
	}

	//GROUND
	for (int _i = 0; _i < 30; _i++)
	{
		AddMapElement(new MapElement(GameDataLoader::allTextures[5], sf::Vector2f(64, 64), sf::Vector2f(64 * _i, _window.getSize().y -64), sf::Vector2i(270, 378), sf::Vector2i(16, 16)));
	}
	
	//COIN
	AddGPElement(new Coin(sf::Vector2f(500, 300), Game::DeltaTime()));
	AddGPElement(new Coin(sf::Vector2f(700, 300), Game::DeltaTime()));
	AddGPElement(new Coin(sf::Vector2f(900, 300), Game::DeltaTime()));
	AddGPElement(new Coin(sf::Vector2f(1100, 300), Game::DeltaTime()));
	AddGPElement(new Coin(sf::Vector2f(500, 500), Game::DeltaTime()));
	AddGPElement(new Coin(sf::Vector2f(700, 500), Game::DeltaTime()));
	AddGPElement(new Coin(sf::Vector2f(900, 500), Game::DeltaTime()));
	AddGPElement(new Coin(sf::Vector2f(1100, 500), Game::DeltaTime()));
}
