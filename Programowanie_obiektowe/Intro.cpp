// Autor: Szymon Cichy 235093
// Data: 11.04.2018

#include "Intro.h"

Intro::Intro()
{
}


Intro::~Intro()
{
}

void Intro::draw(sf::RenderWindow & window, sf::Font font)
{
	window.clear(light_blue);
	// author footnote
	sf::Text author;
	author.setString("Szymon Cichy 235093 Sroda 15");
	author.setFont(font);
	author.setCharacterSize(20);
	// window height - spacing - characte size (up)
	author.setPosition(10, window_height - 10 - 20);
	window.draw(author);
	// big title
	sf::Text title;
	title.setString("Minesweeper");
	title.setFont(font);
	title.setCharacterSize(50);
	float title_width = title.getLocalBounds().width;
	// middle of the screen
	title.setPosition((window_width - title_width) / 2, 15);
	window.draw(title);

	// color of inactive button
	sf::Color btn_inactive = white;
	// color of active button
	sf::Color btn_active = dark_blue;
	sf::RectangleShape btn;
	btn.setSize(btn_size);
	btn.setFillColor(btn_inactive);
	sf::Text btn_text;
	btn_text.setFillColor(black);
	btn_text.setFont(font);
	int char_size = 20;
	btn_text.setCharacterSize(char_size);
	// Row 1 title
	btn_text.setString("Board size");
	btn_text.setPosition(grid_pos + sf::Vector2f(grid_spacing.x * (1 + 0) + btn_size.x * 0, grid_spacing.y * (0 + 0) - char_size));
	window.draw(btn_text);
	// grid 0,0
	btn_text.setString("8x8");
	btn_text.setPosition(grid_pos + sf::Vector2f(grid_spacing.x * (1 + 0) + btn_size.x * 0, grid_spacing.y * (1 + 0) + btn_size.y * 0));
	btn.setPosition(grid_pos + sf::Vector2f(grid_spacing.x * (1 + 0) + btn_size.x * 0, grid_spacing.y * (1 + 0) + btn_size.y * 0));
	btn.setFillColor(btn_inactive);
	if (row_1_active_button == 0) btn.setFillColor(btn_active);
	window.draw(btn);
	window.draw(btn_text);
	// grid 0,1
	btn_text.setString("12x12");
	btn_text.setPosition(grid_pos + sf::Vector2f(grid_spacing.x * (1 + 1) + btn_size.x * 1, grid_spacing.y * (1 + 0) + btn_size.y * 0));
	btn.setPosition(grid_pos + sf::Vector2f(grid_spacing.x * (1 + 1) + btn_size.x * 1, grid_spacing.y * (1 + 0) + btn_size.y * 0));
	btn.setFillColor(btn_inactive);
	if (row_1_active_button == 1) btn.setFillColor(btn_active);
	window.draw(btn);
	window.draw(btn_text);
	// grid 0,2
	btn_text.setString("16x16");
	btn_text.setPosition(grid_pos + sf::Vector2f(grid_spacing.x * (1 + 2) + btn_size.x * 2, grid_spacing.y * (1 + 0) + btn_size.y * 0));
	btn.setPosition(grid_pos + sf::Vector2f(grid_spacing.x * (1 + 2) + btn_size.x * 2, grid_spacing.y * (1 + 0) + btn_size.y * 0));
	btn.setFillColor(btn_inactive);
	if (row_1_active_button == 2) btn.setFillColor(btn_active);
	window.draw(btn);
	window.draw(btn_text);
	// Second row title
	btn_text.setString("Difficulty");
	btn_text.setPosition(grid_pos + sf::Vector2f(grid_spacing.x * (1 + 0) + btn_size.x * 0, grid_spacing.y * (1 + 1) + btn_size.y * 1));
	window.draw(btn_text);
	// grid 1,0
	btn_text.setString("Easy");
	btn_text.setPosition(grid_pos + sf::Vector2f(grid_spacing.x * (1 + 0) + btn_size.x * 0, grid_spacing.y * (2 + 1) + btn_size.y * 1 + char_size));
	btn.setPosition(grid_pos + sf::Vector2f(grid_spacing.x * (1 + 0) + btn_size.x * 0, grid_spacing.y * (2 + 1) + btn_size.y * 1 + char_size));
	btn.setFillColor(btn_inactive);
	if (row_2_active_button == 0) btn.setFillColor(btn_active);
	window.draw(btn);
	window.draw(btn_text);
	// grid 1,1
	btn_text.setString("Medium");
	btn_text.setPosition(grid_pos + sf::Vector2f(grid_spacing.x * (1 + 1) + btn_size.x * 1, grid_spacing.y * (2 + 1) + btn_size.y * 1 + char_size));
	btn.setPosition(grid_pos + sf::Vector2f(grid_spacing.x * (1 + 1) + btn_size.x * 1, grid_spacing.y * (2 + 1) + btn_size.y * 1 + char_size));
	btn.setFillColor(btn_inactive);
	if (row_2_active_button == 1) btn.setFillColor(btn_active);
	window.draw(btn);
	window.draw(btn_text);
	// grid 1,2
	btn_text.setString("Hard");
	btn_text.setPosition(grid_pos + sf::Vector2f(grid_spacing.x * (1 + 2) + btn_size.x * 2, grid_spacing.y * (2 + 1) + btn_size.y * 1 + char_size));
	btn.setPosition(grid_pos + sf::Vector2f(grid_spacing.x * (1 + 2) + btn_size.x * 2, grid_spacing.y * (2 + 1) + btn_size.y * 1 + char_size));
	btn.setFillColor(btn_inactive);
	if (row_2_active_button == 2) btn.setFillColor(btn_active);
	window.draw(btn);
	window.draw(btn_text);



	sf::CircleShape start_btn;
	start_btn.setRadius(50);
	btn_text.setCharacterSize(30);
	btn_text.setString("START");
	start_btn.setFillColor(light_orange);
	start_btn.setOutlineColor(dark_orange);
	start_btn.setOutlineThickness(3);
	start_btn.setPosition(sf::Vector2f(20, 250));
	btn_text.setPosition(sf::Vector2f(20 + 20, 250 + 50 - 20));
	window.draw(start_btn);
	window.draw(btn_text);


	window.display();
}



