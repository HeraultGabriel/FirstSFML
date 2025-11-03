#include "Score.h"

void Score::Draw(sf::RenderWindow& _window)
{
	sf::Font font("Graphics/Minecraft.ttf");
	sf::Text text(font);
	text.setString("Votre score :");
	text.setCharacterSize(24);
	text.setFillColor(sf::Color::Red);
	text.setStyle(sf::Text::Bold | sf::Text::Underlined);
	text.setPosition({ 1650, 30 });
	_window.draw(text);
}
