#pragma once
#include "Field.h"
#include <SFML/Graphics.hpp>
#include <chrono>
class Board
{
	// all fields are on the grid
	Field** grid;
	// if no size is specified this is the default size
	static const int DEFAULT_SIZE;
	int row_num;
	int col_num;
	// for when the game ends and starts
	// game ends when the last field is revealed ( be it last empty or bomb)
	std::chrono::time_point<std::chrono::steady_clock> start_timestamp;
	std::chrono::time_point<std::chrono::steady_clock> end_timestamp;
	// state of the game
	enum GameState {IN_PROGRESS = 0, WIN = 1, LOSS = 2} state;
public:
	Board() : Board(DEFAULT_SIZE, DEFAULT_SIZE) { };
	//Square board MxM
	Board(int M) : Board(M, M) { };
	//Rectangular board MxN
	Board(int M, int N);
	~Board();
	// false if there is no field with x,y index on the grid
	bool in_bounds(int x, int y) const;
	int get_row_num() { return row_num; };
	int get_col_num() { return col_num; };
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
	void debug_display() const;
	// returns game score based on duration, -1 if loss
	int score();
	// return state in int form
	// 0 - in progress
	// 1 - finished, game won
	// 2 - finished, game lost
	int get_state();
	// gets state of field at grid
	int get_field_state(int x, int y);
	void start_game();
};

