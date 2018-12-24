#pragma once
#include <iostream>
#include <random>
#include <ctime>
#include "Statistic.h"

using std::cin;
using std::cout;
using std::endl;

class ThirdGame
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
private:
	bool exists(int);
	bool exists(int) const;
	void copy(const ThirdGame&);
	void move(ThirdGame&&);
};

