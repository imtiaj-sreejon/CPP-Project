#include "stdafx.h"
#include "student.h"
#include <SQLAPI.h>
#include <ora7API.h>
#include <oraAPI.h>

student::student()
{
	id = 0;
	name = "";
	is_res = 0;
}

student::student(int _id, string _name, int _is_res)
{
	id = _id;
	name = _name;
	is_res = _is_res;
}

int student::get_id()
{
	return id;
}

string student::get_name()
{
	return name;
}

int student::get_is_res()
{
	return is_res;
}

// adds student
void student::add_student()
{
	SAConnection con;

	cout << "adding student.......\n";
	try
	{
		// connect to database
		con.Connect(
			"XE",     // database name
			"cpp_proj",   // user name
			"test123",   // password
			SA_Oracle_Client);

		// create a command object
		SACommand cmd(&con, "insert into student values(:1, :2, :3)");

		// bind input to sql command
		cmd.Param(1).setAsLong() = id;
		cmd.Param(2).setAsString() = name.c_str();// convert from c++ string to c_string
		cmd.Param(3).setAsLong() = is_res;

		cmd.Execute();
		cout << "student '" << name << "' successfully added\n";
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

void student::delete_student()
{
}

void student::show_student()
{
}

student::~student()
{
}
