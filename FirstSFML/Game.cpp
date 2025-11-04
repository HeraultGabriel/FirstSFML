#include <iostream>
#include <string>
#include "Game.h"
#include "Coin.h"
#include "GameContent.h"

float Game::deltaTime = 0;

void Game::StartGame()
{
	if (!currentWindow)
	{
		return;
	}
	OnStart();
	while (currentWindow->isOpen())
	{
		deltaTime = timer.restart().asSeconds();
		fps = 1.f / deltaTime;

		while (const std::optional event = currentWindow->pollEvent())
		{
			if (event->is<sf::Event::Closed>())
				currentWindow->close();

		}
		currentWindow->clear();

		player->MovePlayer(200, deltaTime);
		OnFrameUpdate();

		currentWindow->display();
	}
}

void Game::OnStart()
{
	currentWindow->setVerticalSyncEnabled(true);
	loader->LoadData();

	if (player)
	{
		delete player;
	}
	player = new Player(GameDataLoader::allTextures[1]);
	player->SetPlayerPosition( sf::Vector2f(350, 950));

	currentContent->CreateMap(*currentWindow);

	currentScoreFont = loader->allFonts[0];
	scoreText.setFont(currentScoreFont);
	scoreText.setString("aaa");
}

void Game::OnFrameUpdate()
{
	for (int i = 0; i < currentContent->GetGameObjectsSize(); i++)
	{
		currentContent->GetMapElement(i).Draw(*currentWindow);
	}
	for (int i = 0; i < currentContent->GetGPElementSize(); i++)
	{
		currentContent->GetGPEElement(i).Draw(*currentWindow);
		if (currentContent->GetGPEElement(i).Check(*player))
		{
			score += 100;
			scoreText.setString("Score" + std::to_string(score));
			currentContent->RemoveGPElement(i);
		}
	}
	currentWindow->draw(scoreText);
	scoreInfo->Draw(*currentWindow);
	player->Draw(*currentWindow);
}
