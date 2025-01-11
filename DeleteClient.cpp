#pragma  once
#include "clsBankClient.h"
#include "clsInputValidate.h"

void DeleteClient()
{
    string AccountNumber;
    char Ansewer;

    cout << "Please Enter Account Number of you want Deleted ?\n";
    AccountNumber = clsInputValidate::ReadString();

    while (!clsBankClient::IsClientexist(AccountNumber))
    {
        cout << "Account Number Not Found Please enter a nother one ?\n";
        AccountNumber = clsInputValidate::ReadString();

    }

    clsBankClient Client = clsBankClient::Find(AccountNumber);
    Client.Print();

    cout << "Arlrady you want Delete y/n?\n";
    cin >> Ansewer;
    if (Ansewer == 'y' || Ansewer == 'Y')
    {
        if(Client.Delete())
        {
            cout << 
        }
    }

    

}

int main()
{
    DeleteClient();
}