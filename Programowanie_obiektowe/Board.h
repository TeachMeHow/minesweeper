#pragma once
#include "Field.h"
#include <SFML/Graphics.hpp>
class Board
{
	// all fields are on the grid
	Field** grid;
	// if no size is specified this is the default size
	static const size_t DEFAULT_SIZE;
	size_t row_count;
	size_t col_count;
	// true if a mine has been reveal'ed'()
	bool end_game;
	// false if there is no field with x,y index on the grid
	bool in_bounds(int x, int y) const;
	
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
	// set a mine visible and uncover mines and end the game if mine is present
	void reveal(int x, int y);
	// set all fields visible
	// TODO only mines visible?
	void uncover_mines();
	// Text representation of the board displayed in console
	void display() const;
	// Board display linked to a SFML  window
	void display(sf::RenderWindow & win, sf::Font font, sf::Image *icons);


};

