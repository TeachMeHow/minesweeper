// Autor: Szymon Cichy 235093
// Data: 11.04.2018

#include "GameManager.h"
#include <iostream>
#include <string>
#include "ScoreBoard.h"
#include "Intro.h"

using namespace std::chrono;



GameManager::GameManager(Board & brd) : board(brd)
{
}

GameManager::~GameManager()
{
}

void GameManager::draw(sf::RenderWindow & win, sf::Font font, sf::Image* icons)
{
	win.clear(dim_blue);
	// create vector from internal styling
	sf::Vector2f dimensions = sf::Vector2f(width, height);
	// draw each field
	// TODO to avoid creating fields and textures each time, maybe just
	// create them once and draw?
	for (int e = 0; e < board.get_row_num(); e++)
	{
		for (int i = 0; i < board.get_col_num(); i++)
		{
			// calculate the position of the field
			float x, y;
			x = i * padding + padding + i * dimensions.x;
			y = e * padding + padding + e * dimensions.y;
			sf::Vector2f pos(x, y);
			// create a rectangle representing a field
			sf::RectangleShape rectangle = sf::RectangleShape(dimensions);
			rectangle.setPosition(pos);

			sf::Text text;
			sf::Sprite sprite;
			// WARNING texture MUST be the same size as icons used - in my case it's 100x100 png files
			sf::Texture texture;
			texture.create(100, 100);

			// set character size to be the same as either width or height, whichever is smaller
			// style the 
			text.setCharacterSize(width < height ? width : height);
			//set text to empty and style it
			text.setString("");
			text.setFont(font);
			text.setFillColor(sf::Color::Black);
			text.setPosition(pos);



			// styling the field
			// get field corresponding to the rectangle being drawn, get properties and assign according colors
			
			switch (board.get_field_state(i, e))
			{
			case 0:
				rectangle.setFillColor(light_blue);
				break;
			case 1:
				rectangle.setFillColor(light_blue);
				texture.update(icons[2]);

				sprite.setTexture(texture);
				sprite.setPosition(pos);
				sprite.setScale(width / 100.0, height / 100.0);
				break;
			case 2:
				rectangle.setFillColor(light_orange);
				text.setString(std::to_string(board.count_mines(i, e)));

				if (board.count_mines(i, e) == 0)
				{
					text.setString("");
				}
				break;
			case 3:
				rectangle.setFillColor(light_yellow);

				texture.update(icons[1]);

				sprite.setTexture(texture);
				sprite.setPosition(pos);
				sprite.setScale(width / 100.0, height / 100.0);
				break;
			}
			win.draw(rectangle);
			win.draw(text);
			win.draw(sprite);
		}
	}
	if (board.get_state() == 0)
	{
		sf::Event event;
		win.pollEvent(event);
		if (event.type == sf::Event::MouseButtonPressed)
		{
			sf::Vector2i m_pos = sf::Mouse::getPosition(win);
			int i_x = m_pos.x / (width + padding);
			int i_y = m_pos.y / (height + padding);
			if (board.in_bounds(i_x, i_y))
			{
				float x_rel = (float)m_pos.x - i_x * (width + padding);
				float y_rel = (float)m_pos.y - i_y * (height + padding);
				if (0 <= (x_rel - padding) && (x_rel - padding) <= width && 0 <= (y_rel - padding) && (y_rel - padding) <= height)
				{
					if (event.mouseButton.button == sf::Mouse::Left)
					{
						// game ends on last reveal
						board.reveal(i_x, i_y);
					}
					if (event.mouseButton.button == sf::Mouse::Right)
					{
						board.toggle_flag(i_x, i_y);
					}

				}
			}
		}
	}

	win.display();

}
void GameManager::display()
{
	// TODO score starts with creation of the window and ends with bomb
	// create a window, set properties and loop for a responsive gui
	int win_width = board.get_col_num() * (width + padding) + padding;
	int win_height = board.get_row_num() * (height + padding) + padding;
	sf::RenderWindow window(sf::VideoMode(win_width, win_height), "Saper");
	window.setFramerateLimit(60);
	// Load resources
	sf::Font font;
	// icons[0] - explosion icon
	// icons[1] - bomb icon
	// icons[2] - flag icon
	sf::Image* icons = new sf::Image[3];
	if (!icons[0].loadFromFile("boom.png"))
	{
		std::cerr << "Failed to open boom.png \n";
	}
	if (!icons[1].loadFromFile("bomb.png"))
	{
		std::cerr << "Failed to open bomb.png \n";
	}
	if (!icons[2].loadFromFile("flag.png"))
	{
		std::cerr << "Failed to open flag.png \n";
	}
	if (!font.loadFromFile("font.ttf"))
	{
		std::cerr << "Failed to load font \n";
	}
	board.start_game();
	//	// if game doesn't continue, new window with icore appears
	//}
	while (board.get_state() == 0)
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}

		}
		//// game state has to be checked before every draw
		//board.check_state();
		draw(window, font, icons);
	}
	draw(window, font, icons);
	ScoreBoard scb(board);
	scb.display();
	window.close();
	delete[] icons;
}


