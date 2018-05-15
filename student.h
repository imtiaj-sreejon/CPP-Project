#pragma once
#include <string>
using namespace std;

class student
{
	int id;
	string name;
	int is_res;
	int credit_card;
public:
	student();
	student(int _id, string _name, int _is_res, int _credit_card);
	int get_id();
	string get_name();
	int get_is_res();
	int get_credit_card();
	~student();
};

