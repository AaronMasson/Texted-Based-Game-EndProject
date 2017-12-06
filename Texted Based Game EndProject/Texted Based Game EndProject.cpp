// Texted Based Game 
// Player will move around in a 10/10 array fighting enemies and finding items trying to get to the door. 
//There are 3 floors to move through to get to the final boss.
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
void basement(int &, int &, int &, int &, bool &, string &, bool &, bool &, bool &);
void combat(int &, int, int, int, bool &, string &, bool &, bool &, bool &);
int damage(int, int);
void monster(int, int &, int &, string &, int &);
void map();
//void commands(string &, bool &, int &, int &, char &, bool &, bool &);

// Decides what they will run into (items or monster)
void huh(int &, int &, int &, int &, bool &, string &, bool &, bool &, bool &);


int main()
{


	int health = 100;

	// Weapon damage
	int min = 5;
	int max = 11;
	// =============
	bool alive;
	bool fight;
	bool movement;
	bool inventory;
	static bool first = true;
	int floor;
	//====================== Aaron Masson ==============================
	string name;
	string answer;
	bool valid = true;
	

	// Sets the color of ALL the text.
	cout << white;
	if (first && health > 0)
	{
		alive = true;

		first = false;

	}

	else
	{
		alive = false;
	}


	if (alive == true)
	{
		cout << "Welcome to The Dark Tower! " << endl;
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

			basement(health, max, min, floor, alive, answer, movement, fight, inventory);
		}

		else if (answer == "no")
		{
			cout << "Too bad " << endl;
			basement(health, max, min, floor, alive, answer, movement, fight, inventory);
		}
	}
	if (alive == false && first == false)
	{
		cout << "You died" << endl;

		Sleep(2000);
		cout << endl << endl << endl << "Sorry" << endl;
		alive = false;
	}

	system("pause");
	return 0;
}


