// FoodLunchSystem.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

bool userLogin();
bool registerUser();
bool foodMenu();
bool ingridentsList();
bool viewOrder();
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
				if (foodMenu() == false)
				{
					goto start;
				}
				else
				{
					foodMenu();
				}
			}
			break;
		case 'v':
			line();
			cout << "Current order\n\n";
			viewOrder();
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
loginStart:
	int line = 0;
	string userInfo[2];
	string info;

	cout << "Input ID:";
	string ID;
	cin >> ID;

	ifstream openfile("./registeredAccounts/user-" + ID + ".deeez");
	if (openfile.is_open())
	{
		while (getline(openfile, info)) {
			// Output the text from the file
			userInfo[line] = info;
			line++;
		}
		openfile.close();
	}
	else
	{
		cout << "User ID doesn't exist\n";
		goto loginStart;
	}
	string passwordInput;
	cout << "\nEnter password: ";
	
	cin >> passwordInput;

	string actualPassword = "password:";

	actualPassword += passwordInput;

	if (actualPassword == userInfo[1])
	{
		cout << "Welcome student " << ID << "\n";
	}
	else
	{
		cout << "Wrong password try again\n";
		goto loginStart;
	}
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

bool foodMenu()
{
	string foodArray[4] = { "Hot Dog, \t\t$5", "Chicken And Rice, \t$7", "Beans On Toast, \t$100", "Apple, \t\t$2" };

	cout << "Food Menu\n\n";
	for (int i = 0; i < 4; i++) {
		cout << i + 1 << " " << foodArray[i] << "\n";
	}
	
	cout << "\n[10] Ingredients menu\n[11] Go back\n\nAdd item: ";
	int foodChoice;
	cin >> foodChoice;
	foodChoice--;
	if (foodChoice < 4 && foodChoice >= 0){
		cout << "\n" << foodArray[foodChoice] << " added to order. \n";
		string orderAdd = "./registeredAccounts/currOrder.deeez";
		fstream vCurr;
		vCurr.open(orderAdd, ios::app); 
		if (vCurr.is_open()) {
			vCurr << foodArray[foodChoice] << "\n";
			vCurr.close();
		}
	} 
	else if (foodChoice == 9) {
		ingridentsList();
	}
	else if (foodChoice == 10) 
	{
		return false;
	}
}

bool ingridentsList()
{
	int fileLine = 0;
	string ingrInfo;
	cout << "\nPlease select item to check: ";
	cin >> ingrInfo;
	//string checkAddress = "./foodIngridents/" + ingrList + ".deeez";
	ifstream checkFile("./foodIngridents/food-" + ingrInfo + ".deeez");
	cout << "\nIngridients for the selected food are:";
	if (checkFile.is_open())
	{
		while (getline(checkFile, ingrInfo)) {
			// Output the text from the file
			cout << ingrInfo << "\n";
		}
		checkFile.close();
		line();
	}
	else {
		cout << "\nUnable to open file\n";
		line();
	}
	return false;
}

bool viewOrder() {
	string pageLine;
	ifstream fileOpen ("./registeredAccounts/currOrder.deeez");
	if (fileOpen.is_open()) 
	{
		while (getline(fileOpen, pageLine)) {
			// Output the text from the file
			cout << pageLine << "\n"; 
		}
		fileOpen.close(); 
	}
	else {
		cout << "\nUnable to open file\n";
	}
	return 0;
}

void menu()
{
	cout << "[F]ood menu\n[V]iew order\n[L]og in to Account\n[R]egister Account\n[E]xit\n\ninput: ";
}

void line()
{
	for (int i = 0; i < 50; i++)
	{
		cout << "~";
	}
	cout << "\n";
}