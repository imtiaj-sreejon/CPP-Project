#include "stdafx.h"
#include "food.h"
#include "database_check.h"
#include <iomanip>
#include <SQLAPI.h>
#include <ora7API.h>
#include <oraAPI.h>
using namespace std;

void add_food()
{
	// have to take day, meal_time and food items as input
	string day, meal_time, items, newline;
	cout << "Enter day of meal (seven days of week): ";
	cin >> day;
	cout << "Enter meal_time (breakfast, lunch or dinner): ";
	cin >> meal_time;

	getline(cin, newline);
	cout << "Enter food items: ";
	getline(cin, items);

	cout << "Adding item......\n";

	SAConnection con;
	try
	{
		// connect to database
		con.Connect(
			"XE",     // database name
			"cpp_proj",   // user name
			"test123",   // password
			SA_Oracle_Client);

		// create a command object
		SACommand cmd(&con, "insert into food_menu values(:1, :2, :3)");

		// bind input to sql command
		cmd.Param(1).setAsString() = day.c_str();
		cmd.Param(2).setAsString() = meal_time.c_str();// convert from c++ string to c_string
		cmd.Param(3).setAsString() = items.c_str();

		cmd.Execute();
		cout << "Menu added successfully\n";
		con.Commit();
		return;
	}
	catch (SAException &x)
	{
		// SAConnection::Rollback()
		try
		{
			// on error rollback changes
			cout << "rolling back.....";
			con.Rollback();
		}
		catch (SAException &)
		{
		}
		// print error message
		printf("%s\nInvalid input\n", (const char*)x.ErrText());
		return;
	}
}

void show_foods()
{

	SAConnection con;
	try
	{
		// connect to database
		con.Connect(
			"XE",     // database name
			"cpp_proj",   // user name
			"test123",   // password
			SA_Oracle_Client);
		SACommand cmd(&con);

		cmd.setCommandText("select * from food_menu"); // set command for selection
		cmd.Execute();

		// check if result exists
		bool isResult = cmd.isResultSet();
		if (!isResult)
		{
			cout << "No food item is Present!\n";
			return;
		}
		else
		{
			cout << "\tDAY\t\t" << "\tMEAL TIME\t\t" << "\tITEMS\n";
			cout << "--------------------\t" << "    " << "\t-----------------------" << "    " << "\t-----------------------------------\n";
			while (cmd.FetchNext())
			{
				cout << "\t" << setw(10)<< left << string(cmd[1].asString()) << setw(10) << left  << "\t" << string(cmd[2].asString()) << "\t\t" <<  setw(10) << left << string(cmd[3].asString()) << "\n";
			}
			cout << "\n";
		}
		con.Disconnect();
	}
	catch (SAException &x)
	{
		// SAConnection::Rollback()
		try
		{
			// on error rollback changes
			cout << "rolling back.....";
			con.Rollback();
		}
		catch (SAException &)
		{
		}
		// print error message
		printf("%s\n", (const char*)x.ErrText());
	}
}
