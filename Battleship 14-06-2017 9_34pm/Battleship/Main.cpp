//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2005 - 2015 Media Design School
//
// File Name : Main.cpp
// Description : Battleships main cpp file
// Author : Jasper Lyons
// Mail : Jasper.Lyo7552@mediadesignschool.co.nz
//
#include <iostream>
#include <string>
#include <conio.h>
#include <Windows.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "Main.h"

#define defaultcolour 7 // Text colouring code learnt from Kerry.
#define red 12
#define teal 11
#define dark_teal 3
#define grey 8
#define white 15

using namespace std;

void PlayGame(); // MASTER FUNCTION
void ClearScreen(short, short); // Clears the console and resets the mouse position to the input values.
void GotoXY(int, int); // Moves the cursor to the input values.
void PlaceAirCraftCarrier(char(&array0)[10][10], char(&array1)[10][10], char(&array2)[10][10], char(&array3)[10][10], bool, char(&array4)[3], BShip&); // Placing the AirCraftCarrier (Length 5).
void PlaceBattleship(char(&array0)[10][10], char(&array1)[10][10], char(&array2)[10][10], char(&array3)[10][10], bool, char(&array4)[3], BShip&); // Placing the Battleship (Length 4).
void PlaceDestroyer(char(&array0)[10][10], char(&array1)[10][10], char(&array2)[10][10], char(&array3)[10][10], bool, char(&array4)[3], BShip&); // Placing the Destroyer (Length 3).
void PlaceSubmarine(char(&array0)[10][10], char(&array1)[10][10], char(&array2)[10][10], char(&array3)[10][10], bool, char(&array4)[3], BShip&); // Placing the Submarine (Length 3).
void PlacePatrolBoat(char(&array)[10][10], char(&array0)[10][10], char(&array1)[10][10], char(&array2)[10][10], bool, char(&array3)[3], BShip&); // Placing the PatrolBoat (Length 2).
void GenerateEnemyShipPositions(char(&array)[10][10], BShip&, BShip&, BShip&, BShip&, BShip&); // Randomly generate the positions of the enemy ships.
void InitialShipPosition(char(&array)[10][10], char, const int); // Checks if the initial position is going to overlap an already placed ship.
void CheckInputLength(char&); // Checks if the input for the ship orientation is more than one character.
void PCheckInputLength(char*); // Checks if the input for the ship orientation is more than one character.
void PrintGrid(char array0[10][10], char array1[10][10], char array2[10][10], char array3[10][10], bool); // Prints the selected array to the console at a certain position.
void ShipGridNavigation(int, char(&array0)[10][10], char(&array1)[10][10], char(&array2)[10][10], char(&array3)[10][10], char, bool, char(&array4)[3]); // Allows the user to move where the ship is being placed.
void SpaceKeyCaseLoop(char(&array)[10][10]); // Checks the grid array and changes and 0s to @.
void ShootEnemy(char(&array0)[10][10], char(&array1)[10][10], char(&array2)[10][10], char(&array3)[10][10], bool, int&, int&); // The player's shooting master function.
void ShootGridNavigation(char(&array0)[10][10], char(&array1)[10][10], char(&array2)[10][10], char(&array3)[10][10], bool, int&, int&); // Navigating where the player wants to shoot.
void EnemyShootingFunction(char(&array0)[10][10], char(&array1)[10][10], char(&array2)[10][10], char(&array3)[10][10]);
void CinFlush(string); // flushes the cin 
void WinChecker(char(&array)[10][10], bool&, char*); // checks if and who has won the game
void CenterString(char*); // Centers and prints text to the console via cout
void SunkCheck(BShip&, BShip&, BShip&, BShip&, BShip&, char(&array)[10][10], short); // checks for sunk ships
void PositionCheck(char(&array)[10][10], BShip&); // Checks the position of the ship in the array
void ClearArea(float _iX, float _iY); // Clears a specific line

int main()
{
	PlayGame();	
	return (0);
}

