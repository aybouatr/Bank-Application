#pragma once
#include <iostream>
#include <string>
#include "clsPersonne.h"
#include "clsUtil.h"
#include <vector>
#include "clsDate.h"
#include <fstream>

using namespace std;

class clsUser : public clsPersonne
{
public:

    struct stRecoredLogin
    {
        string UserName;
        string DateTime;
        string PasseWde;
        int    Permissions;
    };

private:

    enum enMode{EmptyMode=1,UpdaeMode=2,AddNewMode=3};

    enMode _Mode;

    string _UserName;
    string _PasseWde;
    int _Permissions;

   
    

    bool _MarkforDeleted = false;


    static clsUser _ConvaertLineToObject(string Line,string Sperator = "#//#")
    {
        vector <string> vUsers = clsString::Split(Line,Sperator);

        clsUser Users(enMode::UpdaeMode,vUsers[0],vUsers[1],vUsers[2],vUsers[3],vUsers[4],clsUntil::decryptText(vUsers[5],1),stod(vUsers[6]));

        return (Users);
    }

    static string _ConvertObjectToLine(clsUser User,string Seperator = "#//#" )
    {
        string Line = "";

        Line = User.Name() + Seperator + User.LastName() + Seperator + User.Email() + Seperator + User.UserName() 
                + Seperator + User.Phone() + Seperator + clsUntil::encryptText(User.PassWorde(),1) + Seperator + to_string(User.Permissions());
        return (Line);
    }

    static vector <clsUser> _LoadUserDataFromFile()
    {
        vector <clsUser> vUsers;
        fstream Myfile;

        Myfile.open("User.txt",ios::in);

        if(Myfile.is_open())
        {
            string Line;

            while (getline(Myfile, Line))
            {
                clsUser User = _ConvaertLineToObject(Line);
                vUsers.push_back(User);
            }
        }
        Myfile.close();
        return (vUsers);
    }

    static clsUser _GetObjectEmpty()
    {
        clsUser User(enMode::EmptyMode,"","","","","","",0);

        return (User);
    }

    static clsUser _GetUserModeAddNew(string UserName)
    {
        clsUser User(enMode::AddNewMode,"","","",UserName,"","",0);

        return User;
    }

    static void _SaveDataUserToFile(vector <clsUser> vUsers)
    {
        fstream Myfile;

        Myfile.open("User.txt",ios::out);

        if(Myfile.is_open())
        {
            for(clsUser U : vUsers)
            {
                if(U._MarkforDeleted == false)
                {
                    string Line = _ConvertObjectToLine(U);
                    Myfile << Line << endl;
                }
            }
        }
        Myfile.close();
    }

    static void AddDataLineToFile(string Line)
    {
        fstream Myfile;

        Myfile.open("User.txt",ios::out | ios::app);
        if(Myfile.is_open())
            Myfile << Line << endl;
        Myfile.close();
    }

    void _Update()
    {
        vector <clsUser> vUsers = _LoadUserDataFromFile();

        for(clsUser &U : vUsers)
        {
            if(U.UserName() == _UserName)
            {
                U = *this;
                break;
            }
        }
        _SaveDataUserToFile(vUsers);
    }

    void AddNewUser()
    {
        AddDataLineToFile(_ConvertObjectToLine(*this));
    }

    static stRecoredLogin _ConertLineToLoginRecored(string Line)
    {
        stRecoredLogin Reco;
        vector <string> vRecored = clsString::Split(Line , "#//#");

        Reco.DateTime = vRecored[0];
        Reco.UserName = vRecored[1];
        Reco.PasseWde = vRecored[2];
        Reco.Permissions = stod(vRecored[3]);

        return Reco;
    }

    string _PrepareLogInRecord( string Seperator = "#//#")
    {
        string LoginRecord = "";
        LoginRecord += clsDate::GetSystemDateTimeString() + Seperator;
        LoginRecord += UserName() + Seperator;
        LoginRecord += clsUntil::decryptText(PassWorde()) + Seperator;
        LoginRecord += to_string(Permissions());
        return LoginRecord;
    }



public:

    enum enPermissions{eAll= -1,pListClient=1,pAddNewClient=2,pDeletedClient=4,pUpdateClient=8
    ,pFindClient=16,pTransactions=32,pManageUser=64,pShowLoginRecored=128};

    
    clsUser(enMode Mode,string Name,string LastName,string Email,string UsrNm,string Phone,string PassWd,int  Permissions)
    : clsPersonne(Name,LastName,Email,Phone)
    {
        _Mode = Mode;
        _UserName = UsrNm;
        _PasseWde = PassWd;
        _Permissions = Permissions;
    }

