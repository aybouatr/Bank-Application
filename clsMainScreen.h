#pragma once
#include <iostream>
#include "clsInputValidate.h"
#include "clsClientListScreen.h"
#include "clsAddNewClient.h"
#include "clsDeletedClientScreen.h"
#include "clsUpdateClient.h"
#include "clsFindClient.h"
#include "clsTransaction.h"
#include "clsMangerUserMenueScreen.h"
#include "clsLoginRegister.h"
#include "clsCurrencyExchangeScreen.h"
#include "Global.h"
#include <iomanip>

using namespace std;

class clsMainMenueScreen : protected clsScreen
{

private:
        
    enum _enMainMenueOptions{ClientList = 1,AddClient = 2,DeleteClient = 3,UpdateClient = 4,FindClient = 5,Transaction = 6,ManageUser = 7,LoginRegister=8,CurrencyExch =9,Logout =10 };

    static int _ReadMainMenueOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 10]? ";

        return clsInputValidate::ReadIntNumberBetween(1,10);
    }

    static  void _GoBackToMainMenue()
        {
            cout << setw(37) << left << ""<<"\n\tPress any key to go back to Main Menue...\n";
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cin.get();
            _ShowMainMenue();
        }

    static void _AddNewClient()
    {
       // cout << "\t\tAdd New Client Screen will be Here ?\n";
       clsAddNewClient::ShowAddNewClient();
       
    }

    static void _ShowClientList()
    {
        clsClientListScreen::ShowClientList();  
    }

    static void _DeleteClient()
    {
        //cout << "\t\tDelete Client Screen will be Here ?\n";
        clsDeletedClientScreen::ShowDeletedClientScreen();
    }

    static void _FindClient()
    {
        //cout << "\t\tFind Client Screen will be here !!\n";
        clsFindClint::ShowFindClient();
    }

    static void _UpdateClientInfo()
    {
       // cout << "\t\tUpdate Client Info Screen will be Here ?\n";
        clsUpdateClient::UpdateClientInfo();
    }

    static void _ManagerUser()
    {
        //cout << "\t\tManager User Screen will be Here ?\n";
         clsManagerUserScreen::ShowMangerUserScreen();
    }

    static void _Transaction()
    {
        //cout << "\t\tTransaction Screen will be Here ?\n";
        clsTransaction::ShowTransactionsMenue();
        
    }

    static void _ShowLoginRecored()
    {
        clsLoginRegister::ShowLoginScreen();
    }

    static void _ShowCurrencyExchange()
    {
        clsCurrencyExchangeScreen::ShowCurrencyExchang();
    }

    static void _Logout()
    {
        //cout << "\t\tLogout Screen will be Here ?\n";
        CurrentUser = clsUser::Find("","");
    }

    static void _PerfromMainMenueOption(_enMainMenueOptions Option)
    {
        switch (Option)
        {
            case _enMainMenueOptions::AddClient:
            {
                system("clear");
                _AddNewClient();
                _GoBackToMainMenue();
                break;;
            }
            case _enMainMenueOptions::ClientList:
            {
                system("clear");
                _ShowClientList();
                _GoBackToMainMenue();
                break;
            }
            case _enMainMenueOptions::DeleteClient:
            {
                system("clear");
                _DeleteClient();
                _GoBackToMainMenue();
                break;
            }
            case _enMainMenueOptions::UpdateClient:
            {
                system("clear");
                _UpdateClientInfo();
                _GoBackToMainMenue();
                break;
            }
            case _enMainMenueOptions::FindClient:
            {
                system("clear");
                _FindClient();
                _GoBackToMainMenue();
                break;
            }
            case _enMainMenueOptions::ManageUser:
            {
                system("clear");
                _ManagerUser();
                _GoBackToMainMenue();
                //_GoBackToMainMenue();
                break;
            }
            case _enMainMenueOptions::Transaction:
            {
                system("clear");
                _Transaction();
                _GoBackToMainMenue();
                break;
            }

            case _enMainMenueOptions::LoginRegister:
            {
                system("clear");
                _ShowLoginRecored();
                _GoBackToMainMenue();
                break;
            }

            case _enMainMenueOptions::CurrencyExch:
            {
                system("clear");
                _ShowCurrencyExchange();
                _GoBackToMainMenue();
                break;
            }

            case _enMainMenueOptions::Logout:
            {
                system("clear");
                _Logout();
                break;
            }
        }
    }
public:

    static void _ShowMainMenue()
    {

        system("clear");
        _DrawScreenHeader("Main Screen");

        cout << setw(37) << left <<""<< "===========================================\n";
        cout << setw(37) << left << "" << "\t\tMain Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Show Client List.\n";
        cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
        cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
        cout << setw(37) << left << "" << "\t[4] Update Client Info.\n";
        cout << setw(37) << left << "" << "\t[5] Find Client.\n";
        cout << setw(37) << left << "" << "\t[6] Transactions.\n";
        cout << setw(37) << left << "" << "\t[7] Manage Users.\n";
        cout << setw(37) << left << "" << "\t[8] Login Register.\n";
        cout << setw(37) << left << "" << "\t[9] Currency Exchange.\n";
        cout << setw(37) << left << "" << "\t[10] Logout.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerfromMainMenueOption((_enMainMenueOptions)_ReadMainMenueOption());
    }


};