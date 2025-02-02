#pragma once
#include <iostream>
#include "clsDate.h"
#include "clsString.h"

using namespace std;

class clsUntil
{
    static string formatString(int number)
	{
		if (number < 10)
			return "     : ";

		else if (number < 100)
			return "    : ";

		else if (number < 1000)
			return "   : ";

		else if (number < 10000)
			return "  : ";

		else if (number < 100000)
			return " : ";

	}

public:

    static void sRand()
	{
		srand((unsigned)time(NULL));
	}

    static int  getRandomNumber(int from, int to)
	{
		int randomNum = rand() % (to - from + 1) + from;

		return randomNum;
	}

    enum enCharType { CapitalLetters = 1, SmallLetters, Digits, MixChar, SpecialCharacter };

    static char getRandomCharacter(enCharType charType)
	{
		switch (charType)
		{
		case enCharType::CapitalLetters:
			return char(getRandomNumber(65, 90));

		case enCharType::SmallLetters:
			return char(getRandomNumber(97, 122));

		case enCharType::Digits:
			return char(getRandomNumber(48, 57));

		case enCharType::SpecialCharacter:
			return char(getRandomNumber(32, 47));

		default:

			getRandomCharacter((enCharType)getRandomNumber(1, 3));
		}
	}

    static string generateWord(enCharType charType, short wordLenght)
	{
		string word = "";

		for (short i = 1; i <= wordLenght; i++)
		{
			word += getRandomCharacter(charType);
		}

		return word;
	}

    static string generateKey(enCharType charType)
	{
		string key = "";

		for (short i = 1; i <= 4; i++)
		{
			key += generateWord(charType, 4) + "-";
		}

		return key.substr(0, key.length() - 1);
	}

    static void  generateKeys(short numberOfKeys, enCharType charType)
	{
		for (short i = 1; i <= numberOfKeys; i++)
		{
			cout << "Key [" << i << "]" << formatString(i) << generateKey(charType) << endl;
		}
	}

    static void swap(int &number1, int &number2) 
	{
		int temp;

		temp = number1;
		number1 = number2;
		number2 = temp;
	}

	static void swap(double& number1, double& number2)
	{
		double temp;

		temp = number1;
		number1 = number2;
		number2 = temp;
	}

    static void swap(bool& flag1, bool& flag2)
	{
		bool temp;

		temp = flag1;
		flag1 = flag2;
		flag2 = temp;
	}

	static void swap(string& text1, string& text2)
	{
		string temp;

		temp = text1;
		text1 = text2;
		text2 = temp;
	}

    static void swap(clsDate &date1, clsDate &date2)
	{
		clsDate tempDate;

		tempDate = date1;
		date1 = date2;
		date2 = tempDate;
	}

    static void shuffleArray(int arr[], int length)
	{
		for (int i = 0; i < length; i++) 
		{

			swap(arr[getRandomNumber(0, length -1) ],
				arr[getRandomNumber(0, length -1) ]);
		}
    }

    static void fillArrayWithRandomNumbers(int arr[], int length, int from, int to) 
	{
		for (int i = 0; i < length; i++) 
		{
			arr[i] = getRandomNumber(from, to);
		}
	}

    static void fillArrayWithRandomWords(string arr[], int length, enCharType charType, short wordLength)
	{
		for (int i = 0; i < length; i++)
		{
			arr[i] = generateWord(charType, wordLength);
		}
	}

    static void fillArrayWithRandomKeys(string arr[], int length, enCharType charType)
	{
		for (int i = 0; i < length; i++)
		{
			arr[i] = generateKey(charType);
		}
	}

    static string tabs(short numberOfTabs) 
	{
		string tab = "";

		for (short i = 1; i <= numberOfTabs; i++) 
		{
			tab += "\t";
		}

		return tab;
	}

    static string encryptText(string text, short key = 1) 
	{
		string encryptionText = "";

		for (short i = 0; i < text.length(); i++) 
		{
			encryptionText += text[i] + key;
		}

		return encryptionText;
	}

    static string decryptText(string text, short key = 1)
	{
		string decryptionText = "";

		for (short i = 0; i < text.length(); i++)
		{
			decryptionText += text[i] - key;
		}

		return decryptionText;
	}

	static string NumberToText(int Number)
   	{

       if (Number == 0)
       {
           return "";
       }

       if (Number >= 1 && Number <= 19)
       {
           string arr[] = { "", "One","Two","Three","Four","Five","Six","Seven",
       		"Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen",
         	"Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" };

           return  arr[Number] + " ";

       }

       if (Number >= 20 && Number <= 99)
       {
           string arr[] = { "","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety" };
           return  arr[Number / 10] + " " + NumberToText(Number % 10);
       }

       if (Number >= 100 && Number <= 199)
       {
           return  "One Hundred " + NumberToText(Number % 100);
       }

       if (Number >= 200 && Number <= 999)
       {
           return   NumberToText(Number / 100) + "Hundreds " + NumberToText(Number % 100);
       }

       if (Number >= 1000 && Number <= 1999)
       {
           return  "One Thousand " + NumberToText(Number % 1000);
       }

       if (Number >= 2000 && Number <= 999999)
       {
           return   NumberToText(Number / 1000) + "Thousands " + NumberToText(Number % 1000);
       }

       if (Number >= 1000000 && Number <= 1999999)
       {
           return  "One Million " + NumberToText(Number % 1000000);
       }

       if (Number >= 2000000 && Number <= 999999999)
       {
           return   NumberToText(Number / 1000000) + "Millions " + NumberToText(Number % 1000000);
       }

       if (Number >= 1000000000 && Number <= 1999999999)
       {
           return  "One Billion " + NumberToText(Number % 1000000000);
       }
       else
       {
           return   NumberToText(Number / 1000000000) + "Billions " + NumberToText(Number % 1000000000);
       }

   }

};