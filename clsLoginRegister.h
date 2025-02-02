#pragma once
#include <iostream>
#include "clsScreen.h"

using namespace std;

class clsLoginRegister : protected clsScreen
{
    static void _PrintLoginRecordLine(clsUser::stRecoredLogin vRecoredLogin)
    {

        cout << setw(8) << left << "" << "| " << setw(35) << left << vRecoredLogin.DateTime ;
        cout << "| " << setw(15) << left << vRecoredLogin.UserName;
        cout << "| " << setw(20) << left << vRecoredLogin.PasseWde;
        cout << "| " << setw(10) << left << to_string(vRecoredLogin.Permissions) << endl;
    }


public:

    static void ShowLoginScreen()
    {
        if(!CheckAccessRights(clsUser::enPermissions::pShowLoginRecored))
            return;

        vector <clsUser::stRecoredLogin>  vRecoredLogin = clsUser::LoadRecoredLoginFromfile();

        string Title = "\t(" + to_string(vRecoredLogin.size()) + ") Recored (s)";

        _DrawScreenHeader("Login Register Login Screen !",Title);

        cout << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << "\t| " << left << setw(35) << "Date/time";
        cout << "| " << left << setw(15) << "User Name";
        cout << "| " << left << setw(20) << "Passe Word";
        cout << "| " << left << setw(10) << "Permissions";
        cout << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        for (clsUser::stRecoredLogin &R : vRecoredLogin)
        {
            _PrintLoginRecordLine(R);
        }

        cout << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

    }
};