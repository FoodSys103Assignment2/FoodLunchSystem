// FoodLunchSystem.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

bool userLogin();
bool registerUser();
void foodMenu();
void menu();
void line();

int main()
{
	//fstream foodFile;
	//foodFile.open("Food.txt", ios::out); //write
	//foodFile << "First line\n";
	//foodFile.close();
	start:
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
			while (true)
			{
				line();
				foodMenu();
			}
			break;
		case 'v':
			line();
			cout << "Current order\n\n";
			break;
		case'l':
			line();
			userLogin();
			goto start;
		case'r':
			line();
			if (!registerUser())
			{
				cout << "User was already taken\n\n";
			}
			goto start;
		case'e':
			line();
			cout << "Exit\n\n";
			return 0;
			break;
		default:
			break;
	}
}

bool userLogin()
{
	ifstream openFile;
	stringstream userFile;

	cout << "Enter your school ID: ";
	string userID;
	cin >> userID;
	openFile.open("./registeredAccounts/user-" + userID + ".deeez");
	openFile.close();
	return false;
}

bool registerUser()
{
	cout << "Enter your school ID: ";
	string registeredID;
	cin >> registeredID;
	cout << "Please enter a password: ";
	string registeredPassword;
	cin >> registeredPassword;

	string filename = "./registeredAccounts/user-" + registeredID + ".deeez";

	ifstream fileCheck;
	fileCheck.open(filename);
	if (fileCheck.is_open())
	{
		fileCheck.close();
		return false;
	}

	ofstream newFile;
	newFile.open(filename);
	if (!newFile.is_open())
	{
		return false;
	}
	newFile << "id:" << registeredID << "\npassword:" << registeredPassword;
	newFile.close();
	return true;
}

void foodMenu()
{
	string foodArray[4] = { "Hot Dog, \t\t$5", "Chicken And Rice, \t$7", "Beans On Toast, \t$100", "Apple, \t\t$2" };

	cout << "Food Menu\n\n";
	for (int i = 0; i < 4; i++) {
		cout << i + 1 << " " << foodArray[i] << "\n";
	}
	
	cout << "\n[10] ingridents menu \n\nAdd item: ";
	int foodChoice;
	cin >> foodChoice;
	foodChoice--;
	if (foodChoice < 4 && foodChoice >= 0){
		cout << foodArray[foodChoice] << " added to order. \n";
	}
	else if (foodChoice == 10) {
		cout << "\nPlease select item to check: ";
		string ingrList; 
		cin >> ingrList;
		string checkFile = "./foodIngridents/" + ingrList + ".deeez";
		ifstream ingrCheck;
		ingrCheck.open(checkFile);
		ingrCheck.close();
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