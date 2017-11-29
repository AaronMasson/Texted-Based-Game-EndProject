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
void basement(int &, int &, int &, int &);
void combat(int &, int, int, int);
int damage(int, int);
void monster(int, int &, int &, string &);
void map();

// Decides what they will run into (items or monster)
void huh(int &, int &, int &, int &);


int main()
{

	int health = 100;

	// Weapon damage
	int min = 5;
	int max = 11;
	// =============

	int floor;
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
	cout << "Your prize is waiting at the top of the tower. Make Haste! " << endl;
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
	
		basement(health, max, min, floor);
	}

	else if (answer == "no")
	{
		cout << "Too bad " << endl;
		basement(health, max, min, floor);
	}
	

	system("pause");
    return 0;
}


void basement(int &health, int &max, int &min, int &floor)
{
	string direction;
	floor = 1;
	Sleep(2000);
	system("cls");

	cout << "You awake in a damp cold room with nothing but a wooden sword and a mug (what a night eh). " << endl;
	cout << "You hear a scream in the distance. " << endl;

	// Source: http://www.cplusplus.com/forum/beginner/65037/ By whitenite1
	time_t t;
	srand((unsigned)time(&t));

	char wall_v = 186, wall_h = 205, wall_cross = 206, twall_r = 185, twall_l = 204, twall_u = 203, twall_b = 202, wallcap_h = 254, corner_ul = 201, corner_ur = 187, corner_bl = 200, corner_br = 188, door_h = 215, door_v = 216, encounter = 238; //Level Design, Dianda
	int x = 10;
	int y = 10;
	int i;
	int j;

	// For the while loop to allow constant movement until an enounter.
	bool movement = true;


	// allows movement 
	// side note they're inverted i.e. vert moves you horizontaly.
	int vert = 1;
	int hori = 8;


	char player = 'P';

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


	board[hori][vert] = player;

	for (i = 0; i < 10; i++)
	{


		i = rand() % 10;
		j = rand() % 10;


		while (board[i][j] == '.')
		{

			board[i][j] = '?';

		}

	}


	while (movement) 
	{
		
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
			if (board[hori - 1][vert] != 'w') {
				board[hori][vert] = '.';
				board[hori - 1][vert] = player;
				hori = hori - 1;
			}

			else if (board[hori - 1][vert] == 'w')
			{
				cout << "You ran into a wall, try a different direction." << endl;
				cout << "Side note: You lost 3 hp.";
				health = health - 3;
				Sleep(2000);
			}

			else if (board[hori - 1][vert] == '?')
			{

				huh(health, max, min, floor);
			}
		}
		else if (direction == "down")
		{
			
			if (board[hori + 1][vert] != 'w') 
			{
				board[hori][vert] = '.';
				board[hori + 1][vert] = player;
				hori = hori + 1;
			}
			else if (board[hori + 1][vert] == 'w')
			{
				cout << "You ran into a wall, try a different direction." << endl;
				cout << "Side note: You lost 3 hp.";
				health = health - 3;
				Sleep(2000);
			}

			else if (board[hori + 1][vert] == '?')
			{

				huh(health, max, min, floor);

			}

		}
		else if (direction == "left")
		{
			if (board[hori][vert - 1] != 'w')
			{
				board[hori][vert] = '.';
				board[hori][vert - 1] = player;
				vert = vert - 1;
			}

			else if (board[hori][vert - 1] == 'w')
			{
				cout << "You ran into a wall, try a different direction." << endl;
				cout << "Side note: You lost 3 hp.";
				health = health - 3;
				Sleep(2000);
			}

			else if (board[hori][vert - 1] == '?')
			{

				huh(health, max, min, floor);

			}
			
		}
		else if (direction == "right")
		{
			if (board[hori][vert + 1] != 'w' &&  board[hori][vert + 1] != '?')
			{
				board[hori][vert] = '.';
				board[hori][vert + 1] = player;
				vert = vert + 1;
			}
			else if (board[hori][vert + 1] == 'w')
			{
				cout << "You ran into a wall, try a different direction." << endl;
				cout << "Side note: You lost 3 hp.";
				health = health - 3;
				Sleep(2000);
			}

			else if (board[hori][vert + 1] == '?')
			{

				huh(health, max, min, floor);

			}

		}
		
		system("cls");
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

		cout << "The " << creature << " hit you for " << red << damagedealt << white << "." << endl;


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

void huh(int &health, int &max, int &min, int &floor)
{
	srand(time(NULL));

	int uhh;
	uhh = 1;

	if (uhh == 1)
	{
		combat(health, max, min, floor);

	}


}

// End Justin Marshall
//==============================================================================================================================

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