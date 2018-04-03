#include "Board.h"
#include <iostream>
#include <unordered_set>
#include <vector>
#include <random>
#include <algorithm>
#include <time.h>
#include <string>
using std::unordered_set;
using std::vector;
using std::for_each;
using std::string;

const size_t Board::DEFAULT_SIZE = 10;

//TODO Wrong number of has_mines - bounds?
bool Board::in_bounds(int x, int y) const
{
	return 0 <= x && x < col_count &&
		0 <= y && y < row_count;
}

Board::Board(size_t M, size_t N)
{
	row_count = M;
	col_count = N;
	end_game = false;
	
	grid = new Field*[M];
	for (size_t i = 0; i < M; i++)
	{
		grid[i] = new Field[N];
	}
}


Board::~Board()
{

	for (size_t i = 0; i < row_count; i++)
	{
		delete[] grid[i];
	}
	delete[] grid;
	
}

void Board::deploy_mines(int n, bool random)
{
	if (random)
	{
		//generate MxN numbers, verify uniqueness, then col = num % col_count and row = num / col_count
		size_t range = row_count * col_count;
		unordered_set<int> generated_numbers;
		vector<int> row_indexes;
		vector<int> col_indexes;
		srand(time(NULL));
		while (generated_numbers.size() < n)
		{
			generated_numbers.insert(rand() % range);
		}
		for_each(generated_numbers.begin(), generated_numbers.end(), [&](int i)
		{
			row_indexes.push_back(i / col_count);
			col_indexes.push_back(i % col_count);
		}
		);
		auto it = col_indexes.begin();
		for_each(row_indexes.begin(), row_indexes.end(), [&](int i)
		{
			grid[i][*it].set_mine();
			it++;
		}
		);
		
	}
	else
	{
		for (size_t i = 0; i < col_count; i++)
		{
			grid[0][i].set_mine();
		}
		for (size_t i(1), j(1); row_count < col_count ? (i < row_count) : (j < col_count); i++, j++)
		{
			grid[i][j].set_mine();
		}
	}
}

bool Board::has_mine(int x, int y) const
{
	return in_bounds(x, y) ? grid[y][x].get_mine() : false;
}

int Board::count_mines(int x, int y) const
{
	int count = 0;
	/*Somebody Toucha My 
							   _          _   _   _ 
							  | |        | | | | (_)
		 ___ _ __   __ _  __ _| |__   ___| |_| |_ _ 
		/ __| '_ \ / _` |/ _` | '_ \ / _ \ __| __| |
		\__ \ |_) | (_| | (_| | | | |  __/ |_| |_| |
		|___/ .__/ \__,_|\__, |_| |_|\___|\__|\__|_|
			| |           __/ |                     
			|_|          |___/       
	*/
	if (has_mine(++x, ++y) && in_bounds(x, y)) count++;
	if (has_mine(x, --y) && in_bounds(x, y)) count++;
	if (has_mine(x, --y) && in_bounds(x, y)) count++;
	if (has_mine(--x, y) && in_bounds(x, y)) count++;
	if (has_mine(--x, y) && in_bounds(x, y)) count++;
	if (has_mine(x, ++y) && in_bounds(x, y)) count++;
	if (has_mine(x, ++y) && in_bounds(x, y)) count++;
	if (has_mine(++x, y) && in_bounds(x, y)) count++;
	return count;
}

void Board::display() const
{
	for (size_t i = 0; i < row_count; i++)
	{
		grid[5][i].set_visible();
	}
	for (size_t i = 0; i < col_count; i++)
	{
		grid[i][4].set_flag(true);
	}
	for (size_t e = 0; e < row_count; e++)
	{
		for (size_t i = 0; i < col_count; i++)
		{
			Field element = grid[e][i];
			std::string symbol;
			if (!element.get_visible() && !element.get_flag()) symbol = "[.]";
			else if (!element.get_visible() && element.get_flag()) symbol = "[?]";
			else if (element.get_visible() && count_mines(i,e) == 0
				&& !has_mine(i,e)) symbol = "[ ]";
			else if (element.get_visible() && !has_mine(i, e)) 
				symbol = '[' + std::to_string(count_mines(i, e)) + ']';
			else if (element.get_visible() && has_mine(i, e)) symbol = "[x]";

			std::cout << symbol;
		}
		std::cout << std::endl;
	}

}

