#pragma once
#include <iostream>
#include <random>
#include <ctime>
#include "Statistic.h"
#include "Game.h"

using std::cin;
using std::cout;
using std::endl;

class GameThree : public Game
{
	int *numbers;
	int n;
public:
	GameThree();
	GameThree(int);
	void addNumbers();
	GameThree(const GameThree&);
	GameThree(GameThree&&);
	GameThree& operator=(const GameThree&);
	GameThree& operator=(GameThree&&);
	void print();
	int& operator[](int);
	const int& operator[](int) const;
	void drawnNumbers();
	~GameThree();
	int compare(GameThree&) const; 
	virtual void playGame(User& user) override;
	virtual void printTutorial() override;
private:
	bool exists(int);
	bool exists(int) const;
	void copy(const GameThree&);
	void move(GameThree&&);
};

