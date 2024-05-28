#include <iostream>
#include <iomanip>
#include <string.h>
#include <unistd.h>
#include <conio.h>
using namespace std;

// FUNCTION
void guest();
void adminLogin();
void endProgram();
double calcRide(int);
double calcFood(char, char, int);
void receipt();
void adminMenu();
void totalCust();
void totalFoodSales();
void allInfo();

// GLOBAL VARIABLE
char nationality;
int totalChildren = 0, totalAdult = 0, totalSeniorCitizen = 0;
double totalFood = 0, totalRide = 0, totalPayment = 0;

int main()
{
	char code;
	int age;
	
	restart:
	
	cout<<"+---------------------------------------+"<<endl;
	cout<<"|  WELCOME TO GSG ONLINE TICKET SYSTEM  |"<<endl;
	cout<<"|        LOGIN AS :                     |"<<endl;
	cout<<"+----+----------------------------------+"<<endl;
	cout<<"| 1. |   GUEST                          |"<<endl;
	cout<<"| 2. |   ADMIN                          |"<<endl;
	cout<<"+----+----------------------------------+"<<endl;
	cout<<"| X  |   TERMINATE                      |"<<endl;
	cout<<"+----+----------------------------------+"<<endl<<endl;
	
	cout<<" Please enter code : ";
	cin>>code;
	
	if(code == '1')
	{
		system("cls");
		guest();
	}
	else if(code == '2')
	{
		system("cls");
		adminLogin();
	}
	else if(toupper(code) == 'X')
	{
		system("cls");
		endProgram();
	}
	else
	{
		cout<<"Please enter a valid code!"<<endl;
		sleep(1);
		system("cls");
		goto restart;
	}
	
	return 0;
}

