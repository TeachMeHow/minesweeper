
#include <SFML/Graphics.hpp>

#include "Board.h"
#include "Field.h"


int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");
	Board game = Board(13, 5);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		game.display(window);
	}

	return EXIT_SUCCESS;
}
