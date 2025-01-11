#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsString.h"

void ReadClientInfo(clsBankClient& Add)
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

void AddNewClient()
{
    string AccountNumber;

    cout << "Please enter Clinet Acount Number?\n";
    AccountNumber = clsInputValidate::ReadString();

    while (!clsBankClient::IsClientexist(AccountNumber))
    {
        cout << "Account is alraedy used befor, please choose a nother Account Number?\n";
        AccountNumber = clsInputValidate::ReadString();
    }

    clsBankClient AddClient = clsBankClient::GetAddNewClientObject(AccountNumber);

    ReadClientInfo(AddClient);

    clsBankClient::enSaveResult SaveResult;

    SaveResult = AddClient.Save();


}

int main()
{
    AddNewClient();

}