#include "Field.h"



Field::Field()
{
	mine = false;
	visible = false;
	flag = false;
}


Field::~Field()
{
}

bool Field::get_mine()
{
	return mine;
}
void Field::set_mine()
{
	mine = true;
}


bool Field::get_visible()
{
	return visible;
}
void Field::set_visible()
{
	visible = true;
}
bool Field::get_flag()
{
	return flag;
}

void Field::set_flag(bool val)
{
	flag = val;
}
bool Field::toggle_flag()
{
	set_flag(!this->get_flag());
	return this->get_flag();
}

std::string Field::info()
{
	std::string buffer;
	buffer += (this->get_mine() ? "1" : "0");
	buffer += (this->get_visible() ? "1" : "0");
	buffer += (this->get_flag() ? "1" : "0");
	return buffer;
}
