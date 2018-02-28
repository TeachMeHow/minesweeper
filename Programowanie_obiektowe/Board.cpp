#include "Board.h"
#include <iostream>


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
}
