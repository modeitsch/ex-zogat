// Zogat.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Console.h"
#include "Windows.h"
#include "enemy.h"
#include "slider.h"
#include <sstream>
using namespace std;

bool gamerunning = true;

enemy enemy1;
slider slider1;
Console console;

// Create restart function for when player dies

int main()
{
	while (gamerunning)
	{
		stringstream ss;
		ss << number_of_coins;
		string items = "Coins: ";
		items += ss.str();

		stringstream ss2;
		ss2 << health;
		string health = "Health: ";
		health += ss2.str();

		map[1][26] = '>';
		map[2][30] = '<';

		system("cls");

		for (int i = 0; i < 10; i++)
		{
			cout << map[i] << endl;
		}
		for (int i = 0; i < 1; i++)
		{
			cout << items << "    " << health << endl;
		}
		for (int i = 0; i < 1; i++)
		{
			cout << dialog << endl;
		}
		system("pause>nul");

		enemy1.Init(5, 20);
		slider1.Init_Hor(6, 46);

		if (GetAsyncKeyState(VK_UP))
			console.Move(-1, 0);
		if (GetAsyncKeyState(VK_DOWN))
			console.Move(1, 0);
		if (GetAsyncKeyState(VK_RIGHT))
			console.Move(0, 1);
		if (GetAsyncKeyState(VK_LEFT))
			console.Move(0, -1);
		if (GetAsyncKeyState(VK_RETURN) && dialog_displayed)
			dialog = "";
		if (y == 1 && x == 26)
		{
			y = 1;
			x = 30;
		}
		if (y == 2 && x == 30)
		{
			y = 2;
			x = 25;
		}
		if ((y == 2 && x == 35) && number_of_coins > 19 && 
			(GetAsyncKeyState(VK_RETURN)))
		{
			dialog = "You bought the Money Key!";
			dialog_displayed = true;
			number_of_coins -= 20;
			got_key2 = true;
			map[1][35] = ' ';
		}
		else if ((y == 2 && x == 35) && number_of_coins < 20 &&
			(GetAsyncKeyState(VK_RETURN)) && !got_key2)
		{
			dialog = "You don't have enough money to buy the money key!";
			dialog_displayed = true;
		}
	}
	system("pause");
}

