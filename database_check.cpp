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

int check_smartcard(int id)
{
	return 0;
}


