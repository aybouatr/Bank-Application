#pragma once
#include "iostream"
#include <cstdlib> 
#include "clsUser.h"
#include "clsDate.h"
#include "Global.h"

using namespace std;

class clsScreen
{
public:

    static void _DrawScreenHeader(string message,string Title = "")
    {
        system("clear");
        cout << "\t\t\t\t    ===========================================\n";
        cout << "\t\t\t\t\t\t  " << message <<endl;
        if (Title != "")
            cout <<"\t\t\t\t\t\t "<< Title << endl;
        cout << "\t\t\t\t    ===========================================\n";
        clsDate Date;
        cout << "\t\t\t\t     User : " << CurrentUser.UserName() << endl;
        cout <<  "\t\t\t\t     Date : " << clsDate::DateToString(clsDate()) << endl;
    }

     static bool CheckAccessRights(clsUser::enPermissions Permiss)
    {
        if(!CurrentUser.CheckAccessPermissions(Permiss))
        {
            cout << "\t\t\t\t    ===========================================\n";
            cout << "\t\t\t\t       Access Diened Please Call Staff !\n";
            cout << "\t\t\t\t    ===========================================\n";
            return (false);
        }
        else 
        {
            return (true);
        }
    }
};
