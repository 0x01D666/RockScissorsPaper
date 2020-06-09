#include<iostream>
#include<string>
#include<ctime>
#include<Windows.h>
#include <conio.h>
using namespace std;

/* Macro definition for functions defining a program header */
#define SetCmdTitle SetConsoleTitleA

/* Getting a standard output window (windows console) */
HANDLE stdHNDL = GetStdHandle(STD_OUTPUT_HANDLE);

/* Console colors */
enum ConsoleColor
{
	COLOR_BLACK = 0,
	COLOR_BLUE = 1,
	COLOR_GREEN = 2,
	COLOR_CYAN = 3,
	COLOR_RED = 4,
	COLOR_MAGENTA = 5,
	COLOR_BROWN = 6,
	COLOR_LIGHT_GRAY = 7,
	COLOR_DARK_GRAY = 8,
	COLOR_LIGHT_BLUE = 9,
	COLOR_LIGHT_GREEN = 10,
	COLOR_LIGHT_CYAN = 11,
	COLOR_LIGHT_RED = 12,
	COLOR_LIGHT_MAGENTA = 13,
	COLOR_YELLOW = 14,
	COLOR_WHITE = 15
};

/* Function prototype for console cleaning */
inline void ClearConsoleLog(void);

/* 'DIES_IRAE' (twitter: @DiesIra82600636 / github: Dies1rae) KEYB CLEANER */
void ClearKeyboardBuffer(void) 
{
	while (_kbhit()) 
	{
		_getche();
	}
}

/* Random gesture generation for computer */
int GenerateRandomSign(const int MIN_RANGE = 1, const int MAX_RANGE = 3)
{
	srand(static_cast<unsigned int>(time(NULL)));
	int randomSign = (MIN_RANGE + rand() % (MAX_RANGE - MIN_RANGE + 1));
	return randomSign;
}

/* The structure that stores the variables that are responsible for the names of game gestures */
struct MySign
{
	const string strRock = "ROCK!";
	const string strScissors = "SCISSORS!";
	const string strPaper = "PAPER!";
};
MySign ms;

/* The structure that stores the variables that are responsible for the players */
struct Players
{
	int user;
	string username;
	int computer;

	Players() 
	{
		this->user = 0;
		this->username = "";
		this->computer = 0;
	}

	void SetUsername(string name) 
	{
		this->username = name;
	}
};
Players* players = new Players();

/* Drawing a table listing game gestures */
void DrawTable(void)
{
	SetConsoleTextAttribute(stdHNDL, COLOR_LIGHT_RED);
	cout << "\t\t\t\t\t +-------------------------------+" << endl;
	cout << "\t\t\t\t\t | 1.Rock | 2.Scissors | 3.Paper |" << endl;
	cout << "\t\t\t\t\t +-------------------------------+" << endl;
}

/* Player Turn */
int UserThrow(int& user)
{
	SetConsoleTextAttribute(stdHNDL, COLOR_WHITE);
	cout << " You choose: ";
	switch (user)
	{
	case 1:
		cout << ms.strRock << endl;
		break;
	case 2:
		cout << ms.strScissors << endl;
		break;
	case 3:
		cout << ms.strPaper << endl;
		break;
	default:
		SetConsoleTextAttribute(stdHNDL, COLOR_RED);
		cout << "Invalid sign!" << endl;
		break;
	}

	return user;
}

/* Computer running */
int ComputerThrow(int& computer)
{
	computer = GenerateRandomSign();
	switch (computer)
	{
	case 1:
		cout << ms.strRock << endl;
		break;
	case 2:
		cout << ms.strScissors << endl;
		break;
	case 3:
		cout << ms.strPaper << endl;
		break;
	default:
		SetConsoleTextAttribute(stdHNDL, COLOR_RED);
		cout << "Invalid sign!" << endl;
		break;
	}

	return computer;
}

/* Winner selection */
void SelectWinner(int& user, int& computer, string* username)
{
	if (user == computer) 
	{
		SetConsoleTextAttribute(stdHNDL, COLOR_YELLOW);
		cout << "\t\t\t\t\t\t\tDRAW!" << endl;
	}
	else if (user == 1 && computer == 2 || user == 2 && computer == 3 || user == 3 && computer == 1)
	{
		SetConsoleTextAttribute(stdHNDL, COLOR_LIGHT_GREEN);
		cout << "\t\t\t\t\t\t   " << (*username) << " WIN!" << endl;
	}
	else 
	{
		SetConsoleTextAttribute(stdHNDL, COLOR_LIGHT_MAGENTA);
		cout << "\t\t\t\t\t\t    Computer WINS!" << endl;
	}
}

