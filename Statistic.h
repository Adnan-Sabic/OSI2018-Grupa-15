#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include "Score.h"


//Before using this class create an empty file with the name of the Score u want to keep Logged!!!
class Statistic
{
	std::string fileName;
	std::vector<Score> scoreArray;
	int numberOfElements = 0;
	void insterSortedToVector(int);
	void saveToCSVFile();
public:
	Statistic();
	Statistic(std::string);
	void addScore(int);	     //Call when u need to add new score to statistics, send number of points.
	void printStatistic();   //Call when u need to print your statistic and save to CSV if your wish.
	~Statistic();
};

