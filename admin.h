#pragma once
#include <string>
using namespace std;

class admin
{
	int emp_id;
	string name;
public:
	admin();
	admin(int _id, string _name);
	int get_id();
	string get_name();
	void add_admin();
	void delete_addmin();
	~admin();
};

