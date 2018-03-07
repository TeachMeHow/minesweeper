#include "Board.h"
#include <iostream>
#include <unordered_set>
#include <vector>
#include <random>
#include <algorithm>
#include <time.h>
using std::unordered_set;
using std::vector;
using std::for_each;

const size_t Board::DEFAULT_SIZE = 10;

//TODO Wrong number of has_mines - bounds?
bool Board::in_bounds(int x, int y) const
{
	return (0 <= x < col_count) &&
		(0 <= y < row_count);
}

Board::Board(size_t M, size_t N)
{
	row_count = M;
	col_count = N;
	end_game = false;
	
	grid = new Field*[M];
	for (size_t i = 0; i < M; i++)
	{
		grid[i] = new Field[N];
	}
}


Board::~Board()
{

	for (size_t i = 0; i < row_count; i++)
	{
		delete[] grid[i];
	}
	delete[] grid;
	
}

std::string Board::show_info_about_element(size_t row, size_t col) const
	{
		return grid[row][col].info();
	}

void Board::deploy_mines(int n, bool random)
{
	if (random)
	{
		//generate MxN numbers, verify uniqueness, then col = num % col_count and row = num / col_count
		size_t range = row_count * col_count;
		unordered_set<int> generated_numbers;
		vector<int> row_indexes;
		vector<int> col_indexes;
		srand(time(NULL));
		while (generated_numbers.size() < n)
		{
			generated_numbers.insert(rand() % range);
		}
		for_each(generated_numbers.begin(), generated_numbers.end(), [&](int i)
		{
			row_indexes.push_back(i / col_count);
			col_indexes.push_back(i % col_count);
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
		for (size_t i = 0; i < col_count; i++)
		{
			grid[0][i].set_mine();
		}
		for (size_t i(1), j(1); row_count < col_count ? (i < row_count) : (j < col_count); i++, j++)
		{
			grid[i][j].set_mine();
		}
	}
}

void Board::debug_display() const
{
	for (size_t e = 0; e < row_count; e++)
	{
		for (size_t i = 0; i < col_count; i++)
		{
			std::cout << show_info_about_element(e, i) << " ";
		}
		std::cout << std::endl;
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

void Board::display() const
{
	for (size_t i = 0; i < row_count; i++)
	{
		grid[5][i].set_visible();
	}
	for (size_t i = 0; i < col_count; i++)
	{
		grid[i][4].set_flag(true);
	}
	for (size_t e = 0; e < row_count; e++)
	{
		for (size_t i = 0; i < col_count; i++)
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

void Board::reveal(int x, int y)
{
	grid[y][x].set_visible();
	if (has_mine(x, y)) {
		end_game = true;
		uncover_mines();
	}
}

void Board::uncover_mines()
{
	for (size_t e = 0; e < row_count; e++)
	{
		for (size_t i = 0; i < col_count; i++)
		{
			if (has_mine(i, e))
			{
				reveal(i, e);
			}
		}

	}
}
