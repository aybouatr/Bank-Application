#include <iostream>
#include "clsScreen.h"


using namespace std;


class clsAddNewUserScreen : public clsScreen
{
    static void _ReadInfoUser(clsUser &User)

    {
        cout << "please enter Name ?\n";
        User.setName(clsInputValidate::ReadString());
        cout << "please enter Last Name ?\n";
        User.setLastName(clsInputValidate::ReadString());
        cout << "Please enter Email ?\n";
        User.setEmail(clsInputValidate::ReadString());
        cout << "Please Enter Phone ?\n";
        User.setPhone(clsInputValidate::ReadString());
        cout << "Please enter Passe Word ?\n";
        User.SetPassWde(clsInputValidate::ReadString());
        User.SetPermisions(_ReadPermissionsToSet());
       
    }

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

    static int _ReadPermissionsToSet()
    {

        int Permissions = 0;
        char Answer = 'n';


        cout << "\nDo you want to give full access? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            return -1;
        }

        cout << "\nDo you want to give access to : \n ";

        cout << "\nShow Client List? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {


            Permissions += clsUser::enPermissions::pListClient;
        }

        cout << "\nAdd New Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pAddNewClient;
        }

        cout << "\nDelete Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pDeletedClient;
        }

        cout << "\nUpdate Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pUpdateClient;
        }

        cout << "\nFind Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pFindClient;
        }

        cout << "\nTransactions? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pTransactions;
        }

        cout << "\nManage Users? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pTransactions;
        }

        cout << "\nShow Login Screen? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pShowLoginRecored;
        }

        return Permissions;

    }

public:

    static void ShowAddNewUserScreen()
    {

        _DrawScreenHeader("Add New User Screen");

        cout << "Please Enter User Name \n";
        string UserName = clsInputValidate::ReadString();

        while (!clsUser::IsUserExict(UserName))
        {
            cout << "Please Enter a nother one it's aready exict !\n";
            UserName = clsInputValidate::ReadString();
        }

        clsUser User = clsUser::GetAddNewUsersObject(UserName);

        _ReadInfoUser(User);

        clsUser::enSaveResult ResultSave;

        ResultSave = User.Save();

        switch (ResultSave)
        {
            case clsUser::enSaveResult::svFildEmptyObject:
            {
                cout << "Not Save it Empty Object \n";
                break;
            }
            case clsUser::enSaveResult::svSuccess:
            {
                cout << "\nAccount Addeded Succefully :)\n";
                _PrintUser(User);
                break;
            }
            case clsUser::enSaveResult::svFailExitBefor:
            {
                cout << "Not Save because it Exict Befor\n";
                break;
            }
        }
    }  
};