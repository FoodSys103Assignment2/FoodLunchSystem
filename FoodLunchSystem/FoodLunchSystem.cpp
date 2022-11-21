// FoodLunchSystem.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

// Declearation of functions
void accountMenu(string ID);
string userLogin();
string registerUser();
bool foodMenu();
bool ingridentsList();
bool viewOrder();
void clearOrder(); 
void menu();
void line();

int main()
{
	clearOrder();
	string ID; 
	while (1)
	{
		line();
		cout << "Main Menu\n";
		if (!ID.empty())
		{
			cout << "\n\n\nCurrent User Is: " << ID << "\n";
		}
		else
		{
			cout << "\n\n\nNo User Signed In\n";
		}
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
				if (!foodMenu())
				{
					break;
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
			cout << "\n\n[C]lear order\n[E]xit\n\n";
				char clearCheck; 
				cin >> clearCheck; 
				if (clearCheck == 'c'){clearOrder();}
				else {
					break;
				}
				break;
		case'r':
			line();
			ID = registerUser();
			if (ID.empty())
			{
				cout << "User was already taken\n\n";
			}
			break;
		case'l':
			line();
			ID = userLogin();
			break;
		case's':
			accountMenu(ID);
			break;
		case'e':
			line();
			cout << "Exit\n\n";
			return 0;
			break;
		default:
			break;
		}
	}
}

// function for account settings
void accountMenu(string ID)
{
	string currentAccount = "./registeredAccounts/user-" + ID + ".deeez";
	fstream addfunds;
	addfunds.open(currentAccount, ios::app);

	string accountFunds;
	int accountInput;
	if (ID == "")
	{
		cout << "No user is currently signed in\n";
	}
	else
	{
		cout << "User:" << ID << "\n";
	}
	cout << "[1] Add funds to account\n[2] Billing info\n\nInput: ";
	cin >> accountInput;

	switch (accountInput)
	{
	case 1:
		cout << "Enter how much do you want to add to your funds: ";

		break;
	default:
		break;
	}
}

// function for logining into an existing account
string userLogin()
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
	return ID;
}

// function for registering an account
string registerUser()
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
		return "";
	}

	ofstream newFile;
	newFile.open(filename);
	if (!newFile.is_open())
	{
		return "";
	}
	newFile << "id:" << registeredID << "\npassword:" << registeredPassword;
	newFile.close();
	return registeredID;
}

// function for printing the menu of foods you can order
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
	return !(!(true));
}

// function for printing the spicific food items ingrediant file.
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

// function for viewing contents from the current order file.
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

// function for clearing contents of the current order file.
void clearOrder() {
	string clearing;
	ofstream clearOpen("./registeredAccounts/currOrder.deeez");
	if (clearOpen.is_open())
	{
		clearOpen.close();
	}
	else {
		cout << "\nUnable to open file\n";
	}
}

// function for printing the main menu options.
void menu()
{
	cout << "[F]ood menu\n[V]iew order\n[L]og in to Account\n[R]egister Account\n[S]ettings\n[E]xit\n\ninput: ";
}

// function for printing a dividing line on screen.
void line()
{
	for (int i = 0; i < 50; i++)
	{
		cout << "~";
	}
	cout << "\n";
}