#include "Board.h"
#include "Field.h"
#include <iostream>
#include <unordered_set>
int main()
{
	Board brd =Board(20, 30);
	Board(20);
	Board();
	Field f = Field();
	std::unordered_set<int> my_set;
	my_set.insert(1);
	my_set.insert(2);
	my_set.insert(1);
	auto it = my_set.begin();
	while (it != my_set.end())
	{
		std::cout << *it;
		it++;
	}
	std::cout << f.info() << "@" << brd.show_info_about_element(1, 2);
	return 0;
}