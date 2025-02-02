#pragma once
#include <iostream>
#include "clsCurrency.h"
#include "clsCurrencyListScreen.h"
#include "clsCurrencyFindScreen.h"
#include "clsCurrencyUpdate.h"
#include "clsCurrencyCalculator.h"
#include "clsScreen.h"

using namespace std;

class clsCurrencyExchangeScreen : protected clsScreen
{
		enum enCurrencyExhangeOptions {eListCurrency = 1, eFindCurrency = 2, eUpdateRate = 3,
		eCurrencyCalu = 4, eMainMenu = 5};
		static int _ReadMainMenuScreen()
		{
			int Number = 0;
			cout << setw(37) << left << "" << "Choose what do you want to do ? [1 to 5]?";
			Number = clsInputValidate::ReadIntNumberBetween(1, 5, "\nEnter From 1 to 5");

			return Number;
		
		}
		
		static void _ShowListCurrencyScreen()
		{
			//cout << "\n List Currency Screen will be there soon . \n";
            clsCurrencyListScreen::ShowCurrencyList();
		}
				
		static void _ShowFindCurrencyScreen()
		{
			//cout << "\n Find Currency Screen will be there soon . \n";
            clsFindScreen::ShowCurrencyFind();
		}
				
		static void _ShowUpdateRateScreen()
		{
			//cout << "\n Update Rate Screen will be there soon . \n";
            clsCurrencyUpdateRate::ShowScreenUpdateRate();
		}
						
		static void _ShowCurrencyCalculatorScreen()
		{
			//cout << "\n Currency Calculator Screen will be there soon . \n";
            clsCurrencyCalculator::ShowCurrencyCalculator();
		}

		static void _ShowMainMenuScreen()
		{

		}

		static void _GoBackToCurrencyMainScreen()
		{
			cout << "\nPress any key to back to Currency exchange main menu .... \n";
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cin.get();
			ShowCurrencyExchang();
		}

		static void _PrefromCurrencyExhangeOptions(enCurrencyExhangeOptions CurrencyExhangeOption)
		{
			switch (CurrencyExhangeOption)
			{

			case enCurrencyExhangeOptions::eListCurrency:
				system("clear");
				_ShowListCurrencyScreen();
				_GoBackToCurrencyMainScreen();
				break;

			case enCurrencyExhangeOptions::eFindCurrency:
				system("clear");
				_ShowFindCurrencyScreen();
				_GoBackToCurrencyMainScreen();
				break;

			case enCurrencyExhangeOptions::eUpdateRate:
				system("clear");
				_ShowUpdateRateScreen();
				_GoBackToCurrencyMainScreen();
				break;

			case enCurrencyExhangeOptions::eCurrencyCalu:
				system("clear");
				_ShowCurrencyCalculatorScreen();
				_GoBackToCurrencyMainScreen();
				break;
			
            case enCurrencyExhangeOptions::eMainMenu:
                system("clear");
                _ShowMainMenuScreen();
                break;
            
            }
		}


public:
	static void ShowCurrencyExchang()
	{
		system("cls");
		_DrawScreenHeader(" Currency Exhange Main Screen ");

		cout << setw(37) << left << "" << "================================================= \n";
		cout << setw(37) << left << "" << "\t\tCurrency Exhange Menue \n";
		cout << setw(37) << left << "" << "================================================= \n";
		cout << setw(37) << left << "" << "\t[1] List Currencies. \n";
		cout << setw(37) << left << "" << "\t[2] Find Currency. \n";
		cout << setw(37) << left << "" << "\t[3] Update Rate. \n";
		cout << setw(37) << left << "" << "\t[4] Currency Calculator. \n";
		cout << setw(37) << left << "" << "\t[5] Main Menue. \n";
		cout << setw(37) << left << "" << "================================================= \n";
		_PrefromCurrencyExhangeOptions((enCurrencyExhangeOptions)_ReadMainMenuScreen());
	}
};