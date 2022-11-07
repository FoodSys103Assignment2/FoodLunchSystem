// FoodLunchSystem.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void foodMenu();
void menu();
void line();

int main()
{
	//fstream foodFile;
	//foodFile.open("Food.txt", ios::out); //write
	//foodFile << "First line\n";
	//foodFile.close();

	line();
	cout << "Main Menu\n";
	line();
	char mainMenu;
	menu();
	cin >> mainMenu;
	mainMenu = tolower(mainMenu);

	switch (mainMenu)
	{
		case 'f':
			line();
			foodMenu();
			break;
		case 'V':
			line();
			cout << "Current order\n\n";
			break;
		case'E':
			line();
			cout << "Exit\n\n";
			return 0;
			break;
		default:
			break;
	}
}

void foodMenu()
{
	string foodArray[4] = { "Hot Dog, $5", "Chicken And Rice, $7", "Beans On Toast, $100", "Apple, $ 2" };
	cout << "Food Menu\n\n";
	for (int i = 0; i < 4; i++) {
		cout << i + 1 << " " << foodArray[i] << "\n";
	}
	cout << "Add item: ";
	int foodChoice;
	cin >> foodChoice;


}

void menu()
{
	cout << "[F]ood menu\n[V]iew order\n[E]xit\n\ninput: ";
}

void line()
{
	for (int i = 0; i < 50; i++)
	{
		cout << "~";
	}
	cout << "\n";
}