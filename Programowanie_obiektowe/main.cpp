
#include <SFML/Graphics.hpp>

#include "Board.h"
#include "GameManager.h"
#include <stdlib.h>
#include <iostream>


int main()
{
	// number of rows and columns
	unsigned int col_num = 6;
	unsigned int row_num = 12;
	Board game = Board(row_num, col_num);
	game.deploy_mines(10, true);
	// style game and calculate window size based on number of fields and their size
	unsigned int width = 40;
	unsigned int height = width;
	unsigned int padding = 20;
	sf::Color bg_color = sf::Color(0xE0E0E0);
	game.style_game(width, height, padding, bg_color);
	unsigned int win_width = col_num * (width + padding) + padding;
	unsigned int win_height = row_num * (height + padding) + padding;
	// Open SFML window used for the game w/ max refresh rate
	sf::RenderWindow window(sf::VideoMode(win_width, win_height), "Saper");
	window.setFramerateLimit(60);
	// create a game and deploy mines

	// load font and icons
	GameManager gm(window, game);
	
	// continous loop
	while (window.isOpen())
	{
		// loop closes the window if exit is pressed
		sf::Event event;
		while (window.pollEvent(event))
		{
			//game.handle_mouse(window, event);
			if (event.type == sf::Event::Closed)
				window.close();
			gm.handle_event(event);
		}
		// continous game display
		gm.draw();
	}

	return EXIT_SUCCESS;
}
