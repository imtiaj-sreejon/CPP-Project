#include "stdafx.h"
#include "database_check.h"
#include <SQLAPI.h>
#include <ora7API.h>
#include <oraAPI.h>
using namespace std;

string check_admin(string name)
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

		// check if admin exists and return password
		// prototype: check_admin(ad_name in varchar2, passwd out varchar2)
		cmd.setCommandText("check_admin");
		cmd.Param("ad_name").setAsString() = name.c_str(); // pass parameters

		cmd.Execute();

		// get the pass from the check procedure if admin exists
		// procedure will return "not found" if admin doesn't exist
		string pass = string(cmd.Param("passwd").asString());

		if (pass == "not found")
		{
			cout << "admin doesn't exist\n";
			con.Disconnect(); // disconnect before return
			return pass;
		}
		else
		{
			con.Disconnect();
			return pass;
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
		return 0;
	}
}

void store_pass(string name, string pass)
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

		cmd.setCommandText("update admin set passwd=:1 where name=:2");
		cmd.Param(1).setAsString() = pass.c_str();
		cmd.Param(2).setAsString() = name.c_str();

		cmd.Execute();
		cout << "\npassword changed successfully\n";
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
}

// cut the spent money from smart card balance
int cut_cost(int id, int total_cost)
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

		cmd.setCommandText("update smartcard_info set balance=:1 where id=:2");
		int curr_bal = curr_balance(id);
		cmd.Param(1).setAsLong() = curr_bal - total_cost;
		cmd.Param(2).setAsLong() = id;

		cmd.Execute();
		con.Commit();
		return curr_bal;
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
		return 0;
	}
}

// get the current balance
int curr_balance(int id)
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

		cmd.setCommandText("select balance from smartcard_info where id=:1");
		cmd.Param(1).setAsLong() = id;

		int balance = cmd.Param("balance").asLong();
		return balance;
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


int check_student(int id)
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

		// check if admin exists and return password
		// prototype: check_admin(ad_name in varchar2, passwd out varchar2)
		cmd.setCommandText("check_student");
		cmd.Param("input_id").setAsLong() = id; // pass parameters

		cmd.Execute();

		// get the pass from the check procedure if admin exists
		// procedure will return "not found" if admin doesn't exist
		int present = cmd.Param("chk").asLong();

		if (present == 0)
		{
			cout << "student with id " << id << " doesn't exist\n";
			con.Disconnect(); // disconnect before return
			return present;
		}
		else
		{
			con.Disconnect();
			return present;
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
		return 0;
	}
}

int check_res(int id)
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

		// check if admin exists and return password
		// prototype: check_admin(ad_name in varchar2, passwd out varchar2)
		cmd.setCommandText("check_res");
		cmd.Param("input_id").setAsLong() = id; // pass parameters

		cmd.Execute();

		// get the pass from the check procedure if admin exists
		// procedure will return "not found" if admin doesn't exist
		int present = cmd.Param("chk").asLong();

		if (present == 0)
		{
			cout << "student with id " << id << " doesn't exist\n";
			con.Disconnect(); // disconnect before return
			return present;
		}
		else
		{
			con.Disconnect();
			return present;
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
		con.Disconnect();
		return 0;
	}
}


