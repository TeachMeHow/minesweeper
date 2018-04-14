// Autor: Szymon Cichy 235093
// Data: 11.04.2018

#pragma once
#include "Field.h"
#include "Board.h"
#include <SFML/Graphics.hpp>
#include <chrono>

class GameManager
{
	Board & board;
	// styling with default values
	int width = 40;
	int height = 40;
	int padding = 10;
	// palette
	sf::Color light_orange = sf::Color(255, 197, 94, 255);

public:
	GameManager(Board & brd);
	~GameManager();

	// Board display linked to a SFML  window
	void draw(sf::RenderWindow & win, sf::Font font, sf::Image *icons);

	// Board display with its own window
	void display();

	// Change the default graphical style of the game
	void style_game(unsigned int width, unsigned int height, unsigned int padding, sf::Color bg_color);
	void start_game();
};

