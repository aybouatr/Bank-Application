#pragma once
#include <iostream>
#include <string>
#include "clsPersonne.h"
#include "clsString.h"
#include <vector>
#include <fstream>

using namespace std;



class clsBankClient : public clsPersonne
{
    enum enMode {EmptyMode = 0,UpdateMode = 1,AddNewMode=2};
    enMode _Mode;

    string _AccountNumber;
    string _Pinecode;
    double _AccountBalance;
    bool _Mark_Delete = false;

public :

    struct eTransferLog
    {
       string Date_time;
       string s_AccNum;
       string d_AccNum;
       float  Amount;
       float s_AccBlance;
       float d_AccBlance;
       string UserName;
    };

private:

    static clsBankClient _ConvertLinetoClientObject(string Line,string Seperator = "#//#")
    {
        vector<string> vClientData;
        vClientData = clsString::Split(Line, Seperator);

        clsBankClient Client(enMode::UpdateMode, vClientData[0], vClientData[1], vClientData[2],
            vClientData[3], vClientData[4],vClientData[5],stod(vClientData[6]));
        return (Client);
        
    }

    static string _ConverClientObjectToLine(clsBankClient Client,string Seperator = "#//#")
    {
        string line;
        line = "";
        line = Client.Name() + Seperator + Client.LastName() + Seperator + Client.Email() + Seperator + Client.AccountNumber()
              + Seperator + Client.Phone() + Seperator + Client.PineCode() + Seperator 
              + to_string(Client.AccountBalance());
        
        return (line);
    }

    static vector <clsBankClient> _LoadClientDataFromFile()
    {
        vector <clsBankClient> vClients;
        fstream Myfile;
        Myfile.open("hh.txt",ios::in);

       if (Myfile.is_open())
       {
           string Line;
           while (getline(Myfile, Line))
           {
                clsBankClient Client = _ConvertLinetoClientObject(Line);
                vClients.push_back(Client);
           }
       }
       Myfile.close(); 
       return (vClients);
    }

    void _SaveClientsDataToFile(vector<clsBankClient> vClients)
    {
       string Line;

       fstream Myfile;

       Myfile.open("hh.txt",ios::out);

       if (Myfile.is_open())
       {

            for (clsBankClient & C : vClients)
            {
                if (C._Mark_Delete != true)
                {
                    Line = _ConverClientObjectToLine(C);
                    Myfile << Line << endl;
                }
            }
       }
       Myfile.close();
    }

    static clsBankClient _GetClienModeAddNew(string AddnewClient)
    {
        return (clsBankClient(enMode::AddNewMode,"","","",AddnewClient,"","",0));
    }

    static clsBankClient _GetObjectEmpty()
    {
        clsBankClient Client = clsBankClient(enMode::EmptyMode,"","","","","","",0);
        return (Client);
    }

    void _AddDataLineToFile(string Line)
    {

        fstream Myfile;

        Myfile.open("hh.txt", ios::out | ios::app);
        if (Myfile.is_open())
        {
            Myfile << Line << endl;
        }
       Myfile.close();
    }

    string _PrepareTarnsferRecord(clsBankClient ClientDest,float Amount,string Seperator = "#//#")
    {
        string Tr = "" ;
        Tr =  clsDate::GetSystemDateTimeString() + Seperator + AccountNumber() + Seperator
                + ClientDest.AccountNumber() + Seperator + to_string(Amount) + Seperator
                + to_string(AccountBalance()) + Seperator + to_string(ClientDest.AccountBalance()) + Seperator
                + CurrentUser.UserName();
        return (Tr);
    }

    void _RegisterLogTransfer(clsBankClient ClientDest,float Amount)
    {
        string stDataLine = _PrepareTarnsferRecord(ClientDest,Amount);

        fstream MyFile;
        MyFile.open("TransferLog.txt", ios::out | ios::app);

        if (MyFile.is_open())
        {

            MyFile << stDataLine << endl;

            MyFile.close();
        }

    }

    
    //28/1/2025 - 12:46:1#//#A104#//#A101#//#1000.000000#//#4000.000000#//#10691.000000#//#Voss

    static eTransferLog _ConvertLineToTransferLog(string Line)
    {
        eTransferLog Log;
        vector <string> vLog = clsString::Split(Line,"#//#");
        Log.Date_time = vLog[0];
        Log.s_AccNum = vLog[1];
        Log.d_AccNum = vLog[2];
        Log.Amount = stod(vLog[3]);
        Log.s_AccBlance = stod(vLog[4]);
        Log.d_AccBlance = stod(vLog[5]);
        Log.UserName = vLog[6];

        return (Log);

    }

    static vector<eTransferLog> _LoadTransferLog()
    {
        vector <eTransferLog> vLogs;

        fstream Myfile;

        Myfile.open("TransferLog.txt",ios::in);

        if(Myfile.is_open())
        {
            string Line;
            while (getline(Myfile,Line))
            {
                vLogs.push_back(_ConvertLineToTransferLog(Line));
            } 
        }
        Myfile.close();
        return (vLogs);
    }

public :

    clsBankClient(enMode Mode,string Name,string LastName,string Email,string AccNumber,string Phone,string PineCode,float AccBalance)
    : clsPersonne(Name,LastName,Email,Phone)
    {
        _Mode = Mode;
        _AccountBalance = AccBalance;
        _Pinecode = PineCode;
        _AccountNumber = AccNumber;
    }

