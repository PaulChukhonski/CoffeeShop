#include <iostream>
#include <conio.h>
using namespace std;
#define MENU_CASES_NUM 4
#define COFFEE_CASES_NUM 4
#define ADMIN_CASES_NUM 5
#define ENTER 13

#define ESPRESSO_PRICE 2.50
#define CAPPUCCINO_PRICE 1.60
#define LATTE_PRICE 3.10

#define PIN 1234

void showMainMenu(double userBalance);
void showCoffeeMenu(double userBalance);
void showAdminMenu();
void pauseConsole();
void showUserBalance(double userBalance);

int getChoice();
void showIncorrectChoiceMessage(int num);

double depositeMoney(double userBalance);
bool isDepositedMoneyCorrect(double depositedMoney);

bool isEnoughMoneyToBuy(double userBalance, double coffeePrice);

int inputPIN(int pin);
bool isPinValid(int pin);

int addCups(int addedCups);
bool isNumberAddedCupsCorrect(int addedCups);

int main()
{
	int cups = 7, addedCups = 0, pin = 0, countPinInput = 0, menuChoice, coffeeChoice, adminChoice;
	double userBalance = 0.0, depositedMoney = 0.0, shopBalance = 0.0;
	bool mainMenu = true, coffeeMenu, adminMenu;
	
	while(mainMenu)
	{
		showMainMenu(userBalance);
		menuChoice = getChoice();
		
		switch(menuChoice)
		{
			case 1:
                if(cups <= 0) {
                    cout << "Sorry we don't have cups. Contact service, please." << endl;
                } else {
                    depositedMoney = depositeMoney(depositedMoney);

                    while (!isDepositedMoneyCorrect(depositedMoney)) {
                        cout << "Deposited money cannot be less or equal to 0." << endl;

                        depositedMoney = depositeMoney(depositedMoney);
                    }

                    userBalance += depositedMoney;
                    shopBalance += depositedMoney;
                }

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
						    if(cups <= 0)
                            {
                                cout << "Sorry we don't have cups. Contact service, please." << endl;
                            } else if(isEnoughMoneyToBuy(userBalance, ESPRESSO_PRICE))
                            {
                                userBalance -= ESPRESSO_PRICE;
                                cups--;
                                cout << "Take your ESPRESSO!" << endl;
                            } else
                            {
                                cout << "Not enough money! Your balance: " << userBalance << ". Coffee price: " << ESPRESSO_PRICE << "." << endl;
                                cout << "To buy, you need to deposit " << ESPRESSO_PRICE - userBalance << " BYN more" << endl;
                            }
							break;
						case 2:
                            if(cups <= 0)
                            {
                                cout << "Sorry we don't have cups. Contact service, please." << endl;
                            } else if(isEnoughMoneyToBuy(userBalance, CAPPUCCINO_PRICE))
                            {
                                userBalance -= CAPPUCCINO_PRICE;
                                cups--;
                                cout << "Take your CAPPUCCINO!" << endl;
                            } else
                            {
                                cout << "Not enough money! Your balance: " << userBalance << ". Coffee price: " << CAPPUCCINO_PRICE << "." << endl;
                                cout << "To buy, you need to deposit " << CAPPUCCINO_PRICE - userBalance << " BYN more" << endl;
                            }
                            break;
						case 3:
                            if(cups <= 0)
                            {
                                cout << "Sorry we don't have cups. Contact service, please." << endl;
                            } else if(isEnoughMoneyToBuy(userBalance, LATTE_PRICE))
                            {
                                userBalance -= LATTE_PRICE;
                                cups--;
                                cout << "Take your LATTE!" << endl;
                            } else
                            {
                                cout << "Not enough money! Your balance: " << userBalance << ". Coffee price: " << LATTE_PRICE << "." << endl;
                                cout << "To buy, you need to deposit " << LATTE_PRICE - userBalance << " BYN more" << endl;
                            }
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
				pin = inputPIN(pin);
                adminMenu = isPinValid(pin);

                if(!adminMenu && countPinInput < 2)
                {
                    cout << "PIN isn't correct!" << endl;
                    countPinInput++;
                    cout << "You have " << 2 - countPinInput << " attempts." << endl;
                }
                if (countPinInput >= 2)
                {
                    cout << "Coffee Shop is locked. Contact service, please." << endl;
                    return 0;
                }

				while(adminMenu)
				{
					showAdminMenu();
					adminChoice = getChoice();
					
					switch(adminChoice)
					{
						case 1:
						    cout << "Coffee shop balance: " << shopBalance << endl;
							break;
						case 2:
                            cout << "Current number of cups: " << cups << endl;
							break;
						case 3:
						    cout << shopBalance << " BYN was received." << endl;
                            shopBalance = 0;
							break;
						case 4:
                            addedCups = addCups(addedCups);

                            if(!isNumberAddedCupsCorrect(addedCups))
                            {
                                cout << "Added number of cups must be more than 0" << endl;
                                break;
                            } else cups += addedCups;

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

void pauseConsole()
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

double depositeMoney(double sum)
{
    cout << "Deposit money: ";
    cin >> sum;

    return sum;
}

bool isDepositedMoneyCorrect(double depositedMoney)
{
    if(depositedMoney <= 0) {
        return false;
    } return true;
}

bool isEnoughMoneyToBuy(double userBalance, double coffeePrice)
{
    if (coffeePrice > userBalance) {
        return false;
    } return true;
}

int inputPIN(int pin)
{
    cout << "Input PIN to enter service panel: ";
    cin >> pin;

    return pin;
}

bool isPinValid(int pin)
{
    if(pin == PIN)
    {
        return true;
    } return false;
}

int addCups(int addedCups)
{
    cout << "How many cups do want to add?: ";
    cin >> addedCups;

    return addedCups;
}

bool isNumberAddedCupsCorrect(int addedCups)
{
    if (addedCups <= 0) {
        return false;
    } return true;
}
