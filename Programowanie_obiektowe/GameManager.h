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
	sf::Color bg_color = sf::Color(0x696969);

public:
	//GameManager(sf::RenderWindow & win, Board & board);
	// connect to board
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

