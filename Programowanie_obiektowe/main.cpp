
#include <SFML/Graphics.hpp>

#include "Board.h"
#include "GameManager.h"
#include <stdlib.h>
#include <iostream>


int main()
{
	Board game = Board(13, 5);
	game.deploy_mines(10, true);
	// style game and calculate window size based on number of fields and their size
	game.style_game(40, 40, 20, sf::Color(0x3f3f3f));
	sf::Vector2u win_size = sf::Vector2u(5 * (40 + 20) + 20, 13 * (40 + 20) + 20);
	
	// Open SFML window used for the game w/ max refresh rate
	sf::RenderWindow window(sf::VideoMode(win_size.x, win_size.y), "Saper");
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
