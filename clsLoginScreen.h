#pragma one
#include <iostream>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <string>
#include "clsScreen.h"
#include "clsMainScreen.h"


using namespace std;

class clsLoginScreen : public clsScreen
{

    static bool _login()
    {
        string UserName;
        string PassWord;
        int tr = 3;
        bool FaildTry = false;

        do
        {
            if (FaildTry)
            {
                tr--;
                cout << "\n\nInvalid PassWord/UserName !\n";
                cout << "you have " << tr << " Triels to again\n" <<endl;
            }
            if(!tr)
            {
                cout << "\nyou are Locked after 3 faild tarials\n\n";
                return (true);
            }
            cout << "Please Enter User Name ?\n";
            cin >> UserName;
            cout << "Please Enter Passe Word ?\n";
            cin >> PassWord;

            CurrentUser = clsUser::Find(UserName,PassWord);

            FaildTry = CurrentUser.IsEmpty();

        } while (FaildTry);
        CurrentUser.RegisterLogIn();
        clsMainMenueScreen::_ShowMainMenue(); 
        
        return (false);       
    }

public:

    static bool ShowLogin()
    {
        system("\t\tclear");
        _DrawScreenHeader("     Login");
        return (_login());
    }
};