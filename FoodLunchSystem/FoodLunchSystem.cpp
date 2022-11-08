// FoodLunchSystem.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void registerUser();
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
			while (true)
			{
				foodMenu();
			}
			break;
		case 'v':
			line();
			cout << "Current order\n\n";
			break;
		case'l':
			line();
		case'r':
			line();
			registerUser();
		case'e':
			line();
			cout << "Exit\n\n";
			return 0;
			break;
		default:
			break;
	}
}

void registerUser()
{
	cout << "Please enter a username: ";
	string registeredName;
	cin >> registeredName;
	cout << "Enter your school ID: ";
	string registeredID;
	cin >> registeredID;
	cout << "Please enter a password: ";
	string registeredPassword;
	cin >> registeredPassword;
}

void foodMenu()
{
	string foodArray[4] = { "Hot Dog, \t\t$5", "Chicken And Rice, \t$7", "Beans On Toast, \t$100", "Apple, \t\t$2" };
	cout << "Food Menu\n\n";
	for (int i = 0; i < 4; i++) {
		cout << i + 1 << " " << foodArray[i] << "\n";
	}
	cout << "Add item: ";
	int foodChoice;
	cin >> foodChoice;
	foodChoice--;
	if (foodChoice < 4 && foodChoice >= 0)
	{
		cout << foodArray[foodChoice] << " added to order. \n";
	}
}

void menu()
{
	cout << "[F]ood menu\n[V]iew order\n[E]xit\n[L]og in to Account\n[R]egister Account\n\ninput: ";
}

void line()
{
	for (int i = 0; i < 50; i++)
	{
		cout << "~";
	}
	cout << "\n";
}