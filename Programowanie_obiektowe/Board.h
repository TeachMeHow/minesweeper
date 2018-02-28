#pragma once
#include "Field.h"
class Board
{
	Field* grid;
	static const size_t DEFAULT_VALUE;

public:
	Board() : Board(DEFAULT_VALUE, DEFAULT_VALUE) { };
	//Square board MxM
	Board(size_t M) : Board(M, M) { };
	//Rectangular board MxN
	Board(size_t M, size_t N);
	~Board();
};

