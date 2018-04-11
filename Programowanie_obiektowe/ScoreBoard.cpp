// Autor: Szymon Cichy 235093
// Data: 11.04.2018

#include "ScoreBoard.h"
#include <iostream>
#include <string>



ScoreBoard::ScoreBoard(Board & brd) : board(brd)
{
	window.create(sf::VideoMode(300, 300), "Score");
	if (!font.loadFromFile("font.ttf"))
	{
		std::cerr << "Failed to load font \n";
	}
}


ScoreBoard::~ScoreBoard()
{
}

void ScoreBoard::draw()
{
	window.clear();
	sf::Text text;
	text.setCharacterSize(20);
	text.setFont(font);
	std::string str;
	if (!(board.score() == -1))
	{
		str = "Your score: " + std::to_string(board.score());
	}
	else str = "YOU LOSE";
	text.setString(str);
	window.draw(text);
	window.display();
}

void ScoreBoard::display()
{
	while (window.isOpen())
	{
		sf::Event event;
		if (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}
		draw();
	}
	window.close();
}
