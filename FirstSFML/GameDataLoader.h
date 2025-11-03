#pragma once

#include <string>
#include <vector>
#include <SFML/Graphics.hpp>

class GameDataLoader
{
	std::string folderName;
	std::vector<std::string> filesName = {};

	std::string folderFontName;
	std::vector<std::string> filesFontName = {};

public:
	static std::vector <sf::Texture> allTextures;
	static std::vector <sf::Font> allFonts;

public:
	sf::Texture playerTexture;
	GameDataLoader() {}
	GameDataLoader(const std::string& _folder, std::vector<std::string> _files, const std::string& _folderFont, std::vector<std::string> _filesFont)
	{
		folderName = _folder;
		filesName = _files;

		folderFontName = _folderFont;
		filesFontName = _filesFont;
	}

public :
	void LoadData();
};