void Board::display(sf::RenderWindow & win, sf::Font font, sf::Image* icons)
{
	win.clear(bg_color);
	// create vector from internal styling
	sf::Vector2f dimensions = sf::Vector2f(width, height);
	// draw each field
	// TODO to avoid creating fields and textures each time, maybe just
	// create them once and draw?
	for (size_t e = 0; e < row_count; e++)
	{
		for (size_t i = 0; i < col_count; i++)
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
			Field element = grid[e][i];
			// field not visible  and doesn't have a flag - base color
			if (!element.get_visible() && !element.get_flag()) rectangle.setFillColor(sf::Color::Blue);
			// field visible and has a flag - base color && flag symbol
			else if (!element.get_visible() && element.get_flag())
			{
				rectangle.setFillColor(sf::Color::Blue);
				texture.update(icons[2]);

				sprite.setTexture(texture);
				sprite.setPosition(pos);
				sprite.setScale(width / 100.0, height / 100.0);
			}
			// field is visible and no mines around - empty color
			else if (element.get_visible() && !has_mine(i, e))
			{
				rectangle.setFillColor(sf::Color::Magenta);
				text.setString(std::to_string(count_mines(i,e)));
				
				if (count_mines(i, e) == 0)
				{
					text.setString("");
				}
			}
			// mine - empty/boom color?? and bomb symbol
			else if (element.get_visible() && has_mine(i, e)) 
			{
				rectangle.setFillColor(sf::Color::White);

				texture.update(icons[1]);

				sprite.setTexture(texture);
				sprite.setPosition(pos);
				sprite.setScale(width / 100.0, height / 100.0);		
			}
			win.draw(rectangle);
			win.draw(text);
			win.draw(sprite);
		}
	}
	sf::Event event;
	win.pollEvent(event);
	

	win.display();

}

void Board::handle_mouse(sf::RenderWindow & win, sf::Event & event)
{
	if (event.type == sf::Event::MouseButtonPressed)
	{
		sf::Vector2i m_pos = sf::Mouse::getPosition(win);
		int i_x = m_pos.x / (width + padding);
		int i_y = m_pos.y / (height + padding);
		if (in_bounds(i_x, i_y))
		{
			float x_rel = m_pos.x - i_x * (width + padding);
			float y_rel = m_pos.y - i_y * (height + padding);
			if (0 <= (x_rel - padding) && (x_rel - padding) <= width && 0 <= (y_rel - padding) && (y_rel - padding) <= height)
			{
				if (event.mouseButton.button == sf::Mouse::Left)
				{
					reveal(i_x, i_y);
				}
				if (event.mouseButton.button == sf::Mouse::Right)
				{
					grid[i_y][i_x].toggle_flag();
				}
				
			}
		}
		
		
	}
}

void Board::style_game(unsigned int width, unsigned int height, unsigned int padding, sf::Color bg_color)
{
	this->width = width;
	this->height = height;
	this->padding = padding;
	this->bg_color = bg_color;
}

void Board::reveal(int x, int y)
{
	grid[y][x].set_visible();
	if (has_mine(x, y)) {
		end_game = true;
		uncover_mines();
	}
}

void Board::uncover_mines()
{
	for (size_t e = 0; e < row_count; e++)
	{
		for (size_t i = 0; i < col_count; i++)
		{
			if (has_mine(i, e))
			{
				grid[e][i].set_visible();
			}
		}

	}
}
