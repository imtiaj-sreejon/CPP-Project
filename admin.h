#pragma once
#include <string>
using namespace std;

class admin
{
	int admin_id;
	string name;
	string passwd;
public:
	admin();
	admin(int _id, string _name);
	int get_id();
	string get_name();

	// managing functions
	void add_admin();
	void delete_addmin();
	void show_admin();
	~admin();
};

