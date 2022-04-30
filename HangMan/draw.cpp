#include <iostream>
#include <Windows.h>
#include "gotoxy.h"
using namespace std;

void drawMan(int lives)
{
	if (lives == 6)
	{
		for (int i = 16; i > 6; i--) // the giliotine
		{
			gotoxy(49, i);
			cout << "|";
		}
		gotoxy(49, 6);
		cout << "|/";
		gotoxy(49, 5);
		cout << "| /";
		gotoxy(48, 17);
		cout << "___\n";
		gotoxy(50, 4);
		cout << "_________";
		for (int i = 6; i >= 5; i--)
		{
			gotoxy(59, i);
			cout << "|";
		}

	}
	if (lives == 5) // the face
	{
		drawMan(6);
		gotoxy(56, 7);
		cout << "[ . . ]";
		gotoxy(56, 8);
		cout << "[  -  ]";
	}
	if (lives == 4) // the body
	{
		drawMan(5);
		for (int i = 11; i >= 9; i--)
		{
			gotoxy(59, i);
			cout << "|";
		}
	}
	if (lives == 3) // left hand
	{
		drawMan(4);
		gotoxy(58, 10);
		cout << "/";

	}
	if (lives == 2) // right hand
	{
		drawMan(3);
		gotoxy(60, 10);
		cout << "\\";
	}
	if (lives == 1) // left leg
	{
		drawMan(2);
		gotoxy(58, 12);
		cout << "/";


	}
	if (lives == 0) // right leg and dead eyes
	{
		drawMan(1);
		gotoxy(60, 12);
		cout << "\\";
		gotoxy(56, 7);
		cout << "[ x x ]";
	}


}