    bool Deleted()
    {
            vector <clsUser> vUser;

            vUser = _LoadUserDataFromFile();

            for(clsUser &User : vUser)
            {
                if (User.UserName() == _UserName)
                {
                    User._MarkforDeleted = true;
                    break;
                }
            }
            _SaveDataUserToFile(vUser);
            *this = _GetObjectEmpty();

            return(true);
    }

    void SetPermisions(int i)
    {
        _Permissions = i;
    }

    bool IsEmpty()
    {
        return (enMode::EmptyMode == _Mode);
    }

    static clsUser Find(string UserName)
    {
        fstream Myfile;

        Myfile.open("User.txt",ios::in);

        if(Myfile.is_open())
        {
            string Line;
            while (getline(Myfile,Line))
            {
                clsUser User = _ConvaertLineToObject(Line);
                if (User.UserName() == UserName)
                {
                    Myfile.close();
                    return (User);
                }
            }
        }
        Myfile.close();
        return (_GetObjectEmpty());
    }

    static clsUser Find(string UserName,string PassWorde)
    {
        fstream Myfile;

        Myfile.open("User.txt",ios::in);

        if(Myfile.is_open())
        {
            string Line;
            while (getline(Myfile,Line))
            {
                clsUser User = _ConvaertLineToObject(Line);
                if (User.UserName() == UserName && User.PassWorde() == PassWorde)
                {
                    Myfile.close();
                    return (User);
                }
            }
        }
        Myfile.close();
        return (_GetObjectEmpty());
    }

     enum enSaveResult{svFildEmptyObject = 0,svSuccess = 1,svFailExitBefor = 2};

    static bool IsUserExict(string UserName)
    {
        clsUser User = Find(UserName);

        return(User.IsEmpty());
    }

    enSaveResult Save()
    {
        switch (_Mode)
        {
            case enMode::EmptyMode:
            {
                if(IsEmpty())
                {
                    return (enSaveResult::svFildEmptyObject);
                }
            }
            case enMode::UpdaeMode:
            {
                _Update();
                return (enSaveResult::svSuccess);
            }
            case enMode::AddNewMode:
            {
                if(!clsUser::IsUserExict(_UserName))
                {
                    return (enSaveResult::svFailExitBefor);
                }
                else
                {
                    AddNewUser();
                    _Mode = enMode::UpdaeMode;
                    return(enSaveResult::svSuccess);
                }
            }
        }
        return enSaveResult::svSuccess;
        
    }

    string UserName()
    {
        return (_UserName);
    }

    bool _MarkForDeleted()
    {
        return (_MarkforDeleted);
    }

    void SetUserName(string UserName)
    {
        _UserName = UserName;
    }

    string PassWorde()
    {
        return (_PasseWde);
    }

    void SetPassWde(string Pass)
    {
        _PasseWde = Pass;
    }

    int Permissions()
    {
        return (_Permissions);
    }

   void RegisterLogIn()
    {

        string stDataLine = _PrepareLogInRecord();

        fstream MyFile;
        MyFile.open("LoginRegister.txt", ios::out | ios::app);

        if (MyFile.is_open())
        {

            MyFile << stDataLine << endl;

            MyFile.close();
        }

    }

    static vector <stRecoredLogin> LoadRecoredLoginFromfile()
    {
        vector <clsUser::stRecoredLogin> VRecoredLogin;

        fstream Myfile;

        Myfile.open("LoginRegister.txt",ios::in);

        if(Myfile.is_open())
        {
            string Line = "";
            while (getline(Myfile,Line))
            {
                VRecoredLogin.push_back(clsUser::_ConertLineToLoginRecored(Line));
            }
            
        }
        Myfile.close();

        return (VRecoredLogin);
    }
    
    static clsUser GetAddNewUsersObject(string UserName)
    {
        return (_GetUserModeAddNew(UserName));
    }

    static vector <clsUser> GetUsersList()
    {
        return (_LoadUserDataFromFile());
    }

    bool CheckAccessPermissions(enPermissions Permissions)
    {
        if (Permissions == enPermissions::eAll)
            return (true);

        if ((Permissions & this->Permissions()) == Permissions)
            return (true);
        else
            return (false);

    }

};