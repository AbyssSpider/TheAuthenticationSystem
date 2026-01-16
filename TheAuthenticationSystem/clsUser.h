#pragma once

#include <iostream>
using namespace std;

class clsUser
{
private:
	string _UserName;
	string _UserPassword;
	short _PasswordCounter;
	bool _IsLocked;

public:
	clsUser();
	clsUser(string UserName, string UserPassword);
	clsUser(string UserName, string UserPassword, short PasswordCounter, bool IsLocked);

	// Make Set Attribute
	void _SetUserName(string UserName);
	void _SetUserPassword(string UserPassword);
	void _SetPasswordCounter(short PasswordCounter);
	void _SetIsLocked(bool IsLocked);

	// Make Get Attribute
	string _GetUserName();
	string _GetUserPassword();
	short _GetPasswordCounter();
	bool _GetIsLocked();




};
