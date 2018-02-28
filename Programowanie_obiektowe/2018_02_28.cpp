#include "Board.h"
#include "Field.h"
#include <iostream>
int main()
{
	Board brd =Board(20, 30);
	Board(20);
	Board();
	Field f = Field();
	std::cout << f.info() << "@" << brd.show_info_about_element(1, 2);
	return 0;
}