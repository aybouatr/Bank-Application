#pragma one
#include <iostream>
#include "clsScreen.h"

using namespace std;

class clsFindUserScreen : public clsScreen
{

    static void _PrintUser(clsUser User)
    {
        cout << "\nUser Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << User.Name();
        cout << "\nLastName    : " << User.LastName();
        cout << "\nFull Name   : " << User.FullName();
        cout << "\nEmail       : " << User.Email();
        cout << "\nPhone       : " << User.Phone();
        cout << "\nUser Name   : " << User.UserName();
        cout << "\nPassword    : " << User.PassWorde();
        cout << "\nPermissions : " << User.Permissions();
        cout << "\n___________________\n";

    }

public:

    static void ShowFindUserScreen()
    {
        
        _DrawScreenHeader("Find User Screen");

        cout << "Please Enter User Name \n";
        string UserName = clsInputValidate::ReadString();

        while (clsUser::IsUserExict(UserName))
        {
            cout << "Please Enter a nother one it's Not exict !\n";
            UserName = clsInputValidate::ReadString();
        }

        clsUser User = clsUser::Find(UserName);
        if (!User.IsEmpty())
        {
            cout << "\n\tFound User :\n";
            cout << "_--------------------_\n";
            _PrintUser(User);
        }
        else
        {
            cout << "User Not Found !\n";
        }
        


        
    }
};
