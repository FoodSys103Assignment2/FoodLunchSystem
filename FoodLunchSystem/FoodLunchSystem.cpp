// FoodLunchSystem.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

void menu();
void line();

int main()
{
    cout << "Welcome you little fucking piss ant";
	line();

	cout << "Main Menu";
	line();
	char mainMenu;
	menu();
	cin >> mainMenu;
	mainMenu = tolower(mainMenu);

	if (mainMenu == 'f')
	{

	}
	else if (mainMenu == 'a')
	{

	}
	else if (mainMenu == 'b')
	{

	}
}

void menu()
{
	cout << "[F]ood menu\n[A]llergies menu\n[B]usiness info\n\nUser input: ";
}

void line()
{
	cout << "\n";
	for (int i = 0; i < 50; i++)
	{
		cout << "~";
	}
	cout << "\n";
}