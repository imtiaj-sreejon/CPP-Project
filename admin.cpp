#pragma once
#include "stdafx.h"
#include "admin.h"
#include "control_functions.h"
#include <SQLAPI.h>
#include <ora7API.h>
#include <oraAPI.h>

admin::admin()
{
	admin_id = 0;
	name = "";
	passwd = "";
}

admin::admin(int _id, string _name)
{
	admin_id = _id;
	name = _name;
	passwd == "";
}

int admin::get_id()
{
	return admin_id;
}

string admin::get_name()
{
	return name;
}

// adds admin
void admin::add_admin()
{
	SAConnection con; // create connection object
	
	cout << "adding admin.......\n";
	try
	{
		// connect to database
		con.Connect(
			"XE",     // database name
			"cpp_proj",   // user name
			"test123",   // password
			SA_Oracle_Client);

		cout << "connected!\n";

		// create a command object
		SACommand cmd(&con, "insert into admin(id, name) values(:1, :2)");

		// bind input to sql command
		cmd.Param(1).setAsLong() = admin_id;
		cmd.Param(2).setAsString() = name.c_str();// convert from c++ string to c_string
		cmd.Param(3).setAsNull();
		
		cmd.Execute();
		cout << "admin '" << name << "' successfully added\n";
		cout << "Default password is: 'hello'\n" << "It has to be changed when logging in for first time\n";
		con.Commit(); // commit on success

		// Disconnect is optional
		// autodisconnect will ocur in destructor if needed
		con.Disconnect();
		cout << "We are disconnected!\n";
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

// deletes admin
void admin::delete_addmin()
{
	string del_name;
	cout << "Enter name of admin to delete: ";
	cin >> del_name;
	
	string pass = check_admin(del_name);
	if (!(pass == "not found"))
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

			// delete admin
			cmd.setCommandText("delete from admin where name=:1");
			cmd.Param(1).setAsString() = del_name.c_str();
			cmd.Execute();
			cout << "Admin '" << del_name << "' deleted successfully";
			con.Commit();
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
		con.Disconnect();
	}
	
	
}

void admin::show_admin()
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

		cmd.setCommandText("select * from admin"); // set command for selection
		cmd.Execute();

		// check if result exists
		bool isResult = cmd.isResultSet();
		if (!isResult)
		{
			cout << "No Admin exists\n";
			return;
		}
		else
		{
			cout << "\tID\t\t" << "\tNAME\n";
			cout << "---------------\t" << "    " << "\t----------------\n";
			while (cmd.FetchNext())
			{
				cout <<"\t" << cmd[1].asLong() << "\t\t\t" << string(cmd[2].asString()) << "\n";
			}
			cout << "\n";
		}
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

admin::~admin()
{
}
