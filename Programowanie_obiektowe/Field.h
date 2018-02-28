#pragma once

#include <string>
class Field
{
	bool mine;
	bool visible;
	bool flag;
	//true if contains mine
	bool get_mine();
	void set_mine();

public:
	Field();
	~Field();
	//true if is uncovered
	bool get_visible();
	//true if has been flagged
	void set_visible();

	bool get_flag();
	void set_flag(bool val);
	bool toggle_flag();
	
	//returns [mine, visible, flag] in str form
	std::string info();

};