/* User information */
void DrawInfoAboutUser(void)
{
	/* Ввод данных о пользователе */
	SetConsoleTextAttribute(stdHNDL, COLOR_WHITE);
	cout << " Hey, what's your name?" << endl;
	cout << " My name is ";
	string tmp_username;
	cin >> tmp_username;

	ClearConsoleLog();
	players->SetUsername(tmp_username);
	SetConsoleTextAttribute(stdHNDL, COLOR_WHITE);
	cout << " You are welcome, " << tmp_username << "!\n Enjoy the game!" << endl;
	cout << endl;
}

/* Game data initialization */
void Initialization()
{
	/* The choice of the beginning of the game or exit from the program */
	SetConsoleTextAttribute(stdHNDL, COLOR_WHITE);
	cout << " Are you ready to start the game?" << endl;
	cout << " Press 'F1' to start \n Press 'F2' to quit" << endl;

	for (/*int i = 0*/; /*i < 1*/; /*i++*/)
	{
		if (GetAsyncKeyState(VK_F1) != 0)
		{
			/* Clear the screen from past data */
			ClearConsoleLog();

			/* Player Turn */
			players->user = 0;
			/* 'DIES_IRAE' (twitter: @DiesIra82600636 / github: Dies1rae) KEYB CLEANER */
			ClearKeyboardBuffer();
		
			DrawTable();
			SetConsoleTextAttribute(stdHNDL, COLOR_WHITE);
			cout << " Choose: ";
			cin >> players->user;
			UserThrow(players->user);

			cout << endl;

			/* Computer running */
			players->computer = 0;
			DrawTable();
			SetConsoleTextAttribute(stdHNDL, COLOR_WHITE);
			cout << " Computer choose: ";
			ComputerThrow(players->computer);
			break;
		}
		else if (GetAsyncKeyState(VK_F2) != 0)
		{
			/* Clear the screen from past data */
			ClearConsoleLog();

			/* Exit from the program */
			SetConsoleTextAttribute(stdHNDL, COLOR_WHITE);
			cout << " Thank you for the game! \n See you later!" << endl;
			exit(EXIT_SUCCESS);
			break;
		}
	}

	/* Selection of the winner according to the outcome of the game */
	SelectWinner(players->user, players->computer, &players->username);
}

/* Program entry point */
int main()
{
	/* Set the title for the window */
	SetCmdTitle("ROCK - SCISSORS - PAPER");

	/* Initialization of all data and their processing */
	DrawInfoAboutUser();
	Initialization();

	/* Choice for the user to continue / end the game */
	while (true)
	{
		cout << endl;
		string userChoice;
		SetConsoleTextAttribute(stdHNDL, COLOR_WHITE);
		cout << "\t\t\t\t    Do you wanna trying to play this game again?" << endl;
		cout << "\t\t\t\t\t\t    Yes \t No" << endl;
		cout << "\t\t\t\t\t\t     Your choice: ";
		cin >> userChoice;

		while (userChoice == "Yes" || userChoice == "YES" || userChoice == "yes")
		{
			if (userChoice != "YES" && userChoice != "yes" && userChoice != "Yes")
			{
				/* Clear the screen from past data */
				ClearConsoleLog();

				/* Exit from the program */
				SetConsoleTextAttribute(stdHNDL, COLOR_WHITE);
				cout << " Thank you for the game! \n See you later!" << endl;
				exit(EXIT_SUCCESS);
				break;
			}
			else
			{
				/* Clear the screen from past data */
				ClearConsoleLog();
				Initialization();
				break;
			}
		}

		if (userChoice != "YES" && userChoice != "yes" && userChoice != "Yes")
		{
			/* Clear the screen from past data */
			ClearConsoleLog();

			/* Exit from the program */
			SetConsoleTextAttribute(stdHNDL, COLOR_WHITE);
			cout << " Thank you for the game! \n See you later!" << endl;
			exit(EXIT_SUCCESS);
			break;
		}
	}

	system("pause");
	return NULL;
}

/* Function for cleaning the console */
inline void ClearConsoleLog(void)
{
	system("cls");
}
