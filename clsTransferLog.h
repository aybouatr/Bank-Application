#pragma once
#include <iostream>

using namespace std;


class clsTransferLog : protected clsScreen
{

    static void _PrintLoginRecordLine(clsBankClient::eTransferLog vRecoredLogin)
    {

        cout << setw(8) << left << "" << "| " << setw(30) << left << vRecoredLogin.Date_time ;
        cout << "| " << setw(12) << left << vRecoredLogin.s_AccNum;
        cout << "| " << setw(12) << left << vRecoredLogin.d_AccNum;
        cout << "| " << setw(12) << left << to_string(vRecoredLogin.Amount);
        cout << "| " << setw(15) << left << to_string(vRecoredLogin.s_AccBlance);
        cout << "| " << setw(15) << left << to_string(vRecoredLogin.d_AccBlance);
        cout << "| " << setw(15) << left << vRecoredLogin.UserName << endl;
    }

public:

    static void ShowTransferLog()
    {
        vector <clsBankClient::eTransferLog> vTransferKogs = clsBankClient::GetTransferLog();

        string Haed = "   Transfer Logs List Screen ";
        string Title = "(" + to_string(vTransferKogs.size()) + ") Recored (s)";

        _DrawScreenHeader(Haed,Title);

        cout << "\n\t______________________________________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << "\t| " << left << setw(30) << "Date/time";
        cout << "| " << left << setw(12) << "s.Acc";
        cout << "| " << left << setw(12) << "d.Acc";
        cout << "| " << left << setw(12) << "Amount";
        cout << "| " << left << setw(15) << "s.Balance";
        cout << "| " << left << setw(15) << "d.Balance";
        cout << "| " << left << setw(15) << "User ";


        cout << "\n\t______________________________________________________________________________";
        cout << "_________________________________________\n" << endl;

        for (clsBankClient::eTransferLog &T : vTransferKogs)
        {
            _PrintLoginRecordLine(T);
        }

        cout << "\n\t______________________________________________________________________________";
        cout << "_________________________________________\n" << endl;

        
    }
};
