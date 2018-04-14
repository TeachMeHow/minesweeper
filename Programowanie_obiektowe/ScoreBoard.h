// Autor: Szymon Cichy 235093
// Data: 11.04.2018

#pragma once
#include <SFML\Graphics.hpp>
#include "Board.h"
class ScoreBoard
{
	sf::RenderWindow window;
	sf::Font font;
	Board & board;

	// color palette
	const sf::Color light_blue = sf::Color(76, 155, 211, 255);
	const sf::Color dark_blue = sf::Color(6, 42, 68, 255);
	const sf::Color white = sf::Color(255, 255, 255, 255);
	const sf::Color black = sf::Color(0, 0, 0, 255);
	const sf::Color light_orange = sf::Color(255, 176, 81, 255);
	const sf::Color dark_orange = sf::Color(106, 61, 2, 255);

public:
	ScoreBoard(Board & board);
	~ScoreBoard();
	void draw();
	void display();
};

