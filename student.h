#pragma once
#include <string>
using namespace std;

class student
{
	int id;
	string name;
	int is_res;
public:
	student();
	student(int _id, string _name, int _is_res);
	int get_id();
	string get_name();
	int get_is_res();

	void add_student();
	void delete_student();
	void show_student();
	~student();
};

