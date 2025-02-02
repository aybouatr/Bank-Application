#include <iostream>
#include "clsScreen.h"


using namespace std;

class clsUpdateUserScreen : public clsScreen
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

    static void _ReadNewInfo(clsUser &User)
    {
        cout << "\nplease enter New Name ?\n";
        User.setName(clsInputValidate::ReadString());
        cout << "\nplease enter New Last Name ?\n";
        User.setLastName(clsInputValidate::ReadString());
        cout << "\nPlease enter New Email ?\n";
        User.setEmail(clsInputValidate::ReadString());
        cout << "\nPlease Enter New Phone ?\n";
        User.setPhone(clsInputValidate::ReadString());
        cout << "\nPlease enter New Passe Word ?\n";
        User.SetPassWde(clsInputValidate::ReadString());
        User.SetPermisions(_ReadPermissionsToSet());
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

    static void ShowUpdateUserScreen()
    {
        _DrawScreenHeader("Upadte User Screen ");

        cout << "Enter User Nama Do you Want Update : ";
        string UserName = clsInputValidate::ReadString();

        while (clsUser::IsUserExict(UserName))
        {
            cout << "\nThis User Name Not found Please Enter a noter one : ";
            UserName = clsInputValidate::ReadString();
        }

        clsUser User = clsUser::Find(UserName);

        _PrintUser(User);

        cout << "\nAre Sure Do you Want Update This Count y/n : ";
        char Ansewer = 'n';
        cin >> Ansewer;
        if (Ansewer == 'Y' || Ansewer == 'y')
        {
            cout << "\n\nUpdate Info\n";
            cout << "\n-------------------\n";
            _ReadNewInfo(User);
            clsUser::enSaveResult Result = User.Save();
            switch (Result)
            {
                case clsUser::enSaveResult::svSuccess:
                {
                    cout << "\nIt Update Successffully !\n"; 
                    _PrintUser(User);    
                    break;
                }
                case clsUser::enSaveResult::svFildEmptyObject:
                {
                    cout << "Not Save Because it Object Empty !\n";
                    _PrintUser(User);
                    break;
                }
            }
        }
        else
            cout << "OKy it Concel !): \n";
        
    }

};