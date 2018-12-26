#pragma once
#pragma warning(disable : 4996) //_CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream>
#include <chrono> 
#include <ctime>
#include <algorithm> 
#include <cctype>
#include <locale>


//add #pragma warning(disable : 4996) //_CRT_SECURE_NO_WARNINGS
class Score
{
	int points;
	std::string date;
public:
	Score();
	Score(int);
	Score(std::string);
	inline void setPoints(int points) { this->points = points; }
	inline int getPoints() { return points; }
	inline void setDate(std::string date) { this->date = date; }
	inline std::string getDate() { return date; }
	std::string toString();
	std::string toCSVString();
	//Methods to trim a string.
	static void ltrim(std::string&);
	static void rtrim(std::string&);
	static void trim(std::string&);
	~Score();
};

