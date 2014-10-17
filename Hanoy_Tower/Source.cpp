#include <iostream>
#include <ctime>
#include <windows.h>
#include <conio.h>

using namespace std;

const int FieldSize = 9;
int FieldPlr[FieldSize][FieldSize] = { 0 }, FieldNPC[FieldSize][FieldSize] = { 0 };
HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);//дескриптор вывода
HANDLE hIn = GetStdHandle(STD_INPUT_HANDLE);//дескриптор ввода

void print_field(COORD StartPoint = { 0, 0 }){

	SetConsoleCursorPosition(hOut, StartPoint);

	cout << ' ';
	for (int i = 0; i < FieldSize; i++)
	{
		cout << ' ' << (char)(0x80 + i);
	}

	StartPoint.Y++;
	SetConsoleCursorPosition(hOut, StartPoint);

	for (int i = 0; i <= 2 * FieldSize; i++)
	{
		for (int j = 0; j <= 2 * FieldSize; j++)
		{
			if (i % 2 == 1 && j == 0)
				cout << i / 2;
			else if (i % 2 == 0 && j == 0)
				cout << ' ';

			if (i == 0 && j == 0) // left top corner
				cout << (char)0xC9;
			else if (i == 0 && j == 2 * FieldSize) // right top corner
				cout << (char)0xBB;
			else if (i == 2 * FieldSize && j == 0) // left bottom corner
				cout << (char)0xC8;
			else if (i == 2 * FieldSize && j == 2 * FieldSize) //right bottom corner
				cout << (char)0xBC;
			else if (i == 0 && j % 2 == 0) // middle top 
				cout << (char)0xD1;
			else if (i == 2 * FieldSize && j % 2 == 0) // middle bottom
				cout << (char)0xCF;
			else if (i % 2 == 0 && j == 0) // middle left 
				cout << (char)0xC7;
			else if (i % 2 == 0 && j == 2 * FieldSize) // middle right
				cout << (char)0xB6;
			else if (i == 0 || i == 2 * FieldSize) // top & bottom line
				cout << (char)0xCD;
			else if (j == 0 || j == 2 * FieldSize) // left & right line
				cout << (char)0xBA;
			else if (i % 2 == 0 && j % 2 == 0) // crosshair
				cout << (char)0xC5;
			else if (i % 2 == 1 && j % 2 == 0) // middle vertical lines
				cout << (char)0xB3;
			else if (i % 2 == 0 && j % 2 == 1) // middle horizontal lines
				cout << (char)0xC4;

			else if (FieldPlr[i / 2][j / 2] != -1)
				//cout << '*';
				cout << FieldPlr[i / 2][j / 2];
			else
				cout << '*';


		}
		//cout << endl;
		StartPoint.Y++;
		SetConsoleCursorPosition(hOut, StartPoint);

	}
}

void InitPlrField()
{
	for (int i = 0; i < FieldSize; i++)
	{
		for (int j = 0; j < FieldSize; j++)
		{
			FieldPlr[i][j] = rand() % 10;
		}
	}
}


void main()
{
	srand((int)(time(0)));

	COORD c1 = { 5, 4 }, c2 = { 37, 4 };
	CONSOLE_CURSOR_INFO cInfo = { 0, 0 };//структура с настройками курсора 100-размер, 0-невидимый
	SetConsoleCursorInfo(hOut, &cInfo);
	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
	InitPlrField();
	print_field(c1);
	print_field(c2);

	SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
	for (int i = 0; i < 100; i++)
	{
		c1.X = rand() % 70;
		c1.Y = rand() % 28;
		SetConsoleCursorPosition(hOut, c1);
		cout << (char)1;
		Sleep(150);
	}
	c1 = { 0, 27 };

	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
	SetConsoleCursorPosition(hOut, c1);
}