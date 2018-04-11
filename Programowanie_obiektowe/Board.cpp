#include "Board.h"
#include "Intro.h"
#include "ScoreBoard.h"
#include <iostream>
#include <unordered_set>
#include <vector>
#include <random>
#include <algorithm>
#include <time.h>
#include <string>
using std::unordered_set;
using std::vector;
using std::for_each;
using std::string;
using namespace std::chrono;
typedef high_resolution_clock Time;

const int Board::DEFAULT_SIZE = 10;

//TODO Wrong number of has_mines - bounds?
bool Board::in_bounds(int x, int y) const
{
	return 0 <= x && x < col_num &&
		0 <= y && y < row_num;
}

Board::Board(int M, int N)
{
	row_num = M;
	col_num = N;
	
	grid = new Field*[M];
	for (size_t i = 0; i < M; i++)
	{
		grid[i] = new Field[N];
	}
}


Board::~Board()
{

	for (size_t i = 0; i < row_num; i++)
	{
		delete[] grid[i];
	}
	delete[] grid;
	
}

void Board::deploy_mines(int n, bool random)
{
	if (random)
	{
		//generate MxN numbers, verify uniqueness, then col = num % col_count and row = num / col_count
		size_t range = row_num * col_num;
		unordered_set<int> generated_numbers;
		vector<int> row_indexes;
		vector<int> col_indexes;
		srand((unsigned int)time(NULL));
		while (generated_numbers.size() < n)
		{
			generated_numbers.insert(rand() % range);
		}
		for_each(generated_numbers.begin(), generated_numbers.end(), [&](int i)
		{
			row_indexes.push_back(i / col_num);
			col_indexes.push_back(i % col_num);
		}
		);
		auto it = col_indexes.begin();
		for_each(row_indexes.begin(), row_indexes.end(), [&](int i)
		{
			grid[i][*it].set_mine();
			it++;
		}
		);
		
	}
	else
	{
		for (size_t i = 0; i < col_num; i++)
		{
			grid[0][i].set_mine();
		}
		for (size_t i(1), j(1); row_num < col_num ? (i < row_num) : (j < col_num); i++, j++)
		{
			grid[i][j].set_mine();
		}
	}
}

bool Board::has_mine(int x, int y) const
{
	return in_bounds(x, y) ? grid[y][x].get_mine() : false;
}

int Board::count_mines(int x, int y) const
{
	int count = 0;
	/*Somebody Toucha My 
							   _          _   _   _ 
							  | |        | | | | (_)
		 ___ _ __   __ _  __ _| |__   ___| |_| |_ _ 
		/ __| '_ \ / _` |/ _` | '_ \ / _ \ __| __| |
		\__ \ |_) | (_| | (_| | | | |  __/ |_| |_| |
		|___/ .__/ \__,_|\__, |_| |_|\___|\__|\__|_|
			| |           __/ |                     
			|_|          |___/       
	*/
	if (has_mine(++x, ++y) && in_bounds(x, y)) count++;
	if (has_mine(x, --y) && in_bounds(x, y)) count++;
	if (has_mine(x, --y) && in_bounds(x, y)) count++;
	if (has_mine(--x, y) && in_bounds(x, y)) count++;
	if (has_mine(--x, y) && in_bounds(x, y)) count++;
	if (has_mine(x, ++y) && in_bounds(x, y)) count++;
	if (has_mine(x, ++y) && in_bounds(x, y)) count++;
	if (has_mine(++x, y) && in_bounds(x, y)) count++;
	return count;
}

void Board::debug_display() const
{
	for (int i = 0; i < row_num; i++)
	{
		grid[5][i].set_visible();
	}
	for (int i = 0; i < col_num; i++)
	{
		grid[i][4].set_flag(true);
	}
	for (int e = 0; e < row_num; e++)
	{
		for (int i = 0; i < col_num; i++)
		{
			Field element = grid[e][i];
			std::string symbol;
			if (!element.get_visible() && !element.get_flag()) symbol = "[.]";
			else if (!element.get_visible() && element.get_flag()) symbol = "[?]";
			else if (element.get_visible() && count_mines(i,e) == 0
				&& !has_mine(i,e)) symbol = "[ ]";
			else if (element.get_visible() && !has_mine(i, e)) 
				symbol = '[' + std::to_string(count_mines(i, e)) + ']';
			else if (element.get_visible() && has_mine(i, e)) symbol = "[x]";

			std::cout << symbol;
		}
		std::cout << std::endl;
	}

}

int Board::score()
{
	switch (state)
	{
	case IN_PROGRESS: return -1;
	case LOSS: return -1;
	case WIN:
	{
		// calculate duration in seconds and cast to int
		//TODO
		int score = 0;
		duration<float>count(end_timestamp - start_timestamp);
		score = (int)count.count();
		return score;
	}
	}
	// if for whatever reason none of the above return anything
	return -2;
}

int Board::get_state()
{
	return state;
}

int Board::get_field_state(int x, int y)
{
	Field element = grid[y][x];
	// field not visible  and doesn't have a flag - base color
	if (!element.get_visible() && !element.get_flag()) return 0;
	// field visible and has a flag - base color && flag symbol
	else if (!element.get_visible() && element.get_flag()) return 1;
	// field is visible and no mines around - empty color
	else if (element.get_visible() && !has_mine(x, y)) return 2;
	// mine - empty/boom color?? and bomb symbol
	else if (element.get_visible() && has_mine(x, y)) return 3;
	// mystery state
	return -1;
}

void Board::start_game()
{
	// game start timestamp and marker
	this->start_timestamp = Time::now();
	state = IN_PROGRESS;
}

void Board::reveal(int x, int y)
{

	if (!in_bounds(x, y)) return;
	if (grid[y][x].get_visible()) return;

	grid[y][x].set_visible();
	if (has_mine(x, y)) {
		uncover_mines();
		state = LOSS;
		// when the field is revealed, (potential!) end of the game time is recorded
		this->end_timestamp = Time::now();
	}
	// if the field is blank, reveal all fields around it
	if (count_mines(x, y) == 0)
	{
		reveal(x + 1, y);
		reveal(x + 1, y + 1);
		reveal(x + 1, y - 1);
		reveal(x, y + 1);
		reveal(x, y - 1);
		reveal(x - 1, y + 1);
		reveal(x - 1, y - 1);
		reveal(x - 1, y);
		
	}
}

void Board::toggle_flag(int x, int y)
{
	if (in_bounds(x, y))
	{
		grid[y][x].toggle_flag();
	}
}

void Board::uncover_mines()
{
	for (int e = 0; e < row_num; e++)
	{
		for (int i = 0; i < col_num; i++)
		{
			if (has_mine(i, e))
			{
				grid[e][i].set_visible();
			}
		}

	}
}
