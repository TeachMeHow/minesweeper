// Autor: Szymon Cichy 235093
// Data: 11.04.2018


#include <SFML/Graphics.hpp>

#include "Board.h"
#include "GameManager.h"
#include "Intro.h"
#include <stdlib.h>
#include <iostream>
#include <vector>


int main()
{
	// Intro window before starting the game
	Intro intro = Intro();
	auto params = intro.display();
	if (params[3] == 1)
	{
		Board game = Board(params[0], params[1]);
		game.deploy_mines(params[2], true);
		GameManager gm(game);
		gm.display();
	}

	return EXIT_SUCCESS;
}
