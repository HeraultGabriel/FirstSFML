#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

#include "GameObject.h"
#include "Player.h"
#include "MapElement.h"
#include "GameDataLoader.h"
#include "GPE.h"
#include "Coin.h"
#include "Score.h"

class GameContent
{
	std::vector<MapElement*> mapElement =
	{
	};
	std::vector<GameObject*> gpeElement =
	{
	};

public:
	const int& GetGameObjectsSize() { return  mapElement.size(); }
	const int& GetGPElementSize() { return gpeElement.size(); }

	MapElement& GetMapElement(int _index) { return *mapElement[_index]; }
	GameObject& GetGPEElement(int _index) { return *gpeElement[_index]; }

public : 
	GameContent() {}
	~GameContent()
	{
		for (MapElement* map : mapElement)
		{
			delete map;
		}
		mapElement.clear();
		for (GameObject* GPE : gpeElement)
		{
			delete GPE;
		}
		gpeElement.clear();
	}

public:
	void AddMapElement(MapElement* _gameObject);
	void AddGPElement(GameObject* _gameObject);
	void RemoveGPElement(int _toRemove);
	void CreateMap(sf::RenderWindow& _window);
};

