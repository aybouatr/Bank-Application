#include "clsScreen.h"
//#include "clsInputValidate.h"
//#include "clsBankClient.h"

using namespace std;

class clsFindClint : public clsScreen
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

public:

    static void ShowFindClient()
    {
        if(!CheckAccessRights(clsUser::enPermissions::pFindClient))
            return;
        
        _DrawScreenHeader("Find Client Screen !");;

        string AccountNumber = "";

        cout << "Please enter Client Acount Number?\n";
        AccountNumber = clsInputValidate::ReadString();

        while (clsBankClient::IsClientexist(AccountNumber))
        {
            cout << "choose a nother Account Number?\n";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient Client = clsBankClient::Find(AccountNumber);

        if(!Client.IsEmpty())
        {
            cout << "\nClient Found ls\n";
        }
        else
        {
            cout << "Client Not Found is Empty !\n\n";
        }
        
        _PrintClient(Client);
    }
};