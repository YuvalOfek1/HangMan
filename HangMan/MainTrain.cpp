/*
====================================================================================================================
HangMan-Game by Yuval Ofek. I used the function tool "GotoXY" to draw the man in a specific place in the console.
All the local functions were created by me. 
The programs fetches a random word from the word.txt file
====================================================================================================================
*/

#define _CRT_SECURE_NO_WARNINGS
#include "draw.h"
#include "gotoxy.h"
#include "intro.h"
#include <iostream>
#include <string>
#include <conio.h>
#include <windows.h>
#include <MMsystem.h>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <time.h>
using namespace std;

//Prints the length of the word with the letters that have been already found
void Print_Hidden_Word(char word[], int found[]);
//checks if the user has already tried this letter
bool is_in_mistakes(char mistakes[], char letter);

int main()
{
	bool alert = false;
	//PlaySound(TEXT("victory.wav"), NULL,SND_ASYNC);
	int lives = 6, totallines = 0, correct = 0, mistakes = 0;
	char letter;
	char* word;
	bool current, same;
	char mistake[6] = { 0 };
	vector<string> lines;
	ifstream file{ "words.txt" };
	string line;
	srand(time(NULL));
	while (getline(file, line))
	{
		totallines++;
		lines.push_back(line);
	}
	int random_line = rand() % totallines;
	int len = lines[random_line].length();
	word = new char[len+1];
	strcpy(word, lines[random_line].c_str());
	
	
	//Rules and game intro.
	intro();
	//PlaySound(NULL, 0, 0);
	system("cls");
	int* found = new int[strlen(word)];
	for (int i = 0; i < strlen(word); i++)
		found[i] = 0;

	//While still playing...
	while (lives > 0 && word[correct])
	{
		current = false;
		same = false;
		gotoxy(0, 4);
		//Prints the length of the word with the letters that have been already found
		Print_Hidden_Word(word, found);
		drawMan(lives);
		if (lives == 1)
		{
			gotoxy(48, 19);
			cout << "*** Be carefull! you are almost losing!!! ***\n";
			if(!alert)
				PlaySound(TEXT("Alert.wav"), NULL, SND_ASYNC);
			alert = true;
		}
		gotoxy(54, 14);
		for (int i = 0; i < strlen(mistake); i++)
		{
			cout << mistake[i] << " ";
		}
		//The user hasnt found any letter yet
		if (!correct)
			gotoxy(0, 2);
		else gotoxy(0, 3);
		cout << "Try to guess a letter[>>] ";
		letter = _getch();
		if (letter < 'A' || (letter < 'a' && letter>'Z') || letter >'z')
		{
			system("cls");
			gotoxy(0, 0);
			cout << "Invalid character! try again\nYou have " << lives << " lives left!";
			continue;
		}
		for (int i = 0; i < strlen(word); i++)
		{
			//not case sensitive
			if (letter == word[i] || (word[i] + 32 == letter && i == 0) || (word[i] - 32 == letter /*&&i!=0*/))
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
		//The letter has been already found
		if (same)
		{
			cout << "You have already found this letter.\nYou have " << lives << " lives left!" << endl;
			continue;
		}
		//The user has failed with the current letter and already has lives
		if (!current)
		{
			if (is_in_mistakes(mistake, letter) || is_in_mistakes(mistake, letter+32) || is_in_mistakes(mistake, letter - 32))
			{
				cout << "You have already chosen this letter\nYou have " << lives << " lives left!";
				continue;
			}
			else
			{
				if(letter>='a' && letter<='z')
					mistake[mistakes++] = letter-32;
				else mistake[mistakes++] = letter;
			}
			//The user has at least 2 lives.
			if (--lives >= 1)
			{
				gotoxy(0, 0);
				PlaySound(TEXT("Missed.wav"), NULL, SND_ASYNC);
				cout << "Unfortunately the word doesnt contain that letter.\nYou have " << lives << " lives left, Try again" << endl;

			}
		}
		else
		{
			if (word[correct])
				cout << "Congrats, you found a letter, keep going!\nYou have " << lives << " lives left!" <<endl;
		}
	}
	if (lives)
	{
		PlaySound(TEXT("victory.wav"), NULL, SND_ASYNC);
		gotoxy(0, 0);
		cout << word << "\nCongratulations!!! you found the word\n";
		drawWinning();
		gotoxy(0, 4);
		system("pause");
		PlaySound(NULL, 0, 0);
	}
	else
	{
		PlaySound(TEXT("Loss.wav"), NULL, SND_ASYNC);
		
		cout << "Sorry, you lost! :(\nThe man has been executed, The word was " << word << endl;
		drawMan(lives);
		gotoxy(0, 4);
		system("pause");
		PlaySound(NULL, 0, 0);
	}
	//to print the final exit code etc...
	file.close();
	delete[]word;
	gotoxy(0, 18);
	return 0;
}

//Prints the length of the word with the letters that have been already found
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
bool is_in_mistakes(char mistakes[], char letter)
{
	for (int i = 0; i < strlen(mistakes); i++)
	{
		if (mistakes[i] == letter)
			return true;
	}
	return false;
}