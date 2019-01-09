#pragma once
#include "Game.h"
#include <iostream>
#include <ctime>
#include <random>
#include <Windows.h>
#include <Map>


static int timesPlayed = 0;

class GameOne : public Game
{
	int requiredNumber;
	int creditPut = 0;
	bool isUnlocked = true;

	bool isEntered(int* arr, int number);
public:
	GameOne();
	~GameOne();

	void printTutorial() override;
	void playGame(User& user) override;


};

