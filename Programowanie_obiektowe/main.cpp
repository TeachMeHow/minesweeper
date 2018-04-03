
#include <SFML/Graphics.hpp>

#include "Board.h"
#include "Field.h"
#include <stdlib.h>
#include <iostream>


int main()
{
	// Open SFML window used for the game w/ max refresh rate
	sf::RenderWindow window(sf::VideoMode(800, 600), "Saper");
	window.setFramerateLimit(60);
	// create a game and deploy mines
	Board game = Board(13, 5);
	game.deploy_mines(20, true);
	// load font and icons
	sf::Font font;
	sf::Image icons[3];
	if (!icons[0].loadFromFile("boom.png"))
	{
		std::cerr << "Failed to open boom.png \n";
		return EXIT_FAILURE;
	}
	if (!icons[1].loadFromFile("bomb.png"))
	{
		std::cerr << "Failed to open bomb.png \n";
		return EXIT_FAILURE;
	}
	if (!icons[2].loadFromFile("flag.png"))
	{
		std::cerr << "Failed to open flag.png \n";
		return EXIT_FAILURE;
	}
	if (!font.loadFromFile("font.ttf"))
	{
		std::cerr << "Failed to load font \n";
		return EXIT_FAILURE;
	}
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
		}
		// continous game display
		game.display(window, font, icons);
	}

	return EXIT_SUCCESS;
}
