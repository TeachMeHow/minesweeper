#include "GameManager.h"
#include <iostream>
#include <string>

using namespace std::chrono;
//GameManager::GameManager(sf::RenderWindow & win, Board & brd) : board(brd), window(win)
//{
//	icons = new sf::Image[3];
//	if (!icons[0].loadFromFile("boom.png"))
//	{
//		std::cerr << "Failed to open boom.png \n";
//	}
//	if (!icons[1].loadFromFile("bomb.png"))
//	{
//		std::cerr << "Failed to open bomb.png \n";
//	}
//	if (!icons[2].loadFromFile("flag.png"))
//	{
//		std::cerr << "Failed to open flag.png \n";
//	}
//	if (!font.loadFromFile("font.ttf"))
//	{
//		std::cerr << "Failed to load font \n";
//	}
//	state = START;
//}

GameManager::GameManager(Board & brd) : board(brd)
{
}

GameManager::~GameManager()
{
}

void GameManager::start_game()
{
	board.display();
}

//void GameManager::draw()
//{
//	switch (state)
//	{
//	case START:
//	{
//		window.clear(sf::Color(0x000000));
//		sf::Text text;
//		text.setCharacterSize(25);
//		text.setFont(font);
//		// TODO game doesn't have a score yet
//		text.setString("PRESS ANY KEY TO START THE GAME");
//		window.draw(text);
//		window.display();
//	}
//		break;
//	case GAME:	
//		board.draw(window, font, icons);
//		if (board.end())
//		{
//			state = END;
//		}
//		break;
//	case END:
//		window.clear(sf::Color(0x000000));
//		sf::Text text;
//		text.setCharacterSize(25);
//		text.setFont(font);
//		// TODO game doesn't have a score yet
//
//		text.setString("YOUR SCORE: " + std::to_string(score));
//		window.draw(text);
//		window.display();
//	
//	}
//}
//
//
//void GameManager::debug_change_state()
//{
//	switch (state)
//	{
//	case START: 
//		// start the game
//		state = GAME;
//		
//		break;
//	case GAME: 
//		// end the game
//		state = END;
//		break;
//	case END: 
//		// start over
//		state = START;
//		break;
//	}
//}
//
//void GameManager::handle_event(sf::Event event)
//{
//	// change game state with any button press
//	if (event.type == sf::Event::KeyPressed) 
//	{
//		debug_change_state();
//	}
//}