void guest()
{
		
	double height, totFeeRide = 0, totPayFood = 0, finalPay = 0;;
	char proceed, set, code, member;
	string name;
	int qty, memberCode, age, children = 0, adult = 0, seniorCitizen = 0;
	
	cout<<"+---------------------------------------+"<<endl;
	cout<<"|              GUEST LOGIN              |"<<endl;
	cout<<"+---------------------------------------+"<<endl;
	cout<<"Please enter your name : ";
	cin>>name;
	system("cls");
    
    addTicket:
    
	cout<<"+------------------------------------------+"<<endl;
	cout<<"|  NO. |         LIST OF RIDES             |"<<endl;
	cout<<"+------+-----------------------------------+"<<endl;
	cout<<"|  1.  |    SCREAMING SWING                |"<<endl;
	cout<<"|  2.  |    STAR FLYER                     |"<<endl;
	cout<<"|  3.  |    ROLLER COASTER                 |"<<endl;
	cout<<"|  4.  |    TEA CUPS                       |"<<endl;
	cout<<"|  5.  |    BUNGEE SWINGS                  |"<<endl;
	cout<<"|  6.  |    HAUNTED HOUSE                  |"<<endl;
	cout<<"|  7.  |    CHOO CHOO TRAIN                |"<<endl;
	cout<<"|  8.  |    BUMPER CAR                     |"<<endl;
	cout<<"|  9.  |    FERRIS WHEEL                   |"<<endl;
	cout<<"+------+-----------------------------------+"<<endl<<endl;
	
	cout<<"+------------------------------------------+"<<endl;
	cout<<"|               LIST OF PRICES             |"<<endl;
	cout<<"+--------------+---------------------------+"<<endl;
	cout<<"|              |          PRICE            |"<<endl;
	cout<<"|      AGE     +-----------+---------------+"<<endl;
	cout<<"|              | MALAYSIAN | NON-MALAYSIAN |"<<endl;
	cout<<"+--------------+-----------+---------------+"<<endl;
	cout<<"|    4 to 12   |   RM45    |    RM90       |"<<endl;
	cout<<"|   13 to 59   |   RM75    |    RM150      |"<<endl;
	cout<<"| 60 and above |   RM30    |    RM60       |"<<endl;
	cout<<"+--------------+-----------+---------------+"<<endl;
	cout<<"| FREE ENTERANCE FOR KID UNDER 4 YEARS OLD |"<<endl;
	cout<<"+------------------------------------------+"<<endl<<endl;

	cout<<"+------------------------------------------+"<<endl;
	cout<<"	        Welcome, "<<name<<endl;
	cout<<"+------------------------------------------+"<<endl;
	cout<<"|    ONLY AVAILABLE FOR CUSTOMER(S) AGE    |"<<endl;
	cout<<"|    ABOVE 4 YEARS AND ABOVE 120cm ! !     |"<<endl;
	cout<<"+------------------------------------------+"<<endl<<endl;
	
	cout<<"Enter nationality (M: Malaysian , N: Non-Malaysian): ";
	cin>>nationality;
	while(toupper(nationality) != 'M' && toupper(nationality) != 'N')
	{
		cout<<"Invalid Input."<<endl;
		cout<<"Enter nationality (M: Malaysian , N: Non-Malaysian): ";
		cin>>nationality;
	}
	
	cout<<"Enter height(cm): ";
	cin>>height;
	
	cout<<"Enter age: ";
	cin>>age;
	
	if(height >= 120 && age >= 4)
	{
		totFeeRide = totFeeRide + calcRide(age);
		
		if(age >= 4 && age <= 12)
		{
			children++;
			totalChildren = totalChildren + children;
		}
		else if(age >= 13 && age <= 59 )
		{
			adult++;
			totalAdult = totalAdult + adult;
		}
		else if(age >= 60)
		{
			seniorCitizen++;
			totalSeniorCitizen = totalSeniorCitizen + seniorCitizen;
		}
	}
	else
	{
		cout<<"\nTICKET NOT AVAILABLE FOR PURCHASE!"<<endl;
		sleep(3);
		system("cls");
		goto addTicket;
	}
	
	cout<<"\n\nEnter [Y] to add more ticket or [N] to proceed: ";
	cin>>proceed;
	
	if(toupper(proceed) == 'Y')
	{
		system("cls");
		goto addTicket;
	}
	else
	{
		cout<<"\n+------------------------------------------+"<<endl;
		cout<<"\nEnter [Y] for food package or [N] to proceed: ";
		cin>>proceed;
	}
	
	if(toupper(proceed) == 'Y')
	{
		system("cls");
		do{
		
			cout<<"+------------------------------------------+------------------------------------------+"<<endl;
			cout<<"|              SINGLE SET                  |                 COMBO SET                |"<<endl;
			cout<<"+------+-------------------------+---------+------+-------------------------+---------+"<<endl;
			cout<<"| CODE | DETAILS                 |PRICE(RM)| CODE |  DETAILS                |PRICE(RM)|"<<endl;
			cout<<"+------+-------------------------+---------+------+-------------------------+---------+"<<endl;
			cout<<"|  A   |  HAMBURGER              |  15.95  |  A   |  HAMBURGER + PEPSI      |  19.95  |"<<endl;
			cout<<"|  B   |  CHEESY CORNDOG         |  13.80  |  B   |  CHEESY CORNDOG + COKE  |  17.80  |"<<endl;
			cout<<"|  C   |  CHURROS                |  11.90  |  C   |  CHURROS + HOT CHOCO    |  15.90  |"<<endl;
			cout<<"|  D   |  CHICKEN NUGGET         |  13.99  |  D   |  CHICKEN NUGGET + FANTA |  17.99  |"<<endl;
			cout<<"+------+-------------------------+---------+------+-------------------------+---------+"<<endl<<endl;
	
			cout<<"Enter [S] for SINGLE SET or [C] for COMBO SET: ";
			cin>>set;	
			while(toupper(set) != 'S' && toupper(set) != 'C')
			{
				cout<<"Invalid Input."<<endl;
				cout<<"Enter [S] for SINGLE SET or [C] for COMBO SET: ";
				cin>>set;
			}
	
			cout<<"Enter code: ";
			cin>>code;
			while(toupper(code) != 'A' && toupper(code) != 'B' && toupper(code) != 'C' && toupper(code) != 'D')
			{
				cout<<"Invalid Input."<<endl;
				cout<<"Enter code: ";
				cin>>code;
			}
	
			cout<<"Enter quantity: ";
			cin>>qty;
	
			totPayFood = totPayFood + calcFood(set, code, qty);
	
			cout<<"\n\nEnter [Y] to add more or [N] to proceed: ";
			cin>>proceed;
		
			system("cls");
		}while(toupper(proceed) == 'Y');
	}
	
	system("cls");
	
	cout<<"+--------+---------------------------------+"<<endl;
	cout<<"|  CODE  |        PAYMENT METHOD           |"<<endl;
	cout<<"+--------+---------------------------------+"<<endl;
	cout<<"|   A    |  CREDIT CARD & DEBIT CARD       |"<<endl;
	cout<<"|   B    |  e-Wallet                       |"<<endl;
	cout<<"|   C    |  VISA                           |"<<endl;
	cout<<"+--------+---------------------------------+"<<endl;
	cout<<"|      MEMBERS CAN GET 15% DISCOUNT !!     |"<<endl;
	cout<<"+------------------------------------------+"<<endl<<endl;
	
	cout<<"Enter [Y] if you have MEMBERSHIP or [N] if not: ";
	cin>>member;
	
	if(toupper(member) == 'Y')
	{
		cout<<"Please enter 8 digit MEMBERSHIP code: ";
		cin>>memberCode;
		
		totalFood = totalFood + (totPayFood - (totPayFood * 0.15));
		totalRide = totalRide + (totFeeRide - (totFeeRide * 0.15));
		finalPay = (totFeeRide + totPayFood) - ((totFeeRide + totPayFood) * 0.15);
		
		cout<<"\nEnter code for payment: ";
		cin>>code;
		if(toupper(code) != 'A' && toupper(code) != 'B' && toupper(code) != 'C')
		{
			cout<<"Invalid input."<<endl;
			cout<<"\nEnter code for payment: ";
			cin>>code;
		}
		
		cout<<"\n\nProcessing payment .";
		sleep(1);
		cout<<" .";
		sleep(1);
		cout<<" ."<<endl;
		sleep(1);
		cout<<"Payment completed."<<endl<<endl;
		
		cout<<"press [ENTER] to proceed ";
		getch();
		system("cls");
	}
	else
	{
		finalPay = totFeeRide + totPayFood;
		totalRide = totalRide + totFeeRide;
		totalFood = totalFood + totPayFood;
		
		cout<<"\nEnter code for payment: ";
		cin>>code;
		if(toupper(code) != 'A' && toupper(code) != 'B' && toupper(code) != 'C')
		{
			cout<<"Invalid input."<<endl;
			cout<<"\nEnter code for payment: ";
			cin>>code;
		}
		
		cout<<"Processing payment .";
		sleep(1);
		cout<<" .";
		sleep(1);
		cout<<" ."<<endl;
		sleep(1);
		cout<<"Payment completed."<<endl<<endl;
		
		cout<<"press [ENTER] to proceed ";
		getch();
		system("cls");
	}

	cout<<"+------------------------------------------+"<<endl;
	cout<<"|                 RECEIPT                  |"<<endl;
	cout<<"+------------------------------------------+"<<endl;
	cout<<"     Children       : "<< children <<endl;
	cout<<"     Adult          : "<< adult <<endl;
	cout<<"     Senior citizen : "<< seniorCitizen <<endl;
	cout<<"+------------------------------------------+"<<endl;
	cout<<fixed<<setprecision(2);
	cout<<"     Total fee      : RM"<< totFeeRide <<endl;
	cout<<"     Total food pay : RM"<< totPayFood <<endl<<endl;
	if(toupper(member) == 'Y')
		cout<<"     15% DISCOUNT"<<endl;
	cout<<"     Total pay      : RM"<< finalPay <<endl;
	cout<<"+------------------------------------------+"<<endl<<endl;
	
	totalPayment = totalPayment + finalPay;
	
	cout<<"Press [ENTER] back to main menu";
	getch();
	system("cls");
	main();
}

