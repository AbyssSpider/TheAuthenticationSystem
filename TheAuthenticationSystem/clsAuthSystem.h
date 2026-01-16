#pragma once

#include <iostream>
#include "clsUser.h"
#include "clsFileHandled.h"
#include <vector>
using namespace std;

class clsAuthSystem : clsFileHandled
{
private:
    
    void _PrintLogInScreen();

    void _PrintSignUpScreen();

    void _UpdateDataInFile(vector <clsUser> &DataUserFromFile, clsUser &UpdateUser, string &UserName, string &UserPassword, short& TotalCounter);

    // I Choose the number 3 for Protecting from brute force attacks
    void _TheUserIsLocked(vector <clsUser> &DataUserFromFile, clsUser &UpdateUser, short& TotalCounter);

    bool _CheckUserAccount(vector <clsUser> &DataUserFromFile, string &UserName);

    bool _CheckPassword(vector <clsUser> &DataUserFromFile, string &UserName, string &UserPassword);

    bool _CheckAccountIsLocked(vector <clsUser> &DataUserFromFile, string &UserName);

    short _TotalPasswordCounter(short PasswordCounter);

    string _EnterUserName();

    string _EnterUserPassword();
    
public:

    void _SignUp();

    void _LogIn();
};

