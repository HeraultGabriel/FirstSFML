#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>

#include "GameContent.h"
#include "GameDataLoader.h"
#include "Player.h"


using namespace sf;
using SFMLString = String;

class Game
{
	GameDataLoader* loader = new GameDataLoader("Graphics",
		{
			"HolySheet.png",
			"HolySheet.png"
		},
		"Font", 
		{
			"Minecraft.ttf"
		});

	GameContent* currentContent = new GameContent();
	RenderWindow* currentWindow = nullptr;
	Player* player = nullptr;
	Coin* coin = new Coin();
	Score* scoreInfo = new Score();

	sf::Clock timer;
	float fps;
	static float deltaTime;

	sf::Font currentScoreFont;
	sf::Text scoreText = sf::Text(currentScoreFont);
	int score = 0;

public:
	static const float DeltaTime() { return deltaTime; }

	Game(int _width, int _height, std::string _name)
	{
		currentWindow = new RenderWindow(VideoMode(Vector2u(_width, _height)), _name);
	}
	Game(const Game& _copy)
	{
		this->currentWindow = _copy.currentWindow;
	}
	~Game()
	{
		delete player;
		delete currentContent;
		delete currentWindow;
		delete loader;
		delete coin;
		delete scoreInfo;
	}

public:
	void StartGame();

private:
	void OnStart();
	void OnFrameUpdate();
};
