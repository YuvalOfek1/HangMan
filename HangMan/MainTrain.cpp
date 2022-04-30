#define _CRT_SECURE_NO_WARNINGS
#include "draw.h"
#include "gotoxy.h"
#include "intro.h"
#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <time.h>
using namespace std;

//Prints the length of the word with the letters that have been already found
void Print_Hidden_Word(char word[], int found[]);
bool is_in_mistakes(char mistakes[], char letter);

int main()
{
	int lives = 6, totalLines = 0, correct = 0, mistakes = 0;
	char letter, buffer[30];
	char* word;
	bool current, same;
	char mistake[6] = { 0 };
	//vector<string> lines;
	//fstream file{ "words.txt" };
	//string line;
	//srand(time(0));
	//

	//while (getline(file, line))
	//{
	//	totalLines++;
	//	lines.push_back(line);
	//
	//}
	//int random_line = rand() % totalLines;
	
	//Rules and game intro.
	intro();
	cout << "Please choose a word [>] "; cin >> buffer;
	word = new char[strlen(buffer) + 1];
	//strcpy(word, lines[random_line]);
	
	strcpy(word, buffer);
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
		gotoxy(48, 19);
		for (int i = 0; i < strlen(mistake); i++)
		{
			cout << mistake[i] << " ";
		}
		//The user hasnt found any letter yet
		if (!correct)
			gotoxy(0, 2);
		else gotoxy(0, 3);
		cout << "Try to guess a letter[>>] ";
		cin >> letter;
		for (int i = 0; i < strlen(word); i++)
		{
			//not case sensitive
			if (letter == word[i] || (word[i] + 32 == letter && i == 0) || (word[i] - 32 == letter && i != 0))
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
			cout << "You already found this letter." << endl;
			continue;
		}
		//The user has failed with the current letter and already has lives
		if (!current)
		{
			if (is_in_mistakes(mistake, letter))
			{
				cout << "You have already chosen this letter";
				continue;
			}
			else mistake[mistakes++] = letter;
			//The user has at least 2 lives.
			if (--lives >= 1)
			{
				gotoxy(0, 0);
				cout << "Unfortunately the word doesnt contain that letter.\nYou have " << lives << " mistakes left, Try again" << endl;

			}
		}
		else
		{
			if (word[correct])
				cout << "Congrats, you found a letter, keep going!" << endl;
		}
		if (lives == 1)
		{
			gotoxy(48, 20);
			cout << "Be carefull! you are almost losing!!\n";
		}

	}
	if (lives)
	{
		gotoxy(0, 0);
		cout << word << "\nCongrats!!! you found the word\n";
		drawMan(1);
		gotoxy(60, 10);
		cout << "/";
		gotoxy(58, 10);
		cout << "\\";
		gotoxy(60, 12);
		cout << "\\";
	}
	else
	{
		cout << "Sorry, you lost! :(\nThe man has been executed, The word was " << word << endl;
		drawMan(lives);
	}
	//to print the final exit code etc...
	gotoxy(0, 18);
	//file.close();
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