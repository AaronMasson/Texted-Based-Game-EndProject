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

// Levels
void basement(int &, int &, int &, int &, bool &, string &, bool &, bool &, bool &, int, int, char[][5], bool &, bool &);
void ground_floor(int &, int &, int &, int &, bool &, string &, bool &, bool &, bool &, int, int, char[][5], char zack, bool &, bool &);
void second_floor(int &, int &, int &, int &, bool &, string &, bool &, bool &, bool &, int, int, char[][5], char zack, bool &, bool &);
void third_floor(int &, int &, int &, int &, bool &, string &, bool &, bool &, bool &, int, int, char[][5], char zack, bool &, bool &);
void finale(int &, int &, int &, int &, bool &, string &, bool &, bool &, bool &, int, int, char[][5], char zack, bool &, bool &);
// Levels End
// hud
void hud(int &, int &, int &);
// hud end

void combat(int &, int, int, int, bool &, string &, bool &, bool &, int, int, char[][5], bool &, char zack, bool &, bool &);
int damage(int, int);
void monster(int, int &, int &, string &, int &, char zack, bool &);
void map();
void commands(string &, int &, bool &, int &, char[][10], bool &, int &, int &, char &, bool &, int &, int &, bool &, int, int, char[][5], char, bool &, bool &);

// Inventory
void inventoryscreen(char[][5], int, int, int &, int &, int &, bool &);
void pickUp(char[][5], int, int, bool &);
void useitem(char[][5], char[][3], int, int, int &, int &, int &, bool &);
// End of inventory


// Decides what they will run into (items or monster)
void huh(int &, int &, int &, int &, bool &, string &, bool &, bool &, int, int, char[][5], bool &, char zack, bool &, bool &);

//item list (sorry but theyre globals)
char adminitem = 236;
char itemList[5][3]	{	{ 2, 2, 'P' },			// potion
						{ 2, 1, 'B' },			// loafy bread
						{ 6, 1, 'S' },			// actual stabber/sword
						{ 1, 1, adminitem },	// feckin normies REEEEEE
						{ 1, 1, 'M' }			// das a mug
};
int itemSel;

int main()
{


	int health = 100;

	// Weapon damage
	int min = 10;
	int max = 15;
	// =============
	bool alive;
	bool level_complete;
	bool movement;
	bool op = false;
	bool game_complete = false;
	bool fb = false;
	static bool first = true;
	int floor;
	//====================== Aaron Masson ==============================
	string name;
	string answer;
	bool valid = true;
	// Dianda

	const int invRows = 8, invCols = 5;
	char inventory[invRows][invCols] = {	{ ' ', ' ', ' ', ' ', ' ' },
											{ ' ', ' ', ' ', ' ', ' ' },
											{ ' ', ' ', ' ', ' ', ' ' },
											{ ' ', ' ', ' ', ' ', ' ' },
											{ ' ', ' ', ' ', ' ', ' ' },
											{ ' ', ' ', ' ', ' ', ' ' },
											{ ' ', ' ', ' ', ' ', ' ' },
											{ ' ', ' ', ' ', ' ', ' ' } };


	inventory[7][4] = 'M';

	// Sets the color of ALL the text.
	cout << white;
	// Masson
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
		

		while (answer != "no" && answer != "yes")
		{
			cout << "Enter in a valid answer: ";
			cin >> answer;


		}
		if (answer == "yes")
		{
			cout << "Lets begin! " << endl;

			basement(health, max, min, floor, alive, answer, movement, level_complete, op, invRows, invCols, inventory, fb, game_complete);
		}

		else if (answer == "no")
		{
		
			cout << "Too bad " << endl;
			basement(health, max, min, floor, alive, answer, movement, level_complete, op, invRows, invCols, inventory, fb, game_complete);
		}
	}
	if (alive == false && first == false)
	{
		cout << "You died" << endl;

		Sleep(2000);
		cout << endl << endl << endl << "Sorry, so uhh you want to try again?" << endl;
		cin >> answer;

		if (answer == "yes")
		{
			cout << "Lets begin \nagain... " << endl;
			alive = true;
			health = 100;
			basement(health, max, min, floor, alive, answer, movement, level_complete, op, invRows, invCols, inventory, fb, game_complete);
		}
		else
		{
			cout << "Alright, sorry you died. \nMaybe next time don't die...";
			Sleep(500);
			//insert ending
		}
		
		
	}
	else if (alive && !first)
	{
		cout << "You survived...\n";
		Sleep(500);
		cout << "Woo." << endl << "You uhh you want to play again?\n";
		cin >> answer;
		
		if (answer == "yes")
		{
			game_complete = false;
			cout << "Lets begin... again. " << endl;
			health = 100;
			basement(health, max, min, floor, alive, answer, movement, level_complete, op, invRows, invCols, inventory, fb, game_complete);
			
		}
		else
		{
			cout << "Alright, I guess I'll let you go now.\n";
			Sleep(500);
			//insert ending
		}
	}

	system("pause");
	return 0;
}// masson end

