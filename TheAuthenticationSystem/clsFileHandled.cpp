#include <iostream>
#include "clsUser.h"
#include "clsFileHandled.h"
#include <fstream>
#include <vector>
#include <string>
using namespace std;

string clsFileHandled::_Encrypt(string Data)
{
    string EncryptData;
    short i = 0;
    EncryptData.clear();
    for (i = 0; i < Data.length(); i++)
    {
        Data[i] = char(Data[i] + 2);
        EncryptData = Data;
    }
    return EncryptData;
}

string clsFileHandled::_Decrypt(string Data)
{
    string DecryptData;
    DecryptData.clear();
    for (short i = 0; i < Data.length(); i++)
    {
        Data[i] = char(Data[i] - 2);
        DecryptData += Data[i];
    }
    return DecryptData;
}

vector <string> clsFileHandled::_Split(string line, string Seperator = "#")
{
    short Position = 0;
    string Word = "";
    vector <string> Data;

    while ((Position = line.find(Seperator)) != std::string::npos)
    {
        Word = line.substr(0, Position);
        if (Word != "")
        {
            Data.push_back(Word);
        }
        line.erase(0, Position + Seperator.length());
    }
    if (line != "")
    {
        Data.push_back(line);
    }

    return Data;
}

vector <string> clsFileHandled::_Join(vector <clsUser> DataFromVector, string Seperator = "#")
{
    vector <string> TotalData;

    for (short i = 0; i < DataFromVector.size(); i++)
    {
        string UserData = "";

        UserData += DataFromVector[i]._GetUserName();
        UserData += Seperator;
        UserData += DataFromVector[i]._GetUserPassword();
        UserData += Seperator;
        UserData += to_string(DataFromVector[i]._GetPasswordCounter());
        UserData += Seperator;
        UserData += to_string(DataFromVector[i]._GetIsLocked());

        TotalData.push_back(UserData);
    }

    return TotalData;
}

vector <clsUser> clsFileHandled::_AddDataToVector(string UserName, string UserPassword, short PasswordCounter, bool IsLocked)
{
    vector <string> AddOneUserToFile;
    vector <clsUser> NewUser;

    AddOneUserToFile.push_back(UserName);
    AddOneUserToFile.push_back(UserPassword);
    AddOneUserToFile.push_back(to_string(PasswordCounter));
    AddOneUserToFile.push_back(to_string(IsLocked));

    NewUser.push_back(_UpdateUser(AddOneUserToFile));

    return NewUser;
}

void clsFileHandled::_AddUserToFile(string FileName, string UserName, string UserPassword, short PasswordCounter, bool IsLocked)
{
    fstream MyFile;
    string line;

    vector <string> JoinData = _Join(_AddDataToVector(UserName, UserPassword, PasswordCounter, IsLocked));

    MyFile.open(FileName, ios::in | ios::app);

    if (MyFile.is_open())
    {
        for (string& C : JoinData)
        {
            MyFile << _Encrypt(C) << endl;
        }
        MyFile.close();
    }
}

void clsFileHandled::_SaveUserAccount(string FileName, vector <clsUser> &DataFromFile)
{
    fstream MyFile;
    string line;

    vector <string> JoinData = _Join(DataFromFile);

    MyFile.open(FileName, ios::in | ios::out);

    if (MyFile.is_open())
    {
        for (string& C : JoinData)
        {
            MyFile << _Encrypt(C) << endl;
        }

        MyFile.close();
    }
}

clsUser clsFileHandled::_UpdateUser(vector <string> &DataFromFile)
{
    clsUser User;

    User._SetUserName(DataFromFile[0]);
    User._SetUserPassword(DataFromFile[1]);
    User._SetPasswordCounter(stoi(DataFromFile[2]));
    User._SetIsLocked(stoi(DataFromFile[3]));

    return User;
}

vector <clsUser> clsFileHandled::_DataFromFile(string FileName)
{
    fstream MyFile;
    string line;
    vector <clsUser> DataUserFromFile;

    MyFile.open(FileName, ios::in);

    if (MyFile.is_open())
    {
        while (getline(MyFile, line))
        {
            vector <string> SplitString = _Split(_Decrypt(line));
            DataUserFromFile.push_back(_UpdateUser(SplitString));
        }
        MyFile.close();
    }
    return DataUserFromFile;
}
