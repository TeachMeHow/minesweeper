#pragma once
#include <string>
#include <SFML/Graphics.hpp>
class Field
{
	bool mine;
	bool visible;
	bool flag;
	//true if contains mine
	//position inside a window
	
	// width x height
	
	
	

public:
	Field();
	~Field();
	//true if is uncovered
	bool get_visible() const;
	//true if has been flagged
	void set_visible();
	bool get_mine() const;
	void set_mine();
	bool get_flag() const;
	void set_flag(bool val);
	bool toggle_flag();

	
	//returns [mine, visible, flag] in str form
	std::string info();

};

