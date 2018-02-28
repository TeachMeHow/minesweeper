#include "Board.h"
#include <iostream>
#include <unordered_set>
#include <vector>
#include <random>
#include <algorithm>
using std::unordered_set;
using std::vector;
using std::for_each;

const size_t Board::DEFAULT_SIZE = 10;


Board::Board(size_t M, size_t N)
{
	row_count = M;
	col_count = N;
	
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

std::string Board::show_info_about_element(size_t row, size_t col)
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
		srand(0);
		while (generated_numbers.size() < n)
		{
			generated_numbers.insert(rand() % range);
		}
		for_each(generated_numbers.begin(), generated_numbers.end(), [&](int i)
		{
			row_indexes.push_back(i / col_count);
			col_indexes.push_back(i & col_count);
		}
		);
		/*
		while (it != generated_numbers.cend()) 
		{
			col_indexes.push_back(*it % col_count);
			row_indexes.push_back(*it / col_count);
			++it;
		}

		*/
		for_each(row_indexes.begin(), row_indexes.end(), [&](int i)
		{
			auto it = col_indexes.begin();
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
