#include "stdafx.h"
#include "user.h"
#include <random>
using namespace std;

string generate_token(int res, int st_id)
{
	string id("TK"); // Holds the ID, starting with the characters "ID" followed
	id += to_string(st_id);					  // by a random integer in the range [0-10000].
	uniform_int_distribution<int> distribution(0, 10000);
	random_device rd;
	mt19937 engine(rd());
	id += to_string(distribution(engine));
	return id;
}

void comment()
{
}
