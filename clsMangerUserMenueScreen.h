#include "clsScreen.h"
#include "clsListUserScreen.h"
#include "clsAddNewUserScreen.h"
#include "clsDeletedUserScreen.h"
#include "clsUpdateUserScreen.h"
#include "clsFindUserScreen.h"

class clsManagerUserScreen : protected clsScreen
{
    enum enManageUsersMenueOptions{eListUsers = 1,eAddNewUser = 2,eDeleteUsers = 3,eUpdateUser = 4,eFindUser = 5,eMainMenue = 6};

    static int ReadManageUsersMenueOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]? ";

        return clsInputValidate::ReadIntNumberBetween(1,6);
    }

    static void _GoBackToManageUsersMenue()
    {
        cout << setw(37) << left << ""<<"\n\tPress any key to go back to Main Menue...\n";
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cin.get();
        clsManagerUserScreen::ShowMangerUserScreen();
    }

    static void _ShowListUsers()
    {
        //cout << "List User well be here Soon !\n";
        clsListUserScreen::ShowUsersList();
    }

    static void _ShowAddUsers()
    {
        //cout << "Add User well be here Soon !\n";
        clsAddNewUserScreen::ShowAddNewUserScreen();
    }

    static void _ShowDeleteUsers()
    {
        //cout << "Delete User well be here Soon !\n";
        clsDeletedUserScreen::ShowDeletedUserScreen();
    }

    static void _ShowFindUsers()
    {
       // cout << "Find User well be here Soon !\n";
        clsFindUserScreen::ShowFindUserScreen();
    }

    static void _ShowUpdateUsers()
    {
        //cout << "Update User well be here Soon !\n";
        clsUpdateUserScreen::ShowUpdateUserScreen();
 
    }

    
    static void _PerformManageUsersMenueOption(enManageUsersMenueOptions Options)
    {
        switch (Options)
        {
            case enManageUsersMenueOptions::eListUsers:
            {
                system("clear");
                _ShowListUsers();
                _GoBackToManageUsersMenue();

            }
            case enManageUsersMenueOptions::eAddNewUser:
            {
                system("clear");
                _ShowAddUsers();
                _GoBackToManageUsersMenue();
                break;
            }
            case enManageUsersMenueOptions::eDeleteUsers:
            {
                system("clear");
                _ShowDeleteUsers();
                _GoBackToManageUsersMenue();
                break;
            }
            case enManageUsersMenueOptions::eFindUser:
            {
                system("clear");
                _ShowFindUsers();
                _GoBackToManageUsersMenue();
                break;
            }
            case enManageUsersMenueOptions::eUpdateUser:
            {
                system("clear");
                _ShowUpdateUsers();
                _GoBackToManageUsersMenue();
                break;
            }
            case enManageUsersMenueOptions::eMainMenue:
            {
                
               
            }
            
        }
    }

public:

    static void ShowMangerUserScreen()
    {
        if(!CheckAccessRights(clsUser::enPermissions::pManageUser))
            return;
        system("clear");
        _DrawScreenHeader("Manage Users Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t  Manage Users Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] List Users.\n";
        cout << setw(37) << left << "" << "\t[2] Add New User.\n";
        cout << setw(37) << left << "" << "\t[3] Delete User.\n";
        cout << setw(37) << left << "" << "\t[4] Update User.\n";
        cout << setw(37) << left << "" << "\t[5] Find User.\n";
        cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerformManageUsersMenueOption((enManageUsersMenueOptions)ReadManageUsersMenueOption());

    }
};