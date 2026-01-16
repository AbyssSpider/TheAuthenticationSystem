#pragma once

#include <iostream>
#include "clsAuthSystem.h"
using namespace std;

class clsMainMenu : clsAuthSystem
{
private:
    enum enChoice { SignUp = 1, LogIn = 2, Exit = 3 };

    short _ChoiceNumber();
    void _BackToMainScreen();
    void _IntendedChoice();

public:
    void PrintMainScreen();
};

