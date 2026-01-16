
#include <iostream>
#include "clsMainMenu.h"
#include "clsAuthSystem.h"
using namespace std;

void clsMainMenu::PrintMainScreen()
{
    cout << "\t\t\t\t===================================================\n";
    cout << "\t\t\t\t\tThe Guard Authentication System\n";
    cout << "\t\t\t\t===================================================\n";
    cout << "\t\t\t\t[1] Sign Up\n";
    cout << "\t\t\t\t[2] Log in\n";
    cout << "\t\t\t\t[3] Exit\n";
    cout << "\t\t\t\t===================================================\n";

    _IntendedChoice();
}

short clsMainMenu::_ChoiceNumber()
{
    short Number;

    do
    {
        cout << "\t\t\t\tChoose What Do You Want? [1 to 3] ";
        cin >> Number;

        if (Number < 1 || Number > 3)
        {
            cout << "\t\t\t\tInvalid Choice, You Should Choose from List\n\n";
        }

    } while (Number < 1 || Number > 3);

    return Number;
}

void clsMainMenu::_BackToMainScreen()
{
    cout << "\n\t\t\t\tPress any enter to go to Main Screen ..." << endl;
    system("pause>0");
    system("cls");
    PrintMainScreen();
}

void clsMainMenu::_IntendedChoice()
{
    short ChoiceNumber = _ChoiceNumber();

    switch ((enChoice)ChoiceNumber)
    {
    case (enChoice::SignUp):
        system("cls");
        _SignUp();
        _BackToMainScreen();
        break;

    case (enChoice::LogIn):
        system("cls");
        _LogIn();
        _BackToMainScreen();
        break;

    case (enChoice::Exit):
        cout << "\n\t\t\t\tThank You For Using Our System" << endl;
        break;
    }
}
