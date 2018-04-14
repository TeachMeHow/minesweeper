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
	window.clear(sf::Color(76, 155, 211, 255));
	sf::Text author;
	author.setString("Szymon Cichy 235093 Sroda 15");
	author.setFont(font);
	author.setCharacterSize(20);
	author.setPosition(10, 400 - 10 - 20);
	window.draw(author);
	sf::Text title;
	title.setString("Minesweeper");
	title.setFont(font);
	title.setCharacterSize(50);
	float title_width = title.getLocalBounds().width;
	title.setPosition((400 - title_width) / 2, 15);
	window.draw(title);

	// x,y position relative to the window
	sf::Vector2f grid_pos = sf::Vector2f(15,100);
	// x - horizontal, y - vertical space between buttons
	sf::Vector2f grid_spacing = sf::Vector2f(10,10);
	// size of difficulty and size buttons
	sf::Vector2f btn_size = sf::Vector2f(60,30);
	// color of inactive button
	sf::Color btn_inactive = sf::Color(255,255,255,255);
	// color of active button
	sf::Color btn_active = sf::Color(6, 42, 68, 255);
	sf::RectangleShape btn;
	btn.setSize(btn_size);
	btn.setFillColor(btn_inactive);
	sf::Text btn_text;
	btn_text.setFillColor(sf::Color(0, 0, 0, 255));
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
	window.draw(btn);
	window.draw(btn_text);
	// grid 0,1
	btn_text.setString("12x12");
	btn_text.setPosition(grid_pos + sf::Vector2f(grid_spacing.x * (1 + 1) + btn_size.x * 1, grid_spacing.y * (1 + 0) + btn_size.y * 0));
	btn.setPosition(grid_pos + sf::Vector2f(grid_spacing.x * (1 + 1) + btn_size.x * 1, grid_spacing.y * (1 + 0) + btn_size.y * 0));
	window.draw(btn);
	window.draw(btn_text);
	// grid 0,2
	btn_text.setString("16x16");
	btn_text.setPosition(grid_pos + sf::Vector2f(grid_spacing.x * (1 + 2) + btn_size.x * 2, grid_spacing.y * (1 + 0) + btn_size.y * 0));
	btn.setPosition(grid_pos + sf::Vector2f(grid_spacing.x * (1 + 2) + btn_size.x * 2, grid_spacing.y * (1 + 0) + btn_size.y * 0));
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
	window.draw(btn);
	window.draw(btn_text);
	// grid 1,1
	btn_text.setString("Medium");
	btn_text.setPosition(grid_pos + sf::Vector2f(grid_spacing.x * (1 + 1) + btn_size.x * 1, grid_spacing.y * (2 + 1) + btn_size.y * 1 + char_size));
	btn.setPosition(grid_pos + sf::Vector2f(grid_spacing.x * (1 + 1) + btn_size.x * 1, grid_spacing.y * (2 + 1) + btn_size.y * 1 + char_size));
	window.draw(btn);
	window.draw(btn_text);
	// grid 1,2
	btn_text.setString("Hard");
	btn_text.setPosition(grid_pos + sf::Vector2f(grid_spacing.x * (1 + 2) + btn_size.x * 2, grid_spacing.y * (2 + 1) + btn_size.y * 1 + char_size));
	btn.setPosition(grid_pos + sf::Vector2f(grid_spacing.x * (1 + 2) + btn_size.x * 2, grid_spacing.y * (2 + 1) + btn_size.y * 1 + char_size));
	window.draw(btn);
	window.draw(btn_text);



	sf::CircleShape start_btn;
	start_btn.setRadius(50);
	btn_text.setCharacterSize(30);
	btn_text.setString("START");
	start_btn.setFillColor(sf::Color(255, 176, 81, 255));
	start_btn.setOutlineColor(sf::Color(106, 61, 2, 255));
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
	params[2] = 6;
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


	// field size times bomb percentage
	int easy_diff = params[0] * params[1] * 0.10;
	int medium_diff = params[0] * params[1] * 0.15;
	int hard_diff = params[0] * params[1] * 0.20;
	return params;

}