std::vector<int> Intro::display()
{
	int small_size = 8;
	int medium_size = 12;
	int large_size = 16;
	// set default parameters
	std::vector<int> params(4);
	params[0] = params[1] = small_size;
	params[2] = params[0] * params[1] * 0.1; //6
	params[3] = 0;
	// load font
	sf::Font font;
	if (!font.loadFromFile("font.ttf"))
	{
		std::cerr << "Failed to load font \n";
	}
	// activate antialiasing and create window
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	sf::RenderWindow window(sf::VideoMode(400, 400), "Introduction", sf::Style::Default, settings);
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
			if (event.type = sf::Event::MouseButtonPressed)
			{
				if (event.mouseButton.button == sf::Mouse::Left)
				{
					handle_mouse(sf::Vector2f(sf::Mouse::getPosition(window)));
				}
			}
		}
		draw(window, font);
	}

	// if active button values are unexpected default values are assumed
	switch (row_1_active_button)
	{
	case 0: params[0] = params[1] = small_size;
		break;
	case 1: params[0] = params[1] = medium_size;
		break;
	case 2: params[0] = params[1] = large_size;
		break;
	default: std::cerr << "Unexpected size choice";
		break;
	}

	// field size times bomb percentage
	int easy_diff = params[0] * params[1] * 0.10;
	int medium_diff = params[0] * params[1] * 0.15;
	int hard_diff = params[0] * params[1] * 0.20;
	switch (row_2_active_button)
	{
	case 0: params[2] = easy_diff;
		break;
	case 1: params[2] = medium_diff;
		break;
	case 2: params[2] = hard_diff;
		break;
	default: std::cerr << "Unexpected difficulty choice";
		break;
	}

	return params;

}

void Intro::handle_mouse(sf::Vector2f m_pos)
{
	// mouse position logic
}
