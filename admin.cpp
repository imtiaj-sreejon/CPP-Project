#include "stdafx.h"
#include "admin.h"
#include <SQLAPI.h>
#include <ora7API.h>
#include <oraAPI.h>

admin::admin()
{
	emp_id = 0;
	name = "";
}

admin::admin(int _id, string _name)
{
	emp_id = _id;
	name = _name;
}

int admin::get_id()
{
	return emp_id;
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

		printf("connected!\n");

		// create a command object
		SACommand cmd(&con, "insert into admin(id, name) values(:1, :2)");

		// bind input to sql command
		cmd.Param(1).setAsLong() = emp_id;
		cmd.Param(2).setAsString() = name.c_str(); // convert from c++ string to c_string
		
		cmd.Execute();
		cout << "admin '" << name << "' successfully added\n";
		con.Commit(); // commit on success

		// Disconnect is optional
		// autodisconnect will ocur in destructor if needed
		con.Disconnect();
		printf("We are disconnected!\n");
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
	int del_id;
	cout << "Enter id of admin to delete: ";
	cin >> del_id;

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

		// check if id to be deleted exists
		int x;
		cmd.setCommandText("check_admin"); // prototype: check_admin(id in number, x out varchar2)
		cmd.Param("input_id").setAsLong() = del_id; // pass parameters
		
		cmd.Execute();

		// get the return value of the check procedure
		string admin_name = string(cmd.Param("x").asString());

		if (admin_name == "not found")
		{
			cout << "invalid id\n";
		}	
		else // delete the admin
		{
			cmd.setCommandText("delete from admin where id=:1");
			cmd.Param(1).setAsLong() = del_id;
			cmd.Execute();
			cout << "Admin '" << admin_name << "' deleted successfully";
			con.Commit();
		}
		con.Disconnect();
		printf("We are disconnected!\n");
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
