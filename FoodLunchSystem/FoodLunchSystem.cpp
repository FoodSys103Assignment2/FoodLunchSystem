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
bool payment(int totalFunds);
void menu();
void line();
bool drinksMenu();

int main()
{
	// Calls the funtion which clears the file storing the order
	clearOrder();
	string ID; 
	int totalFunds = 200;
	// while loop to for running the program until the user wants to end stop the application
	while (1)
	{
		int counter = 0;
		string arrayStorage[99];
		string fileLines;
		string fundLine;
		ifstream openTheFile("./registeredAccounts/user-" + ID + ".deeez");
		if (openTheFile.is_open())
		{
			while (getline(openTheFile, fileLines)) {
				arrayStorage[counter] = fileLines;
				counter++;
				fundLine = arrayStorage[2];
			}
			openTheFile.close();
		}
		try
		{
			totalFunds = stoi(fundLine);
		}
		catch (...)
		{
			cout << "break \"" << fundLine << "\"\n\n";
		}
		// Prints correct responses depending on if a user is signed in or not
		line();
		cout << "Main Menu \n";
		if (!ID.empty())
		{
			cout << "\n\n\nCurrent User Is: " << ID << "\n";
			cout << totalFunds << "\n";
		}
		else
		{
			cout << "\n\n\nNo User Signed In\n";
			cout << totalFunds << "\n";
		}
		line();

		// switch cases for navigation of the menu system to the correct functions
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
			cout << "\n\n[C]lear order\n[P]ay\n[E]xit\n\n";
				char clearCheck; 
				cin >> clearCheck; 
				if (clearCheck == 'c'){clearOrder();}
				else if (clearCheck == 'p')
				{
					payment(totalFunds);
				}
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
			clearOrder(); 
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

// function for displaying account settings and billing info.
void accountMenu(string ID)
{
	string currentAccount = "./registeredAccounts/user-" + ID + ".deeez";
	fstream addInfo;

	string accountInfo;
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
	
	if (accountInput == 1)
	{	
		cout << "Enter how much do you want to add to your funds: ";
		cin >> accountInfo;
		addInfo.open(currentAccount, ios::app);
		if (addInfo.is_open())
		{
			addInfo << "\n" << accountInfo << "\n";
			addInfo.close();
		}
	}
}

// function for logining into an existing account.
string userLogin()
{
loginStart:
	int line = 0;
	string userInfo[999];
	string info;
	string theusersId;
	cout << "Input ID:";
	string loginId;
	cin >> loginId;

	ifstream openfile("./registeredAccounts/user-" + loginId + ".deeez");
	if (openfile.is_open())
	{
		while (getline(openfile, info)) {
			// Output the text from the file
			userInfo[line] = info;
			line++;
			theusersId = userInfo[1];
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
		cout << "Welcome student " << loginId << "\n";
	}
	else
	{
		cout << "Wrong password try again\n";
		goto loginStart;
	}
	return loginId;
}

// function for registering an account of a new user.
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

// function for printing the menu of foods you can order.
bool foodMenu()
{
	string foodArray[] = { "Hot Dog, \t\t$5", "Chicken And Rice, \t$7", "Beans On Toast, \t$100", "Apple, \t\t$2",};

	cout << "Food Menu\n\n";
	for (int i = 0; i < 4; i++) {
		cout << i + 1 << " " << foodArray[i] << "\n";
	}
	
	cout << "\n[10] Ingredients menu\n[11] Drink Menu\n[12] Go back\n\nAdd item: ";
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
		drinksMenu();
	}
	else if (foodChoice == 11) 
	{
		return false;
	}
	return !(!(true));
}

//
bool drinksMenu()
{
	string drinkArray[8] = { "Coco-Cola 330ml, \t\t $2", "Coco-Cola 500ml, \t\t $3.5", "Sprite 330ml, \t\t $2", "Sprite 500ml, \t\t $3.5", "Fanta 330ml, \t\t\t $2", "Fanta 500ml, \t\t\t $3.5", "Mtn Dew 330ml, \t\t $2", "Mtn Dew 500ml, \t\t $3.5" };

	cout << "Drinks Menu\n\n";
	for (int i = 0; i < 8; i++)
	{
		cout << i + 1 << " " << drinkArray[i] << "\n";
	}

	cout << "\n[10] Go Back\n\nAdd item: ";
	int drinkChoice;
	cin >> drinkChoice;
	drinkChoice--;
	if (drinkChoice < 8 && drinkChoice >= 0){
		cout << "\n" << drinkArray[drinkChoice] << " added to order. \n";
		string orderAddDrink = "./registeredAccounts/currOrder.deeez";
		fstream dCurr;
		dCurr.open(orderAddDrink, ios::app);
		if (dCurr.is_open()){
			dCurr << drinkArray[drinkChoice] << "\n";
			dCurr.close();
		}
	}
	else if (drinkChoice == 9)
	{
		return false;
	}
	return true;
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
	cout << "\nIngridients for the selected food are:\n";
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

bool payment(int totalFunds) {
	cout << "\n\n";
	line();
	cout << "Payment\n\ntotal funds: " << totalFunds << "\n\n";
	return 0;
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