#include <iostream>
#include "clsInputValidate.h"
using namespace std;

int main() 
{
	
	cout << clsInputValidate::IsNumberBetween(15, 10, 20) << endl;

	cout << clsInputValidate::IsNumberBetween(20.91, 10.3, 20.9) << endl;

	cout << clsInputValidate::IsDateBetween(clsDate(), clsDate(1, 4, 2024), clsDate(1, 5, 2024)) << endl;
	cout << clsInputValidate::IsDateBetween(clsDate(), clsDate(1, 4, 2024), clsDate(15, 4, 2024)) << endl;
	cout << clsInputValidate::IsDateBetween(clsDate(), clsDate(1, 5, 2024), clsDate(1, 4, 2024)) << endl;
	cout << clsInputValidate::IsDateBetween(clsDate(), clsDate(1, 5, 2024), clsDate(15, 5, 2024)) << endl;
	cout << clsInputValidate::IsDateBetween(clsDate(1, 4, 2024), clsDate(1, 4, 2024), clsDate(1, 5, 2024)) << endl;
	cout << clsInputValidate::IsDateBetween(clsDate(1, 5, 2024), clsDate(1, 4, 2024), clsDate(1, 5, 2024)) << endl;

	cout << "\n\nPlease Enter A Number  ? :  \n";
	
	int x = clsInputValidate::readIntegerNumber("Invalid Number, Enter Again :");
	cout << "x = " << x << endl;

	cout << "\n\nPlease Enter A Number  ? :  \n";

	double y = clsInputValidate::readdoubleNumber("Invalid Number, Enter Again :");
	cout << "y = " << y << endl;

	cout << "\nPlease Enter A Number Between 1 and 100: \n";
	int a = clsInputValidate::w(1, 100, "Number Is Not Within The Range, Enter Again :");
	
	cout << "a = " << a << endl;

	cout << "\nPlease Enter A Number Between 10.5 and 105.6: \n";
	double b = clsInputValidate::readdoubleBetweenNumber(10.5, 105.6, "Number Is Not Within The Range, Enter Again :");

	cout << "b = " << b << endl;

	

	

	return 0;
}