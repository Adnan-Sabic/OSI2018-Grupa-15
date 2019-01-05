#pragma once
#include "Game.h"
#include <iostream>
#include <ctime>
#include <random>
#include <Windows.h>
class GameOne : public Game
{
	int requiredNumber;
public:
	GameOne();
	~GameOne();

	void printTutorial() override;
	void playGame() override;
};

