#pragma once
#define NUMBER_OF_MINES 10 
#define COLUMNS 5
#define ROWS 5
#include <iostream>
#include <ctime>
#include <random>
#include <Windows.h>
#include "Game.h"

class GameFour : public Game
{
	int mineField[ROWS][COLUMNS]; //0 - Nema mine 1 - Ima mina
	int visitedFields[ROWS][COLUMNS]; // 0 - neotvoreni 1 - otvoreni
	int numberOfMines;
	int points;

	void printMineField();
	
	char fieldInfo(int info);
	void gameOver();

public:
	void playGame(User& user) override;
	void printTutorial() override;
	GameFour();
	~GameFour();

};

