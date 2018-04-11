// Autor: Szymon Cichy 235093
// Data: 11.04.2018


#include <SFML/Graphics.hpp>

#include "Board.h"
#include "GameManager.h"
#include <stdlib.h>
#include <iostream>


int main()
{
	// number of rows and columns
	unsigned int col_num = 10;
	unsigned int row_num = 10;
	Board game = Board(row_num, col_num);
	game.deploy_mines(10, true);
	GameManager gm(game);
	gm.display();

	return EXIT_SUCCESS;
}
