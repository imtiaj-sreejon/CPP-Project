#pragma once
#include "stdafx.h"
#include "database_functions.h"
#include "admin.h"
#include "control_functions.h"
#include "food.h"
using namespace std;

void manage_admins()
{
	map <int, string> madmin_options;

	// map menu options into numbers
	madmin_options.insert(pair <int, string>(1, "Add Admins"));
	madmin_options.insert(pair <int, string>(2, "Delete Admins"));
	madmin_options.insert(pair <int, string>(3, "Show All Admins"));
	madmin_options.insert(pair <int, string>(4, "Go Back to Main Menu"));

	map <int, string> ::iterator itr;

	while (1)
	{
		// print the menu
		cout << "\t\t\t|ADMIN MANAGE MENU|\n\n";
		for (itr = madmin_options.begin(); itr != madmin_options.end(); itr++)
		{
			cout << "\t\t" << itr->first << "\t\t" << itr->second << "\n";
		}

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
			break;
		}
		case 2: // delete admin
		{
			admin ob;
			ob.delete_addmin();		
			break;
		}
		case 3: // show admin
		{
			admin ob;
			ob.show_admin();		
			break;
		}
		case 4:
			menu();
			break;
		default:
		{
			cout << "invalid input\n";
			break;
		}
		}
	}

	
}

void manage_students()
{
	map <int, string> mstd_options;

	// map menu options into numbers
	mstd_options.insert(pair <int, string>(1, "Add Student Info"));
	mstd_options.insert(pair <int, string>(2, "Delete Student"));
	mstd_options.insert(pair <int, string>(3, "Show Student Info"));
	mstd_options.insert(pair <int, string>(4, "Go Back to Main Menu"));

	map <int, string> ::iterator itr;

	while (1)
	{
		// print the menu
		cout << "\t\t\t|STUDENT MANAGE MENU|\n\n";
		for (itr = mstd_options.begin(); itr != mstd_options.end(); itr++)
		{
			cout << "\t\t" << itr->first << "\t\t" << itr->second << "\n";
		}

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
		case 1:
		{
			break;
		}
		case 2:
		{
			break;
		}
		case 3:
		{
			break;
		}
		case 4:
		{
			break;
		}
		default:
		{
			cout << "invalid input\n";
			break;
		}	
		}
	}
}

void manage_food()
{
	map <int, string> food_options;

	// map menu options into numbers
	food_options.insert(pair <int, string>(1, "Add or Replace Item"));
	food_options.insert(pair <int, string>(2, "Show Food menu"));
	food_options.insert(pair <int, string>(3, "Go Back to Main Menu"));

	map <int, string> ::iterator itr;
	
	while (1)
	{
		// print the menu
		cout << "\t\t\t|FOOD MANAGE MENU|\n\n";
		for (itr = food_options.begin(); itr != food_options.end(); itr++)
		{
			cout << "\t\t" << itr->first << "\t\t" << itr->second << "\n";
		}

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
		case 1:
		{
			add_food();
			break;
		}
		case 2:
		{
			break;
		}
		case 3:
		{
			break;
		}
		default:
			cout << "invalid input\n";
			break;
		}
	}
}

void manage_comments()
{
}
