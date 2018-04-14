// Autor: Szymon Cichy 235093
// Data: 11.04.2018

#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
class Intro
{
	// color palette
	const sf::Color light_blue;
	const sf::Color dark_blue;
	const sf::Color white;
	const sf::Color black;
	const sf::Color light_orange;
	const sf::Color dark_orange;

	const int window_width = 400;
	const int window_height = 400;

public:
	Intro();
	~Intro();
	void draw(sf::RenderWindow & window, sf::Font font);
	// when the window closes, returns parameters chosen by the user
	// parameters are as follows
	// param[0] - number of fields horizontal
	// param[1] - number of fields vertical
	// param[2] - difficulty - number of bombs
	// param[3]	- start was pressed (window not closed by X) 0 - not started, 1 - started
	std::vector<int> display();
	void handle_mouse(sf::Vector2f m_pos);
};

