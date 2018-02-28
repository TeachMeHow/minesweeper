#pragma once
#include "Field.h"
class Board
{
	Field** grid;
	static const size_t DEFAULT_SIZE;
	size_t row_count;
	size_t col_count;
public:
	Board() : Board(DEFAULT_SIZE, DEFAULT_SIZE) { };
	//Square board MxM
	Board(size_t M) : Board(M, M) { };
	//Rectangular board MxN
	Board(size_t M, size_t N);
	~Board();
	std::string show_info_about_element(size_t row, size_t col);
	void deploy_mines(int n, bool random);
};

