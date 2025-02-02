#pragma once
#include "clsScreen.h"

#include "clsUtil.h"



class clsTotalBalanceScreen : protected clsScreen
{
    static void PrintClientRecordBalanceLine(clsBankClient Client)
    {
        cout << setw(15) << left << "" << "| " << setw(15) << left << Client.AccountNumber();
        cout << "| " << setw(40) << left << Client.FullName();
        cout << "| " << setw(12) << left << Client.AccountBalance();
    }

public:

    static void ShowTotalBalanceScreen()
    {
        vector <clsBankClient> vClients = clsBankClient::GetClientList();
        string Title = "Total Balance Screen ";
        string Substr = "(" + to_string(vClients.size()) + ") client (s);";

        _DrawScreenHeader(Title,Substr);
        cout << setw(25) << left << "" << "\n\t\t_______________________________________________________";
        cout << "__________________________\n" << endl;

        cout << setw(15) << left << "" << "| " << left << setw(15) << "Accout Number";
        cout << "| " << left << setw(40) << "Client Name";
        cout << "| " << left << setw(12) << "Balance";
        cout << setw(25) << left << "" << "\n\t\t_______________________________________________________";
        cout << "__________________________\n" << endl;

        double TotalBalances = clsBankClient::GetTotalBalances();

        if (vClients.size() == 0)
            cout << "\t\t\t\tNo Clients Available In the System!";
        else

            for (clsBankClient Client : vClients)
            {
                PrintClientRecordBalanceLine(Client);
                cout << endl;
            }

        cout << setw(25) << left << "" << "\n\t\t_______________________________________________________";
        cout << "__________________________\n" << endl;
        
        cout << setw(8) << left << "" << "\t\t\t\t    Total Balances = " << TotalBalances << endl;
        cout << setw(8) << left << "" << "\t\t\t  ( " << clsUntil::NumberToText(TotalBalances) << ")";
    }

    
};