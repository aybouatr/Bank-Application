#pragma one
#include "clsScreen.h"
#include "clsShowDepositScreen.h"
#include "clsShowWithdrawScreen.h"
#include "clsTotalBalanceScreen.h"
#include "clsTransfer.h"
#include "clsTransferLog.h"


class clsTransaction : protected clsScreen
{
    enum enTransactionsMenueOptions{eDeposit = 1,eWithdraw = 2,eTotalBlance = 3,eTransfert=4,eTransferLog= 5,eMaineMenue = 6};

    static int ReadTransactionsMenueOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]? ";

        return (clsInputValidate::ReadIntNumberBetween(1,6));
    }

    static void _ShowDepositScrenn()
    {
        //cout << "Deposit well be here !!\n";
        clsDepositScreen::ShowDepositScreen();
    }

    static void _ShowWithdrawScreen()
    {
        //cout << "Withdraw well be here !!\n";
        clsWithdraw::ShowWithdrawScreen();
    }

    static void _ShowTotalBalanceScreen()
    {
        //cout << "Total Balance well be here !\n";
        clsTotalBalanceScreen::ShowTotalBalanceScreen();
    }

    static void _ShowTransferLog()
    {
        clsTransferLog::ShowTransferLog();
    }

    static void _ShowTransfer()
    {
        clsTransfer::ShowTransferScreen();
    }

    static void _GoBackTrasactionsMenue()
    {
        cout << setw(37) << left << ""<<"\n\tPress any key to go back to Main Menue...\n";
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cin.get();
            clsTransaction::ShowTransactionsMenue();
    }

   static void _PerformTransactionsMenueOption(enTransactionsMenueOptions Option)
   {
        switch (Option)
        {
            case enTransactionsMenueOptions::eDeposit:
            {
                system("clear");
                _ShowDepositScrenn();
                _GoBackTrasactionsMenue();
            }
            case enTransactionsMenueOptions::eWithdraw:
            {
                system("clear");
                _ShowWithdrawScreen();
                _GoBackTrasactionsMenue();
            }
            case enTransactionsMenueOptions::eTotalBlance:
            {
                system("clear");
                _ShowTotalBalanceScreen();
                _GoBackTrasactionsMenue();
            }

            case enTransactionsMenueOptions::eTransfert:
            {
                system("clear");
                _ShowTransfer();
                _GoBackTrasactionsMenue();
            }

            case enTransactionsMenueOptions::eTransferLog:
            {
                system("clear");
                _ShowTransferLog();
                _GoBackTrasactionsMenue();
            }

            case enTransactionsMenueOptions::eMaineMenue:
            {

            }
        }
   }

public:

    static void ShowTransactionsMenue()
    {

        if(!CheckAccessRights(clsUser::enPermissions::pTransactions))
            return;
        system("clear");

        _DrawScreenHeader(" Transactions Screen");



        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t  Transactions Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Deposit.\n";
        cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
        cout << setw(37) << left << "" << "\t[3] Total Balances.\n";
        cout << setw(37) << left << "" << "\t[4] Transfer.\n";
        cout << setw(37) << left << "" << "\t[5] Transfer Log.\n";
        cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerformTransactionsMenueOption((enTransactionsMenueOptions)ReadTransactionsMenueOption());
    }


};