// Texted Based Game 
// Player will move around in a 10/10 array fighting enemies and finding items trying to get to the door. 
//There are 5 floors to move through to get to the final boss.
//Aaron Masson
//5252

#include "stdafx.h"
#include <iostream>
#include <string>
#include <stdio.h>
#include <Windows.h>
#include <ctime>


using namespace std;
// Prototype Functions
void basement();
void map();
void displaymap(int row, int col, char board[10][10]);
void combat(int &, int, int);
int damage(int, int);
string monster(int);

int main()
{

	int health = 100;

//====================== Aaron Masson ==============================
	string name;
	string answer;
	bool valid = true;

	cout << "Welcome to my program! " << endl;
	cout << "Enter in your name: " << endl;
	getline(cin, name);
	cout << "Well " << name << ", get ready for a grand adventure through a dark and dangerous tower! " << endl;
	cout << "Your prize is waiting at the top. Make Haste! " << endl;
	cout << "To move around simply type up, down. Same is for left and right. " << endl;
	cout << "Are you ready to embark on your journey? (yes) or (no) ";
	cin >> answer;
	if (answer == "map")
	{
		map();
	}
	
	while (answer != "no" && answer != "yes")
	{
		cout << "Enter in a valid answer: ";
		cin >> answer;
	}
	if (answer == "yes")
	{
		cout << "Lets begin! " << endl;
	
		basement();
	}
	if (answer == "map")
	{
		map();
	}

	else if (answer == "no")
	{
		cout << "Too bad " << endl;
		basement();
	}
	

	system("pause");
    return 0;
}

void map()
{
	const int rows = 10;
	const int cols = 10;

	char board[rows][cols] = {
		{' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' ,' ' },
		{' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' ,' ' },
		{' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' ,' ' },
		{' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' ,' ' },
		{' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' ,' ' },
		{' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' ,' ' },
		{' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' ,' ' },
		{' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' ,' ' },
		{' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' ,' ' },
		{'/' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' ,' ' },

	};
	displaymap(rows, cols, board);
}

void displaymap(int row, int col, char board[10][10])
{
	system("cls");
	string div = "=====================";
	string between = "---------------------";
	cout << div << endl;
	for (int i = 0; i < row; i++)
	{
		//used to divide cells
		cout << "|";
		for (int j = 0; j < col; j++)
		{
			//Display contents of array and a divider between each cell
			cout << board[i][j] << "|";
		}
		//i dont want to display this if this is my last row because I will display div instead
		if (i != row - 1)
		{
			//Divider between rows
			cout << endl << between << endl;
		}
		else
		{
			cout << endl;
		}

	}
	cout << div << endl;
}

void basement()
{
	string direction;

	Sleep(2000);
	system("cls");
	cout << "You awake in a damp cold room with nothing but a wooden sword. " << endl;
	cout << "You hear a scream in the distance. " << endl;
	cout << "Which direction will you go? ";
	cin >> direction;
	while (direction != "up" && direction != "down" && direction != "left" && direction != "right")
	{
		cout << "Invalid. Please enter up or down or left or right. ";
		cin >> direction;
	}

	if (direction == "up")
	{

	}
	if (direction == "down")
	{


	}
	if (direction == "left")
	{

	}
	if (direction == "right")
	{

	}

}


// Justin Marshall
void combat(int &health, int min, int max)
{


	int floor;
	int health = 100;
	int creaturehp = 100;
	string action;
	string creature;
	int damagedealt;





	cout << "Enter in a minimum value: ";
	cin >> min;

	cout << "Enter in a maximum value: ";
	cin >> max;

	cout << "Enter in the floor: ";
	cin >> floor;

	creature = monster(floor);
	cout << "You run into a " << creature << ".\nChoose what you want to do attack, flee, or use item: ";
	cin >> action;

	while (health > 0 && creaturehp > 0 && action == "attack")
	{

		if (action == "attack")
		{

			damagedealt = damage(min, max);
			creaturehp = creaturehp - damagedealt;

			cout << "You deal " << red << damagedealt << white << " damage." << endl;
		}


		damagedealt = damage(min, max);
		health = health - damagedealt;

		cout << health << endl;

		cout << "The " << monster << " hit you for " << red << damagedealt << white << "." << endl;


		cout << "Choose what you want to do attack, flee, or use item : ";
		cin >> action;
	}


}

int damage(int min, int max)
{

	int ow;
	static bool first = true;

	// Source: https://stackoverflow.com/questions/7560114/random-number-c-in-some-range/7560171#7560171 by Nawaz and Benjamin Lindley
	if (first == true)
	{

		srand(time(NULL));
		first = false;
	}


	for (int i = 0; i < 1; i++)
	{

		ow = min + rand() % max;


	}


	return ow;


}
string monster(int)
{

	string munster;
	int yeet;
	int max = floor;

	srand(time(NULL));

	yeet = rand() % max;


	if (yeet == 0)
	{

		munster = "imp";

	}

	if (yeet == 1)
	{

		munster = "goblin";

	}


	if (yeet == 2)
	{

		munster = "orc";

	}

	if (yeet == 3)
	{

		munster = "chandelier";

	}

	if (yeet == 4)
	{

		munster = "sleep deprived college students";

	}
	if (yeet == 5)
	{

		munster = "Zachary Moore";

	}



	return munster;

}

// End Justin Marshall
//==============================================================================================================================