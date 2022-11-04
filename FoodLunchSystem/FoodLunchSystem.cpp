// FoodLunchSystem.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>

using namespace std;

void menu();
void line();



int main()
{
	fstream foodFile("Food.txt");

	line();
	cout << "\tMain Menu";
	line();
	char mainMenu;
	menu();
	cin >> mainMenu;
	mainMenu = tolower(mainMenu);



	switch (mainMenu)
	{
		case 'f':
			cout << "Food Menu\n";
			break;
		case 'V':
			cout << "Current order\n";
			break;
		case'E':
			cout << "Exit\n";
			return 0;
			break;
		default:
			break;
	}
}





void menu()
{
	cout << "[F]ood menu\n[V]iew order\n[E]xit\n\ninput: ";
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