void inventoryscreen(char inventory[][5], int invRows, int invCols, int &min, int &max, int &health, bool &op) // Dianda
{
	system("cls");
	string invAction;

	cout << "Backpack:\n";
	
	for (int x = 0; x <invRows; x++)
	{
		for (int y = 0; y<invCols; y++)
		{
			cout << "[" << inventory[x][y] << "]";
		}
		cout << endl;
	}
	cout << "Item key:\n0 = potion = P\n1 = Bread = B\n2 = Sword = S\n4 = Mug = M\n";
	cout << "What would you like to do?";
	cin >> invAction;
	while (invAction != "exit") {
		if (invAction == "useitem") {
			cout << "what is the item to be used? ";
			cin >> itemSel;
			//while (itemSel > 4 && itemSel < 0) {
			//	cout << "Please enter a valid inventory item code:";
			//	cin >> itemSel;
			//}
			useitem(inventory, itemList, invRows, invCols, min, max, health, op);
			cout << "Item has been used, what would you like to do?";
			cin >> invAction;
		}
		else {
			cout << invAction << " is not a recognized command.\nType useitem to use an item or type exit to leave the inventory.";
			cin >> invAction;
		}
	}
	cout << "Exiting the inventory screen...";

}

void pickUp(char inventory[][5], int invRows, int invCols, bool &op) // Dianda
{
	int itemSizeX;
	int itemSizeY;
	int posx;
	int posy;
	int itemC1;
	int itemC2;
	int counterX;
	int counterY;
	int posyCounter;
	int posxCounter;
	static bool admin = false;
	static bool encounter = false;
	itemSizeX = itemList[itemSel][0];
	itemSizeY = itemList[itemSel][1];

	if (op && !admin)
	{
		admin = true;

	} //admin weapon
	posx = 0; posxCounter = 0; posy = 0; posyCounter = 0; counterX = 0; counterY = 0; itemC1 = 0; itemC2 = 0;
	system("cls");
	cout << "Backpack:\n";
	for (int x = 0; x <invRows; x++)
	{
		for (int y = 0; y<invCols; y++)
		{
			cout << "[" << inventory[x][y] << "]";
		}
		cout << endl;
	}

	cout << "Where would you like to place the item? X position: ";
	cin >> posx;
	cout << "                                        Y position: ";
	cin >> posy;
	posxCounter = posx;

	for (counterX = 0; counterX < itemSizeX; counterX++) { // inv space test
		posyCounter = posy;
		for (counterY = 0; counterY < itemSizeY; counterY++) {
			if (inventory[posxCounter][posyCounter] == ' ' && posyCounter < 5) {

			}
			else {
				cout << "Required inventory space is not empty.\n";
				cout << "Where would you like to place the item? X position: ";
				cin >> posx;
				cout << "                                        Y position: ";
				cin >> posy;
				posxCounter = posx;
			}

			posyCounter++;
		}
		posxCounter++;
	}

	posyCounter = 0; posxCounter = posx;

	for (counterX = 0; counterX < itemSizeX; counterX++) { // placement
		posyCounter = posy;
		for (counterY = 0; counterY < itemSizeY; counterY++) {
			inventory[posxCounter][posyCounter] = itemList[itemSel][2];

			posyCounter++;
		}
		posxCounter++;
	}
	system("cls");
	cout << "The item was placed at position (" << posx << "), (" << posy << ")\nBackpack:\n";
	for (int x = 0; x <invRows; x++)
	{
		for (int y = 0; y<invCols; y++)
		{
			cout << "[" << inventory[x][y] << "]";
		}
		cout << endl;
	}
}