//				CALCULATION

double calcRide(int age)
{
	double price;
	
	if(age >= 4 && age <= 12)
	{
		if(toupper(nationality) == 'M')
		{
			price = 45.00;
		}
		else
		{
			price = 90.00;
		}
	}
	else if(age >= 13 && age <= 59 )
	{
		if(toupper(nationality) == 'M')
		{
			price = 75.00;
		}
		else
		{
			price = 150.00;
		}
	}
	else if(age >= 60)
	{
		if(toupper(nationality) == 'M')
		{
			price = 75.00;
		}
		else
		{
			price = 150.00;
		}
	}
	
	return price;
}

double calcFood(char set, char code, int qty)
{
	double price;
	
	if(toupper(set) == 'S')
	{
		if(toupper(code) == 'A')
		{
			price = 15.95;
		}
		else if(toupper(code) == 'B')
		{
			price = 13.80;
		}
		else if(toupper(code) == 'C')
		{
			price = 11.90;
		}
		else if(toupper(code) == 'D')
		{
			price =13.99;
		}
	}
	else if(toupper(set) == 'C')
	{
		if(toupper(code) == 'A')
		{
			price = 19.95;
		}
		else if(toupper(code) == 'B')
		{
			price = 17.80;
		}
		else if(toupper(code) == 'C')
		{
			price = 15.90;
		}
		else if(toupper(code) == 'D')
		{
			price =17.99;
		}
	}
	
	return  price * qty;
}

//				ADMIN

