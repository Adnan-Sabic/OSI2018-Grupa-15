#pragma once
#define NUMBER_OF_MINES 10 
#define COLUMNS 5
#define ROWS 5
#include <iostream>
#include <ctime>
#include <random>
#include <Windows.h>
class GameFour
{
	int mineField[ROWS][COLUMNS]; //0 - Nema mine 1 - Ima mina
	int visitedFields[ROWS][COLUMNS]; // 0 - neotvoreni 1 - otvoreni
	int numberOfMines;
	int points;

	void printMineField();
	void printTutorial();
	char fieldInfo(int info);
	void gameOver();

public:
	void playGame();
	GameFour();
	~GameFour();

};

