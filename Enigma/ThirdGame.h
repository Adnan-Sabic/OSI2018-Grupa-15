#pragma once
#include <iostream>
#include <random>
#include <ctime>
#include "Statistic.h"
#include "Game.h"

using std::cin;
using std::cout;
using std::endl;

class ThirdGame : public Game
{
	int *numbers;
	int n;
public:
	ThirdGame();
	ThirdGame(int);
	void addNumbers();
	ThirdGame(const ThirdGame&);
	ThirdGame(ThirdGame&&);
	ThirdGame& operator=(const ThirdGame&);
	ThirdGame& operator=(ThirdGame&&);
	void print();
	int& operator[](int);
	const int& operator[](int) const;
	void drawnNumbers();
	~ThirdGame();
	int compare(ThirdGame&) const; 
	virtual void playGame(User& user) override;
	virtual void printTutorial() override;
private:
	bool exists(int);
	bool exists(int) const;
	void copy(const ThirdGame&);
	void move(ThirdGame&&);
};

