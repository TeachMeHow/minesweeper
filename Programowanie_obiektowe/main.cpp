
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
	game.deploy_mines(1, true);
	GameManager gm(game);
	gm.start_game();

	return EXIT_SUCCESS;
}