void PlayGame()
{	
	char cRestart; // Game restart variable
	do {
		/// Declaring/Initializing Variables
		cRestart = NULL; // Setting cRestart to null so the program does not automatically loop.
		bool bDebug = false; // TF: Variable Type	
		bool bGameWon = false;
		char cInput; // TF: Variable Type
		char *pcNewGame = new char; // TF: Dynamic Memory
		char cNewGame = *pcNewGame;
		char* cComputer = "Computer has won!";
		char* cPlayer = "Player has won!";
		int iPositionX = 0; // The x position of the players reticle on the shooting grid.
		int iPositionY = 0; // The y position of the players reticle on the shooting grid.

		char cShipPB[3]; // PatrolBoat x coord, y coord and orientation ( x , y , orientation in that order ) // TF: Pointer Initialised // TF: Dynamic Memory			 	
		char cShipS[3]; // Submarine x y coord and orientation ( x , y , orientation in that order )
		char cShipD[3]; // Destroyer x y coord and orientation ( x , y , orientation in that order )
		char cShipB[3]; // Battleship x y coord and orientation ( x , y , orientation in that order )
		char cShipACC[3]; // Air Craft Carrier x y coord and orientation ( x , y , orientation in that order )

		char cGrid[10][10] = // TF: Array , Player's ship grid
		{
			{ 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x' },
			{ 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x' },
			{ 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x' },
			{ 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x' },
			{ 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x' },
			{ 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x' },
			{ 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x' },
			{ 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x' },
			{ 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x' },
			{ 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x' }
		};

		char cShotsGrid[10][10] = // Player's shot grid
		{
			{ 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x' },
			{ 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x' },
			{ 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x' },
			{ 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x' },
			{ 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x' },
			{ 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x' },
			{ 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x' },
			{ 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x' },
			{ 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x' },
			{ 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x' }
		};

		char cEnemyGrid[10][10] = // Enemy's ship grid
		{
			{ 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x' },
			{ 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x' },
			{ 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x' },
			{ 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x' },
			{ 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x' },
			{ 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x' },
			{ 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x' },
			{ 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x' },
			{ 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x' },
			{ 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x' }
		};

		char cEnemyShotsGrid[10][10] = // Enemy's shot grid
		{
			{ 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x' },
			{ 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x' },
			{ 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x' },
			{ 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x' },
			{ 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x' },
			{ 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x' },
			{ 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x' },
			{ 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x' },
			{ 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x' },
			{ 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x' }
		};


		/// Initilizing Class Instances
		BShip PatrolBoat; // TF: Class Instance
		BShip Submarine(PatrolBoat); // TF: Copy Constructor
		BShip Destroyer;
		BShip Battleship;
		BShip AirCraftCarrier;
		BShip ePatrolBoat; // If prefixed with e, means enemy ship
		BShip eSubmarine;
		BShip eDestroyer;
		BShip eBattleship;
		BShip eAirCraftCarrier;

		/// Title
		cout << "    " << "  ____            _     _     _                _       _               " << endl;
		cout << "    " << " |  _ \\          | |   | |   | |              | |     (_)              " << endl;
		cout << "    " << " | |_) |   __ _  | |_  | |_  | |   ___   ___  | |__    _   _ __    ___ " << endl;
		cout << "    " << " |  _ <   / _` | | __| | __| | |  / _ \\ / __| | '_ \\  | | | '_ \\  / __|" << endl;
		cout << "    " << " | |_) | | (_| | | |_  | |_  | | |  __/ \\__ \\ | | | | | | | |_) | \\__ \\" << endl;
		cout << "    " << " |____/   \\__,_|  \\__|  \\__| |_|  \\___| |___/ |_| |_| |_| | .__/  |___/" << endl;
		cout << "    " << "                                                          | |          " << endl;
		cout << "    " << "                                                          |_|          " << endl;

		CenterString("Would you like to turn debug mode on? T/F: ");
		CheckInputLength(cInput);
		ClearScreen(0, 0);
		if (cInput == 'T')
		{
			bDebug = true;
		}
		CenterString("Would you like to manually place your ships? Or randomly generate positions?");
		cout << endl;
		CenterString("If you'd like to place them manually, type T:");
		cout << endl;
		CenterString(">");
		CheckInputLength(cInput);
		if (cInput == 'T' || cInput == 't')
		{
			/// Player places ships	
			// Placing Air Craft Carrier
			CenterString("Where would you like to place your Aircraft Carrier (Length 5)?");
			cout << endl;
			PlaceAirCraftCarrier(cGrid, cShotsGrid, cEnemyGrid, cEnemyShotsGrid, bDebug, cShipACC, AirCraftCarrier);
			ClearScreen(0, 0);

			// Placing Battleship
			CenterString("Where would you like to place your Battleship (Length 4)?");
			cout << endl;
			PlaceBattleship(cGrid, cShotsGrid, cEnemyGrid, cEnemyShotsGrid, bDebug, cShipB, Battleship);
			ClearScreen(0, 0);

			// Placing Destroyer
			CenterString("Where would you like to place your Destroyer (Length 3)?");
			cout << endl;
			PlaceDestroyer(cGrid, cShotsGrid, cEnemyGrid, cEnemyShotsGrid, bDebug, cShipD, Destroyer);
			ClearScreen(0, 0);

			// Placing Submarine
			CenterString("Where would you like to place your Submarine (Length 3)?");
			cout << endl;
			PlaceSubmarine(cGrid, cShotsGrid, cEnemyGrid, cEnemyShotsGrid, bDebug, cShipS, Submarine);
			ClearScreen(0, 0);

			// Placing Patrol Boat
			CenterString("Where would you like to place your Patrol Boat (Length 2)?");
			cout << endl;
			PlacePatrolBoat(cGrid, cShotsGrid, cEnemyGrid, cEnemyShotsGrid, bDebug, cShipPB, PatrolBoat);
		}
		else
		{
			srand((unsigned int)time(NULL)); // Seeding rand for player ship placement.
			CenterString("> Generating player ship positions..");
			GenerateEnemyShipPositions(cGrid, PatrolBoat, Submarine, Destroyer, Battleship, AirCraftCarrier);
		}

		// Generate Enemy Ship Positions
		cout << endl;
		CenterString("> Generating enemy ship positions..");
		Sleep(3000); // Sleep to make sure the random generation of the enemy ships is different to the players ships.
		GenerateEnemyShipPositions(cEnemyGrid, ePatrolBoat, eSubmarine, eDestroyer, eBattleship, eAirCraftCarrier);
		ClearScreen(0, 0);

		// Shooting
		while (!bGameWon) // TF: Logical Operator
		{
			ShootEnemy(cGrid, cShotsGrid, cEnemyGrid, cEnemyShotsGrid, bDebug, iPositionX, iPositionY);	// Player shoots the enemy
			ClearScreen(0, 6);
			PrintGrid(cGrid, cShotsGrid, cEnemyGrid, cEnemyShotsGrid, bDebug); // Prints grids to console
			SunkCheck(ePatrolBoat, eSubmarine, eDestroyer, eBattleship, eAirCraftCarrier, cShotsGrid, 1); // Check if the enemies ships are sunk	
			WinChecker(cShotsGrid, bGameWon, cPlayer); // Check if the player has won the game
			if (bGameWon) // If the game has been won, break out of the while loop
			{
				break;
			}
			EnemyShootingFunction(cGrid, cShotsGrid, cEnemyGrid, cEnemyShotsGrid);	// Enemy shoots the player
			ClearScreen(0, 6);
			PrintGrid(cGrid, cShotsGrid, cEnemyGrid, cEnemyShotsGrid, bDebug); // Prints grids to console
			SunkCheck(PatrolBoat, Submarine, Destroyer, Battleship, AirCraftCarrier, cEnemyShotsGrid, 0); // Check if the player's ships are sunk		
			WinChecker(cEnemyShotsGrid, bGameWon, cComputer); // Check if the enemy has won the game				
		}
		if (bGameWon)
		{		// if the game has been won, ask the player if they would like to play a new game, if so call PlayGame(), otherwise exit.		
			GotoXY(0, 1);
			CenterString("Would you like to play again? (Y/N): ");
			cout << endl;
			CenterString(">");
			CheckInputLength(cNewGame);
			switch (cNewGame)
			{
			case 'y':
			case 'Y':
				ClearScreen(0, 0);
				delete pcNewGame;
				cRestart = 'Y';
				break;
			case 'n':
			case 'N':				
				ClearScreen(0, 0);
				cout << "               " << "   _____ _____  ______ _____ _____ _______ _____ " << endl;
				cout << "               " << "  / ____|  __ \\|  ____|  __ \\_   _|__   __/ ____|" << endl;
				cout << "               " << " | |    | |__) | |__  | |  | || |    | | | (___  " << endl;
				cout << "               " << " | |    |  _  /|  __| | |  | || |    | |  \\___ \\ " << endl;
				cout << "               " << " | |____| | \\ \\| |____| |__| || |_   | |  ____) |" << endl;
				cout << "               " << "  \\_____|_|  \\_\\______|_____/_____|  |_| |_____/ " << endl;
				cout << endl;
				CenterString("Author: Jasper Lyons");
				cout << endl;
				CenterString("Language: C++");
				cout << endl;
				CenterString("Date: June, 2017");
				_getch();
				break;
			}
		}
	}
	while (cRestart == 'Y');

}

void SunkCheck(BShip& PatrolBoat, BShip& Submarine, BShip& Destroyer, BShip& Battleship, BShip& AirCraftCarrier, char(&cGrid)[10][10], short sEnemyOrPlayer) // TF: Reference
{
	if (PatrolBoat.bSunk == false) // If the boat has already been sunk, don't output that it has been sunk again.
	{
		PositionCheck(cGrid, PatrolBoat); // Check if the ship has been sunk
		if (PatrolBoat.bSunk == true)
		{
			if (sEnemyOrPlayer == 0)
			{
				GotoXY(0, 3);
				CenterString("Your PatrolBoat has been sunk!");
				
			}
			else if (sEnemyOrPlayer == 1)
			{	
				GotoXY(0, 2);
				CenterString("The enemy's PatrolBoat has been sunk!");				
			}
		}
	}
	if (Submarine.bSunk == false) // If the boat has already been sunk, don't output that it has been sunk again.
	{
		PositionCheck(cGrid, Submarine); // Check if the ship has been sunk
		if (Submarine.bSunk == true) // If the ship has been sunk, check if its the enemy or players ship and output that it is sunk to console.
		{
			if (sEnemyOrPlayer == 0)
			{
				GotoXY(0, 3);
				CenterString("Your Submarine has been sunk!");				
			}
			else if (sEnemyOrPlayer == 1)
			{
				GotoXY(0, 2);
				CenterString("The enemy's Submarine has been sunk!");				
			}
		}
	}
	if (Destroyer.bSunk == false) // If the boat has already been sunk, don't output that it has been sunk again.
	{
		PositionCheck(cGrid, Destroyer); // Check if the ship has been sunk
		if (Destroyer.bSunk == true) // If the ship has been sunk, check if its the enemy or players ship and output that it is sunk to console.
		{
			if (sEnemyOrPlayer == 0)
			{
				GotoXY(0, 3);
				CenterString("Your Destroyer has been sunk!");				
			}
			else if (sEnemyOrPlayer == 1)
			{
				GotoXY(0, 2);
				CenterString("The enemy's Destroyer has been sunk!");				
			}
		}
	}
	if (Battleship.bSunk == false) // If the boat has already been sunk, don't output that it has been sunk again.
	{
		PositionCheck(cGrid, Battleship); // Check if the ship has been sunk
		if (Battleship.bSunk == true) // If the ship has been sunk, check if its the enemy or players ship and output that it is sunk to console.
		{
			if (sEnemyOrPlayer == 0)
			{
				GotoXY(0, 3);
				CenterString("Your Battleship has been sunk!");				
			}
			else if (sEnemyOrPlayer == 1)
			{
				GotoXY(0, 2);
				CenterString("The enemy's Battleship has been sunk!");				
			}
		}
	}
	if (AirCraftCarrier.bSunk == false) // If the boat has already been sunk, don't output that it has been sunk again.
	{
		PositionCheck(cGrid, AirCraftCarrier); // Check if the ship has been sunk
		if (AirCraftCarrier.bSunk == true) // If the ship has been sunk, check if its the enemy or players ship and output that it is sunk to console.
		{
			if (sEnemyOrPlayer == 0)
			{
				GotoXY(0, 3);
				CenterString("Your AirCraftCarrier has been sunk!");				
			}
			else if (sEnemyOrPlayer == 1)
			{
				GotoXY(0, 2);
				CenterString("The enemy's AirCraftCarrier has been sunk!");				
			}
		}
	}
} 

void PositionCheck(char(&cGrid)[10][10], BShip& _Ship)
{
	bool bTempBool = true; // Declare and initialize temp bool
	short sTempLength = _Ship.GetLength(); // Set sTempLength to the length of the ship
	short sTempX = _Ship.sXCoord; // Set sTempX to the xcoord of the ship
	short sTempY = _Ship.sYCoord; // Set sTempY to the ycoord of the ship
	switch (_Ship.cOrientation) // Switch based on the orientation of the ship
	{
	case 'h':
	case 'H':
		for (int i = 0; i < sTempLength; i++) // TF: Iteration Structure
		{
			if (cGrid[sTempY][sTempX + i] != '/') // TF: Arithmetic Operator, TF: Relational Operator, TF: Conditional Statement
			{
				bTempBool = false;				
			}			
		}
		if (bTempBool == true) // If bTempBool is true, set the ships sunk bool to true.
		{
			_Ship.bSunk = true;
		}
		break;
	case 'v':
	case 'V':
		for (int i = 0; i < sTempLength; i++)
		{
			if (cGrid[sTempY + i][sTempX] != '/') // If either of these locations in the array do not contain a /, set bTempBool as false.
			{				
				bTempBool = false;				
			}
		}
		if (bTempBool == true) // If bTempBool is true, set the ships sunk bool to true.
		{
			_Ship.bSunk = true;
		}
		break;
	}	
}

void ShootEnemy(char(&cGrid)[10][10], char(&cShotsGrid)[10][10], char(&cEnemyGrid)[10][10], char (&cEnemyShotsGrid)[10][10], bool bDebug, int& iPositionX, int& iPositionY)
{	
	PrintGrid(cGrid, cShotsGrid, cEnemyGrid, cEnemyShotsGrid, bDebug);
	//ClearScreen(0, 6);
	GotoXY(0, 0);
	CenterString("> O = Missed Shot, / = Hit Shot"); 
	cout << endl;
	GotoXY(0, 1);
	CenterString("> Use arrowkeys to move shot, press space to confirm shot.");
	cout << endl;
	ShootGridNavigation(cShotsGrid, cEnemyGrid, cGrid, cEnemyShotsGrid, bDebug, iPositionX, iPositionY); // Call the shooting navigation function
	PrintGrid(cGrid, cShotsGrid, cEnemyGrid, cEnemyShotsGrid, bDebug);
}

void WinChecker(char(&cGrid)[10][10], bool& _bGameWon, char *sName)
{
	short sHitCount = 0; // Declare and Initialize a short to count the number of hits.
	
	for (int i = 0; i < 10; ++i) // Iterate through the array to count the number of hits.
	{
		for (int j = 0; j < 10; ++j)
		{
			if (cGrid[i][j] == '/') // The / character means a hit shot, O means a missed shot
			{				
				sHitCount++;
			}
		}
	}	
	if (sHitCount >= 17) // If all the ship locations have been hit, set game won to true and output who has won to the console.
	{
		_bGameWon = true; 
		//cout << sName << " has won!" << endl;		
		cout << endl;
		ClearArea(0, 0);
		ClearArea(0, 1);
		ClearArea(0, 2);
		ClearArea(0, 3);
		GotoXY(0, 0);		
		CenterString(sName);
		cout << endl;
	}
}

void EnemyShootingFunction(char(&cGrid)[10][10], char(&cShotsGrid)[10][10], char(&cEnemyGrid)[10][10], char(&cEnemyShotsGrid)[10][10])
{
	//When it's the computer's turn, have the computer shoot at a random position on the grid.If the computer hits, record it on the computer’s shots grid.
	//For the computers next shot, if a hit has been made, shoot randomly west, east, north or south of the hit depending on the available positions
	//If a hit is made, keep shooting one across or above that point until a ship is sunk or the shot misses, 
	//if the shot misses shoot in the opposite direction of the original hit.When the ship is sunk, have the computer shoot randomly again.
	//If 5 ships have been sunk, the computer has won the game.


	srand((unsigned int)time(NULL)); // seed rand
	short sXCoord = rand() % 10; // x coord
	short sYCoord = rand() % 10; // y coord
	bool bShotBeenHit = false; // Bool for if a shot has been hit already.
	short sHitXCoord; // Hit X coordinate
	short sHitYCoord; // Hit Y coordinate
	bool bShotMade = false;	// Bool for if a shot has been made, AKA if the enemys turn is over	

	for (int i = 0; i < 10; ++i) // Itterate through the array and check for a hit shot
	{
		for (int j = 0; j < 10; ++j)
		{
			if (cEnemyShotsGrid[i][j] == '/') // The / character means a hit shot, O means a missed shot
			{
				if (cEnemyShotsGrid[i - 1][j] == 'x' || cEnemyShotsGrid[i + 1][j] == 'x' || cEnemyShotsGrid[i][j + 1] == 'x' || cEnemyShotsGrid[i][j - 1] == 'x')
				{ // If a hit shot is found, check if it has an avaliable location to shoot adjacent to it
					bShotBeenHit = true; // set shotbeen hit to true as a viable location has been found
					sHitXCoord = j; // set the location of the hit shot 
					sHitYCoord = i;
					break;
				}
			}			
		}
	}
	
	if (!bShotBeenHit) 
	{ // If no shot has been hit yet, shoot a random location in the array
	start:
		sYCoord = rand() % 10; // randomize the x and y coords
		sXCoord = rand() % 10;
		while (cEnemyShotsGrid[sYCoord][sXCoord] == 'O' || cEnemyShotsGrid[sYCoord][sXCoord] == '/')
		{ // if the location chosen has already had a shot hit or missed, randomize the location again
			sXCoord = rand() % 10; // x coord
			sYCoord = rand() % 10; // y coord
		}
		if (cGrid[sYCoord][sXCoord] == '@') 
		{ // If the location shot contains a ship, set the location to a /
			cGrid[sYCoord][sXCoord] = '/';
			cEnemyShotsGrid[sYCoord][sXCoord] = '/';
			bShotMade = true;			
		}
		else
		{ // Otherwise the shot has been missed, so set the location to an O
			cEnemyShotsGrid[sYCoord][sXCoord] = 'O';
			bShotMade = true;			
		}
	}
	else // If a hit has already been made
	{		
		while (!bShotMade) {
			switch (0)
			{
			case 0: // north
				if ((sHitYCoord - 1) >= 0 && cEnemyShotsGrid[sHitYCoord - 1][sHitXCoord] != 'O' && cEnemyShotsGrid[sHitYCoord - 1][sHitXCoord] != '/')
				{ // If it is possible to shoot to the north of the hit coord, do so, otherwise move to the next case.
					if (cGrid[sHitYCoord - 1][sHitXCoord] == '@')
					{
						cGrid[sHitYCoord - 1][sHitXCoord] = '/';
						cEnemyShotsGrid[sHitYCoord - 1][sHitXCoord] = '/';
						bShotMade = true;
						break;
					}
					else
					{
						cEnemyShotsGrid[sHitYCoord - 1][sHitXCoord] = 'O';
						bShotMade = true;
						break;
					}
				}				
			case 1: // east
				if ((sHitXCoord + 1) <= 9 && cEnemyShotsGrid[sHitYCoord][sHitXCoord + 1] != 'O' && cEnemyShotsGrid[sHitYCoord][sHitXCoord + 1] != '/')
				{// If it is possible to shoot to the east of the hit coord, do so, otherwise move to the next case.
					if (cGrid[sHitYCoord][sHitXCoord + 1] == '@')
					{
						cGrid[sHitYCoord][sHitXCoord + 1] = '/';
						cEnemyShotsGrid[sHitYCoord][sHitXCoord + 1] = '/';
						bShotMade = true;
						break;
					}
					else
					{
						cEnemyShotsGrid[sHitYCoord][sHitXCoord + 1] = 'O';
						bShotMade = true;
						break;
					}
				}				
			case 2: // south
				if ((sHitYCoord + 1) >= 0 && cEnemyShotsGrid[sHitYCoord + 1][sHitXCoord] != 'O' && cEnemyShotsGrid[sHitYCoord + 1][sHitXCoord] != '/')
				{// If it is possible to shoot to the south of the hit coord, do so, otherwise move to the next case.
					if (cGrid[sHitYCoord + 1][sHitXCoord] == '@')
					{
						cGrid[sHitYCoord + 1][sHitXCoord] = '/';
						cEnemyShotsGrid[sHitYCoord + 1][sHitXCoord] = '/';
						bShotMade = true;
						break;
					}
					else
					{
						cEnemyShotsGrid[sHitYCoord + 1][sHitXCoord] = 'O';
						bShotMade = true;
						break;
					}
				}				
			case 3: // west
				if ((sHitXCoord - 1) >= 0 && cEnemyShotsGrid[sHitYCoord][sHitXCoord - 1] != 'O' && cEnemyShotsGrid[sHitYCoord][sHitXCoord - 1] != '/')
				{// If it is possible to shoot to the west of the hit coord, do so, otherwise make a random shot as there is no avaliable position to shoot.
					if (cGrid[sHitYCoord][sHitXCoord - 1] == '@')
					{
						cGrid[sHitYCoord][sHitXCoord - 1] = '/';
						cEnemyShotsGrid[sHitYCoord][sHitXCoord - 1] = '/';
						bShotMade = true;
						break;
					}
					else
					{
						cEnemyShotsGrid[sHitYCoord][sHitXCoord - 1] = 'O';
						bShotMade = true;
						break;
					}
				}
				else
				{
					goto start; // goto start, shoot a random position
				}
				break;
			}
		}
	}
	
}

void ShootGridNavigation(char(&cShotsGrid)[10][10], char(&cEnemyGrid)[10][10], char(&cGrid)[10][10], char(&cEnemyShotsGrid)[10][10], bool bDebug, int& iPositionX, int& iPositionY)
{ // Allows the player to visually navigate where they are going to place their shot.
	int iC = 0;	
	bool bShotPlaced = false;

	if (cShotsGrid[iPositionY][iPositionX] == '/')
	{
		cShotsGrid[iPositionY][iPositionX] = '/';
	}
	else if (cShotsGrid[iPositionY][iPositionX] == 'O')
	{
		cShotsGrid[iPositionY][iPositionX] = 'O';
	}
	else
	{
		cShotsGrid[iPositionY][iPositionX] = '#';
	}

	while (!bShotPlaced)
	{
		PrintGrid(cGrid, cShotsGrid, cEnemyGrid, cEnemyShotsGrid, bDebug);
		//PrintShotsGrid(cShotsGrid);
		iC = 0; // set iC to zero
		switch ((iC = _getch())) { // take input from the keyboard
		case KEY_UP:
			if (cShotsGrid[iPositionY][iPositionX] == '/')
			{
				cShotsGrid[iPositionY][iPositionX] = '/';
			}
			else if (cShotsGrid[iPositionY][iPositionX] == 'O')
			{
				cShotsGrid[iPositionY][iPositionX] = 'O';
			}
			else
			{
				cShotsGrid[iPositionY][iPositionX] = 'x';
			}
			if (iPositionY != 0) // negative increment the y position
			{
				iPositionY--;
			}
			if (cShotsGrid[iPositionY][iPositionX] == '/')
			{
				cShotsGrid[iPositionY][iPositionX] = '/';
			}
			else if (cShotsGrid[iPositionY][iPositionX] == 'O')
			{
				cShotsGrid[iPositionY][iPositionX] = 'O';
			}
			else
			{
				cShotsGrid[iPositionY][iPositionX] = '#';
			}
			ClearScreen(0, 6);
			break;
		case KEY_DOWN:
			if (cShotsGrid[iPositionY][iPositionX] == '/')
			{
				cShotsGrid[iPositionY][iPositionX] = '/';
			}
			else if (cShotsGrid[iPositionY][iPositionX] == 'O')
			{
				cShotsGrid[iPositionY][iPositionX] = 'O';
			}
			else
			{
				cShotsGrid[iPositionY][iPositionX] = 'x';
			}
			if (iPositionY != 9) // increment the y position
			{
				iPositionY++;
			}
			if (cShotsGrid[iPositionY][iPositionX] == '/')
			{
				cShotsGrid[iPositionY][iPositionX] = '/';
			}
			else if (cShotsGrid[iPositionY][iPositionX] == 'O')
			{
				cShotsGrid[iPositionY][iPositionX] = 'O';
			}
			else
			{
				cShotsGrid[iPositionY][iPositionX] = '#';
			}
			ClearScreen(0, 6);
			break;
		case KEY_LEFT:
			if (cShotsGrid[iPositionY][iPositionX] == '/')
			{
				cShotsGrid[iPositionY][iPositionX] = '/';
			}
			else if (cShotsGrid[iPositionY][iPositionX] == 'O')
			{
				cShotsGrid[iPositionY][iPositionX] = 'O';
			}
			else
			{
				cShotsGrid[iPositionY][iPositionX] = 'x';
			}
			if (iPositionX != 0) // negative increment the x position
			{
				iPositionX--;
			}
			if (cShotsGrid[iPositionY][iPositionX] == '/')
			{
				cShotsGrid[iPositionY][iPositionX] = '/';
			}
			else if (cShotsGrid[iPositionY][iPositionX] == 'O')
			{
				cShotsGrid[iPositionY][iPositionX] = 'O';
			}
			else
			{
				cShotsGrid[iPositionY][iPositionX] = '#';
			}
			ClearScreen(0, 6);
			break;
		case KEY_RIGHT:
			if (cShotsGrid[iPositionY][iPositionX] == '/')
			{
				cShotsGrid[iPositionY][iPositionX] = '/';
			}
			else if (cShotsGrid[iPositionY][iPositionX] == 'O')
			{
				cShotsGrid[iPositionY][iPositionX] = 'O';
			}
			else
			{
				cShotsGrid[iPositionY][iPositionX] = 'x';
			}
			if (iPositionX != 9) // increment the x position 
			{
				iPositionX++;
			}
			if (cShotsGrid[iPositionY][iPositionX] == '/')
			{
				cShotsGrid[iPositionY][iPositionX] = '/';
			}
			else if (cShotsGrid[iPositionY][iPositionX] == 'O')
			{
				cShotsGrid[iPositionY][iPositionX] = 'O';
			}
			else
			{
				cShotsGrid[iPositionY][iPositionX] = '#';
			}
			ClearScreen(0, 6);
			break;
		case KEY_SPACE: // When the player chooses where they are shooting, set the position to a / if it was a hit, otherwise set it to a O
			if (cShotsGrid[iPositionY][iPositionX] != 'O'
				&& cShotsGrid[iPositionY][iPositionX] != '/')
			{
				if (cEnemyGrid[iPositionY][iPositionX] == '@')
				{
					cShotsGrid[iPositionY][iPositionX] = '/';
				}
				else
				{
					cShotsGrid[iPositionY][iPositionX] = 'O';
				}				
				bShotPlaced = true;
			}
			ClearScreen(0, 6);
			break;
		default:
			break;
		}
	}
}

void PlacePatrolBoat(char(&cGrid)[10][10], char(&cShotsGrid)[10][10], char(&cEnemyGrid)[10][10], char(&cEnemyShotsGrid)[10][10], bool bDebug, char(&cShipPB)[3], BShip& PatrolBoat)
{	
	PatrolBoat.SetLength(2); // Set the length of the ship to 2
	const int iLength = PatrolBoat.GetLength(); // TF: Constant
	char cOrientation = 0;	// set the orientation to 0

	CenterString("Would you like to place it vertically or horizontally? Enter V or H");
	cout << endl;
	CenterString(">");
	CheckInputLength(cOrientation);
	while (cOrientation != 'V' && cOrientation != 'v' && cOrientation != 'H' && cOrientation != 'h')
	{	// Checking the users input
		CenterString("Invalid selection, try again."); // Tells the user the input is invalid.
		cout << endl;
		CenterString(">");
		CheckInputLength(cOrientation);
	}
	cout << endl;
	ClearScreen(0, 2);
	CenterString("Use the arrow keys to move the position of your boat on the grid!");
	cout << endl;
	CenterString("Press space to choose the position of your Patrol Boat.");

	InitialShipPosition(cGrid, cOrientation, iLength);	// Checking if the initial position of the ship already contains a placed ship. Display ship appropriately.
	ShipGridNavigation(iLength, cGrid, cShotsGrid, cEnemyGrid, cEnemyShotsGrid, cOrientation, bDebug, cShipPB); // Navigate the position of the ship
	PatrolBoat.sXCoord = cShipPB[0]; // Set the boats x, y and orientation depending on what location and orientation was chosen.
	PatrolBoat.sYCoord = cShipPB[1];
	PatrolBoat.cOrientation = cShipPB[2];
}

void PlaceSubmarine(char(&cGrid)[10][10], char(&cShotsGrid)[10][10], char(&cEnemyGrid)[10][10], char(&cEnemyShotsGrid)[10][10], bool bDebug, char(&cShipS)[3], BShip& Submarine)
{
	Submarine.SetLength(3);
	const int iLength = Submarine.GetLength();
	char cOrientation = 0;

	CenterString("Would you like to place it vertically or horizontally? Enter V or H");
	cout << endl;
	CenterString(">");
	CheckInputLength(cOrientation);
	while (cOrientation != 'V' && cOrientation != 'v' && cOrientation != 'H' && cOrientation != 'h')
	{
		CenterString("Invalid selection, try again."); // Tells the user the input is invalid.
		cout << endl;
		CenterString(">");
		CheckInputLength(cOrientation);
	}
	cout << endl;
	ClearScreen(0, 2);
	CenterString("Use the arrow keys to move the position of your boat on the grid!");
	cout << endl;
	CenterString("Press space to choose the position of your Submarine.");

	InitialShipPosition(cGrid, cOrientation, iLength);	// Checking if the initial position of the ship already contains a placed ship.
	ShipGridNavigation(iLength, cGrid, cShotsGrid, cEnemyGrid, cEnemyShotsGrid, cOrientation, bDebug, cShipS);
	Submarine.sXCoord = cShipS[0];
	Submarine.sYCoord = cShipS[1];
	Submarine.cOrientation = cShipS[2];
}

void PlaceDestroyer(char(&cGrid)[10][10], char(&cShotsGrid)[10][10], char(&cEnemyGrid)[10][10], char(&cEnemyShotsGrid)[10][10], bool bDebug, char(&cShipD)[3], BShip& Destroyer)
{
	Destroyer.SetLength(3);
	const int iLength = Destroyer.GetLength();
	char cOrientation = 0;	

	CenterString("Would you like to place it vertically or horizontally? Enter V or H");
	cout << endl;
	CenterString(">");
	CheckInputLength(cOrientation);
	while (cOrientation != 'V' && cOrientation != 'v' && cOrientation != 'H' && cOrientation != 'h')
	{
		CenterString("Invalid selection, try again."); // Tells the user the input is invalid.
		cout << endl;
		CenterString(">");
		CheckInputLength(cOrientation);
	}
	cout << endl;
	ClearScreen(0, 2);
	CenterString("Use the arrow keys to move the position of your boat on the grid!");
	cout << endl;
	CenterString("Press space to choose the position of your Destroyer.");

	InitialShipPosition(cGrid, cOrientation, iLength);	// Checking if the initial position of the ship already contains a placed ship.
	ShipGridNavigation(iLength, cGrid, cShotsGrid, cEnemyGrid, cEnemyShotsGrid, cOrientation, bDebug, cShipD);
	Destroyer.sXCoord = cShipD[0];
	Destroyer.sYCoord = cShipD[1];
	Destroyer.cOrientation = cShipD[2];
}

void PlaceBattleship(char(&cGrid)[10][10], char(&cShotsGrid)[10][10], char(&cEnemyGrid)[10][10], char(&cEnemyShotsGrid)[10][10], bool bDebug, char(&cShipB)[3], BShip& Battleship)
{	
	Battleship.SetLength(4);
	const int iLength = Battleship.GetLength();
	char cOrientation = 0;	

	CenterString("Would you like to place it vertically or horizontally? Enter V or H");
	cout << endl;
	CenterString(">");
	CheckInputLength(cOrientation);
	while (cOrientation != 'V' && cOrientation != 'v' && cOrientation != 'H' && cOrientation != 'h')
	{
		CenterString("Invalid selection, try again."); // Tells the user the input is invalid.
		cout << endl;
		CenterString(">");
		CheckInputLength(cOrientation);
	}
	cout << endl;
	ClearScreen(0, 2);	
	CenterString("Use the arrow keys to move the position of your boat on the grid!");
	cout << endl;
	CenterString("Press space to choose the position of your Battleship.");

	InitialShipPosition(cGrid, cOrientation, iLength);	// Checking if the initial position of the ship already contains a placed ship.
	ShipGridNavigation(iLength, cGrid, cShotsGrid, cEnemyGrid, cEnemyShotsGrid, cOrientation, bDebug, cShipB);
	Battleship.sXCoord = cShipB[0];
	Battleship.sYCoord = cShipB[1];
	Battleship.cOrientation = cShipB[2];
}

void PlaceAirCraftCarrier(char(&cGrid)[10][10], char(&cShotsGrid)[10][10], char(&cEnemyGrid)[10][10], char(&cEnemyShotsGrid)[10][10], bool bDebug, char(&cShipACC)[3], BShip& AirCraftCarrier)
{	
	AirCraftCarrier.SetLength(5);
	const int iLength = AirCraftCarrier.GetLength();
	char cOrientation = 0;		

	CenterString("Would you like to place it vertically or horizontally? Enter V or H");
	cout << endl;
	CenterString(">");
	CheckInputLength(cOrientation);
	while (cOrientation != 'V' && cOrientation != 'v' && cOrientation != 'H' && cOrientation != 'h')
	{
		CenterString("Invalid selection, try again."); // Tells the user the input is invalid.
		cout << endl;
		CenterString(">");
		CheckInputLength(cOrientation);
	}
	cout << endl;
	ClearScreen(0, 2);	
	CenterString("Use the arrow keys to move the position of your boat on the grid!");
	cout << endl;
	CenterString("Press space to choose the position of your Aircraft Carrier.");

	InitialShipPosition(cGrid, cOrientation, iLength);	// Checking if the initial position of the ship already contains a placed ship.	
	ShipGridNavigation(iLength, cGrid, cShotsGrid, cEnemyGrid, cEnemyShotsGrid, cOrientation, bDebug, cShipACC);	
	AirCraftCarrier.sXCoord = cShipACC[0];
	AirCraftCarrier.sYCoord = cShipACC[1];
	AirCraftCarrier.cOrientation = cShipACC[2];
}

void ShipGridNavigation(int _iLength, char(&cGrid)[10][10], char(&cShotsGrid)[10][10], char(&cEnemyGrid)[10][10], char(&cEnemyShotsGrid)[10][10], char _cOrientation, bool bDebug, char(&iXYCoords)[3])
{
	const int iTempLength = _iLength - 1; // Minus one from the length since arrays count from 0.
	_iLength = iTempLength; // Making _iLength = to the length originally passed to the function, so that the other for loops will work as intended.
	int iC = 0;	 // TF: Variable Type
	bool bShipPlaced = false; // Set bool to false, no ship has been placed yet.
	int iPositionX = 0; // Set X position to 0
	int iPositionY = 0; // Set Y position to 0

	while (!bShipPlaced)
	{
		switch (_cOrientation)
		{
		case 'v':
		case 'V':
		{
			PrintGrid(cGrid, cShotsGrid, cEnemyGrid, cEnemyShotsGrid, bDebug); // Print the grids to console
			iC = 0; // Set iC to zero
			switch ((iC = _getch())) { // Take keyboard input
			case KEY_UP:
				for (_iLength; _iLength >= 0; _iLength--)
				{ // Display the ship on the grid visually, itterate based on the length of the ship.
					if (cGrid[iPositionY + _iLength][iPositionX] == '@') // If the position already has an @, do not overwrite it.
						cGrid[iPositionY + _iLength][iPositionX] = '@';
					else
						cGrid[iPositionY + _iLength][iPositionX] = 'x';
				}
				_iLength = iTempLength; // Making _iLength = to the length originally passed to the function, so that the other for loops will work as intended.
				if (iPositionY != 0) // negative increment the y position
				{
					iPositionY--;
				}
				for (_iLength; _iLength >= 0; _iLength--)
				{// Display the ship on the grid visually, itterate based on the length of the ship.
					if (cGrid[iPositionY + _iLength][iPositionX] == '@')
						cGrid[iPositionY + _iLength][iPositionX] = '@';
					else
						cGrid[iPositionY + _iLength][iPositionX] = '0';
				}
				_iLength = iTempLength; // Making _iLength = to the length originally passed to the function, so that the other for loops will work as intended.
				ClearScreen(0, 6);
				break;
			case KEY_DOWN:
				for ((_iLength); _iLength >= 0; _iLength--)
				{// Display the ship on the grid visually, itterate based on the length of the ship.
					if (cGrid[iPositionY + _iLength][iPositionX] == '@')
						cGrid[iPositionY + _iLength][iPositionX] = '@';
					else
						cGrid[iPositionY + _iLength][iPositionX] = 'x';
				}
				_iLength = iTempLength; // Making _iLength = to the length originally passed to the function, so that the other for loops will work as intended.
				if (iPositionY != (9 - _iLength)) // positively increment the y position
				{
					iPositionY++;
				}
				for (_iLength; _iLength >= 0; _iLength--)
				{// Display the ship on the grid visually, itterate based on the length of the ship.
					if (cGrid[iPositionY + _iLength][iPositionX] == '@')
						cGrid[iPositionY + _iLength][iPositionX] = '@';
					else
						cGrid[iPositionY + _iLength][iPositionX] = '0';
				}
				_iLength = iTempLength; // Making _iLength = to the length originally passed to the function, so that the other for loops will work as intended.
				ClearScreen(0, 6);
				break;
			case KEY_LEFT:
				for (_iLength; _iLength >= 0; _iLength--)
				{// Display the ship on the grid visually, itterate based on the length of the ship.
					if (cGrid[iPositionY + _iLength][iPositionX] == '@')
						cGrid[iPositionY + _iLength][iPositionX] = '@';
					else
						cGrid[iPositionY + _iLength][iPositionX] = 'x';
				}
				_iLength = iTempLength; // Making _iLength = to the length originally passed to the function, so that the other for loops will work as intended.
				if (iPositionX != 0) // negatively increment the x position
				{
					iPositionX--;
				}
				for (_iLength; _iLength >= 0; _iLength--)
				{// Display the ship on the grid visually, itterate based on the length of the ship.
					if (cGrid[iPositionY + _iLength][iPositionX] == '@')
						cGrid[iPositionY + _iLength][iPositionX] = '@';
					else
						cGrid[iPositionY + _iLength][iPositionX] = '0';
				}
				_iLength = iTempLength; // Making _iLength = to the length originally passed to the function, so that the other for loops will work as intended.
				ClearScreen(0, 6);
				break;
			case KEY_RIGHT:
				for (_iLength; _iLength != -1; _iLength--)
				{// Display the ship on the grid visually, itterate based on the length of the ship.
					if (cGrid[iPositionY + _iLength][iPositionX] == '@')
						cGrid[iPositionY + _iLength][iPositionX] = '@';
					else
						cGrid[iPositionY + _iLength][iPositionX] = 'x';
				}
				_iLength = iTempLength; // Making _iLength = to the length originally passed to the function, so that the other for loops will work as intended.
				if (iPositionX != 9) // positively increment the x position
				{
					iPositionX++;
				}
				for (_iLength; _iLength != -1; _iLength--)
				{// Display the ship on the grid visually, itterate based on the length of the ship.
					if (cGrid[iPositionY + _iLength][iPositionX] == '@')
						cGrid[iPositionY + _iLength][iPositionX] = '@';
					else
						cGrid[iPositionY + _iLength][iPositionX] = '0';
				}
				_iLength = iTempLength; // Making _iLength = to the length originally passed to the function, so that the other for loops will work as intended.
				ClearScreen(0, 6);
				break;
			case KEY_SPACE: // Based on the length of the ship, set the positions in the array according to where the ship was placed.
				if (_iLength == 4)
				{
					if (cGrid[iPositionY][iPositionX] != '@' // Checking if the positions are already taken by previously placed ships
						&& cGrid[iPositionY + 1][iPositionX] != '@'
						&& cGrid[iPositionY + 2][iPositionX] != '@'
						&& cGrid[iPositionY + 3][iPositionX] != '@'
						&& cGrid[iPositionY + 4][iPositionX] != '@')
					{
						iXYCoords[0] = iPositionY; // Setting array values to be accessed to set the specific boats coordinates and orientation after the function ends.
						iXYCoords[1] = iPositionX;
						iXYCoords[2] = _cOrientation;
						SpaceKeyCaseLoop(cGrid); // Sets all 0 in the array to @ symbols to properly represent a placed ship.
						iPositionX = 0;
						iPositionY = 0;
						bShipPlaced = true; // Set the bool to true to show that the ship has been placed.
					}
				}
				else if (_iLength == 3)
				{
					if (cGrid[iPositionY][iPositionX] != '@'
						&& cGrid[iPositionY + 1][iPositionX] != '@'
						&& cGrid[iPositionY + 2][iPositionX] != '@'
						&& cGrid[iPositionY + 3][iPositionX] != '@')
					{
						iXYCoords[0] = iPositionY;
						iXYCoords[1] = iPositionX;
						iXYCoords[2] = _cOrientation;
						SpaceKeyCaseLoop(cGrid);
						iPositionX = 0;
						iPositionY = 0;
						bShipPlaced = true;
					}
				}
				else if (_iLength == 2)
				{
					if (cGrid[iPositionY][iPositionX] != '@'
						&& cGrid[iPositionY + 1][iPositionX] != '@'
						&& cGrid[iPositionY + 2][iPositionX] != '@')
					{
						iXYCoords[0] = iPositionY;
						iXYCoords[1] = iPositionX;
						iXYCoords[2] = _cOrientation;
						SpaceKeyCaseLoop(cGrid);
						iPositionX = 0;
						iPositionY = 0;
						bShipPlaced = true;
					}
				}
				else if (_iLength == 1)
				{
					if (cGrid[iPositionY][iPositionX] != '@'
						&& cGrid[iPositionY + 1][iPositionX] != '@')
					{
						iXYCoords[0] = iPositionY;
						iXYCoords[1] = iPositionX;
						iXYCoords[2] = _cOrientation;
						SpaceKeyCaseLoop(cGrid);
						iPositionX = 0;
						iPositionY = 0;
						bShipPlaced = true;
					}
				}
				ClearScreen(0, 6);
				PrintGrid(cGrid, cShotsGrid, cEnemyGrid, cEnemyShotsGrid, bDebug);
				break;
			default:
				break;
			}
			break;
		}
		case 'h':
		case 'H':
			PrintGrid(cGrid, cShotsGrid, cEnemyGrid, cEnemyShotsGrid, bDebug);
			iC = 0;
			switch ((iC = _getch())) {
			case KEY_UP:
				for (_iLength; _iLength >= 0; _iLength--)
				{
					if (cGrid[iPositionY][iPositionX + _iLength] == '@')
						cGrid[iPositionY][iPositionX + _iLength] = '@';
					else
						cGrid[iPositionY][iPositionX + _iLength] = 'x';
				}
				_iLength = iTempLength;
				if (iPositionY != 0)
				{
					iPositionY--;
				}
				for (_iLength; _iLength >= 0; _iLength--)
				{
					if (cGrid[iPositionY][iPositionX + _iLength] == '@')
						cGrid[iPositionY][iPositionX + _iLength] = '@';
					else
						cGrid[iPositionY][iPositionX + _iLength] = '0';
				}
				_iLength = iTempLength;
				ClearScreen(0, 6);
				break;
			case KEY_DOWN:
				for (_iLength; _iLength >= 0; _iLength--)
				{
					if (cGrid[iPositionY][iPositionX + _iLength] == '@')
						cGrid[iPositionY][iPositionX + _iLength] = '@';
					else
						cGrid[iPositionY][iPositionX + _iLength] = 'x';
				}
				_iLength = iTempLength;
				if (iPositionY != 9)
				{
					iPositionY++;
				}
				for (_iLength; _iLength >= 0; _iLength--)
				{
					if (cGrid[iPositionY][iPositionX + _iLength] == '@')
						cGrid[iPositionY][iPositionX + _iLength] = '@';
					else
						cGrid[iPositionY][iPositionX + _iLength] = '0';
				}
				_iLength = iTempLength;
				ClearScreen(0, 6);
				break;
			case KEY_LEFT:
				for (_iLength; _iLength >= 0; _iLength--)
				{
					if (cGrid[iPositionY][iPositionX + _iLength] == '@')
						cGrid[iPositionY][iPositionX + _iLength] = '@';
					else
						cGrid[iPositionY][iPositionX + _iLength] = 'x';
				}
				_iLength = iTempLength;
				if (iPositionX != 0)
				{
					iPositionX--;
				}
				for (_iLength; _iLength >= 0; _iLength--)
				{
					if (cGrid[iPositionY][iPositionX + _iLength] == '@')
						cGrid[iPositionY][iPositionX + _iLength] = '@';
					else
						cGrid[iPositionY][iPositionX + _iLength] = '0';
				}
				_iLength = iTempLength;
				ClearScreen(0, 6);
				break;
			case KEY_RIGHT:
				for (_iLength; _iLength >= 0; _iLength--)
				{
					if (cGrid[iPositionY][iPositionX + _iLength] == '@')
						cGrid[iPositionY][iPositionX + _iLength] = '@';
					else
						cGrid[iPositionY][iPositionX + _iLength] = 'x';
				}
				_iLength = iTempLength;
				if (iPositionX != (9 - _iLength))
				{
					iPositionX++;
				}
				for (_iLength; _iLength >= 0; _iLength--)
				{
					if (cGrid[iPositionY][iPositionX + _iLength] == '@')
						cGrid[iPositionY][iPositionX + _iLength] = '@';
					else
						cGrid[iPositionY][iPositionX + _iLength] = '0';
				}
				_iLength = iTempLength;
				ClearScreen(0, 6);
				break;
			case KEY_SPACE:
				if (_iLength == 4)
				{
					if (cGrid[iPositionY][iPositionX] != '@'
						&& cGrid[iPositionY][iPositionX + 1] != '@'
						&& cGrid[iPositionY][iPositionX + 2] != '@'
						&& cGrid[iPositionY][iPositionX + 3] != '@'
						&& cGrid[iPositionY][iPositionX + 4] != '@')
					{
						iXYCoords[0] = iPositionY;
						iXYCoords[1] = iPositionX;
						iXYCoords[2] = _cOrientation;
						SpaceKeyCaseLoop(cGrid);
						iPositionX = 0;
						iPositionY = 0;
						bShipPlaced = true;
					}
				}
				else if (_iLength == 3)
				{
					if (cGrid[iPositionY][iPositionX] != '@'
						&& cGrid[iPositionY][iPositionX + 1] != '@'
						&& cGrid[iPositionY][iPositionX + 2] != '@'
						&& cGrid[iPositionY][iPositionX + 3] != '@')
					{
						iXYCoords[0] = iPositionY;
						iXYCoords[1] = iPositionX;
						iXYCoords[2] = _cOrientation;
						SpaceKeyCaseLoop(cGrid);
						iPositionX = 0;
						iPositionY = 0;
						bShipPlaced = true;
					}
				}
				else if (_iLength == 2)
				{
					if (cGrid[iPositionY][iPositionX] != '@'
						&& cGrid[iPositionY][iPositionX + 1] != '@'
						&& cGrid[iPositionY][iPositionX + 2] != '@')
					{
						iXYCoords[0] = iPositionY;
						iXYCoords[1] = iPositionX;
						iXYCoords[2] = _cOrientation;
						SpaceKeyCaseLoop(cGrid);
						iPositionX = 0;
						iPositionY = 0;
						bShipPlaced = true;
					}
				}
				else if (_iLength == 1)
				{
					if (cGrid[iPositionY][iPositionX] != '@'
						&& cGrid[iPositionY][iPositionX + 1] != '@')
					{
						iXYCoords[0] = iPositionY;
						iXYCoords[1] = iPositionX;
						iXYCoords[2] = _cOrientation;
						SpaceKeyCaseLoop(cGrid);
						iPositionX = 0;
						iPositionY = 0;
						bShipPlaced = true;
					}
				}
				_iLength = iTempLength;
				ClearScreen(0, 6);
				PrintGrid(cGrid, cShotsGrid, cEnemyGrid, cEnemyShotsGrid, bDebug);
				break;
			default:
				break;
			}
			break;
		default:
			break;
		}
	}
}

void GenerateEnemyShipPositions(char(&cEnemyGrid)[10][10], BShip& ePatrolBoat, BShip& eSubmarine, BShip& eDestroyer, BShip& eBattleship, BShip& eAirCraftCarrier)
{
	// Generate Air Craft Carrier position
	srand((unsigned int)time(NULL)); // seed rand

	// Declare & Initialize bools
	bool bAirCraftPlaced = false; 
	bool bBattleshipPlaced = false; 
	bool bDestroyerPlaced = false;
	bool bSubmarinePlaced = false; 
	bool bPatrolBoatPlaced = false; 
	bool bAllPlaced = false; 

	int iVAirCraftXPosition; 
	int iVAirCraftYPosition; 
	int iHAirCraftXPosition;
	int iHAirCraftYPosition; 
	int iVBattleshipXPosition;
	int iVBattleshipYPosition;
	int iHBattleshipXPosition; 
	int iHBattleshipYPosition; 
	int iVDestroyerXPosition; 
	int iVDestroyerYPosition; 
	int iHDestroyerXPosition; 
	int iHDestroyerYPosition;
	int iVSubmarineXPosition;
	int iVSubmarineYPosition; 
	int iHSubmarineXPosition; 
	int iHSubmarineYPosition; 
	int iVPatrolBoatXPosition; 
	int iVPatrolBoatYPosition; 
	int iHPatrolBoatXPosition; 
	int iHPatrolBoatYPosition; 							   
	int iOrientationGen = rand() % 2; // 0 = Vertical, 1 = Horizontal, TF: Pseudo Random Number

	eAirCraftCarrier.SetLength(5); // Set the length of the enemy ships appropriately
	eBattleship.SetLength(4);
	eDestroyer.SetLength(3);
	eSubmarine.SetLength(3);
	ePatrolBoat.SetLength(2);

	while (!bAllPlaced)
	{
		if (bAirCraftPlaced && bBattleshipPlaced && bDestroyerPlaced
			&& bSubmarinePlaced && bPatrolBoatPlaced)
		{ // If all ships have been placed, set bAllPlaced to true and break
			bAllPlaced = true;
			break;
		}
		srand((unsigned int)time(NULL)); // seed srand
		iOrientationGen = rand() % 2; // 1 = Vertical, 0 = Horizontal | Randomly generate orientation
		while (!bAirCraftPlaced) // if aircraftcarrier not yet placed
		{
			switch (iOrientationGen) 
			{
			case 1: // If vertical randomly place within avaliable coordinates ( first 60 array positions avaliable assuming none already taken )
				iVAirCraftXPosition = rand() % 10; // Randomly generate vertical aircraft x & y position
				iVAirCraftYPosition = rand() % 6;
				if (cEnemyGrid[iVAirCraftYPosition][iVAirCraftXPosition] == '@' // Checking if any of the positions about to be overwritten already contain a ship.
					|| cEnemyGrid[iVAirCraftYPosition + 1][iVAirCraftXPosition] == '@'
					|| cEnemyGrid[iVAirCraftYPosition + 2][iVAirCraftXPosition] == '@'
					|| cEnemyGrid[iVAirCraftYPosition + 3][iVAirCraftXPosition] == '@'
					|| cEnemyGrid[iVAirCraftYPosition + 4][iVAirCraftXPosition] == '@')
				{
					srand((unsigned int)time(NULL)); // re seed for new results
					iVAirCraftXPosition = rand() % 10; // re-generate X & Y positions
					iVAirCraftYPosition = rand() % 6;
				}
				else
				{
					cEnemyGrid[iVAirCraftYPosition][iVAirCraftXPosition] = '@'; // Set ship as placed
					cEnemyGrid[iVAirCraftYPosition + 1][iVAirCraftXPosition] = '@';
					cEnemyGrid[iVAirCraftYPosition + 2][iVAirCraftXPosition] = '@';
					cEnemyGrid[iVAirCraftYPosition + 3][iVAirCraftXPosition] = '@';
					cEnemyGrid[iVAirCraftYPosition + 4][iVAirCraftXPosition] = '@';
					bAirCraftPlaced = true; // Set placed variable as true
					eAirCraftCarrier.sXCoord = iVAirCraftXPosition; // Set the enemy BShip's variables according to how it was placed.
					eAirCraftCarrier.sYCoord = iVAirCraftYPosition;
					eAirCraftCarrier.cOrientation = 'V';
				}
				break;
			case 0: // If horizontal randomly place within avaliable coordiantes
				iHAirCraftXPosition = rand() % 6; // Integer horizontal aircraft x & y position
				iHAirCraftYPosition = rand() % 10;
				if (cEnemyGrid[iHAirCraftYPosition][iHAirCraftXPosition] == '@' // Checking if any of the positions about to be overwritten already contain a ship.
					|| cEnemyGrid[iHAirCraftYPosition][iHAirCraftXPosition + 1] == '@'
					|| cEnemyGrid[iHAirCraftYPosition][iHAirCraftXPosition + 2] == '@'
					|| cEnemyGrid[iHAirCraftYPosition][iHAirCraftXPosition + 3] == '@'
					|| cEnemyGrid[iHAirCraftYPosition][iHAirCraftXPosition + 4] == '@')
				{
					srand((unsigned int)time(NULL)); // re seed for new results
					iHAirCraftXPosition = rand() % 6; // re-generate X & Y positions
					iHAirCraftYPosition = rand() % 10;
				}
				else
				{
					cEnemyGrid[iHAirCraftYPosition][iHAirCraftXPosition] = '@'; // Set ship as placed
					cEnemyGrid[iHAirCraftYPosition][iHAirCraftXPosition + 1] = '@';
					cEnemyGrid[iHAirCraftYPosition][iHAirCraftXPosition + 2] = '@';
					cEnemyGrid[iHAirCraftYPosition][iHAirCraftXPosition + 3] = '@';
					cEnemyGrid[iHAirCraftYPosition][iHAirCraftXPosition + 4] = '@';
					bAirCraftPlaced = true; // Set placed variable as true
					eAirCraftCarrier.sXCoord = iHAirCraftXPosition; // Set the enemy BShip's variables according to how it was placed.
					eAirCraftCarrier.sYCoord = iHAirCraftYPosition;
					eAirCraftCarrier.cOrientation = 'H';
				}
				break;
			default:
				cout << "You shouldn't be here (LINE 2393 DEFAULT CASE REACHED)" << endl; // Code should not reach this point.
				break;
			}
		}

		iOrientationGen = rand() % 2; // 1 = Vertical, 0 = Horizontal
		srand((unsigned int)time(NULL));
		while (!bBattleshipPlaced) // Same as above but for the battleship
		{
			switch (iOrientationGen)
			{
			case 1: // If vertical randomly place within avaliable coordinates 
				iVBattleshipXPosition = rand() % 10; // Integer vertical batteship x & y position
				iVBattleshipYPosition = rand() % 7;
				if (cEnemyGrid[iVBattleshipYPosition][iVBattleshipXPosition] == '@' // Checking if any of the positions about to be overwritten already contain a ship.
					|| cEnemyGrid[iVBattleshipYPosition + 1][iVBattleshipXPosition] == '@'
					|| cEnemyGrid[iVBattleshipYPosition + 2][iVBattleshipXPosition] == '@'
					|| cEnemyGrid[iVBattleshipYPosition + 3][iVBattleshipXPosition] == '@')
				{
					srand((unsigned int)time(NULL)); // re seed for new results
					iVBattleshipXPosition = rand() % 10; // re-generate X & Y positions
					iVBattleshipYPosition = rand() % 7;
				}
				else
				{
					cEnemyGrid[iVBattleshipYPosition][iVBattleshipXPosition] = '@';
					cEnemyGrid[iVBattleshipYPosition + 1][iVBattleshipXPosition] = '@';
					cEnemyGrid[iVBattleshipYPosition + 2][iVBattleshipXPosition] = '@';
					cEnemyGrid[iVBattleshipYPosition + 3][iVBattleshipXPosition] = '@';
					bBattleshipPlaced = true;
					eBattleship.sXCoord = iVBattleshipXPosition;
					eBattleship.sYCoord = iVBattleshipYPosition;
					eBattleship.cOrientation = 'V';
				}
				break;
			case 0: // If horizontal randomly place within avaliable coordiantes
				iHBattleshipXPosition = rand() % 7; // Integer horizontal battleship x & y position
				iHBattleshipYPosition = rand() % 10;
				if (cEnemyGrid[iHBattleshipYPosition][iHBattleshipXPosition] == '@' // Checking if any of the positions about to be overwritten already contain a ship.
					|| cEnemyGrid[iHBattleshipYPosition][iHBattleshipXPosition + 1] == '@'
					|| cEnemyGrid[iHBattleshipYPosition][iHBattleshipXPosition + 2] == '@'
					|| cEnemyGrid[iHBattleshipYPosition][iHBattleshipXPosition + 3] == '@')
				{
					srand((unsigned int)time(NULL)); // re seed for new results
					iHBattleshipXPosition = rand() % 7; // re-generate X & Y positions
					iHBattleshipYPosition = rand() % 10;
				}
				else
				{
					cEnemyGrid[iHBattleshipYPosition][iHBattleshipXPosition] = '@';
					cEnemyGrid[iHBattleshipYPosition][iHBattleshipXPosition + 1] = '@';
					cEnemyGrid[iHBattleshipYPosition][iHBattleshipXPosition + 2] = '@';
					cEnemyGrid[iHBattleshipYPosition][iHBattleshipXPosition + 3] = '@';
					bBattleshipPlaced = true;
					eBattleship.sXCoord = iHBattleshipXPosition;
					eBattleship.sYCoord = iHBattleshipYPosition;
					eBattleship.cOrientation = 'H';
				}
				break;
			default:
				cout << "You shouldn't be here (LINE 2393 DEFAULT CASE REACHED)" << endl; // Code should not reach this point.
				break;
			}
		}

		iOrientationGen = rand() % 2; // 1 = Vertical, 0 = Horizontal
		srand((unsigned int)time(NULL));
		while (!bDestroyerPlaced) // Same as above but for the destroyer
		{
			switch (iOrientationGen)
			{
			case 1: // If vertical randomly place within avaliable coordinates
				iVDestroyerXPosition = rand() % 10; // Integer vertical destroyer x & y position
				iVDestroyerYPosition = rand() % 8;
				if (cEnemyGrid[iVDestroyerYPosition][iVDestroyerXPosition] == '@' // Checking if any of the positions about to be overwritten already contain a ship.
					|| cEnemyGrid[iVDestroyerYPosition + 1][iVDestroyerXPosition] == '@'
					|| cEnemyGrid[iVDestroyerYPosition + 2][iVDestroyerXPosition] == '@')
				{
					srand((unsigned int)time(NULL)); // re seed for new results
					iVDestroyerXPosition = rand() % 10; // re-generate X & Y positions
					iVDestroyerYPosition = rand() % 8;
				}
				else
				{
					cEnemyGrid[iVDestroyerYPosition][iVDestroyerXPosition] = '@';
					cEnemyGrid[iVDestroyerYPosition + 1][iVDestroyerXPosition] = '@';
					cEnemyGrid[iVDestroyerYPosition + 2][iVDestroyerXPosition] = '@';
					bDestroyerPlaced = true;
					eDestroyer.sYCoord = iVDestroyerYPosition;
					eDestroyer.sXCoord = iVDestroyerXPosition;
					eDestroyer.cOrientation = 'V';
				}
				break;
			case 0: // If horizontal randomly place within avaliable coordiantes
				iHDestroyerXPosition = rand() % 8; // Integer horizontal destroyer x & y position
				iHDestroyerYPosition = rand() % 10;
				if (cEnemyGrid[iHDestroyerYPosition][iHDestroyerXPosition] == '@' // Checking if any of the positions about to be overwritten already contain a ship.
					|| cEnemyGrid[iHDestroyerYPosition][iHDestroyerXPosition + 1] == '@'
					|| cEnemyGrid[iHDestroyerYPosition][iHDestroyerXPosition + 2] == '@')
				{
					srand((unsigned int)time(NULL)); // re seed for new results
					iHDestroyerXPosition = rand() % 8; // re-generate X & Y positions
					iHDestroyerYPosition = rand() % 10;
				}
				else
				{
					cEnemyGrid[iHDestroyerYPosition][iHDestroyerXPosition] = '@';
					cEnemyGrid[iHDestroyerYPosition][iHDestroyerXPosition + 1] = '@';
					cEnemyGrid[iHDestroyerYPosition][iHDestroyerXPosition + 2] = '@';
					bDestroyerPlaced = true;
					eDestroyer.sYCoord = iHDestroyerYPosition;
					eDestroyer.sXCoord = iHDestroyerXPosition;
					eDestroyer.cOrientation = 'H';
				}
				break;
			default:
				cout << "You shouldn't be here (LINE 2393 DEFAULT CASE REACHED)" << endl; // Code should not reach this point.
				break;
			}
		}

		iOrientationGen = rand() % 2; // 1 = Vertical, 0 = Horizontal
		srand((unsigned int)time(NULL));
		while (!bSubmarinePlaced) // Same as above but for the submarine
		{
			switch (iOrientationGen)
			{
			case 1: // If vertical randomly place within avaliable coordinates
				iVSubmarineXPosition = rand() % 10; // Integer vertical submarine x & y position
				iVSubmarineYPosition = rand() % 8;
				if (cEnemyGrid[iVSubmarineYPosition][iVSubmarineXPosition] == '@' // Checking if any of the positions about to be overwritten already contain a ship.
					|| cEnemyGrid[iVSubmarineYPosition + 1][iVSubmarineXPosition] == '@'
					|| cEnemyGrid[iVSubmarineYPosition + 2][iVSubmarineXPosition] == '@')
				{
					srand((unsigned int)time(NULL)); // re seed for new results
					iVSubmarineXPosition = rand() % 10; // re-generate X & Y positions
					iVSubmarineYPosition = rand() % 8;
				}
				else
				{
					cEnemyGrid[iVSubmarineYPosition][iVSubmarineXPosition] = '@';
					cEnemyGrid[iVSubmarineYPosition + 1][iVSubmarineXPosition] = '@';
					cEnemyGrid[iVSubmarineYPosition + 2][iVSubmarineXPosition] = '@';
					bSubmarinePlaced = true;
					eSubmarine.sYCoord = iVSubmarineYPosition;
					eSubmarine.sXCoord = iVSubmarineXPosition;
					eSubmarine.cOrientation = 'V';
				}
				break;
			case 0: // If horizontal randomly place within avaliable coordiantes
				iHSubmarineXPosition = rand() % 8; // Integer horizontal destroyer x & y position
				iHSubmarineYPosition = rand() % 10;
				if (cEnemyGrid[iHSubmarineYPosition][iHSubmarineXPosition] == '@' // Checking if any of the positions about to be overwritten already contain a ship.
					|| cEnemyGrid[iHSubmarineYPosition][iHSubmarineXPosition + 1] == '@'
					|| cEnemyGrid[iHSubmarineYPosition][iHSubmarineXPosition + 2] == '@')
				{
					srand((unsigned int)time(NULL)); // re seed for new results
					iHSubmarineXPosition = rand() % 8; // re-generate X & Y positions
					iHSubmarineYPosition = rand() % 10;
				}
				else
				{
					cEnemyGrid[iHSubmarineYPosition][iHSubmarineXPosition] = '@';
					cEnemyGrid[iHSubmarineYPosition][iHSubmarineXPosition + 1] = '@';
					cEnemyGrid[iHSubmarineYPosition][iHSubmarineXPosition + 2] = '@';
					bSubmarinePlaced = true;
					eSubmarine.sYCoord = iHSubmarineYPosition;
					eSubmarine.sXCoord = iHSubmarineXPosition;
					eSubmarine.cOrientation = 'H';
				}
				break;
			default:
				cout << "You shouldn't be here (LINE 2393 DEFAULT CASE REACHED)" << endl; // Code should not reach this point.
				break;
			}
		}

		iOrientationGen = rand() % 2; // 1 = Vertical, 0 = Horizontal
		srand((unsigned int)time(NULL));
		while (!bPatrolBoatPlaced) // Same as above but for the patrol boat
		{
			switch (iOrientationGen)
			{
			case 1: // If vertical randomly place within avaliable coordinates
				iVPatrolBoatXPosition = rand() % 10; // Integer vertical submarine x & y position
				iVPatrolBoatYPosition = rand() % 9;
				if (cEnemyGrid[iVPatrolBoatYPosition][iVPatrolBoatXPosition] == '@' // Checking if any of the positions about to be overwritten already contain a ship.
					|| cEnemyGrid[iVPatrolBoatYPosition + 1][iVPatrolBoatXPosition] == '@')
				{
					srand((unsigned int)time(NULL)); // re seed for new results
					iVPatrolBoatXPosition = rand() % 10; // re-generate X & Y positions
					iVPatrolBoatYPosition = rand() % 9;
				}
				else
				{
					cEnemyGrid[iVPatrolBoatYPosition][iVPatrolBoatXPosition] = '@';
					cEnemyGrid[iVPatrolBoatYPosition + 1][iVPatrolBoatXPosition] = '@';
					bPatrolBoatPlaced = true;
					ePatrolBoat.sYCoord = iVPatrolBoatYPosition;
					ePatrolBoat.sXCoord = iVPatrolBoatXPosition;
					ePatrolBoat.cOrientation = 'V';
				}
				break;
			case 0: // If horizontal randomly place within avaliable coordiantes
				iHPatrolBoatXPosition = rand() % 9; // Integer horizontal destroyer x & y position
				iHPatrolBoatYPosition = rand() % 10;
				if (cEnemyGrid[iHPatrolBoatYPosition][iHPatrolBoatXPosition] == '@' // Checking if any of the positions about to be overwritten already contain a ship.
					|| cEnemyGrid[iHPatrolBoatYPosition][iHPatrolBoatXPosition + 1] == '@')
				{
					srand((unsigned int)time(NULL)); // re seed for new results
					iHPatrolBoatXPosition = rand() % 9; // re-generate X & Y positions
					iHPatrolBoatYPosition = rand() % 10;
				}
				else
				{
					cEnemyGrid[iHPatrolBoatYPosition][iHPatrolBoatXPosition] = '@';
					cEnemyGrid[iHPatrolBoatYPosition][iHPatrolBoatXPosition + 1] = '@';
					bPatrolBoatPlaced = true;
					ePatrolBoat.sYCoord = iHPatrolBoatYPosition;
					ePatrolBoat.sXCoord = iHPatrolBoatXPosition;
					ePatrolBoat.cOrientation = 'H';
				}
				break;
			default:
				cout << "You shouldn't be here (LINE 2393 DEFAULT CASE REACHED)" << endl; // Code should not reach this point.
				break;
			}
		}
	}
}

void SpaceKeyCaseLoop(char(&cGrid)[10][10])
{ // Set all 0  in the array to @
	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			if (cGrid[i][j] == '0')
			{
				cGrid[i][j] = '@';
			}
		}
	}
}

void CheckInputLength(char &cOrientation)
{ // Checking the length of the users input and flushing the cin 
	string sInput;
	getline(cin, sInput);
	CinFlush(sInput);

	while (sInput.length() != 1) // Restricting the input for the ship orientation to one character.
	{
		CenterString("Invalid selection, try again.");
		cout << endl; // Tells the user the input is invalid.
		CenterString(">");
		getline(cin, sInput);
		CinFlush(sInput);
	}
	cOrientation = sInput[0]; // Initializes input as the first character in the string 'sInput'
}

void PCheckInputLength(char *cOrientation)
{ // Checking the length of the users input and flushing the cin 
	string sInput;
	getline(cin, sInput);
	CinFlush(sInput);

	while (sInput.length() != 1) // Restricting the input for the ship orientation to one character.
	{
		CenterString("Invalid selection, try again.");
		cout << endl; // Tells the user the input is invalid.
		CenterString(">");
		getline(cin, sInput);
		CinFlush(sInput);
	}
	*cOrientation = sInput[0]; // TF: Dereferencing Pointer
}

void CinFlush(string _sInput)
{
	while (!cin.good())
	{
		cin.clear();
		cin.ignore(1000, '\n');		
		getline(cin, _sInput);
	}
}

void PrintGrid(char cGrid[10][10], char cShotsGrid[10][10], char cEnemyGrid[10][10], char cEnemyShotsGrid[10][10], bool bDebug)
{// Places the players grids and the enemy grids if debug is enabled.
	int iX = 20;
	int iY = 4;
	int iX2 = 41; // the x and y position where the grid is printed in the console
	int iDebugX1 = 20;
	int iDebugY1 = 15;
	int iDebugX2 = 41;	

	GotoXY(iX, iY);
	iY++;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), white);
	cout << "Player's Ship Grid";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), defaultcolour);
	for (int i = 0; i < 10; ++i)
	{
		GotoXY(iX, iY);
		iY++;
		for (int j = 0; j < 10; ++j)
		{
			if (cGrid[i][j] == '@')
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), teal);
				cout << cGrid[i][j];
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), defaultcolour);
			}
			else if (cGrid[i][j] == '/')
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), red);
				cout << cGrid[i][j];
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), defaultcolour);
			}
			else if (cGrid[i][j] == 'O')
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), dark_teal);
				cout << cGrid[i][j];
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), defaultcolour);
			}
			else
			{
				cout << cGrid[i][j];
			}
			cout << " ";
		}
		cout << endl;
	}
	iY = 4;
	GotoXY(iX2, iY);
	iY++;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), white);
	cout << "Player's Shot Grid";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), defaultcolour);
	for (int i = 0; i < 10; ++i)
	{
		GotoXY(iX2, iY);
		iY++;
		for (int j = 0; j < 10; ++j)
		{
			if (cShotsGrid[i][j] == '@')
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), teal);
				cout << cShotsGrid[i][j];
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), defaultcolour);
			}
			else if (cShotsGrid[i][j] == '/')
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), red);
				cout << cShotsGrid[i][j];
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), defaultcolour);
			}
			else if (cShotsGrid[i][j] == 'O')
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), dark_teal);
				cout << cShotsGrid[i][j];
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), defaultcolour);
			}
			else
			{
				cout << cShotsGrid[i][j];
			}
			cout << " ";
		}
		cout << endl;
	}

	// Enemy Grids
	if (bDebug == true)
	{	
		GotoXY(iDebugX1, iDebugY1);
		iDebugY1++;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), white);
		cout << "Enemy's Grid:";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), defaultcolour);
		for (int i = 0; i < 10; ++i)
		{
			GotoXY(iDebugX1, iDebugY1);
			iDebugY1++;
			for (int j = 0; j < 10; ++j)
			{
				if (cEnemyGrid[i][j] == '@')
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), teal);
					cout << cEnemyGrid[i][j];
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), defaultcolour);
				}
				else if (cEnemyGrid[i][j] == '/')
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), red);
					cout << cEnemyGrid[i][j];
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), defaultcolour);
				}
				else if (cEnemyGrid[i][j] == 'O')
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), dark_teal);
					cout << cEnemyGrid[i][j];
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), defaultcolour);
				}
				else
				{
					cout << cEnemyGrid[i][j];
				}
				cout << " ";
				
			}
			cout << endl;
		}
		iDebugY1 = 15;
		GotoXY(iDebugX2, iDebugY1);
		iDebugY1++;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), white);
		cout << "Enemy's Shot Grid:";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), defaultcolour);
		for (int i = 0; i < 10; ++i)
		{
			GotoXY(iDebugX2, iDebugY1);
			iDebugY1++;
			for (int j = 0; j < 10; ++j)
			{
				if (cEnemyShotsGrid[i][j] == '@')
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), teal);
					cout << cEnemyShotsGrid[i][j];
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), defaultcolour);
				}
				else if (cEnemyShotsGrid[i][j] == '/')
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), red);
					cout << cEnemyShotsGrid[i][j];
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), defaultcolour);
				}
				else if (cEnemyShotsGrid[i][j] == 'O')
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), dark_teal);
					cout << cEnemyShotsGrid[i][j];
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), defaultcolour);
				}
				else
				{
					cout << cEnemyShotsGrid[i][j];
				}
				cout << " ";
			}
			cout << endl;
		}
	}
}

