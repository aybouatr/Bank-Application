#pragma once
#include <iostream>
#include "clsScreen.h"

using namespace std;

class clsCurrencyListScreen : protected clsScreen
{
    static void PrintCurrencyCountry(clsCurrency Curr)
    {

        cout << "\t| " << setw(35) << left << Curr.Currency();
        cout << "| " << setw(15) << left << Curr.CurrencyCode();
        cout << "| " << setw(35) << left << Curr.CurrencyName();
        cout << "| " << setw(20) << left << Curr.Rate();
       
    }

public:

    static void ShowCurrencyList()
    {
        vector <clsCurrency> vCurrency = clsCurrency::GetCurrencyList();

        string Title = "Currency List Screen";
        string SubTitle = "(" + to_string(vCurrency.size()) + ") Currency .";

        _DrawScreenHeader(Title,SubTitle);

        cout << "\n\t___________________________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << "\t| " << left << setw(35) << "Country";
        cout << "| " << left << setw(15) << "Code";
        cout << "| " << left << setw(35) << "Name";
        cout << "| " << left << setw(20) << "Rate/($)";
        cout << "\n\t_______________________________________________________";
        cout << "_____________________________________________________\n" << endl;

         if (vCurrency.size() == 0)
            cout << "\t\t\t\tNo Currency Available In the System!";
        else

            for (clsCurrency Curr : vCurrency)
            {

                PrintCurrencyCountry(Curr);
                cout << endl;
            }

        cout << "\n\t___________________________________________________________________";
        cout << "_________________________________________\n" << endl;

    }
};