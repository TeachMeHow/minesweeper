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
public:
	ScoreBoard(Board & board);
	~ScoreBoard();
	void draw();
	void display();
};

