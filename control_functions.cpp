#pragma once
#include "stdafx.h"
#include "admin.h"
#include "control_functions.h"
#include "database_functions.h"
#include "database_check.h"
#include <SQLAPI.h>
#include <ora7API.h>
#include <oraAPI.h>
using namespace std;

void menu()
{
	map <int, string> menu_options;
	
	// map menu options into numbers
	menu_options.insert(pair <int, string>(1, "Master Admin section"));
	menu_options.insert(pair <int, string>(2, "Regular Admin section"));
	menu_options.insert(pair <int, string>(3, "Exit program"));

	map <int, string> ::iterator itr;
	
	while (1)
	{
		// print the menu
		cout << "\t\t\tMENU\n\n";
		for (itr = menu_options.begin(); itr != menu_options.end(); itr++)
		{
			cout << "\t\t" << itr->first << "\t\t" << itr->second << "\n";
		}

		//ask for menu choice
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
			string pass = "";
			// a trailing '\n' remains after previous cin
			// newline will take that '\n'
			getline(cin, newline);
			cout << "Enter master user name: \n";
			getline(cin, name);

			// check if master name is valid
			if (name != "genesis")
			{
				system("cls");
				cout << "invalid user name\n\n";
				menu();
			}
			cout << "Enter master password: ";
			// hide typed characters
			char a;
			while (1) {
				a = _getch();
				if (a == 8) continue;
				if (a == 13) break;
				cout << "*";
				pass += a;
			}

			//call master function
			master(pass);
			break;
		}
		case 2:
		{
			system("cls");
			string name, newline;
			string pass = "";

			// a trailing '\n' remains after previous cin
			// newline will take that '\n'
			getline(cin, newline);

			cout << "Enter admin user name: ";
			getline(cin, name);

			// check if admin exists
			string check_pass = check_admin(name);
			if (check_pass == "hello")
			{
				cout << "You are logging in for the first time\nChange the password\n";
				while (1)
				{
					pass = "";
					cout << "\nEnter new password: ";
					char a;
					while (1) {
						a = _getch();
						if (a == 8) continue;
						if (a == 13) break;
						cout << "*";
						pass += a;
					}
					// confirm new password
					string temp_pass = "";
					cout << "\nConfirm pasword: ";
					while (1) {
						a = _getch();
						if (a == 8) continue;
						if (a == 13) break;
						cout << "*";
						temp_pass += a;
					}
					if (pass != temp_pass)
					{
						// again go back to ask password
						cout << "passwords do not match\nenter again....";
						continue; 
					}
					else // store the password 
					{
						store_pass(name, pass);
						break;
					}
				}
				// call admin function
				admin_func();
			}
			else
			{
				while (1)
				{
					pass = "";
					cout << "Enter admin password: ";
					char a;
					while (1) {
						a = _getch();
						if (a == 8) continue;
						if (a == 13) break;
						cout << "*";
						pass += a;
					}
					if (check_pass != pass)
					{
						cout << "incorrect password\n";
						continue;
					}
					else
					{
						break;
					}
				}
				// call admin function
				admin_func();			
			}
			break;
		}
		case 3:
		{
			system("cls");
			cout << "program terminated";
			exit(1);
		}
		default:
		{
			system("cls");
			cout << "invalid input\n";
		    break;
		}
		}
	}
	
}

// this function will have admin privileges and will create master admin object
// master admin can add or delete other admins and can perform other admin functions
void master(string passwd)
{
	// check for password validity
	if (passwd != "1569")
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

	
	while (1)
	{
		// print the menu
		cout << "\n\t\t\t|MASTER MENU|\n\n";
		for (itr = master_options.begin(); itr != master_options.end(); itr++)
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
			admin_func();
			break;
		}
		case 3:
		{
			system("cls");
			menu();
		}
		case 4:
		{
			cout << "program terminated\n";
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
// can see and review comments
// can manage food_menu
void admin_func()
{
	map <int, string> admin_options;

	// map menu options into numbers
	admin_options.insert(pair <int, string>(1, "Manage Students"));
	admin_options.insert(pair <int, string>(2, "Manage Food Menu"));
	admin_options.insert(pair <int, string>(3, "Manage Comments"));
	admin_options.insert(pair <int, string>(4, "Go Back to Main Menu"));
	admin_options.insert(pair <int, string>(5, "Exit program"));

	map <int, string> ::iterator itr;

	
	while (1)
	{
		// print the menu
		cout << "\n\t\t\t|Admin MENU|\n\n";
		for (itr = admin_options.begin(); itr != admin_options.end(); itr++)
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

		// review choice
		switch (choice)
		{
		case 1:
		{
			system("cls");
			manage_students();
			break;
		}
		case 2:
		{
			system("cls");
			manage_food();
			break;
		}
		case 3:
		{
			system("cls");
			manage_comments();
			break;
		}
		case 4:
		{
			system("cls");
			menu();
		}
		case 5:
		{
			cout << "program terminated\n";
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