    static clsBankClient Find(string AccountNumber)
    {
       vector<clsBankClient> vClient;
       fstream Myfile;

       Myfile.open("hh.txt",ios::in);

       if (Myfile.is_open())
       {
           string Line;
           while (getline(Myfile, Line))
           {
                clsBankClient Client = _ConvertLinetoClientObject(Line);
                if (Client.AccountNumber() == AccountNumber)
                {
                    Myfile.close();
                    return (Client);
                }
                vClient.push_back(Client);
           }
       }
       Myfile.close(); 
       return (_GetObjectEmpty());
    }

    static clsBankClient Find(string AccountNumber,string PineCode)
    {
       vector<clsBankClient> vClient;
       fstream Myfile;

       Myfile.open("hh.txt",ios::in);

       if (Myfile.is_open())
       {
           string Line;
           while (getline(Myfile, Line))
           {
                clsBankClient Client = _ConvertLinetoClientObject(Line);
                if (Client.AccountNumber() == AccountNumber && Client.PineCode() == PineCode)
                {
                    Myfile.close();
                    return (Client);
                }
                vClient.push_back(Client);
           }
       }
       Myfile.close(); 
       return (_GetObjectEmpty());
    }

    bool Delete()
    {
        vector<clsBankClient> vClients;
        vClients = _LoadClientDataFromFile();

        for(clsBankClient& C: vClients)
        {
            if (AccountNumber() == C.AccountNumber())
            {
                C._Mark_Delete = true;
                break;
            }
        }
        _SaveClientsDataToFile(vClients);
        *this = _GetObjectEmpty();
        return true;
    }

    bool IsEmpty()
    {
        return (_Mode == enMode::EmptyMode);
    }

    void SetAccountBalance(float accBa)
    {
        _AccountBalance = accBa;
    }

    float AccountBalance()
    {
        return (_AccountBalance);
    }

    void SetPineCode(string pinecode)
    {
        _Pinecode = pinecode;
    }

    string PineCode()
    {
        return (_Pinecode);
    }
    
    string AccountNumber()
    {
        return (_AccountNumber);
    }

    // void Print()
    // {
    //     cout << "\nClient Card:\n";
    //     cout << "\n-----------------------------------------";
    //     cout << "\nName      : "<< Name() ;
    //     cout << "\nLast Name : "<< LastName();
    //     cout << "\nFull Name : " << FullName();
    //     cout << "\nEmail     : " << Email() ;
    //     cout << "\nPhone     : " << Phone() ;
    //     cout << "\nAccNumber : " << AccountNumber();
    //     cout << "\nPinCode   : " << PineCode();
    //     cout << "\nBalance   : " << AccountBalance() ;
    //     cout << "\n------------------------------------------\n";
    // }

    static bool IsClientexist(string AccountNumber)
    {
        clsBankClient Client = Find(AccountNumber);
        return (Client.IsEmpty());
    }

    enum enSaveResult{svFaildEmptyObject = 0,svSucceeded = 1,svExitAlready = 2,svFailAlreadyAcountNumberExit = 3};

    void  _Update()
    {
        vector<clsBankClient> _vClints;

        _vClints = _LoadClientDataFromFile();
        for(clsBankClient &C : _vClints)
        {
            if(C.AccountNumber() == AccountNumber())
            {
                C = *this;
                break;
            }
        }
        _SaveClientsDataToFile(_vClints);
    }

    void _AddNew()
    {
        _AddDataLineToFile(_ConverClientObjectToLine(*this));
    }

    void Deposit(float Amount)
    {
        _AccountBalance += Amount;
        Save();
    }

    void Withdraw(float Amount)
    {
        _AccountBalance -= Amount;
        Save();
    }

    bool Transfer(float Amount, clsBankClient &DestinationClient)
    {
        if (Amount > AccountBalance())
        {
            return false;
        }
    
        Withdraw(Amount);
        DestinationClient.Deposit(Amount);
       _RegisterLogTransfer(DestinationClient,Amount);
   
        return true;
    }

    static clsBankClient GetAddNewClientObject(string addNewClient)
	{
		return (_GetClienModeAddNew(addNewClient));
	}

    enSaveResult Save()
    {
        switch (_Mode)
        {
            case enMode::EmptyMode:
            {
                return (enSaveResult::svFaildEmptyObject);
            }
            case enMode::UpdateMode:
            {
                _Update();

                return (enSaveResult::svSucceeded);
            }
            case enMode::AddNewMode:
            {
                _AddNew();
                
                _Mode = enMode::UpdateMode;

                return enSaveResult::svSucceeded;
            }
        }
        return enSaveResult::svSucceeded;
    }

    static double GetTotalBalances()
    {
        vector<clsBankClient> vClients;

        vClients = _LoadClientDataFromFile();
        double TotalBalance = 0;

        for(clsBankClient &C: vClients)
        {
            TotalBalance += C.AccountBalance();
        }
        return (TotalBalance);
    }

    static vector<eTransferLog> GetTransferLog()
    {
        return (_LoadTransferLog());
    } 

    static vector <clsBankClient> GetClientList()
    {
        return (_LoadClientDataFromFile());
    }
};