void basement(int &health, int &max, int &min, int &floor, bool &alive, string &answer, bool &movement, bool &fight, bool &inventory, bool &flee)
{
	
	floor = 5;
	Sleep(3000);
	system("cls");
	static bool first = true;
	bool flee = true;
	
	if (flee = true)
	{
		cout << "You awake in a damp cold room with nothing but a wooden sword and a mug (what a night eh). " << endl;
		cout << "You hear a scream in the distance. " << endl;
	}
	
	// Source: http://www.cplusplus.com/forum/beginner/65037/ By whitenite1
	time_t t;
	srand((unsigned)time(&t));

	char wall_v = 186, wall_h = 205, wall_cross = 206, twall_r = 185, twall_l = 204, twall_u = 203, twall_b = 202, wallcap_h = 254, corner_ul = 201, corner_ur = 187, corner_bl = 200, corner_br = 188, door_h = 215, door_v = 216, encounter = 238; //Level Design, Dianda
	int x = 10;
	int y = 10;
	int i;
	int j;

	// For the while loop to allow constant movement until an enounter.
	movement = true;


	// allows movement 
	// side note they're inverted i.e. vert moves you horizontaly.
	int vert = 1;
	int hori = 8;


	char player = 'P';
	// Dianda start
	char board[10][10] = { { corner_ul, wall_h, wall_h, wall_h, wall_h, wall_h, wall_h, wall_h, wall_h, corner_ur },
	{ wall_v, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',wall_v },
	{ wall_v, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',wall_v },
	{ wall_v, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',wall_v },
	{ wall_v, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',wall_v },
	{ wall_v, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',wall_v },
	{ wall_v, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',wall_v },
	{ wall_v, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',wall_v },
	{ wall_v, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',wall_v },
	{ corner_bl, wall_h, wall_h, wall_h, wall_h, wall_h, wall_h, wall_h, wall_h, corner_br }
	};
	// Dianda end
	//for (i = 0; i < x; i++)
	//{

	//	for (j = 0; j < y; j++)
	//	{
	//		if (board[i][j] != 'w' && board[i][j] != 'D') // prevents printing of unicode/level design characters
	//		{
	//			board[i][j] = '.';
	//		}

	//	}

	//}


	board[hori][vert] = player;

	for (x = 0; x < 10; x++)
	{


		i = 1 + rand() % 9;
		j = 1 + rand() % 9;


		while (board[i][j] == ' ')
		{

			board[i][j] = '?';

		}

	}


	while (movement && alive)
	{

		for (i = 0; i < x; i++)
		{
			for (j = 0; j < y; j++)
			{
				if (i == 0 && j < 9) {
					cout << board[i][j] << wall_h;
				}
				else if (i == 9 && j < 9) {
					cout << board[i][j] << wall_h;
				}
				else {
					cout << board[i][j] << " ";
				}
			}
			cout << endl;
		}

		cout << "Which direction will you go? ";
		cin >> answer;
		while (answer != "up" && answer != "down" && answer != "left" && answer != "right")
		{
			cout << "Invalid. Please enter up or down or left or right. ";
			cin >> answer;
		}

		if (answer == "up")
		{
			if (board[hori - 1][vert] != wall_h && board[hori - 1][vert] != '?') {
				board[hori][vert] = ' ';
				board[hori - 1][vert] = player;
				hori = hori - 1;
			}

			else if (board[hori - 1][vert] == wall_h)
			{
				cout << "You ran into a wall, try a different direction." << endl;
				cout << "Side note: You lost 3 hp.";
				health = health - 3;
				Sleep(2000);
			}

			else if (board[hori - 1][vert] == '?')
			{

				huh(health, max, min, floor, alive, answer, movement, fight, inventory, flee);
				board[hori][vert] = ' ';
				board[hori - 1][vert] = player;
				hori = hori - 1;
			}
		}
		else if (answer == "down")
		{

			if (board[hori + 1][vert] != wall_h && board[hori + 1][vert] != '?')
			{
				board[hori][vert] = ' ';
				board[hori + 1][vert] = player;
				hori = hori + 1;
			}
			else if (board[hori + 1][vert] == wall_h)
			{
				cout << "You ran into a wall, try a different direction." << endl;
				cout << "Side note: You lost 3 hp.";
				health = health - 3;
				Sleep(2000);
			}

			else if (board[hori + 1][vert] == '?')
			{

				huh(health, max, min, floor, alive, answer, movement, fight, inventory);
				board[hori][vert] = ' ';
				board[hori + 1][vert] = player;
				hori = hori + 1;

			}

		}
		else if (answer == "left")
		{
			if (board[hori][vert - 1] != wall_v && board[hori][vert - 1] != '?')
			{
				board[hori][vert] = ' ';
				board[hori][vert - 1] = player;
				vert = vert - 1;
			}

			else if (board[hori][vert - 1] == wall_v)
			{
				cout << "You ran into a wall, try a different direction." << endl;
				cout << "Side note: You lost 3 hp.";
				health = health - 3;
				Sleep(2000);
			}

			else if (board[hori][vert - 1] == '?')
			{

				huh(health, max, min, floor, alive, answer, movement, fight, inventory);
				board[hori][vert] = ' ';
				board[hori][vert - 1] = player;
				vert = vert - 1;
			}

		}
		else if (answer == "right")
		{
			if (board[hori][vert + 1] != wall_v && board[hori][vert + 1] != '?')
			{
				board[hori][vert] = ' ';
				board[hori][vert + 1] = player;
				vert = vert + 1;
			}
			else if (board[hori][vert + 1] == wall_v)
			{
				cout << "You ran into a wall, try a different direction." << endl;
				cout << "Side note: You lost 3 hp.";
				health = health - 3;
				Sleep(2000);
			}

			else if (board[hori][vert + 1] == '?')
			{

				huh(health, max, min, floor, alive, answer, movement, fight, inventory);

				board[hori][vert] = ' ';
				board[hori][vert + 1] = player;
				vert = vert + 1;
			}

		}

		system("cls");
	}
}


// Justin Marshall
void combat(int &health, int min, int max, int floor, bool &alive, string &answer, bool &movement, bool &fight, bool &inventory, bool &flee)
{

	int creaturehp;
	string creature;
	int damagedealt;
	int cmin;
	int cmax;
	






	monster(floor, cmax, cmin, creature, creaturehp);

	// Checks to make sure they are returning correct values.
	//cout << cmax << endl << cmin << endl << creature << endl << creaturehp << endl;
	cout << "You run into a " << creature << endl;

	while (health > 0 && creaturehp > 0)
	{
		if (creature == "chandelier")
		{
			damagedealt = damage(cmin, cmax);
			health = health - damagedealt;
			creaturehp = creaturehp - 1;
			cout << "The " << creature << " hit you for " << red << damagedealt << white << "." << endl;

			cout << "You have " << health << " remaining." << endl << "The " << creature << " has " << creaturehp << " remaining." << endl;
		}
		else
		{
			cout << "Choose what you want to do attack, flee, or use item : ";
			cin >> answer;

			if (answer == "attack")
			{

				damagedealt = damage(min, max);
				creaturehp = creaturehp - damagedealt;

				cout << "You deal " << red << damagedealt << white << " damage." << endl;

			}

			else if (answer == "flee")
			{
				flee = false;
				cout << "You flee the battle and you hear the other creatures moving in the distance. " << endl;
				basement(health, max, min, floor, alive, answer, movement, fight, inventory, flee);
			
			}
			else if (answer == "item")
			{

			}

			if (creaturehp > 0)
			{
				damagedealt = damage(cmin, cmax);
				health = health - damagedealt;


				cout << "The " << creature << " hit you for " << red << damagedealt << white << "." << endl;

				cout << "You have " << health << " remaining." << endl << "The " << creature << " has " << creaturehp << " remaining." << endl;
			}
			Sleep(500);
		}
	}

	if (creaturehp <= 0)
	{
		cout << "You defeated the " << creature << ". Good Job!" << endl;
		Sleep(1500);
	}

	else if (health <= 0)
	{
		alive = false;
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


void monster(int floor, int &maxdam, int &mindam, string &munster, int &creaturehp)
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
		creaturehp = 30;


	}

	if (yeet == 1)
	{

		munster = "goblin";

		mindam = 4;
		maxdam = 8;
		creaturehp = 50;
	}


	if (yeet == 2)
	{

		munster = "orc";

		mindam = 7;
		maxdam = 12;
		creaturehp = 55;
	}

	if (yeet == 3)
	{

		munster = "chandelier";

		mindam = 20;
		maxdam = 25;
		creaturehp = 1;


	}

	if (yeet == 4)
	{

		munster = "sleep deprived college students";

		mindam = 14;
		maxdam = 19;
		creaturehp = 70;

	}
	/*if (yeet == 5)
	{

	munster = "Zachary Moore";

	mindam = 18;
	maxdam = 25;
	creaturehp = 400;
	}*/



}

void huh(int &health, int &max, int &min, int &floor, bool &alive, string &answer, bool &movement, bool &fight, bool &inventory, bool &flee)
{
	srand(time(NULL));

	int uhh;
	uhh = 1;

	if (uhh == 1)
	{
		combat(health, max, min, floor, alive, answer, movement, fight, inventory, flee);

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
		{ 'w' , '|' , '_' , '_' , '_' , '_' , '_' , '_' , '|' ,'w' },
		{ 'w' , '|' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , '|' ,'w' },
		{ 'w' , '|' , '_' , '_' , '_' , '_' , '_' , '_' , '|' ,'w' },

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

//void commands(string &answer, bool &movement, int &hori, int &vert, char &player, bool &fight, bool &inventory)
//{
//	if (movement)
//	{
//			cout << "Which direction will you go? ";
//		cin >> answer;
//		while (answer != "up" && answer != "down" && answer != "left" && answer != "right")
//		{
//			cout << "Invalid. Please enter up or down or left or right. ";
//			cin >> answer;
//		}
//
//		if (answer == "up")
//		{
//			if (board[hori - 1][vert] != 'w' && board[hori - 1][vert] != '?') {
//				board[hori][vert] = '.';
//				board[hori - 1][vert] = player;
//				hori = hori - 1;
//			}
//
//			else if (board[hori - 1][vert] == 'w')
//			{
//				cout << "You ran into a wall, try a different direction." << endl;
//				cout << "Side note: You lost 3 hp.";
//				health = health - 3;
//				Sleep(2000);
//			}
//
//			else if (board[hori - 1][vert] == '?')
//			{
//
//				huh(health, max, min, floor, alive, answer, movement, fight, inventory);
//				board[hori][vert] = '.';
//				board[hori - 1][vert] = player;
//				hori = hori - 1;
//			}
//		}
//		else if (answer == "down")
//		{
//			
//			if (board[hori + 1][vert] != 'w' && board[hori + 1][vert] != '?')
//			{
//				board[hori][vert] = '.';
//				board[hori + 1][vert] = player;
//				hori = hori + 1;
//			}
//			else if (board[hori + 1][vert] == 'w')
//			{
//				cout << "You ran into a wall, try a different direction." << endl;
//				cout << "Side note: You lost 3 hp.";
//				health = health - 3;
//				Sleep(2000);
//			}
//
//			else if (board[hori + 1][vert] == '?')
//			{
//
//				huh(health, max, min, floor, alive, answer, movement, fight, inventory);
//				board[hori][vert] = '.';
//				board[hori + 1][vert] = player;
//				hori = hori + 1;
//
//			}
//
//		}
//		else if (answer == "left")
//		{
//			if (board[hori][vert - 1] != 'w' && board[hori][vert - 1] != '?')
//			{
//				board[hori][vert] = '.';
//				board[hori][vert - 1] = player;
//				vert = vert - 1;
//			}
//
//			else if (board[hori][vert - 1] == 'w')
//			{
//				cout << "You ran into a wall, try a different direction." << endl;
//				cout << "Side note: You lost 3 hp.";
//				health = health - 3;
//				Sleep(2000);
//			}
//
//			else if (board[hori][vert - 1] == '?')
//			{
//
//				huh(health, max, min, floor, alive, answer, movement, fight, inventory);
//				board[hori][vert] = '.';
//				board[hori][vert - 1] = player;
//				vert = vert - 1;
//			}
//			
//		}
//		else if (answer == "right")
//		{
//			if (board[hori][vert + 1] != 'w' && board[hori][vert + 1] != '?')
//			{
//				board[hori][vert] = '.';
//				board[hori][vert + 1] = player;
//				vert = vert + 1;
//			}
//			else if (board[hori][vert + 1] == 'w')
//			{
//				cout << "You ran into a wall, try a different direction." << endl;
//				cout << "Side note: You lost 3 hp.";
//				health = health - 3;
//				Sleep(2000);
//			}
//
//			else if (board[hori][vert + 1] == '?')
//			{
//
//				huh(health, max, min, floor, alive, answer, movement, fight, inventory);
//
//				board[hori][vert] = '.';
//				board[hori][vert + 1] = player;
//				vert = vert + 1;
//			}
//
//		}
//		
//		system("cls");
//	}
//	}
//
//
//
//}