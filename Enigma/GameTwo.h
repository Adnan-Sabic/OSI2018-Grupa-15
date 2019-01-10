#pragma once
#define MAX 25
#include "Game.h"
#include <Windows.h>
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

class GameTwo : public Game
{
	question *arr;
	int n;
public:
	GameTwo();
	GameTwo(const GameTwo&);
	GameTwo(GameTwo&&);
	GameTwo& operator=(const GameTwo&);
	GameTwo& operator=(GameTwo&&);
	~GameTwo();
	void printTutorial();
	void playGame(User& user) override;
	
private:
	void copy(const GameTwo&);
	void move(GameTwo&&);
	void readQuestions();
	static int search(int, int, int*);
};