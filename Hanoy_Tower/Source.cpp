#include <iostream>
#include <ctime>
#include <windows.h>
#include <conio.h>
using namespace std;

const int field_size = 10;
int plr_field[field_size][field_size] = { 0 }, npc_field[field_size][field_size] = { 0 };

void print_field(){
	for (int i = 0; i <= 2 * field_size; i++)
	{
		for (int j = 0; j <= 2 * field_size; j++)
		{
			if (i == 0 && j == 0) // left top corner
				cout << (char)0xC9;
			else if (i == 0 && j == 2 * field_size) // right top corner
				cout << (char)0xBB;
			else if (i == 2 * field_size && j == 0) // left bottom corner
				cout << (char)0xC8;
			else if (i == 2 * field_size && j == 2 * field_size) //right bottom corner
				cout << (char)0xBC;
			else if (i == 0 && j % 2 == 0) // middle top 
				cout << (char)0xD1;
			else if (i == 2 * field_size && j % 2 == 0) // middle bottom
				cout << (char)0xCF;
			else if (i % 2 == 0 && j == 0) // middle left 
				cout << (char)0xC7;
			else if (i % 2 == 0 && j == 2 * field_size) // middle right
				cout << (char)0xB6;
			else if (i == 0 || i == 2 * field_size) // top & bottom line
				cout << (char)0xCD;
			else if (j == 0 || j == 2 * field_size) // left & right line
				cout << (char)0xBA;
			else if (i % 2 == 0 && j % 2 == 0) // crosshair
				cout << (char)0xC5;
			else if (i % 2 == 1 && j % 2 == 0) // middle vertical lines
				cout << (char)0xB3;
			else if (i % 2 == 0 && j % 2 == 1) // middle horizontal lines
				cout << (char)0xC4;

			else if (plr_field[i][j] == 0)
				cout << '*';

			else
				cout << ' ';


		}
		cout << endl;
	}
}


void main()
{
	print_field();
}