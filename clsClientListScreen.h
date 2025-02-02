#include "clsBankClient.h"
#include "clsScreen.h"
#include <iomanip>
#include <vector>


class clsClientListScreen : public clsScreen
{
private:

    static void PrintClientRecordBalanceLine(clsBankClient Client)
    {

        cout << "\t| " << setw(15) << left << Client.AccountNumber();
        cout << "| " << setw(20) << left << Client.FullName();
        cout << "| " << setw(12) << left << Client.Phone();
        cout << "| " << setw(20) << left << Client.Email();
        cout << "| " << setw(10) << left << Client.PineCode();
        cout << "| " << setw(12) << left << Client.AccountBalance();

    }

public:

    static void ShowClientList()
    {
        if(!CheckAccessRights(clsUser::enPermissions::pListClient))
            return;

        vector <clsBankClient> vClients = clsBankClient::GetClientList();

        string message = "Client List Screen";
        string Title = "(" + to_string(vClients.size()) + ") Clients(s):";

        clsScreen::_DrawScreenHeader(message,Title);

        cout << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << "\t| " << left << setw(15) << "Accout Number";
        cout << "| " << left << setw(20) << "Client Name";
        cout << "| " << left << setw(12) << "Phone";
        cout << "| " << left << setw(20) << "Email";
        cout << "| " << left << setw(10) << "Pin Code";
        cout << "| " << left << setw(12) << "Balance";
        cout << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vClients.size() == 0)
            cout << "\t\t\t\tNo Clients Available In the System!";
        else

            for (clsBankClient Client : vClients)
            {

                PrintClientRecordBalanceLine(Client);
                cout << endl;
            }

        cout << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

    }

};