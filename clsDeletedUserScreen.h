#pragma one
#include "clsScreen.h"
#include <iostream>


using namespace std;

class clsDeletedUserScreen : public clsScreen
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

    static void ShowDeletedUserScreen()
    {
        _DrawScreenHeader("Deleted User screen");
        cout << "\nPlease Enter User Name Do you want Deleted : ";
        string UserName = "";
        UserName = clsInputValidate::ReadString();

        while (clsUser::IsUserExict(UserName))
        {
           cout << "\nPlease Enter a nther User Name That Not Found ; ";
           UserName = clsInputValidate::ReadString();
        }

        clsUser User = clsUser::Find(UserName);
        _PrintUser(User);
        cout << "\nAre you Sure Do you want Deleted y/n : ";
        char Ansewer = 'n';
        cin >> Ansewer;
        if (Ansewer == 'Y' || Ansewer == 'y')
        {
            if (User.Deleted() )
            {
                cout << "\nIs Deleted Successfully :) \n\n";
                _PrintUser(User);
            }
            else
            {
                
            }
        }
        else
        {       
            cout << "\nNot Deleted it Concel (:>) !\n\n";
        }
            
    }
};