#include "intro.h"
#include <iostream>
using namespace std;
void intro()
{
	cout << "Welcome to HangMan\n\n";
	system("pause");
	system("cls");
	cout << "In this game you need to guess the letters of a random word.\nAny mistake will result in the addition of the man's body part (you have 6 lives in total)." << endl;
	cout << "\nWhen you guess a correct letter it will be added and will make you one step closer to the winning." << endl;
	cout << "Are Your Ready ? ? ?" << endl;
	system("pause");
}
