#pragma once
#include <iostream>
#include "clsCurrency.h"
#include "clsScreen.h"
#include "clsInputValidate.h"

using namespace std;

class clsCurrencyUpdateRate : protected clsScreen
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

    static void ShowScreenUpdateRate()
    {
        _DrawScreenHeader("Update Currency Screen");

        cout << "Please Enter Currency Code ? ";
        string Code = clsInputValidate::ReadString();

        while (!clsCurrency::IsExictCurrency(Code))
        {
           cout << "\n\nThis Currency Code Not Found Please Enter a nother one ? ";
            Code = clsInputValidate::ReadString();
        }

        clsCurrency Curr = clsCurrency::FindByCode(Code);

        _PrintCurrencyInfo(Curr);

        char Ansewer;
        cout << "\nAre you Sure Do you want Update the Rate of this Currency Y/N ";
        cin >> Ansewer;

        if (Ansewer == 'Y' || Ansewer == 'y')
        {
            cout << "\nUpdate Currency Rate ";
            cout << "\n___________________________\n";
            cout << "\nEnter New Rate : ";
            float rat;
            cin >> rat;
            Curr.UpdateRate(rat);
            _PrintCurrencyInfo(Curr);
        }
        
    }
};