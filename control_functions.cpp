#include "stdafx.h"
#include "admin.h"
#include "control_functions.h"
#include "database_functions.h"
using namespace std;

void menu()
{
	map <int, string> menu_options;
	
	// map menu options into numbers
	menu_options.insert(pair <int, string>(1, "Master Admin section"));
	menu_options.insert(pair <int, string>(2, "Regular Admin section"));
	menu_options.insert(pair <int, string>(3, "Exit program"));

	map <int, string> ::iterator itr;

	// print the menu
	cout << "\t\t\tMENU\n\n";
	for (itr = menu_options.begin(); itr != menu_options.end(); itr++)
	{
		cout << "\t\t" << itr->first << "\t\t" << itr->second << "\n";
	}

	//ask for menu choice
	while (1)
	{
		string temp;
		cout << "Enter option number: ";
		cin >> temp;
		int num;
		
		if (temp.size() == 1 && temp[0] >= '0' && temp[0] < '9')
			num = temp[0] - '0';
		else
			num = 15;

		// review choice
		switch (num)
		{
		case 1:
		{
			system("cls");
			string newline, name;
			string pass;
			// a trailing '\n' remains after previous cin
			// newline will take that '\n'
			getline(cin, newline);
			cout << "Enter master user name: \n";
			getline(cin, name);
			cout << "Enter master password: ";
			cin >> pass;

			//call master function
			master(name, pass);
			break;
		}
		case 2:
		{
			system("cls");
			string name;
			string pass;
			cout << "Enter admin user name: ";
			getline(cin, name);
			cout << "Enter admin password: ";
			cin >> pass;

			// call admin function
			admin_func(name, pass);
			break;
		}
		case 3:
		{
			system("cls");
			cout << "program terminated";
			exit(1);
		}
		default:
		{	cout << "invalid input\n";
		    break;
		}
		}
	}
	
}

// this function will have admin privileges and will create master admin object
// master admin can add or delete other admins and can perform other admin functions
void master(string name, string passwd)
{
	if (name != "genesis")
	{
		system("cls");
		cout << "invalid user name\n\n";
		menu();
		return;
	}
	else if (passwd != "1569")
	{
		system("cls");
		cout << "invalid password\n\n";
		menu();
		return;
	}
	system("cls");
	cout << "You're logged in\n";

	map <int, string> master_options;

	// map menu options into numbers
	master_options.insert(pair <int, string>(1, "Manage Admins"));
	master_options.insert(pair <int, string>(2, "Regular Admin functions"));
	master_options.insert(pair <int, string>(3, "Go Back to Main Menu"));
	master_options.insert(pair <int, string>(4, "Exit program"));

	map <int, string> ::iterator itr;

	// print the menu
	cout << "\n\t\t\tMASTER MENU\n\n";
	for (itr = master_options.begin(); itr != master_options.end(); itr++)
	{
		cout << "\t\t" << itr->first << "\t\t" << itr->second << "\n";
	}

	//ask for menu choice
	//string choice;
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
		
		// review choice
		switch (choice)
		{
		case 1:
		{
			system("cls");
			manage_admins();
			break;
		}
		case 2:
		{
			system("cls");
			admin_func("genesis", "1569");
			break;
		}
		case 3:
		{
			system("cls");
			menu();
		}
		case 4:
		{
			system("cls");
			cout << "program terminated";
			exit(1);
		}
		default:
		{	
			cout << "invalid input\n";
		break;
		}
		}
	}
}

// can add or delete student
// can see and review complaints
// can manage food_menu
void admin_func(string name, string passwd)
{
}
