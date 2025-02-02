#pragma once
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"
#include <iostream>

using namespace std;

class clsFindScreen : protected clsScreen
{
    static void _PrintCurrencyInfo(clsCurrency Currency)
    {
        cout << "\nCurrency Card:\n";
        cout << "_____________________________\n";
        cout << "\nCountry    : " << Currency.Currency();
        cout << "\nCode       : " << Currency.CurrencyCode();
        cout << "\nName       : " << Currency.CurrencyName();
        cout << "\nRate(1$) = : " << Currency.Rate();

        cout << "\n_____________________________\n";

    }

public:

    static void ShowCurrencyFind()
    {
        _DrawScreenHeader("Currency Find Screen");

        enum enChoie{searchContry=2,searchCode=1};

        short ansew;
        string Code_or_Country;
        cout << "Find by; [1] Code or [2] Country ? ";
       ansew = clsInputValidate::ReadIntNumberBetween(1,2);
        switch (ansew)
        {
            case enChoie::searchCode:
            {
                cout << "please Enter CurrencyCode ? ";
               Code_or_Country = clsInputValidate::ReadString();
                clsCurrency Curr = clsCurrency::FindByCode(Code_or_Country);
                if(!Curr.IsEmptyObject())
                {
                    cout << "Currency Founf -) ";
                    _PrintCurrencyInfo(Curr);
                }
                else
                    cout << "Not Found !\n";
                break;
            }
            case enChoie::searchContry:
            {
                cout << "please Enter Country Name ? ";
                Code_or_Country = clsInputValidate::ReadString();
                clsCurrency Curr = clsCurrency::FindByContry(Code_or_Country);
                if(!Curr.IsEmptyObject())
                {
                    cout << "Currency Founf -) ";
                    _PrintCurrencyInfo(Curr);
                }
                else
                    cout << "Not Found !\n";
                break;

            }
        }
    }
};