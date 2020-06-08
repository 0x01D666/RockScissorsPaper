#include<iostream>
#include<string>
#include<ctime>
#include<Windows.h>
using namespace std;

/* ���������������� ��� �������, �������� ��������� ��������� */
#define SetCmdTitle SetConsoleTitleA

/* �������� ������� ��� ������� ������� */
inline void ClearConsoleLog(void);

/* ��������� ���������� ����� ��� ���������� */
int GenerateRandomSign(const int MIN_RANGE = 1, const int MAX_RANGE = 3)
{
	srand(static_cast<unsigned int>(time(NULL)));
	int randomSign = ((rand() % MAX_RANGE) + MIN_RANGE);

	return randomSign;
}

/* ���������, �������� ����������, ������� �������� �� ������������ ������� ������ */
struct MySign
{
	const string strRock = "ROCK!";
	const string strPaper = "PAPER!";
	const string strScissors = "SCISSORS!";
};
MySign ms;

/* ���������, �������� ����������, ������� �������� �� ������� */
struct Players
{
	int user = 0;
	string username;
	int computer = 0;
};
Players players;

/* ��������� ������� � ������������� ������� ������ */
void DrawTable(void)
{
	cout << "\t\t\t\t\t +-------------------------------+" << endl;
	cout << "\t\t\t\t\t | 1.Rock | 2.Paper | 3.Scissors |" << endl;
	cout << "\t\t\t\t\t +-------------------------------+" << endl;
}

/* ��� ������ */
int UserThrow(int& user)
{
	switch (user)
	{
	case 1:
		cout << "You choose: " << ms.strRock << endl;
		break;
	case 2:
		cout << "You choose: " << ms.strPaper << endl;
		break;
	case 3:
		cout << "You choose: " << ms.strScissors << endl;
		break;
	default:
		cout << "Invalid sign!" << endl;
		break;
	}

	return user;
}

/* ��� ���������� */
int ComputerThrow(int& computer)
{
	computer = GenerateRandomSign();
	switch (computer)
	{
	case 1:
		cout << ms.strRock << endl;
		break;
	case 2:
		cout << ms.strPaper << endl;
		break;
	case 3:
		cout << ms.strScissors << endl;
		break;
	default:
		cout << "Invalid sign!" << endl;
		break;
	}

	return computer;
}

/* ����� ���������� */
void SelectWinner(int& user, int& computer, string* username)
{
	if (user == computer)
		cout << "\t\t\t\t\t\t DRAW!" << endl;
	else if (user == 1 && computer == 3)
		cout << "\t\t\t\t\t\t " << (*username) << " WIN!" << endl;
	else if (user == 3 && computer == 2) 
		cout << "\t\t\t\t\t\t " << (*username) << " WIN!" << endl;
	else if (user == 2 && computer == 1) 
		cout << "\t\t\t\t\t\t " << (*username) << " WIN!" << endl;
	else 
		cout << "\t\t\t\t\t\t Computer WINS!" << endl;
}

/* ���������� � ������������ */
void DrawInfoAboutUser(void)
{
	/* ���� ������ � ������������ */
	cout << "Hey, what's your name?" << endl;
	cout << "My name is ";
	cin >> players.username;

	ClearConsoleLog();
	cout << "You are welcome, " << players.username << "!\nEnjoy the game!" << endl;
	cout << endl;
}

/* ������������� ������� ������ */
void Initialization(void)
{
	/* ����� � ������ ���� ��� �� � ������ �� ��������� */
	cout << "You are ready to start the game?" << endl;
	cout << "Press 'F1' to start \nPress 'F2' to quit" << endl;

	for (/*int i = 0*/; /*i < 1*/; /*i++*/)
	{
		if (GetAsyncKeyState(VK_F1) != 0)
		{
			/* ������� ������ �� ������� ������ */
			ClearConsoleLog();

			/* ��� ������������ */
			players.user = 0;
			DrawTable();
			cout << "Choose: ";
			cin >> players.user;
			UserThrow(players.user);

			cout << endl;

			/* ��� ���������� */
			players.computer = 0;
			DrawTable();
			cout << "Computer choose: ";
			ComputerThrow(players.computer);
			break;
		}
		else if (GetAsyncKeyState(VK_F2) != 0)
		{
			/* ������� ������ �� ������� ������ */
			ClearConsoleLog();

			/* ����� �� ��������� */
			cout << "Thank you for the game! \n See you later!" << endl;
			exit(EXIT_SUCCESS);
			break;
		}
	}

	/* ����� ���������� �� ����� ���� */
	SelectWinner(players.user, players.computer, &players.username);
}

/* ����� ����� � ��������� */
int main()
{
	/* ������������� ��������� (��������) ��� ���� */
	SetCmdTitle("ROCK - PAPER - SCISSORS");

	/* ������������� ���� ������ � �� ��������� */
	DrawInfoAboutUser();
	Initialization();

	/* ����� ��� ������������ � ����������� / ��������� ���� */
	while (true)
	{
		string choice;
		cout << endl;
		cout << "Do you wanna trying to play this game again?" << endl;
		cout << "Yes \t No" << endl;
		cout << "Your choice: ";
		cin >> choice;

		if (choice != "YES" && choice != "yes" && choice != "Yes")
		{
			/* ������� ������ �� ������� ������ */
			ClearConsoleLog();

			/* ����� �� ��������� */
			cout << "Thank you for the game! \n See you later!" << endl;
			exit(EXIT_SUCCESS);
			break;
		}
		else
		{
			/* ������� ������ �� ������� ������ */
			ClearConsoleLog();
			Initialization();
			break;
		}
	}

	system("pause");
	return NULL;
}

/* ������� ��� ������� ������� */
inline void ClearConsoleLog(void)
{
	system("cls");
}