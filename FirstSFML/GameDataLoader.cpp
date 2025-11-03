#include "GameDataLoader.h"

std::vector <sf::Texture> GameDataLoader::allTextures = {};
std::vector <sf::Font> GameDataLoader::allFonts = {};

void GameDataLoader::LoadData()
{
	for (int i = 0; i < filesName.size(); i++)
	{
		allTextures.push_back(sf::Texture(folderName + "\\" + filesName[i]));
	}

	//font
	//a

	for (int i = 0; i < filesFontName.size(); i++)
	{
		allFonts.push_back(sf::Font(folderFontName + "\\" + filesFontName[i]));
	}
}
