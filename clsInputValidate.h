#include <iostream>
#include "clsDate.h"
#include <limits>    // std::numeric_limits

using namespace std;

class clsInputValidate
{


public:

    static bool IsNumberBetween(int nb,int a,int b)
    {
        return ((nb >= a && nb <= b) || (nb <= a && nb >= b));
    }

    static bool IsNumberBetween(float nb,float a,float b)
    {
        return ((nb >= a && nb <= b) || (nb <= a && nb >= b));
    }

    static bool IsNumberBetween(double nb,double a,double b)
    {
        return ((nb >= a && nb <= b) || (nb <= a && nb >= b));
    }

    static bool IsDateBetween(clsDate A1,clsDate a,clsDate b)
    {
        return ((clsDate::IsDate1AfterDate2(a,A1) && clsDate::IsDate1BeforeDate2(b,A1)) || (clsDate::IsDate1AfterDate2(b,A1) && clsDate::IsDate1BeforeDate2(a,A1)));
    }

    static double readdoubleNumber(string message) 
	{
		double number = 0;
		double input;
        
		cin >> input;
		while (cin.fail()) 
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			cout << message << endl;
			cin >> input;
		}

		number = input;
		return number;
	}

    static float readFloatNumber(string message) 
	{
		float number = 0;
		float input;
        
		cin >> input;
		while (cin.fail()) 
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			cout << message << endl;
			cin >> input;
		}

		number = input;
		return number;
	}

    static int readIntegerNumber(string message) 
	{
		int number = 0;
		double input;
        
		cin >> input;
		while (cin.fail()) 
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			cout << message << endl;
			cin >> input;
		}

		number = input;
		return number;
	}

    static double readdoubleBetweenNumber(double a,double b,string message) 
	{
		double number = 0;
		double input;
        
		cin >> input;
		while (cin.fail() || !IsNumberBetween(input,a,b)) 
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			cout << message << endl;
			cin >> input;
		}

		number = input;
		return number;
	}

    static float readFloatBetweenNumber(float a,float b,string message) 
	{
		float number = 0;
		float input;
        
		cin >> input;
		while (cin.fail() || !IsNumberBetween(input,a,b)) 
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			cout << message << endl;
			cin >> input;
		}

		number = input;
		return number;
	}

    static int readIntegerBetweenNumber(int a,int b,string message) 
	{
		int number = 0;
		int input;
        
		cin >> input;
		while (!IsNumberBetween(input,a,b)) 
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			cout << message << endl;
			cin >> input;
		}

		number = input;
		return number;
	}


};
