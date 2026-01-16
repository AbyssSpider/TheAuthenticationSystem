#include <iostream>
#include "clsUser.h"
using namespace std;

clsUser::clsUser()
{

}

clsUser::clsUser(string UserName, string UserPassword)
{
	_UserName = UserName;
	_UserPassword = UserPassword;
	_PasswordCounter = 0;
	_IsLocked = false;
}

clsUser::clsUser(string UserName, string UserPassword, short PasswordCounter, bool IsLocked)
{
	_UserName = UserName;
	_UserPassword = UserPassword;
	_PasswordCounter = PasswordCounter;
	_IsLocked = IsLocked;
}

void clsUser::_SetUserName(string UserName)
{
	_UserName = UserName;
}

void clsUser::_SetUserPassword(string UserPassword)
{
	_UserPassword = UserPassword;
}

void clsUser::_SetPasswordCounter(short PasswordCounter)
{
	_PasswordCounter = PasswordCounter;
}

void clsUser::_SetIsLocked(bool IsLocked)
{
	_IsLocked = IsLocked;
}

string clsUser::_GetUserName()
{
	return _UserName;
}

string clsUser::_GetUserPassword()
{
	return _UserPassword;
}

short clsUser::_GetPasswordCounter()
{
	return _PasswordCounter;
}

bool clsUser::_GetIsLocked()
{
	return _IsLocked;
}
