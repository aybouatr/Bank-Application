//#include "clsBankClient.h"
#include "clsScreen.h"

using namespace std;


class clsAddNewClient : public clsScreen
{
    static void _PrintClient(clsBankClient Client)
    {
        cout << "\nClient Card:\n";
        cout << "\n-----------------------------------------";
        cout << "\nName      : "<< Client.Name() ;
        cout << "\nLast Name : "<< Client.LastName();
        cout << "\nFull Name : " << Client.FullName();
        cout << "\nEmail     : " << Client.Email() ;
        cout << "\nPhone     : " << Client.Phone() ;
        cout << "\nAccNumber : " << Client.AccountNumber();
        cout << "\nPinCode   : " << Client.PineCode();
        cout << "\nBalance   : " << Client.AccountBalance() ;
        cout << "\n------------------------------------------\n";
    }

    static void _ReadClientInfo(clsBankClient& Add)
    {
        cout << "please enter New Name ?\n";
        Add.setName(clsInputValidate::ReadString());
        cout << "please enter New Last Name ?\n";
        Add.setLastName(clsInputValidate::ReadString());
        cout << "Please enter New Email ?\n";
        Add.setEmail(clsInputValidate::ReadString());
        cout << "Please Enter New Phone ?\n";
        Add.setPhone(clsInputValidate::ReadString());
        cout << "Please enter Account Balance ?\n";
        Add.SetAccountBalance(clsInputValidate::ReadDblNumber("invalid Number \n"));
        cout << "Please enter New Pine Code ?\n";
        Add.SetPineCode(clsInputValidate::ReadString());

    }

public:

    static void ShowAddNewClient()
    {
        if(!CheckAccessRights(clsUser::enPermissions::pAddNewClient))
            return;
        _DrawScreenHeader("Screeen Add New Screen :)!");

        string AccountNumber;

        cout << "Please enter Clinet Acount Number?\n";
        AccountNumber = clsInputValidate::ReadString();

        while (!clsBankClient::IsClientexist(AccountNumber))
        {
            cout << "Account is alraedy used befor, please choose a nother Account Number?\n";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient AddClient = clsBankClient::GetAddNewClientObject(AccountNumber);

        _ReadClientInfo(AddClient);

        clsBankClient::enSaveResult SaveResult;

        SaveResult = AddClient.Save();

        switch (SaveResult)
        {
            case clsBankClient::enSaveResult::svSucceeded:
            {
                cout << "\nAccount Addeded Succefully :)\n";
                _PrintClient(AddClient);
                break;
            }
            case clsBankClient::enSaveResult::svFaildEmptyObject:
            {
                cout << "Error New Client Not Saved becouse it's Empty Object\n";
                break;
            }
            case clsBankClient::enSaveResult::svFailAlreadyAcountNumberExit:
            {
                cout << "\nError account was not saved because account number is used!\n";
                break;

            }
        }

    }
};