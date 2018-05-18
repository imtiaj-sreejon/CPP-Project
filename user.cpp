#include "stdafx.h"
#include "user.h"
#include "database_check.h"
#include <random>
using namespace std;

#define BREAKFAST 35
#define LUNCH 60

int get_order(int res, int st_id)
{
	if (!res) // for non-res
	{
		int total_cost = 0;
		cout << "You are a non-residential student\nDo you want to buy food?('1' for yes and '0' for no): ";
		while (1)
		{
			int choice;
			cin >> choice;
			if (!choice)
				return 0;
			else if (choice == 1)
				break;
			else
				cout << "invalid input\n";
		}
		
		int smartcard;
		cout << "Enter your smartcard id: ";
		cin >> smartcard;
		int valid = check_smartcard(st_id, smartcard);
		if (!valid)
		{
			return 0;
		}
		map <int, string> day_options;

		// map menu options into numbers
		day_options.insert(pair <int, string>(1, "Saturday"));
		day_options.insert(pair <int, string>(2, "Sunday"));
		day_options.insert(pair <int, string>(3, "Monday"));
		day_options.insert(pair <int, string>(4, "Tuesday"));
		day_options.insert(pair <int, string>(5, "Wednesday"));
		day_options.insert(pair <int, string>(6, "Thirsday"));
		day_options.insert(pair <int, string>(7, "Friday"));
		day_options.insert(pair <int, string>(8, "Complete buying"));

		map <int, string> ::iterator itr;

		while (1)
		{
			// print the menu
			cout << "\n\t\t\t|Select day|\n\n";
			for (itr = day_options.begin(); itr != day_options.end(); itr++)
			{
				cout << "\t\t" << itr->first << "\t\t" << itr->second << "\n";
			}

			//ask for menu choice
			string temp;
			cout << "Enter option number: ";
			cin >> temp;
			int choice;
			if (temp[0] >= '0' && temp[0] < '9')
				choice = temp[0] - '0';
			else
				choice = 15;

			switch (choice)
			{
			case 1:
			case 2:
			{
				cout << "Sorry you are not allowed to buy meal on this day\nCome back in the week days\n";
				break;
			}
			case 3:
			case 4:
			case 5:
			case 6:
			case 7:
			{
				while (1)
				{
					string meal_time;
					cout << "Which meal you want to buy?(breakfast/ lunch)?";
					cin >> meal_time;
					if (meal_time == "breakfast")
					{
						total_cost += BREAKFAST;
					}
					else if (meal_time == "lunch")
					{
						total_cost += LUNCH;
					}
				}
				break;
			}
			case 8:
			{
				cout << "Your total cost is: Tk" << total_cost << "\n";
				int curr_bal = cut_cost(st_id, total_cost);
				cout << "Now your current balance is: Tk" << curr_bal << "\n";
				cout << "Thanks for your co-operation. Have a great day\n";
				return 1;
			}
			default:
			{
				cout << "invalid input\n";
				break;
			}
			}
		}
	}
	else
	{
		cout << "You are a residential student\n";
		return 1;
	}
}

string generate_token(int st_id)
{
	cout << "Generating token........\n";
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
