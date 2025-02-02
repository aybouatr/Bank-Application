#include "clsScreen.h"

using namespace std;

class clsUpdateClient : public clsScreen
{
    static void _ReadClientInfo(clsBankClient& Client)
    {
        cout << "\nEnter New Name ?\n";
        Client.setName(clsInputValidate::ReadString());

        cout << "\nEnter New Last Name?\n";
        Client.setLastName(clsInputValidate::ReadString());

        cout << "\nEnter New Email ?\n";
        Client.setEmail(clsInputValidate::ReadString());

        cout << "\nEnter New Phone ?\n";
        Client.setPhone(clsInputValidate::ReadString());

        cout << "\nEnter New PineCode ?\n";
        Client.SetPineCode(clsInputValidate::ReadString());

        cout << "\nEnter New Account Balance ?\n";
        Client.SetAccountBalance(clsInputValidate::ReadfloatNumber());
    }

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


public:


    static void UpdateClientInfo()
    {
        if(!CheckAccessRights(clsUser::enPermissions::pUpdateClient))
            return;

        _DrawScreenHeader("Update Client Info Screeb :)");

        string AccountNumber = "";

        cout << "Please enter Clinet Acount Number?\n";
        AccountNumber = clsInputValidate::ReadString();

        while (clsBankClient::IsClientexist(AccountNumber))
        {
            cout << "choose a nother Account Number?\n";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient Client = clsBankClient::Find(AccountNumber);

        _PrintClient(Client);

        cout << "\n\nUpdate Info Client\n";

        _ReadClientInfo(Client);

        clsBankClient::enSaveResult SaveResult;

        SaveResult = Client.Save();

        switch (SaveResult)
        {
            case clsBankClient::enSaveResult::svSucceeded:
            {
                cout << "\nAccount save Successfully :)\n";
                _PrintClient(Client);
                break;
            }
            
            case clsBankClient::enSaveResult::svFaildEmptyObject:
            {
                cout << "\nError Account not saved because it's Empty\n";
                break;
            }
        }
    }
};