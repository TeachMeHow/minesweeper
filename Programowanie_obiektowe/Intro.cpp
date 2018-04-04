#include "Intro.h"



Intro::Intro()
{
}


Intro::~Intro()
{
}

void Intro::draw(sf::RenderWindow & window, sf::Font font)
{
	window.clear(sf::Color(0x686868));
	sf::Text text;
	text.setString("Press any key to start");
	text.setFont(font);
	text.setCharacterSize(30);
	window.draw(text);
	window.display();
}

void Intro::display()
{
	sf::Font font;
	if (!font.loadFromFile("font.ttf"))
	{
		std::cerr << "Failed to load font \n";
	}
	sf::RenderWindow window(sf::VideoMode(300, 100), "Introduction");
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed || event.type == sf::Event::KeyPressed)
			{
				window.close();
			}
		}
		draw(window, font);
		// if game doesn't continue, new window with intro appears
	}
	window.close();

}
