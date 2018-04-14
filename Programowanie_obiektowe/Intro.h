// Autor: Szymon Cichy 235093
// Data: 11.04.2018

#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
class Intro
{
	// color palette
	const sf::Color light_blue = sf::Color(76, 155, 211, 255);
	const sf::Color dark_blue = sf::Color(6, 42, 68, 255);
	const sf::Color white = sf::Color(255, 255, 255, 255);
	const sf::Color black = sf::Color(0, 0, 0, 255);
	const sf::Color light_orange = sf::Color(255, 176, 81, 255);
	const sf::Color dark_orange = sf::Color(106, 61, 2, 255);

	// window size
	const int window_width = 400;
	const int window_height = 400;
	
	// position and size of elements inside a window
	//
	// button grid elements
	const sf::Vector2f grid_pos = sf::Vector2f(15, 100);
	const sf::Vector2f grid_spacing = sf::Vector2f(10, 10);
	const sf::Vector2f btn_size = sf::Vector2f(60, 30);
	const int title_char_size = 20;
	const int start_btn_radius = 50;
	const sf::Vector2f start_btn_pos = sf::Vector2f(20, 250);
	// button and title positions
	sf::Vector2f title_1_pos = grid_pos;
	sf::Vector2f row_0_btn_0_pos = title_1_pos + sf::Vector2f(0, title_char_size + grid_spacing.y);
	sf::Vector2f row_0_btn_1_pos = row_0_btn_0_pos + sf::Vector2f(btn_size.x + grid_spacing.x, 0);
	sf::Vector2f row_0_btn_2_pos = row_0_btn_1_pos + sf::Vector2f(btn_size.x + grid_spacing.x, 0);
	sf::Vector2f title_2_pos = row_0_btn_0_pos + sf::Vector2f(0, grid_spacing.y + btn_size.y);
	sf::Vector2f row_1_btn_0_pos = title_2_pos + sf::Vector2f(0, title_char_size + grid_spacing.y);
	sf::Vector2f row_1_btn_1_pos = row_1_btn_0_pos + sf::Vector2f(btn_size.x + grid_spacing.x, 0);
	sf::Vector2f row_1_btn_2_pos = row_1_btn_1_pos + sf::Vector2f(btn_size.x + grid_spacing.x, 0);
	// IMPORTANT - active buttons
	// buttons are numbered from 0 to 2 and one in each row is active
	// buttons are colored according to those values
	// minesweeper values are changed accordingly to active button
	int row_0_active_button = 0;
	int row_1_active_button = 0;
	int start_btn_clicked = 0;
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
	void handle_mouse(sf::RenderWindow& window);
};

