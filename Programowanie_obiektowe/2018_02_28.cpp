#include "Board.h"
#include "Field.h"
#include <iostream>
#include <unordered_set>
int main()
{
	Board brd = Board(8, 8);
	Board(20);
	Board();


	brd.deploy_mines(12, false);
	brd.debug_display();
	brd.display();
	std::cout << brd.count_mines(2,1);
	return 0;
}