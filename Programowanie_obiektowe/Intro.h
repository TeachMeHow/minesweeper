// Autor: Szymon Cichy 235093
// Data: 11.04.2018

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