void InitialShipPosition(char(&cGrid)[10][10], char cOrientation, int iLength)
{ // Displaying the ships initial position on the grid based on which positions are avaliable
	int i = iLength - 1; // -1 because arrays start from 0	

	if (cOrientation == 'V' || cOrientation == 'v')
	{
		for (i; i >= 0; i--)
		{
			if (cGrid[i][0] != '@')
			{
				cGrid[i][0] = '0';
			}
		}
	}

	else if (cOrientation == 'H' || cOrientation == 'h')
	{
		for (i; i >= 0; i--)
		{
			if (cGrid[0][i] != '@')
			{
				cGrid[0][i] = '0';
			}
		}
	}
}

void ClearScreen(short _iX, short _iY)
{ // Clears the screen based on input values
	COORD coordScreen = { _iX, _iY };
	DWORD cCharsWritten;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	DWORD dwConSize;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hConsole, &csbi);
	dwConSize = csbi.dwSize.X * csbi.dwSize.Y;
	FillConsoleOutputCharacter(hConsole, TEXT(' '), dwConSize,
		coordScreen, &cCharsWritten);
	GetConsoleScreenBufferInfo(hConsole, &csbi);
	FillConsoleOutputAttribute(hConsole, csbi.wAttributes, dwConSize,
		coordScreen, &cCharsWritten);
	SetConsoleCursorPosition(hConsole, coordScreen);
}

void ClearArea(float _iX, float _iY) // TF: Variable Type
{// overwrites a line in the console with spaces
	GotoXY((int)_iX, (int)_iY);
	cout << "                                                                              ";
}

void GotoXY(int _iX, int _iY)
{ // move the cursor position based on input values
	COORD point;
	point.X = _iX;
	point.Y = _iY;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), point);
}

void CenterString(char* _output) 
{ // Outputs text to the console centered
	int iL = (int) strlen(_output); // Sets iL to the length of the string input 
	int iPos = (int)((80 - iL) / 2); // Sets the starting position based on the width of the window minus the length of the string, divided by two.
	for (int i = 0; i < iPos; i++)
	{ // outputs spaces to the console to pad the left side of the screen to simulate centered text
		cout << " ";
	}
	cout << _output; // outputs the string to console
}




