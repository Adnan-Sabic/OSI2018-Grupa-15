#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include "Score.h"


class Statistic
{
	std::string fileName;
	std::vector<Score> scoreArray;
	int numberOfElements = 0;
	void insertSortedToVector(int);
	void saveToCSVFile();
public:
	Statistic();
	Statistic(std::string);
	void addScore(int);	     //Call when u need to add new score to statistics, send number of points.
	void printStatistic();   //Call when u need to print your statistic and save to CSV if your wish.
	~Statistic();
};

