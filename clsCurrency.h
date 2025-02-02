#pragma once
#include <iostream>
#include "clsString.h"
#include <fstream>


using namespace std;

class clsCurrency 
{

private:

    enum enMode{eUpdateMode=1,eEmpyMode=2};

    enMode _Mode;

    string _Currency;
    string _Currency_Code;
    string _Currency_Name;
    float _Rate;

    static clsCurrency _ConvertLintToObject(string Line)
    {
        vector <string> vLine = clsString::Split(Line,"#//#");
        clsCurrency Curr(enMode::eUpdateMode,vLine[0],vLine[1],vLine[2],stod(vLine[3]));
        return (Curr);
    }

    static string _ConvertObjectToLine(clsCurrency Curr,string Seperator = "#//#")
    {
        string Line = "";

        Line = Curr.Currency() + Seperator;
        Line += Curr.CurrencyCode() + Seperator;
        Line += Curr.CurrencyName() + Seperator;
        Line += to_string(Curr.Rate());

        return (Line);
    }

    static vector<clsCurrency> _LoadDataCurrencyFromFile()
    {
        vector <clsCurrency> vCurr;
        fstream Myfile;
        Myfile.open("Currencies.txt",ios::in);

        if (Myfile.is_open())
        {
            string line;

            while (getline(Myfile,line))
            {
                vCurr.push_back(_ConvertLintToObject(line));
            }
        }
        Myfile.close();
        return (vCurr);
    }

    static void _SaveDataCurrencyToFile(vector <clsCurrency> vCurr)
    {
        fstream Myfile;

        Myfile.open("Currencies.txt",ios::out);

        if(Myfile.is_open())
        {
            string Line;
            for(clsCurrency &C : vCurr)
            {
                Line = _ConvertObjectToLine(C);
                Myfile << Line << endl;
            }
        }
        Myfile.close();
    }

   void _Update()
    {
        vector <clsCurrency> vCurrency = _LoadDataCurrencyFromFile();
        for(clsCurrency &C : vCurrency)
        {
            if (Currency() == C.Currency())
            {
                C = *this;
                break;
            }
        }
        _SaveDataCurrencyToFile(vCurrency);
    }

    static clsCurrency _GetEmptyObject()
    {
        return (clsCurrency(enMode::eEmpyMode,"","","",0));
    }

public:

    clsCurrency(enMode Mode,string Currency,string Currency_Code,string Currency_Name,float Rate)
    {
        _Mode = Mode;
        _Currency = Currency;
        _Currency_Code = Currency_Code;
        _Currency_Name = Currency_Name;
        _Rate = Rate;
    }

    void UpdateRate(float rate)
    {
        Rate(rate);
        _Update();
    }

    string Currency()
    {
        return (_Currency);
    }

    bool IsEmptyObject()
    {
        return (enMode::eEmpyMode == _Mode);
    }

    string CurrencyCode()
    {
        return (_Currency_Code);
    }

    string CurrencyName()
    {
        return (_Currency_Name);
    }

    static   clsCurrency FindByCode(string CurrencyCode)
    {
     
        CurrencyCode = clsString::UpperAllString(CurrencyCode);

        fstream MyFile;
        MyFile.open("Currencies.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsCurrency Currency = _ConvertLintToObject(Line);
                if (Currency.CurrencyCode() == CurrencyCode)
                {
                    MyFile.close();
                    return Currency;
                }
            }

            MyFile.close();

        }

        return _GetEmptyObject();

    }


    static clsCurrency FindByContry(string contry)
    {
        contry = clsString::UpperAllString(contry);

        fstream Myfile;

        Myfile.open("Currencies.txt",ios::in);

        if(Myfile.is_open())
        {
            string Line;
            while(getline(Myfile,Line))
            {
                clsCurrency Curr = _ConvertLintToObject(Line);
                if (clsString::UpperAllString(Curr.Currency()) == contry)
                {
                    Myfile.close();
                    return (Curr);
                }
            }
        }
        Myfile.close();
        return (_GetEmptyObject());
    }

    static bool IsExictCurrency(string CurrCode)
    {
        clsCurrency Curr = clsCurrency::FindByCode(CurrCode);

        return(!Curr.IsEmptyObject());
    }

    void Rate(float rate)
    {
        _Rate = rate;
    }

    float Rate()
    {
        return (_Rate);
    }

    static vector <clsCurrency> GetCurrencyList()
    {
        return (_LoadDataCurrencyFromFile());
    }

    float ConvertToUSD(float Amount)
    {
        return (float)(Amount / Rate());
    }

    float ConvertToOtherCurrency(float Amount, clsCurrency Currency2)
    {
        float AmountInUSD = ConvertToUSD(Amount);

        if (Currency2.CurrencyCode() == "USD")
        {
            return AmountInUSD;
        }

        return (float)(AmountInUSD * Currency2.Rate());

    }
};
