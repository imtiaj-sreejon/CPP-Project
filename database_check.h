#pragma once
#include "stdafx.h"
using namespace std;

string check_admin(string name); // returns password if admin exists
void store_pass(string name, string pass); // store password in database
int check_smartcard(int id);