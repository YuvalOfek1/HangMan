#define _CRT_SECURE_NO_WARNINGS
#include "HangMan.h"
#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
#include <cstdlib>
#include <conio.h>

using namespace std;

void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void intro()
{
	cout << "Welcome to HangMan\n";
	system("pause");
	system("cls");
	cout << "\nIn this game you need to guess the letters of a random word.\nAny mistake will result in the addition of the man's body part (you have 6 lives in total)"<<endl;
	cout << "\nWhen you guess a correct letter it will be added and will make you one step closer to the winning" << endl;
	cout << "Are Your Ready ? ? ?" << endl;
	system("pause");
	system("cls");
}


void drawMan(int lives)
{
	if (lives == 6)
	{
		for (int i = 16; i > 6; i--)
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
	if (lives == 5)
	{
		drawMan(6);
		gotoxy(56, 7);
		cout << "[ . . ]";
		gotoxy(56, 8);
		cout << "[  -  ]";
	}
	if (lives == 4)
	{
		drawMan(5);
		for (int i = 11; i>= 9; i--)
		{
			gotoxy(59, i);
			cout << "|";
		}
	}
	if (lives == 3)
	{
		drawMan(4);
		gotoxy(58, 10);
		cout<<"/";
		
	}
	if (lives == 2)
	{
		drawMan(3);
		gotoxy(60, 10);
		cout << "\\";
	}
	if (lives == 1)
	{
		drawMan(2);
		gotoxy(58, 12);
		cout << "/";
		

	}
	if (lives == 0)
	{
		drawMan(1);
		gotoxy(60, 12);
		cout << "\\";
		gotoxy(56, 7);
		cout << "[ x x ]";
	}

}

void Print_Hidded_Word(char word[], int found[])
{
	for (int i = 0; i < strlen(word); i++)
	{
		if (found[i] == 1)
		{
			cout << word[i] << " ";
		}
		else
		{
			cout << "_ ";
		}
	}
}


void start()
{
	int lives = 6;
	char buffer[30];
	char letter;
	char* word;
	bool current;
	bool same;
	cout << "Please choose a word [>] "; cin >> buffer;
	system("cls");
	word = new char[strlen(buffer) + 1];
	int correct = 0;
	strcpy(word, buffer);
	int* found = new int[strlen(word)];
	for (int i = 0; i < strlen(word); i++)
		found[i] = 0;


	while (lives > 0 && word[correct])
	{
		current = false;
		same = false;
		gotoxy(0, 3);
		Print_Hidded_Word(word, found);
		drawMan(lives);
		gotoxy(0, 4);
		cout << "Try to guess a letter[>>] ";

		cin >> letter;
		for (int i = 0; i < strlen(word); i++)
		{
			if ((letter == word[i] || word[i] + 32 == letter || word[i]-32 == letter))
			{
				if (found[i] == 1)
				{
					same = true;
					break;
				}
				correct++;
				found[i] = 1;
				current = true;
			}
		}
		system("cls");
		if (same)
		{
			cout << "You already found this letter, don't be dumb" << endl;
			continue;
		}
		//The user has failed with the current letter and he already has lives
		if (!current) 
		{
			//The user has at least 1 life.
			if (--lives >= 1)
			{
				cout << "Unfortunately the word doesnt contain that letter.\nYou have " << lives << " mistakes left, Try again" << endl;
				
			}
		}
		else
		{
			if(word[correct])
				cout << "Congrats, you found a letter, keep going!" << endl;
		}
		
		
		/*for (int i = 0; i < correct; i++)
			cout << word[i] << " ";
		for (int i = correct; i < strlen(word); i++)
			cout << "_ ";*/
		
		/*else
		{
			if(!current)
			lives--;

		}*/
		if (lives == 1)
		{
			gotoxy(48, 19);
			cout << "Be carefull! you are almost losing!!\n";
		}
		
	}
	if (lives)
		cout << word << "\nCongrats!!! you found the word\n";
	else
	{
		cout << "Sorry, you lost! :(\nThe man has been executed, The word was " << word<<endl;
		drawMan(lives);
	}
	gotoxy(0, 18);
}


