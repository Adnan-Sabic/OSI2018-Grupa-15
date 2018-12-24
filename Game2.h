#pragma once
#include "Game.h"
#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <ctime>

struct question
{
	std::string text, ans1, ans2, ans3, correct;
	friend std::ostream& operator<<(std::ostream&, const question&);
};

class Game2 : public Game
{
	question *arr;
	int n;

public:
	Game2(int = 0);
	Game2(const Game2&);
	Game2(Game2&&);
	Game2& operator=(const Game2&);
	Game2& operator=(Game2&&);
	~Game2();
	virtual bool checkCredit() override;
	virtual void printTutorial();
	virtual void playGame() override;
	static void readQuestions(Game2&);

private:
	void copy(const Game2&);
	void move(Game2&&);


	
};