void adminLogin()
{
	string username, password;
	int error = 0;
	
	cout<<"+------------------------------------------+"<<endl;
	cout<<"|              ADMIN LOGIN                 |"<<endl;
	cout<<"+------------------------------------------+"<<endl<<endl;
	
	cout<<"Enter Admin Username: ";
	cin>>username;
	cout<<"Enter password: ";
	cin>>password;
	while(username != "GSG@Admin123" || password != "GSG@AdminPass")
	{
		if(error == 3)
		{
			system("cls");
			main();
		}
		error++;
		cout<<"\nInvalid USERNAME or PASSWORD."<<endl;
		cout<<"Attempt left: "<< 4 - error <<endl;
		cout<<"Enter Admin Username: ";
		cin>>username;
		cout<<"Enter password: ";
		cin>>password;
	}
	
	system("cls");
	adminMenu();
}

void adminMenu()
{
	char code;
	
	restart:
	
	cout<<"+------------------------------------------+"<<endl;
	cout<<"|               ADMIN MENU                 |"<<endl;
	cout<<"+------+-----------------------------------+"<<endl;
	cout<<"|  1.  |  CHECK TOTAL CUSTOMER             |"<<endl;
	cout<<"|  2.  |  CHECK TOTAL FOOD SALES           |"<<endl;
	cout<<"|  3.  |  SHOW ALL INFORMATIONS            |"<<endl;
	cout<<"+------+-----------------------------------+"<<endl;
	cout<<"|  X.  |  BACK TO MAIN MENU                |"<<endl;
	cout<<"+------+-----------------------------------+"<<endl<<endl;
	
	cout<<"Enter code: ";
	cin>>code;
	
	if(code == '1')
	{
		system("cls");
		totalCust();
	}
	else if(code == '2')
	{
		system("cls");
		totalFoodSales();
	}
	else if(code == '3')
	{
		system("cls");
		allInfo();
	}
	else if(toupper(code) == 'X')
	{
		system("cls");
		main();
	}
	else
	{
		cout<<"Please enter a valid code!"<<endl;
		sleep(1);
		system("cls");
		goto restart;
	}
}

void totalCust()
{
	cout<<"+------------------------------------------+"<<endl;
	cout<<"|              TOTAL CUSTOMERS             |"<<endl;
	cout<<"+------------------------------------------+"<<endl<<endl;
	
	cout<<"Total Children       : "<< totalChildren <<endl;
	cout<<"Total Adult          : "<< totalAdult <<endl;
	cout<<"Total Senior Citizen : "<< totalSeniorCitizen <<endl;
	cout<<"Total Customers      : "<< totalChildren + totalAdult + totalSeniorCitizen <<endl<<endl;
	cout<<fixed<<setprecision(2);
	cout<<"Total Fees gathered  : RM"<< totalRide <<endl<<endl;	
	
	cout<<"Press [ENTER] to continue";
	getch();
	system("cls");
	adminMenu();
}

void totalFoodSales()
{
	cout<<"+------------------------------------------+"<<endl;
	cout<<"|             TOTAL FOOD SALES             |"<<endl;
	cout<<"+------------------------------------------+"<<endl<<endl;
	
	cout<<fixed<<setprecision(2);
	cout<<"Total food sales: RM"<< totalFood <<endl<<endl;
	
	cout<<"Press [ENTER] to continue";
	getch();
	system("cls");
	adminMenu();
}

void allInfo()
{
	cout<<"+------------------------------------------+"<<endl;
	cout<<"|             ALL INFORMATIONS             |"<<endl;
	cout<<"+------------------------------------------+"<<endl<<endl;
	
	cout<<"Total Children       : "<< totalChildren <<endl;
	cout<<"Total Adult          : "<< totalAdult <<endl;
	cout<<"Total Senior Citizen : "<< totalSeniorCitizen <<endl;
	cout<<"Total Customers      : "<< totalChildren + totalAdult + totalSeniorCitizen <<endl<<endl;
	cout<<fixed<<setprecision(2);
	cout<<"Total ride sales  : RM"<< totalRide <<endl;
	cout<<"Total food sales: RM"<< totalFood <<endl<<endl;
	
	cout<<"Total all : RM"<< totalPayment <<endl<<endl;
	
	cout<<"Press [ENTER] to continue";
	getch();
	system("cls");
	adminMenu();
}

//				END PROGRAM

void endProgram()
{
	char option; 
	
	restart:
	
	cout<<"+------------------------------------------+"<<endl;
	cout<<"|           TERMINATE PROGRAM ?            |"<<endl;
	cout<<"+------------------------------------------+"<<endl<<endl;
	
	cout<<"Press [Y] to TERMINATE or [N] to CANCEL: ";
	cin>>option;
	
	if(toupper(option) == 'Y')
	{
		terminate();
	}
	else if(toupper(option) == 'N')
	{
		system("cls");
		main();
	}
	else
	{
		cout<<"Please enter a valid input!"<<endl;
		sleep(1);
		system("cls");
		goto restart;
	}
}
