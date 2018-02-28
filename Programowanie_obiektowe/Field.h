#pragma once
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
	bool set_visible();

	bool get_flag();
	bool set_flag();

};