void useitem(char inventory[][5], char itemList[][3], int invRows, int invCols, int &min, int &max, int &health, bool &op) // Dianda
{
	int itemcounter = 0;

	if (itemSel == 0) { // item P
		for (int x = 0; x < invRows; x++)
		{
			for (int y = 0; y < invCols; y++)
			{
				if (inventory[x][y] == 'P' && itemcounter < 4) {
					inventory[x][y] = ' ';
					itemcounter++;
				}
			}
			cout << endl;
		}
		health + 30; //ADD HEALTH HERE
		if (health > 100)
		{
			cout << "Health cannot be greater than 100.";
			health = 100;
		}
	}
	if (itemSel == 1); { // item B
		for (int x = 0; x < invRows; x++)
		{
			for (int y = 0; y < invCols; y++)
			{
				if (inventory[x][y] == 'B' && itemcounter < 2) {
					inventory[x][y] = ' ';
					itemcounter++;
				}
			}
			cout << endl;
		}
		health + 10; //ADD HEALTH HERE
		if (health > 100)
		{
			cout << "Health cannot be greater than 100.";
			health = 100;
		}
	}
	if (itemSel == 2); { // item S
		for (int x = 0; x < invRows; x++)
		{
			for (int y = 0; y < invCols; y++)
			{
				if (inventory[x][y] == 'S' && itemcounter < 6) {
					inventory[x][y] = ' ';
					itemcounter++;
				}
			}
			cout << endl;
		}
	min = 25;
	max = 31; //ADD DAMAGE VALUES HERE
	}
	if (itemSel == 3); { // item ∞
		for (int x = 0; x < invRows; x++)
		{
			for (int y = 0; y < invCols; y++)
			{
				if (inventory[x][y] == adminitem && itemcounter < 1) {
					inventory[x][y] = ' ';
					itemcounter++;
				}
			}
			cout << endl;
		}
		min = 100;
		max = 115;
	}
	if (itemSel == 4); { // item M
		for (int x = 0; x < invRows; x++)
		{
			for (int y = 0; y < invCols; y++)
			{
				if (inventory[x][y] == 'M' && itemcounter < 1) {
					inventory[x][y] = ' ';
					itemcounter++;
				}
			}
			cout << endl;
		}
	}

	system("cls");
	cout << "Backpack:\n";
	for (int x = 0; x <invRows; x++)
	{
		for (int y = 0; y<invCols; y++)
		{
			cout << "[" << inventory[x][y] << "]";
		}
		cout << endl;
	}

}



