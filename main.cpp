#include <iostream>
#include "clsLoginScreen.h"

#include "clsCurrency.h"

using namespace std;

int main() 
{

	//clsMainMenueScreen::_ShowMainMenue();
	while(1)
	{
		if(clsLoginScreen::ShowLogin())
		{
			break;
		}
	}



}
