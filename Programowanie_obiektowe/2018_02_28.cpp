#include "Board.h"
#include "Field.h"
#include <iostream>
#include <unordered_set>
int main()
{
	Board brd = Board(8, 8);
	Board(20);
	Board();


	brd.deploy_mines(12, true);
	brd.debug_display();
	return 0;
}