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

//======================================================================================================================
//THIS CODE WAS FOUND ANS WRITTEN BY ERIK ENGLISH CIS150-02.  He allowed me to upload this for everyone to use
//Code found from cplusplus.com: SOURCE: http://www.cplusplus.com/forum/beginner/105484/ ; User: Giblit
enum COLOR
{
	black, blue,
	green, cyan,
	red, magenta,
	brown, normal,
	darkgrey, lightblue,
	lightgreen, lightcyan,
	lightred, lightmagenta,
	yellow, white
};


//Not entirely sure what this does but is necessary for coloring text.
ostream& operator<<(ostream &stm, const COLOR &c)
{
	HANDLE out_handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(out_handle, c);
	return(stm);
}
//End of found code from cplusplus.com
//END OF ERIK'S CODE
//=============================================================================================================================

// Prototype Functions
void basement();
void map();

void combat(int &, int, int, int);
int damage(int, int);
void monster(int, int &, int &, string &);


int main()
{

	int health = 100;

	// Weapon damage
	int min = 5;
	int max = 10;
	// =============
//====================== Aaron Masson ==============================
	string name;
	string answer;
	bool valid = true;

	// Sets the color of ALL the text.
	cout << white;

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
	
	while (answer != "no" && answer != "yes" && answer != "map")
	{
		cout << "Enter in a valid answer: ";
		cin >> answer;


	}
	if (answer == "yes")
	{
		cout << "Lets begin! " << endl;
	
		basement();
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

	system("cls");
	// Source: http://www.cplusplus.com/forum/beginner/65037/ By whitenite1
	time_t t;
	srand((unsigned)time(&t));

	int x = 10;
	int y = 10;
	int i;
	int j;
	

	char board[10][10] = {
		{ 'w' , 'w' , 'w' , 'w' , 'w' , 'w' , 'w' , 'w' , 'w' ,'w' },
		{ 'w' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' ,'w' },
		{ 'w' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' ,'w' },
		{ 'w' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' ,'w' },
		{ 'w' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' ,'w' },
		{ 'w' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' ,'w' },
		{ 'w' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' ,'w' },
		{ 'w' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' ,'w' },
		{ 'w' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' ,'w' },
		{ 'w' , 'w' , 'w' , 'w' , 'w' , 'w' , 'w' , 'w' , 'w' ,'w' },

	};

	for (i = 0; i < x; i++)
	{
		for (j = 0; j < y; j++)
		{
			if (board[i][j] != 'w')
			{
				board[i][j] = '.';
			}
		}
	}

	board[8][1] = 'P';
	
	for (i = 0; i < x; i++)
	{

		for (j = 0; j < y; j++)
		{

			cout << board[i][j] << " ";

		}

		cout << endl;
	}

}

void basement()
{
	string direction;

	Sleep(2000);
	system("cls");

	cout << "You awake in a damp cold room with nothing but a wooden sword. " << endl;
	cout << "You hear a scream in the distance. " << endl;

	// Source: http://www.cplusplus.com/forum/beginner/65037/ By whitenite1
	time_t t;
	srand((unsigned)time(&t));

	int x = 10;
	int y = 10;
	int i;
	int j;
	static int vert = 1;
	static int hori = 8;

	char board[10][10] = {
		{ 'w' , 'w' , 'w' , 'w' , 'w' , 'w' , 'w' , 'w' , 'w' ,'w' },
		{ 'w' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' ,'w' },
		{ 'w' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' ,'w' },
		{ 'w' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' ,'w' },
		{ 'w' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' ,'w' },
		{ 'w' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' ,'w' },
		{ 'w' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' ,'w' },
		{ 'w' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' ,'w' },
		{ 'w' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' ,'w' },
		{ 'w' , 'w' , 'w' , 'w' , 'w' , 'w' , 'w' , 'w' , 'w' ,'w' },

	};


	for (i = 0; i < x; i++)
	{

		for (j = 0; j < y; j++)
		{
			if (board[i][j] != 'w')
			{
				board[i][j] = '.';
			}

		}

	}


	board[hori][vert] = 'P';

	for (i = 0; i < 10; i++)
	{


		i = rand() % 10;
		j = rand() % 10;


		while (board[i][j] == '.')
		{

			board[i][j] = '?';

		}

	}

	for (i = 0; i < x; i++)
	{
		for (j = 0; j < y; j++)
		{
			cout << board[i][j] << " ";
		}
		cout << endl;
	}

	cout << "Which direction will you go? ";
	cin >> direction;
	while (direction != "up" && direction != "down" && direction != "left" && direction != "right")
	{
		cout << "Invalid. Please enter up or down or left or right. ";
		cin >> direction;
	}

	if (direction == "up")
	{

		board[hori][vert] = '.';
		board[hori - 1][vert] = 'P';

	}
	if (direction == "down")
	{
		//insert check
		board[hori][vert] = '.';
		board[hori + 1][vert] = 'P';


	}
	if (direction == "left")
	{



	}
	if (direction == "right")
	{



	}

	for (i = 0; i < x; i++)
	{

		for (j = 0; j < y; j++)
		{

			cout << board[i][j] << " ";

		}

		cout << endl;
	}

}


// Justin Marshall
void combat(int &health, int min, int max, int floor)
{

	int creaturehp = 100;
	string action;
	string creature;
	int damagedealt;
	int cmin;
	int cmax;





	cout << "Enter in a minimum value: ";
	cin >> min;

	cout << "Enter in a maximum value: ";
	cin >> max;

	cout << "Enter in the floor: ";
	cin >> floor;

	monster(floor, cmax, cmin, creature);
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
void monster(int floor, int &maxdam, int &mindam, string &munster)
{
	int yeet;
	int hp;

	srand(time(NULL));

	yeet = rand() % floor;


	if (yeet == 0)
	{

		munster = "imp";
		mindam = 1;
		maxdam = 5;


	}

	if (yeet == 1)
	{

		munster = "goblin";

		mindam = 4;
		maxdam = 8;

	}


	if (yeet == 2)
	{

		munster = "orc";

		mindam = 7;
		maxdam = 12;

	}

	if (yeet == 3)
	{

		munster = "chandelier";

		mindam = 10;
		maxdam = 16;


	}

	if (yeet == 4)
	{

		munster = "sleep deprived college students";

		mindam = 14;
		maxdam = 19;

	}
	if (yeet == 5)
	{

		munster = "Zachary Moore";

		mindam = 18;
		maxdam = 25;

	}



}

// End Justin Marshall
//==============================================================================================================================