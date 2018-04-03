
#include <SFML/Graphics.hpp>

#include "Board.h"
#include "Field.h"
#include <stdlib.h>


int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");
	window.setFramerateLimit(60);
	Board game = Board(13, 5);
	game.deploy_mines(20, true);
	sf::Font font;
	sf::Image icons[3];
	if (!icons[0].loadFromFile("boom.png"))
	{
		// error
	}
	if (!icons[1].loadFromFile("bomb.png"))
	{
		// error
	}
	if (!icons[2].loadFromFile("flag.png"))
	{
		//error
	}
	if (!font.loadFromFile("font.ttf"))
	{
		// error
	}

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		game.display(window, font, icons);
	}

	return EXIT_SUCCESS;
}
