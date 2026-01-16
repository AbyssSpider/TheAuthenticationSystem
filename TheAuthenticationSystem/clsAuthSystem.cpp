#include <iostream>
#include "clsUser.h"
#include "clsAuthSystem.h"
#include "clsFileHandled.h"
#include <string>
#include <vector>
using namespace std;

void clsAuthSystem::_LogIn()
{
    _PrintLogInScreen();
    short TotalCounter = 0;

    string EnterUserName = _EnterUserName();

    do
    {
        string EnterUserPassword = _EnterUserPassword();

        vector <clsUser> DataFromFile = _DataFromFile("UserAccounts.txt");
        bool CheckUserAccount = _CheckUserAccount(DataFromFile, EnterUserName);
        clsUser UpdateUser(EnterUserName, EnterUserPassword);

        if (!CheckUserAccount)
        {
            cout << "\n\t\t\t\tUser Or Password is not correct." << endl;
            EnterUserName = _EnterUserName();
        }

        if (CheckUserAccount)
        {
            if (_CheckAccountIsLocked(DataFromFile, EnterUserName))
            {
                cout << "\n\t\t\t\tYou Can't Log In This Account Because It becomes Locked." << endl;
                break;
            }

            if (_CheckPassword(DataFromFile, EnterUserName, EnterUserPassword))
            {
                cout << "\n\t\t\t\tWelcome [" << EnterUserName << "] \n";
                break;
            }

            if (!_CheckPassword(DataFromFile, EnterUserName, EnterUserPassword))
            {
                _UpdateDataInFile(DataFromFile, UpdateUser, EnterUserName, EnterUserPassword, TotalCounter);
                _TheUserIsLocked(DataFromFile, UpdateUser, TotalCounter);
            }
        }
    } while (TotalCounter != 3);
}

void clsAuthSystem::_PrintLogInScreen()
{
    cout << "\n\t\t\t\t=============================================\n";
    cout << "\t\t\t\t\t\tLog In Page\n";
    cout << "\t\t\t\t=============================================\n";
}

void clsAuthSystem::_SignUp()
{
    _PrintSignUpScreen();
    vector <clsUser> DataFromFile;
    string EnterUserName;
    string EnterUserPassword;
    do
    {
        EnterUserName = _EnterUserName();
        EnterUserPassword = _EnterUserPassword();
        clsUser NewUser(EnterUserName, EnterUserPassword);

        DataFromFile = _DataFromFile("UserAccounts.txt");

        if (!_CheckUserAccount(DataFromFile, EnterUserName))
        {
            _AddUserToFile("UserAccounts.txt", NewUser._GetUserName(), NewUser._GetUserPassword(),
                NewUser._GetPasswordCounter(), NewUser._GetIsLocked());

            cout << "\n\t\t\t\tIt Creates Your Account Successfully" << endl;
            break;
        }

        if (_CheckUserAccount(DataFromFile, EnterUserName))
        {
            cout << "\n\t\t\t\tThis Account Is already exist, Please Try to enter again.\n" << endl;
        }

    } while (_CheckUserAccount(DataFromFile, EnterUserName));
}

void clsAuthSystem::_PrintSignUpScreen()
{
    cout << "\n\t\t\t\t=============================================\n";
    cout << "\t\t\t\t\t\tSign Up Page\n";
    cout << "\t\t\t\t=============================================\n";
}

void clsAuthSystem::_UpdateDataInFile(vector <clsUser> &DataUserFromFile, clsUser &UpdateUser, string &UserName, string &UserPassword, short& TotalCounter)
{
    for (int i = 0; i < DataUserFromFile.size(); i++)
    {
        if (UpdateUser._GetUserName() == DataUserFromFile[i]._GetUserName())
        {
            TotalCounter = _TotalPasswordCounter(DataUserFromFile[i]._GetPasswordCounter());
            UpdateUser._SetPasswordCounter(TotalCounter);
            cout << "\n\t\t\t\tYour Password Is Wrong.";
            cout << "\n\t\t\t\tThe rest of Tries are [" << UpdateUser._GetPasswordCounter() << "].\n\n";

            DataUserFromFile[i]._SetPasswordCounter(UpdateUser._GetPasswordCounter());
            break;
        }
    }
    _SaveUserAccount("UserAccounts.txt", DataUserFromFile);
}

void clsAuthSystem::_TheUserIsLocked(vector <clsUser> &DataUserFromFile, clsUser &UpdateUser, short& TotalCounter)
{
    if (TotalCounter == 3)
    {
        cout << "\t\t\t\tYour Account Is Locked." << endl;
        UpdateUser._SetIsLocked(true);

        for (int i = 0; i < DataUserFromFile.size(); i++)
        {
            if (UpdateUser._GetUserName() == DataUserFromFile[i]._GetUserName())
            {
                clsUser UpdateUser(DataUserFromFile[i]._GetUserName(), DataUserFromFile[i]._GetUserPassword(), TotalCounter, 1);
                DataUserFromFile[i]._SetPasswordCounter(UpdateUser._GetPasswordCounter());
                DataUserFromFile[i]._SetIsLocked(UpdateUser._GetIsLocked());
                break;
            }
        }
        _SaveUserAccount("UserAccounts.txt", DataUserFromFile);
    }
}

bool clsAuthSystem::_CheckUserAccount(vector <clsUser> &DataUserFromFile, string &UserName)
{
    for (int i = 0; i < DataUserFromFile.size(); i++)
    {
        if (UserName == DataUserFromFile[i]._GetUserName())
        {
            return true;
        }
    }
    return false;
}

bool clsAuthSystem::_CheckPassword(vector <clsUser> &DataUserFromFile, string &UserName, string &UserPassword)
{
    for (int i = 0; i < DataUserFromFile.size(); i++)
    {
        if (UserName == DataUserFromFile[i]._GetUserName())
        {
            if (UserPassword == DataUserFromFile[i]._GetUserPassword())
            {
                return true;
            }
            return false;
        }
    }
}

bool clsAuthSystem::_CheckAccountIsLocked(vector <clsUser> &DataUserFromFile, string &UserName)
{
    for (int i = 0; i < DataUserFromFile.size(); i++)
    {
        if (UserName == DataUserFromFile[i]._GetUserName())
        {
            if (DataUserFromFile[i]._GetIsLocked())
            {
                return true;
            }
            return false;
        }
    }
}

short clsAuthSystem::_TotalPasswordCounter(short PasswordCounter)
{
    if (PasswordCounter < 3)
    {
        PasswordCounter++;
    }

    return PasswordCounter;
}

string clsAuthSystem::_EnterUserName()
{
    string Name;

    cout << "\t\t\t\tEnter your Name, Please? ";
    getline(cin >> ws, Name);

    return Name;
}

string clsAuthSystem::_EnterUserPassword()

{
    string Password;

    do
    {
        cout << "\t\t\t\tEnter your Password, Please? ";
        cin >> Password;

        if (Password.length() <= 7)
        {
            cout << "\n\t\t\t\tYour Password Should be 7 character\n";
        }

    } while (Password.length() <= 7);

    return Password;
}




