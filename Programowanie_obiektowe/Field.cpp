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
bool Field::set_visible()
{
	visible = true;
}
bool Field::get_flag()
{
	return flag;
}
bool Field::set_flag()
{
	flag = !flag;
}