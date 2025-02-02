#include "clsScreen.h"

using namespace std;

class clsDeletedClientScreen : public clsScreen
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

    static void ShowDeletedClientScreen()
    {
        if(!CheckAccessRights(clsUser::enPermissions::pDeletedClient))
            return;

        _DrawScreenHeader("Deleted Client Screen !");

        string AccountNumber;
        char Ansewer;

        cout << "\nPlease Enter Account Number of you want Deleted ?\n";
        AccountNumber = clsInputValidate::ReadString();

        while (clsBankClient::IsClientexist(AccountNumber))
        {
            cout << "\nAccount Number Not Found Please enter a nother one ?\n";
            AccountNumber = clsInputValidate::ReadString();

        }

        clsBankClient Client = clsBankClient::Find(AccountNumber);
        _PrintClient(Client);

        cout << "Arlrady you want Delete y/n?\n";
        cin >> Ansewer;
        if (Ansewer == 'y' || Ansewer == 'Y')
        {
            if(Client.Delete())
            {
                _PrintClient(Client);
                cout << "oky is Delete succefylly ?\n";

            }
            else
            {
                cout << "Error Client not Deleted  !!!\n";

            }
        }
        else
        {
            cout << "Oky is Opreration Cencel :)\n";
        }
    }

};