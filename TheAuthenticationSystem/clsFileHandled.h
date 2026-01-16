#pragma once

#include <iostream>
#include <vector>
#include "clsUser.h"
using namespace std;

class clsFileHandled
{
protected:
	string _Encrypt(string Data);

	string _Decrypt(string Data);

	vector <string> _Split(string line, string Seperator);

	vector <string> _Join(vector <clsUser> DataFromVector, string Seperator);

	vector <clsUser> _AddDataToVector(string UserName, string UserPassword, short PasswordCounter, bool IsLocked);

	void _AddUserToFile(string FileName, string UserName, string UserPassword, short PasswordCounter, bool IsLocked);

	void _SaveUserAccount(string FileName, vector <clsUser> &DataFromFile);
	
	clsUser _UpdateUser(vector <string> &DataFromFile);

	vector <clsUser> _DataFromFile(string FileName);

};

