#pragma one
#include "clsScreen.h"



class clsDepositScreen : protected clsScreen
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

    static void ShowDepositScreen()
    {
        string AccNumber = "";
        _DrawScreenHeader("Deposit Screen ");

        cout << "please Enter Account Number\n";
        AccNumber = clsInputValidate::ReadString();

        while (clsBankClient::IsClientexist(AccNumber))
        {
            cout << "Please Choose a nother Account Number That not Exist ?\n";
            AccNumber = clsInputValidate::ReadString();
        }

        clsBankClient Client = clsBankClient::Find(AccNumber);

        _PrintClient(Client);

        cout << "Enter Amount Do you Want Deposit \n";
        float Amount = clsInputValidate::ReadfloatNumber();
        cout << "Are you Sure do you want Add this Amount ?\n";
        char Ansewer = 'n';
        cin >> Ansewer;

        if (Ansewer == 'y' || Ansewer == 'Y')
        {
            Client.Deposit(Amount);
            cout << "Deposit Succefully Amount \n";
            cout << "New Total Balance is : ";
            cout << Client.AccountBalance() << endl;
        }
        else
        {
            cout << "Opration is Concel !\n";
        }
    }
};