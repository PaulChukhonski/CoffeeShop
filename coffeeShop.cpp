#include <iostream>
#include <conio.h>
using namespace std;
#define MENU_CASES_NUM 4
#define COFFEE_CASES_NUM 4
#define ADMIN_CASES_NUM 5
#define ENTER 13

void showMainMenu(double userBalance);
void showCoffeeMenu(double userBalance);
void showAdminMenu();
void pause();
void showUserBalance(double userBalance);

int getChoice();
void showIncorrectChoiceMessage(int num);

int main()
{
	int cups = 7, pin = 0, menuChoice, coffeeChoice, adminChoice; 
	double userBalance = 0.0, shopBalance = 0.0;
	bool mainMenu = true, coffeeMenu, adminMenu;
	
	while(mainMenu)
	{
		showMainMenu(userBalance);
		menuChoice = getChoice();
		
		switch(menuChoice)
		{
			case 1:
				break;
			case 2:
				coffeeMenu = true;
					
				while(coffeeMenu)
				{
					showCoffeeMenu(userBalance);
					coffeeChoice = getChoice();
					
					switch(coffeeChoice)
					{
						case 1:
							break;
						case 2:
			
							break;
						case 3:
							break;
						case 4:
							coffeeMenu = false;
							break;				
						default:
							showIncorrectChoiceMessage(COFFEE_CASES_NUM);
							break;		
					}
				}
				break;
			case 3:
				adminMenu = true;
				
				while(adminMenu)
				{
					showAdminMenu();
					adminChoice = getChoice();
					
					switch(adminChoice)
					{
						case 1:
							break;
						case 2:
			
							break;
						case 3:
							break;
						case 4:
							break;
						case 5:
							adminMenu = false;
							break;											
						default:
							showIncorrectChoiceMessage(ADMIN_CASES_NUM);
							break;		
					}
				}
				break;
			case 4:
				mainMenu = false;
				break;				
			default:
				showIncorrectChoiceMessage(MENU_CASES_NUM);
				break;		
		}
	}
	
	return 0;	
}

void showMainMenu(double userBalance)
{
	system("cls");
	cout << "Welcome to CoffeeShop!" << endl;
	cout << "------------------------" << endl;	
	showUserBalance(userBalance);		
	cout << "------------------------" << endl;	
	cout << "1. Deposit money" << endl;	
	cout << "2. Choose type of coffee" << endl;		
	cout << "3. Service" << endl;
	cout << "4. Exit from shop" << endl;	
	cout << "------------------------" << endl;		
}

void showCoffeeMenu(double userBalance)
{
	system("cls");
	cout << "Types of coffee!" << endl;
	cout << "--------------------" << endl;	
	showUserBalance(userBalance);		
	cout << "--------------------" << endl;
	cout << "1. Espresso" << endl;
	cout << "2. Cappuccino" << endl;
	cout << "3. Latte" << endl;
	cout << "4. Back to main menu" << endl;	
	cout << "--------------------" << endl;		
}

void showAdminMenu()
{
	system("cls");
	cout << "Admin panel!" << endl;
	cout << "--------------------------------" << endl;		
	cout << "1. Show current balance" << endl;
	cout << "2. Show current number of cups" << endl;
	cout << "3. Take money from shop" << endl;	
	cout << "4. Add cups" << endl;
	cout << "5. Back to main menu" << endl;	
	cout << "--------------------------------" << endl;			
}

void pause()
{
	do 
	{
		cout << "Press the Enter key to continue.";
	} while (getch() != ENTER);	
}

void showUserBalance(double userBalance)
{
	cout << "Current balance: " << userBalance << endl;
}

int getChoice()
{
	int choice;
	
	cout << "Your choice: ";
	cin >> choice;
	
	return choice;
}

void showIncorrectChoiceMessage(int num)
{
	cout << "Incorrect input. Enter number 1..." << num << "!" << endl;
	pause();
}
