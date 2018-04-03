#pragma once
#include <string>
#include <SFML/Graphics.hpp>
class Field
{
	bool mine;
	bool visible;
	bool flag;

public:
	Field();
	~Field();
	bool get_visible() const;
	void set_visible();
	bool get_mine() const;
	void set_mine();
	bool get_flag() const;
	// set_flag changes to element specified, toggle sets flag to boolean opposite of current
	void set_flag(bool val);
	bool toggle_flag();
	//returns [mine, visible, flag] in str form
	std::string info();

};

