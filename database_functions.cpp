#include "stdafx.h"
#include "database_functions.h"
#include "admin.h"
#include "control_functions.h"
using namespace std;

void manage_admins()
{
	map <int, string> madmin_options;

	// map menu options into numbers
	madmin_options.insert(pair <int, string>(1, "Add Admins"));
	madmin_options.insert(pair <int, string>(2, "Delete Admins"));
	madmin_options.insert(pair <int, string>(3, "Show Admins"));
	madmin_options.insert(pair <int, string>(4, "Go Back to Main Menu"));

	map <int, string> ::iterator itr;

	// print the menu
	print_menu:
	cout << "\t\t\tMENU\n\n";
	for (itr = madmin_options.begin(); itr != madmin_options.end(); itr++)
	{
		cout << "\t\t" << itr->first << "\t\t" << itr->second << "\n";
	}


	string command;
	while (1)
	{
		string temp;
		cout << "Enter option number: ";
		cin >> temp;
		int choice;
		if (temp[0] >= '0' && temp[0] < '9')
			choice = temp[0] - '0';
		else
			choice = 15;
		system("cls");
		switch (choice)
		{
		case 1: // add admin
		{
			int id;
			string newline, name;
			cout << "Enter ID of admin: ";
			cin >> id;
			getline(cin, newline);
			cout << "Enter name of admin: ";
			getline(cin, name);
			system("cls");
			// create admin object
			admin ob(id, name);
			ob.add_admin();
			goto print_menu;
			break;
		}
		case 2: // delete admin
		{
			admin ob;
			ob.delete_addmin();
			goto print_menu;
			break;
		}
		case 3: // show admin
		{
			admin ob;
			ob.show_admin();
			goto print_menu;
			break;
		}
		case 4:
			menu();
			break;
		default:
			cout << "invalid input\n";
			break;
		}
	}

	
}

void manage_students()
{
}

void manage_food()
{
}

void manage_complaints()
{
}
