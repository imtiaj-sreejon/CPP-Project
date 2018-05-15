#include "stdafx.h"
#include "student.h"




student::student()
{
	id = 0;
	name = "";
	is_res = 0;
	credit_card = 0;
}

student::student(int _id, string _name, int _is_res, int _credit_card)
{
	id = _id;
	name = _name;
	is_res = _is_res;
	credit_card = _credit_card;
}

int student::get_id()
{
	return id;
}

string student::get_name()
{
	return name;
}

int student::get_is_res()
{
	return is_res;
}

int student::get_credit_card()
{
	return credit_card;
}

student::~student()
{
}
