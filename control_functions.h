#pragma once
#include "stdafx.h"
using namespace std;

void menu();
void master(string name, string passwd);
string check_admin(string name);
void admin_func(string name, string passwd); // will perform admin functions
