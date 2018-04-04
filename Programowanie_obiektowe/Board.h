#pragma once
#include "Field.h"
#include <SFML/Graphics.hpp>
#include <chrono>
class Board
{
	// all fields are on the grid
	Field** grid;
	// if no size is specified this is the default size
	static const size_t DEFAULT_SIZE;
	size_t row_num;
	size_t col_num;
	// true if a mine has been reveal'ed'()
	bool end_game;
	// false if there is no field with x,y index on the grid
	bool in_bounds(int x, int y) const;
	// styling with default values
	unsigned int width = 40;
	unsigned int height = 40;
	unsigned int padding = 10;
	sf::Color bg_color = sf::Color(0x696969);
	// for when the game ends and starts
	std::chrono::time_point<std::chrono::steady_clock> start_timestamp;
	std::chrono::time_point<std::chrono::steady_clock> end_timestamp;
	enum GameState {IN_PROGRESS, WIN, LOSS} state;
public:
	Board() : Board(DEFAULT_SIZE, DEFAULT_SIZE) { };
	//Square board MxM
	Board(size_t M) : Board(M, M) { };
	//Rectangular board MxN
	Board(size_t M, size_t N);
	~Board();
	// deploys mines on the board, if random is true randomly,
	// if not, in a set pattern
	void deploy_mines(int n, bool random);
	// checks whether a field has a mine
	bool has_mine(int x, int y) const;
	// counts the number of mines around a field
	int count_mines(int x, int y) const;
	// game ends on last reveal
	// set a mine visible and uncover mines and end the game if mine is present
	void reveal(int x, int y);
	// toggle flag
	void toggle_flag(int x, int y);
	// set all fields visible
	void uncover_mines();
	// Text representation of the board displayed in console
	void display() const;
	// Board display linked to a SFML  window
	void draw(sf::RenderWindow & win, sf::Font font, sf::Image *icons);
	// Board display with its own window
	void display(int i);
	// Change the default graphical style of the game
	void style_game(unsigned int width, unsigned int height, unsigned int padding, sf::Color bg_color);
	// returns true if bomb has been revealed
	bool end() { return end_game; };
	// checks for condition for game end
	void check_state();
	// returns game score based on duration, -1 if loss
	int score();

};

