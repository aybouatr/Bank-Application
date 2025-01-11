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
                Line = _ConverClientObjectToLine(C);
                Myfile << Line << endl;
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

    void Print()
    {
        cout << "\nClient Card:\n";
        cout << "\n-----------------------------------------";
        cout << "\nName      : "<< Name() ;
        cout << "\nLast Name : "<< LastName();
        cout << "\nFull Name : " << FullName();
        cout << "\nEmail     : " << Email() ;
        cout << "\nPhone     : " << Phone() ;
        cout << "\nAccNumber : " << AccountNumber();
        cout << "\nPinCode   : " << PineCode();
        cout << "\nBalance   : " << AccountBalance() ;
        cout << "\n------------------------------------------\n";
    }

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
                cout << "----> enter Add new \n\n";
                _AddNew();
                
                _Mode = enMode::UpdateMode;

                return enSaveResult::svSucceeded;
            }
        }
        return enSaveResult::svSucceeded;
    }
};