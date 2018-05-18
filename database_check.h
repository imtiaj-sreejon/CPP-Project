#pragma once
#include "stdafx.h"
using namespace std;

string check_admin(string name); // returns password if admin exists
void store_pass(string name, string pass); // store password in database
int cut_cost(int id, int total_cost);
int curr_balance(int id);
int check_student(int id);
int check_res(int id);