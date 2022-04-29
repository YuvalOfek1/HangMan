#define _CRT_SECURE_NO_WARNINGS
#include "HangMan.h"
#include "draw.h"
#include "gotoxy.h"
#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
#include <cstdlib>
#include <conio.h>

using namespace std;




void Print_Hidden_Word(char word[], int found[])
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
		gotoxy(0, 4);
		Print_Hidden_Word(word, found);
		drawMan(lives);
		if (!correct)
			gotoxy(0, 2);
		else gotoxy(0, 3);
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
	{
		cout << word << "\nCongrats!!! you found the word\n";
		drawMan(lives);
	}
	else
	{
		cout << "Sorry, you lost! :(\nThe man has been executed, The word was " << word << endl;
		drawMan(lives);
	}
	gotoxy(0, 18);
}


