#include <Windows.h>
#include <iostream>
using namespace std;

HANDLE hOut_t = GetStdHandle(STD_OUTPUT_HANDLE);//дескриптор вывода
HANDLE hIn_t = GetStdHandle(STD_INPUT_HANDLE);//дескриптор ввода

void main_test()
{
	system("color 3f");
	int size = 10;
	int **pole = new int*[10];
	for (int i = 0; i < size; i++){
		pole[i] = new int[size];
		for (int j = 0; j < size; j++)
		{
			pole[i][j] = 0;
		}
	}

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cout << pole[i][j] << '\t';
		}
		cout << endl;
	}
	cout << endl;

	CONSOLE_CURSOR_INFO cInfo = { 100, 0 };//структура с настройками курсора 100-размер, 0-невидимый
	CONSOLE_SCREEN_BUFFER_INFO csbInfo;//
	INPUT_RECORD ir;
	DWORD x, consoleMode;
	SetConsoleCursorInfo(hOut_t, &cInfo);//устанавливает настройки курсора
	COORD c = { 0, 0 };
	COORD current = { 0, 0 };

	GetConsoleMode(hIn_t, &consoleMode);//запоминает текущий режим консоли в consoleMode

	while (1)
	{
		SetConsoleMode(hIn_t, ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT);//устанавливает режим консоли
		while (ReadConsoleInput(hIn_t, &ir, 1, &x))//считываем буфер действий консоли и помещает его в ir
		{
			if (ir.EventType == MOUSE_EVENT)
			{
				if (ir.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
				{
					//SetConsoleCursorPosition(hOut, ir.Event.MouseEvent.dwMousePosition);
					//SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_RED);
					//cout << '@';

					SetConsoleCursorPosition(hOut_t, c);
					current = ir.Event.MouseEvent.dwMousePosition;

					for (int i = 0; i <= size * 2; ++i)//пробежка по вертикали
					{
						for (int j = 0; j <= size * 2; ++j)//пробежка по горизонтали
						{
							if (i == current.Y && j == current.X&&current.Y % 2 == 1 && current.X % 2 == 1)
							{
								//cout << '*';
								SetConsoleTextAttribute(hOut_t, FOREGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_GREEN);//меняет цвет текста
								cout << char(1);
								SetConsoleTextAttribute(hOut_t, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_GREEN | BACKGROUND_BLUE);//меняет цвет текста
							}
							else
							if (i == 0 && j == 0)
								cout << char(0xDA);
							else if (i == 0 && j == size * 2)
								cout << char(0xBF);
							else if (j == 0 && i == size * 2)
								cout << char(0xC0);
							else if (j == size * 2 && i == size * 2)
								cout << char(0xD9);
							else if (i == 0 && j % 2 == 0)
								cout << char(0xc2);
							else if (i == size * 2 && j % 2 == 0)
								cout << char(0xc1);
							else if (j == 0 && i % 2 == 0)
								cout << char(0xc3);
							else if (j == size * 2 && i % 2 == 0)
								cout << char(0xB4);
							else if (j % 2 == 0 && i % 2 == 0)
								cout << char(0xc5);
							else if (j % 2 == 1 && i % 2 == 0)
								cout << char(0xc4);
							else if (i % 2 == 1 && j % 2 == 0)
								cout << char(0xb3);
							else
								cout << ' ';
						}
						cout << "\n";
					}
					cout << "x= " << ir.Event.MouseEvent.dwMousePosition.X << "     " << endl;
					cout << "y= " << ir.Event.MouseEvent.dwMousePosition.Y << "     " << endl;

				}
				else if (ir.Event.MouseEvent.dwButtonState == RIGHTMOST_BUTTON_PRESSED)
				{
					GetConsoleScreenBufferInfo(hOut_t, &csbInfo);//получает информацию о  консоли
					FillConsoleOutputAttribute(hOut_t, FOREGROUND_BLUE, csbInfo.dwSize.X*csbInfo.dwSize.Y, c, &x);
					FillConsoleOutputCharacter(hOut_t, '*', csbInfo.dwSize.X*csbInfo.dwSize.Y, c, &x);
				}
			}
			/*	else if (ir.EventType == KEY_EVENT)
			break;*/
		}
		/*	SetConsoleMode(hIn, consoleMode);
		cin >> x;
		cout << x;
		*/
	}
}
