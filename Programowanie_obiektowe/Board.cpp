#include "Board.h"


const size_t Board::DEFAULT_VALUE = 10;


Board::Board(size_t M, size_t N)
{
	row_count = N;
	col_count = M;
	grid = new Field**[M];
	for (size_t i = 0; i < N; i++)
	{
		grid[i] = new Field*[N];
	}
	for (size_t e = 0; e < M; e++)
	{
		for (size_t i = 0; i < N; i++)
		{
			//TODO random mine insertion?
			grid[N][M] = &Field();
		}
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
