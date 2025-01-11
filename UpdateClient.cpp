#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsString.h"

void ReadClientInfo(clsBankClient& Client)
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

void UpdateClient()
{
    string AccountNumber = "";

    cout << "Please enter Clinet Acount Number?\n";
    AccountNumber = clsInputValidate::ReadString();

    while (!clsBankClient::IsClientexist(AccountNumber))
    {
        cout << "choose a nother Account Number?\n";
        AccountNumber = clsInputValidate::ReadString();
    }

    clsBankClient Client = clsBankClient::Find(AccountNumber);

    Client.Print();

    cout << "\n\nUpdate Info Client\n";

    ReadClientInfo(Client);

    clsBankClient::enSaveResult SaveResult;

    SaveResult = Client.Save();

    switch (SaveResult)
    {
        case clsBankClient::enSaveResult::svSucceeded:
        {
            cout << "\nAccount save Successfully :)\n";
            Client.Print();
            break;
        }
        
        case clsBankClient::enSaveResult::svFaildEmptyObject:
        {
            cout << "\nError Account not saved because it's Empty\n";
            break;
        }
    }
    
}  

int main()
{
    UpdateClient();
}