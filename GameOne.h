#pragma once
#include "Game.h"
#include <iostream>
#include <ctime>
#include <random>
#include <Windows.h>


static int timesPlayed = 3;

class GameOne : public Game
{
	int requiredNumber;
	int creditPut = 0;
	bool isUnlocked = true;
public:
	GameOne();
	~GameOne();

	void printTutorial() override;
	void playGame(User& user) override;

	//void cancelGame() override;    /* TO DO */

};

