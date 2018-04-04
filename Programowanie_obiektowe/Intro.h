#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
class Intro
{
public:
	Intro();
	~Intro();
	void draw(sf::RenderWindow & window, sf::Font font);
	void display();
};