// =========================================================== Levels =================================================================================
void basement(int &health, int &max, int &min, int &floor, bool &alive, string &answer, bool &movement, bool &level_complete, bool &op, int invRows, int invCols, char inventory[][5], bool &fb, bool &game_complete)
{
	
	floor = 1;
	Sleep(3000);
	system("cls");
	static bool first = true;
	level_complete = false;
	
	if (!game_complete) 
	{
		cout << "You awake in a damp cold room with nothing but a wooden sword and a mug (what a night eh). " << endl;
		cout << "You hear a scream in the distance. " << endl;
	}
	
	// Source: http://www.cplusplus.com/forum/beginner/65037/ By whitenite1. This allows for random spawning of encounters
	time_t t;
	srand((unsigned)time(&t));

	char wall_v = 186, wall_h = 205, wall_cross = 206, twall_r = 185, twall_l = 204, twall_u = 203, twall_b = 202, wallcap_h = 254, corner_ul = 201, corner_ur = 187, corner_bl = 200, corner_br = 188, door_h = 215, door_v = 216, encounter = 238; //Level Design, Dianda
	int x = 10;
	int y = 10;
	int i;
	int j;
	char zack = 'b';

	// For the while loop to allow constant movement until an enounter.
	movement = true;


	// allows movement 
	// side note they're inverted i.e. vert moves you horizontaly.
	int vert = 1;
	int hori = 8;


	char player = 'P';
	// Dianda start
	char board[10][10] = { { corner_ul, wall_h, wall_h, wall_h, door_h, wall_h, wall_h, wall_h, wall_h, corner_ur },
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

	for (x = 0; x < 5; x++)
	{


		i = 1 + rand() % 9;
		j = 1 + rand() % 9;


		while (board[i][j] == ' ')
		{

			board[i][j] = '?';

		}

	}


	while (movement && alive && health > 0 && !level_complete && !game_complete)
	{
		hud(health, min, max);

		x = 10;
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
		while (answer != "up" && answer != "down" && answer != "left" && answer != "right" && answer != "map" && answer != "admin" && answer != "inv")
		{
			cout << "Invalid. Please enter up or down or left or right. ";
			cin >> answer;
		}

		commands(answer, health, alive, floor, board, movement, hori, vert, player, level_complete, max, min, op, invRows, invCols, inventory, zack, fb, game_complete);

		system("cls");
	}

	if (health <= 0)
	{
		alive = false;
	}
	else if (level_complete)
	{
		ground_floor(health, max, min, floor, alive, answer, movement, level_complete, op, invRows, invCols, inventory, zack, fb, game_complete);
	}
}

void ground_floor(int &health, int &max, int &min, int &floor, bool &alive, string &answer, bool &movement, bool &level_complete, bool &op, int invRows, int invCols, char inventory[][5], char zack, bool &fb, bool &game_complete)
{ 
	system("cls");
	floor = 2;
	level_complete = false;
	if (!game_complete) 
	{
		cout << "You head up a staircase to a new floor and you hear more monsters within the dark room" << endl;
	}


	// Source: http://www.cplusplus.com/forum/beginner/65037/ By whitenite1. This allows for random spawning of encounters
	time_t t;
	srand((unsigned)time(&t));

	char wall_v = 186, wall_h = 205, wall_cross = 206, twall_r = 185, twall_l = 204, twall_u = 203, twall_b = 202, wallcap_h = 254, corner_ul = 201, corner_ur = 187, corner_bl = 200, corner_br = 188, door_h = 215, door_v = 216, encounter = 238; //Level Design, Dianda
	int x = 10;
	int y = 10;
	int i;
	int j;

	int vert = 1;
	int hori = 8;


	char player = 'P';
	char board[10][10] = { { corner_ul, wall_h, wall_h, wall_h, wall_h, wall_h, wall_h, wall_h, wall_h, corner_ur },
	{ door_v, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',wall_v },
	{ wall_v, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',wall_v },
	{ twall_l, wall_h, corner_ul, ' ', ' ', ' ', ' ', ' ', ' ',wall_v },
	{ wall_v, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',wall_v },
	{ wall_v, ' ', ' ', wall_v, ' ', ' ', ' ', ' ', ' ',wall_v },
	{ wall_v, ' ', ' ', wall_v, ' ', ' ', ' ', ' ', wall_h,twall_r },
	{ wall_v, ' ', ' ', wall_v, ' ', ' ', wall_v, ' ', ' ',wall_v },
	{ wall_v, ' ', ' ', wall_v, ' ', ' ', wall_v, ' ', ' ',wall_v },
	{ corner_bl, wall_h, wall_h, twall_b, wall_h, wall_h, twall_b, wall_h, wall_h, corner_br }
	};
	// The encounter in the room is going to be a weapon. With the weapons they have to be used to update max and min damage.
	
	board[hori][vert] = player;

	for (x = 0; x < 15; x++)
	{


		i = 1 + rand() % 9;
		j = 1 + rand() % 9;


		while (board[i][j] == ' ')
		{

			board[i][j] = '?';

		}

	}


	while (movement && alive && health > 0 && !level_complete && !game_complete)
	{
		hud(health, min, max);

		x = 10;

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
		while (answer != "up" && answer != "down" && answer != "left" && answer != "right" && answer != "map" && answer != "admin" && answer != "inv")
		{
			cout << "Invalid. Please enter up or down or left or right. ";
			cin >> answer;
		}

		commands(answer, health, alive, floor, board, movement, hori, vert, player, level_complete, max, min, op, invRows, invCols, inventory, zack, fb, game_complete);

		system("cls");
	}

	if (health <= 0)
	{
		alive = false;
	}
	else if (level_complete)
	{
		second_floor(health, max, min, floor, alive, answer, movement, level_complete, op, invRows, invCols, inventory, zack, fb, game_complete);
	}


}

void second_floor(int &health, int &max, int &min, int &floor, bool &alive, string &answer, bool &movement, bool &level_complete, bool &op, int invRows, int invCols, char inventory[][5], char zack, bool &fb, bool &game_complete)
{
	system("cls");
	floor = 3;
	level_complete = false;

	if (!game_complete)
	{
		cout << "As you enter yet anotherroom of the tower you see rickety old chandeliers hazardly hanging from the ceiling. Then a lot coser than before you hear a scream." << endl;
	}


	// Source: http://www.cplusplus.com/forum/beginner/65037/ By whitenite1. This allows for random spawning of encounters
	time_t t;
	srand((unsigned)time(&t));

	char wall_v = 186, wall_h = 205, wall_cross = 206, twall_r = 185, twall_l = 204, twall_u = 203, twall_b = 202, wallcap_h = 254, corner_ul = 201, corner_ur = 187, corner_bl = 200, corner_br = 188, door_h = 215, door_v = 216, encounter = 238; //Level Design, Dianda
	int x = 10;
	int y = 10;
	int i;
	int j;

	int vert = 1;
	int hori = 8;


	char player = 'P';
	char board[10][10] = { { corner_ul, wall_h, wall_h, wall_h, wall_h, wall_h, wall_h, wall_h, wall_h, corner_ur },
	{ wall_v, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',wall_v },
	{ door_v, ' ', ' ', wall_v, ' ', ' ', ' ', ' ', ' ',wall_v },
	{ wall_v, ' ', ' ', wall_v, ' ', ' ', ' ', ' ', ' ',wall_v },
	{ twall_l, wall_h, wall_h, corner_br, ' ', ' ', ' ', ' ', ' ',wall_v },
	{ wall_v, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',wall_v },
	{ wall_v, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',wall_v },
	{ wall_v, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',wall_v },
	{ wall_v, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',wall_v },
	{ corner_bl, wall_h, wall_h, wall_h, wall_h, wall_h, wall_h, wall_h, wall_h, corner_br }
	};
	// The encounter in the room is going to be a weapon. With the weapons they have to be used to update max and min damage.

	board[hori][vert] = player;

	for (x = 0; x < 17; x++)
	{


		i = 1 + rand() % 9;
		j = 1 + rand() % 9;


		while (board[i][j] == ' ')
		{

			board[i][j] = '?';

		}

	}


	while (movement && alive && health > 0 && !level_complete && !game_complete)
	{
		hud(health, min, max);

		x = 10;

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
		while (answer != "up" && answer != "down" && answer != "left" && answer != "right" && answer != "map" && answer != "admin" && answer != "inv")
		{
			cout << "Invalid. Please enter up or down or left or right. ";
			cin >> answer;
		}

		commands(answer, health, alive, floor, board, movement, hori, vert, player, level_complete, max, min, op, invRows, invCols, inventory, zack, fb, game_complete);

		system("cls");
	}

	if (health <= 0)
	{
		alive = false;
	}
	else if (level_complete)
	{
		third_floor(health, max, min, floor, alive, answer, movement, level_complete, op, invRows, invCols, inventory, zack, fb, game_complete);
	}


}
void third_floor(int &health, int &max, int &min, int &floor, bool &alive, string &answer, bool &movement, bool &level_complete, bool &op, int invRows, int invCols, char inventory[][5], char zack, bool &fb, bool &game_complete)
{
	system("cls");
	floor = 4;
	level_complete = false;

	if (!game_complete) 
	{
		cout << "The screaming is growing ever louder and you wonder what horrors await in the next room." << endl;
	}



	// Source: http://www.cplusplus.com/forum/beginner/65037/ By whitenite1. This allows for random spawning of encounters
	time_t t;
	srand((unsigned)time(&t));

	char wall_v = 186, wall_h = 205, wall_cross = 206, twall_r = 185, twall_l = 204, twall_u = 203, twall_b = 202, wallcap_h = 254, corner_ul = 201, corner_ur = 187, corner_bl = 200, corner_br = 188, door_h = 215, door_v = 216, encounter = 238; //Level Design, Dianda
	int x = 10;
	int y = 10;
	int i;
	int j;

	int vert = 1;
	int hori = 8;


	char player = 'P';
	char board[10][10] = { { corner_ul, wall_h, wall_h, twall_u, wall_h, wall_h, wall_h, wall_h, wall_h, corner_ur },
	{ wall_v, ' ', ' ', wall_v, ' ', ' ', ' ', ' ', ' ',wall_v },
	{ wall_v, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',wall_v },
	{ wall_v, ' ', ' ', wall_v, ' ', ' ', ' ', ' ', ' ',wall_v },
	{ wall_v, ' ', ' ', wall_v, ' ', ' ', ' ', ' ', ' ',wall_v },
	{ wall_v, ' ', ' ', wall_v, ' ', ' ', ' ', ' ', ' ',wall_v },
	{ wall_v, ' ', corner_ul, corner_br, ' ', ' ', corner_ul, wall_h, wall_h,twall_r },
	{ wall_v, ' ', wall_v, ' ', ' ', ' ', ' ', ' ', ' ',wall_v },
	{ wall_v, ' ', wall_v, ' ', ' ', ' ', ' ', ' ', ' ',wall_v },
	{ corner_bl, wall_h, twall_b, wall_h, wall_h, wall_h, wall_h, door_h, wall_h, corner_br }
	};
	// The encounter in the room is going to be a weapon. With the weapons they have to be used to update max and min damage.

	board[hori][vert] = player;

	for (x = 0; x < 19; x++)
	{


		i = 1 + rand() % 9;
		j = 1 + rand() % 9;


		while (board[i][j] == ' ')
		{

			board[i][j] = '?';

		}

	}


	while (movement && alive && health > 0 && !level_complete && !game_complete)
	{
		hud(health, min, max);


		x = 10;

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
		while (answer != "up" && answer != "down" && answer != "left" && answer != "right" && answer != "map" && answer != "admin" && answer != "inv")
		{
			cout << "Invalid. Please enter up or down or left or right. ";
			cin >> answer;
		}

		commands(answer, health, alive, floor, board, movement, hori, vert, player, level_complete, max, min, op, invRows, invCols, inventory, zack, fb, game_complete);

		system("cls");
	}

	if (health <= 0)
	{
		alive = false;
	}
	else if (level_complete)
	{
		finale(health, max, min, floor, alive, answer, movement, level_complete, op, invRows, invCols, inventory, zack, fb, game_complete);
	}


}
void finale(int &health, int &max, int &min, int &floor, bool &alive, string &answer, bool &movement, bool &level_complete, bool &op, int invRows, int invCols, char inventory[][5], char zack, bool &fb, bool &game_complete)
{
	system("cls");
	floor = 2;
	level_complete = false;

	if (!game_complete) 
	{
		cout << "As you enter into another room you see light coming through a doorway on the otherside of the room, but it's blocked by a shadowy figure." << endl;
	}


	// Source: http://www.cplusplus.com/forum/beginner/65037/ By whitenite1. This allows for random spawning of encounters
	time_t t;
	srand((unsigned)time(&t));

	char wall_v = 186, wall_h = 205, wall_cross = 206, twall_r = 185, twall_l = 204, twall_u = 203, twall_b = 202, wallcap_h = 254, corner_ul = 201, corner_ur = 187, corner_bl = 200, corner_br = 188, door_h = 215, door_v = 216, encounter = 238; //Level Design, Dianda
	int x = 10;
	int y = 10;
	int i;
	int j;

	int vert = 1;
	int hori = 8;
	


	char player = 'P';
	char board[10][10] = { { corner_ul, wall_h, wall_h, wall_h, door_h, wall_h, wall_h, wall_h, wall_h, corner_ur },
	{ wall_v, ' ', ' ', wall_v, zack, wall_v, ' ', ' ', ' ',wall_v },
	{ wall_v, ' ', ' ', wall_v, ' ', wall_v, ' ', ' ', ' ',wall_v },
	{ wall_v, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',wall_v },
	{ wall_v, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',wall_v },
	{ wall_v, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',wall_v },
	{ wall_v, ' ', ' ', ' ', ' ', ' ', corner_ul, ' ', wall_h,twall_r },
	{ wall_v, ' ', ' ', ' ', ' ', ' ', wall_v, ' ', ' ',wall_v },
	{ wall_v, ' ', ' ', ' ', ' ', ' ', wall_v, ' ', ' ',wall_v },
	{ corner_bl, wall_h, wall_h, wall_h, wall_h, wall_h, twall_b, wall_h, wall_h, corner_br }
	};
	

	board[hori][vert] = player;

	for (x = 0; x < 22; x++)
	{


		i = 1 + rand() % 9;
		j = 1 + rand() % 9;


		while (board[i][j] == ' ')
		{

			board[i][j] = '?';

		}

	}


	while (movement && alive && health > 0 && !level_complete && !game_complete)
	{
		hud(health, min, max);

		x = 10;

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
		while (answer != "up" && answer != "down" && answer != "left" && answer != "right" && answer != "map" && answer != "admin" && answer != "inv")
		{
			cout << "Invalid. Please enter up or down or left or right. ";
			cin >> answer;
		}

		commands(answer, health, alive, floor, board, movement, hori, vert, player, level_complete, max, min, op, invRows, invCols, inventory, zack, fb, game_complete);

		system("cls");
	}

	if (health <= 0)
	{
		alive = false;
	}
	else if (health >= 0)
	{
		cout << "You have defeated the final boss, and you are now free from the tower. As you emerge through the doorway you see the great landscape all around the tower, but you are really high up and must have missed the actual exit on a different floor.\n";
		game_complete = true;
		system("pause");
	
	}

}
//========================================================= End of Levels ==============================================================================

// ============================================================================ Justin Marshall start =========================================================================================================
void combat(int &health, int min, int max, int floor, bool &alive, string &answer, bool &movement, bool &level_complete, int invRows, int invCols, char inventory[][5], bool &op, char zack, bool &fb, bool &game_complete)
{

	int creaturehp;
	string creature;
	int damagedealt;
	int cmin;
	int cmax;
	
		
	monster(floor, cmax, cmin, creature, creaturehp, zack, fb);

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
			cout << "The " << creature << " fell on your head dealing " << red << damagedealt << white << "." << endl;

			cout << "You have " << health << " remaining." << endl;
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
				
				cout << "You flee the battle and you hear the other creatures moving in the distance. " << endl;
				Sleep(2000);
				
				damagedealt = damage(cmin, cmax);
				health = health - damagedealt;


				cout << "The " << creature << " hit you for " << red << damagedealt << white << "." << endl;

				cout << "You have " << health << " remaining." << endl;
				Sleep(2000);
				break;
			
			}
			else if (answer == "item")
			{

				inventoryscreen(inventory, invRows, invCols, min, max, health, op);

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

	if (creaturehp <= 0 && creature != "chandelier")
	{
		cout << "You defeated the " << creature << ". Good Job!" << endl;
		Sleep(500);
	}

	else if (creaturehp <= 0 && creature == "chandelier")
	{
		cout << "The chandlier lies broken upon the floor." << endl;
		Sleep(1000);
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


void monster(int floor, int &maxdam, int &mindam, string &munster, int &creaturehp, char zack, bool &fb)
{
	int yeet;
	int hp;

	srand(time(NULL));
	if (!fb) 
	{
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
	}
	else if(fb)
	{
		munster = "Zachary Moore";
		mindam = 18;
		maxdam = 25;
		creaturehp = 400;
	}



}

void huh(int &health, int &max, int &min, int &floor, bool &alive, string &answer, bool &movement, bool &level_complete, int invRows, int invCols, char inventory[][5], bool &op, char zack, bool &fb, bool &game_complete)
{
	srand(time(NULL));

	int uhh;
	string invAction;
	int item;

	//uhh = 2;
	uhh = 1 + rand() % 2;


	if (uhh == 1) // monster
	{
		combat(health, max, min, floor, alive, answer, movement, level_complete, invRows, invCols, inventory, op, zack, fb, game_complete);

	}
	else if (uhh == 2) 
	{
		item = 1 + rand() % 3;

		if (item == 1) {//potion
			itemSel = 0;
			cout << "You find a potion on the ground.\nWhat would you like to do with it? (pickup or ignore)\n";
			cin >> invAction;
			if (invAction == "pickup") {
				pickUp(inventory, invRows, invCols, op);
				Sleep(3000);
			}
			else if (invAction == "ignore") {
			}
		}
		else if (item == 2) {
			itemSel = 1;
			cout << "You find a loaf of bread on the ground.\nWhat would you like to do with it? (pickup or ignore)\n";
			cin >> invAction;
			if (invAction == "pickup") {
				pickUp(inventory, invRows, invCols, op);
				Sleep(3000);
			}
			else if (invAction == "ignore") {
			}
		}
		else if (item == 3) {
			itemSel = 2;
			cout << "You find a sword on the ground.\nWhat would you like to do with it? (pickup or ignore)\n";
			cin >> invAction;
			if (invAction == "pickup") {
				pickUp(inventory, invRows, invCols, op);
				Sleep(3000);
			}
			else if (invAction == "ignore") {
			}
		}
	}
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
		{ ' ' , '|' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , '|' ,' ' },
		{ ' ' , '|' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , '|' ,' ' },
		{ ' ' , '|' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , '|' ,' ' },
		{ ' ' , '|' , '_' , '_' , '_' , '_' , '_' , '_' , '|' ,' ' },
		{ ' ' , '|' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , '|' ,' ' },
		{ ' ' , '|' , '_' , '_' , '_' , '_' , '_' , '_' , '|' ,' ' },
		{ ' ' , '|' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , '|' ,' ' },
		{ '_' , '|' , '_' , '_' , '_' , '_' , '_' , '_' , '|' ,'_' },
		{ ' ' , '|' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , '|' ,' ' },
		{ ' ' , '|' , '_' , '_' , '_' , '_' , '_' , '_' , '|' ,' ' },

	};

	for (i = 0; i < x; i++)
	{
		for (j = 0; j < y; j++)
		{
			
			cout << board[i][j] << " ";
		
		}
		cout << endl;
	}

	Sleep(3000);

}

void hud(int &health, int &min, int &max)
{
	cout << "Health: " << health << "          " << "Minimum: " << min << "          Maximum: " << max << endl << endl;
	

}

void commands(string &answer, int &health, bool &alive, int &floor, char board[][10], bool &movement, int &hori, int &vert, char &player, bool &level_complete, int &max, int &min, bool &op, int invRows, int invCols, char inventory[][5], char zack, bool &fb, bool &game_complete)
{

	char wall_v = 186, wall_h = 205, wall_cross = 206, twall_r = 185, twall_l = 204, twall_u = 203, twall_b = 202, wallcap_h = 254, corner_ul = 201, corner_ur = 187, corner_bl = 200, corner_br = 188, door_h = 215, door_v = 216, encounter = 238; //Level Design, Dianda
	string response;
	string admin;
	int level;
	int heal;
	bool sword;
	static bool question = false;


	if (movement && (answer == "up" || answer == "down" || answer == "left" || answer == "right"))
	{
	
		if (answer == "up")
		{
			if (board[hori - 1][vert] != wall_h && board[hori - 1][vert] != '?' && board[hori - 1][vert] != door_h && board[hori - 1][vert] != 'b')
			{
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

				huh(health, max, min, floor, alive, answer, movement, level_complete, invRows, invCols, inventory, op, zack, fb, game_complete);
				board[hori][vert] = ' ';
				board[hori - 1][vert] = player;
				hori = hori - 1;
			}
			else if (board[hori - 1][vert] == 'b')
			{
				fb = true;
				combat(health, max, min, floor, alive, answer, movement, level_complete, invRows, invCols, inventory, op, zack, fb, game_complete);
				board[hori][vert] = ' ';
				board[hori - 1][vert] = player;
				hori = hori - 1;
			}

			else if (board[hori - 1][vert] == door_h)
			{
				level_complete = true;
				
			}
			
		}
		else if (answer == "down")
		{

			if (board[hori + 1][vert] != wall_h && board[hori + 1][vert] != '?' && board[hori][vert] != door_h && board[hori + 1][vert] != 'b' && board[hori + 1][vert] != encounter)
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

				huh(health, max, min, floor, alive, answer, movement, level_complete, invRows, invCols, inventory, op, zack, fb, game_complete);
				board[hori][vert] = ' ';
				board[hori + 1][vert] = player;
				hori = hori + 1;

			}
			
			else if ( board[hori][vert] == door_h)
			{
				level_complete = true;
				
			}

			else if (board[hori + 1][vert] == encounter)
			{
				sword = true;
				pickUp(inventory, invRows, invCols, op);

			}

		}
		else if (answer == "left")
		{
			if (board[hori][vert - 1] != wall_v && board[hori][vert - 1] != '?' && board[hori][vert - 1] != door_v)
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

				huh(health, max, min, floor, alive, answer, movement, level_complete, invRows, invCols, inventory, op, zack, fb, game_complete);
				board[hori][vert] = ' ';
				board[hori][vert - 1] = player;
				vert = vert - 1;
			}
			
			else if (board[hori][vert - 1] == door_v )
			{
				level_complete = true;
				
			}

		}
		else if (answer == "right")
		{
			if (board[hori][vert + 1] != wall_v && board[hori][vert + 1] != '?' && board[hori][vert + 1] != door_v && board[hori][vert + 1] != encounter)
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

				huh(health, max, min, floor, alive, answer, movement, level_complete, invRows, invCols, inventory, op, zack, fb, game_complete);

				board[hori][vert] = ' ';
				board[hori][vert + 1] = player;
				vert = vert + 1;
			}
			else if (board[hori][vert + 1] == door_v )
			{
				level_complete = true;
				
			}

		}
		else if (board[hori][vert + 1] == encounter)
		{
			sword = true;
			pickUp(inventory, invRows, invCols, op);

		}


		
	}

	if(answer == "map")
	{
		map();
	}

	if ( answer == "inv")
	{
		inventoryscreen(inventory, invRows, invCols, min, max, health, op);
		Sleep(2000);
	}

	if (answer == "admin")
	{
		system("cls");
		if (!question) {
			cout << "Are you sure you want access to admin commands?" << endl;
			cin >> response;
			if (response == "yes")
			{
				question = true;
			}
		}
		if (response == "yes" || question)
		{
			cout << "Enter in the command you wish to use: ";
			cin >> admin;

			while (admin == "help")
			{
				cout << "Your possible admin commands include: heal, elevator, damage, and op\n";
				cout << "Enter in the command you wish to use: ";
				cin >> admin;
			}
			if (admin == "elevator")
			{
				cout << "Choose a floor: ";
				cin >> level;

				if (level == 1)
				{
					cout << "Don't know why you're going back to the start, but I guess I can't stop you.";
					basement(health, max, min, floor, alive, answer, movement, level_complete, op, invRows, invCols, inventory, fb, game_complete);

				}

				else if (level == 2)
				{

					cout << "Alright, to the second level we go.\n";
					ground_floor(health, max, min, floor, alive, answer, movement, level_complete, op, invRows, invCols, inventory, zack, fb, game_complete);

				}

				else if (level == 3)
				{

					cout << "Not sure you're properly equiped for this floor, but I guess if you want to.\n";
					second_floor(health, max, min, floor, alive, answer, movement, level_complete, op, invRows, invCols, inventory, zack, fb, game_complete);
					
				}

				else if (level == 4)
				{
					cout << "There is plenty of monsters to be found here so good luck.\n";
					third_floor(health, max, min, floor, alive, answer, movement, level_complete, op, invRows, invCols, inventory, zack, fb, game_complete);

				}

				else if (level == 5)
				{
					cout << "Do you have enough potions to take on the boss?\n No, oh well this is the floor you chose.\n";
					finale(health, max, min, floor, alive, answer, movement, level_complete, op, invRows, invCols, inventory, zack, fb, game_complete);
				}
			}

			else if (admin == "heal")
			{
				cout << "Choose an amount to heal for: ";
				cin >> heal;

				health = health + heal;

				if (health > 100)
				{
					health = 100;
					cout << "Your health can't be above 100." << endl;

				}

			}
			else if (admin == "op")
			{	
				op = true;
				pickUp(inventory, invRows, invCols, op);
			}
			
			else if (admin == "damage")
			{
				cout << "What would you like your minimum to be: ";
				cin >> min;
				cout << "What would you like your maximum to be: ";
				cin >> max;
			}
			Sleep(1000);
		}

		else
		{
			cout << "Alright, back to the game you go then.";
			Sleep(1250);
		}
	}
}

// ============================================================================== End Justin Marshall ========================================================================================================
