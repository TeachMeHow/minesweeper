#pragma once
#include "Field.h"
#include "Board.h"
#include <SFML/Graphics.hpp>

class GameManager
{
	Board & board;
	sf::RenderWindow & window;
	sf::Font font;
	sf::Image* icons;
	enum GameState {START, GAME, END} state;
public:
	GameManager(sf::RenderWindow & win, Board & board);
	~GameManager();
	void draw();
	void debug_change_state();
	void handle_event(sf::Event event);
};

