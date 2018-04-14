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
	sf::Color light_blue = sf::Color(90, 105, 200, 255);
	sf::Color dim_blue = sf::Color(54, 56, 73, 255);
	sf::Color light_yellow = sf::Color(255, 227, 119, 255);

public:
	GameManager(Board & brd);
	~GameManager();

	// Board display linked to a SFML  window
	void draw(sf::RenderWindow & win, sf::Font font, sf::Image *icons);

	// Board display with its own window
	void display();
	void start_game();
};

