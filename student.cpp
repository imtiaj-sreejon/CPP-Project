#include "stdafx.h"
#include "student.h"
#include "database_check.h"
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
	int del_id;
	cout << "Enter id of student to delete: ";
	cin >> del_id;

	int present = check_student(del_id); // check if student with given id is present
	if (present)
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
			cmd.setCommandText("delete from student where id=:1");
			cmd.Param(1).setAsLong() = del_id;
			cmd.Execute();
			cout << "Student id '" << del_id << "' deleted successfully\n";
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

void student::show_student()
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

		cmd.setCommandText("select * from student"); // set command for selection
		cmd.Execute();

		// check if result exists
		bool isResult = cmd.isResultSet();
		if (!isResult)
		{
			cout << "No Student is Present!\n";
			return;
		}
		else
		{
			cout << "\tID\t\t" << "\tNAME\t\t" << "\tIS_RES\n";
			cout << "---------------\t" << "    " << "\t----------------" << "    " << "\t----------------\n";
			while (cmd.FetchNext())
			{
				cout << "\t" << cmd[1].asLong() << "\t\t\t" << string(cmd[2].asString()) << "\t\t\t" << cmd[3].asLong() << "\n";
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

student::~student()
{
}
