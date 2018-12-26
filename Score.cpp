#include "Score.h"

Score::Score()
{
}

Score::Score(int points)
{
	this->points = points;
	//get current time
	auto timenow = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
	date = ctime(&timenow);
	//delete new line from date string
	date.erase(date.length() - 1);
}

Score::Score(std::string line)
{
	std::string tempPoints = line;
	this -> date = line.substr(0, line.length() - 4);
	tempPoints = tempPoints.substr(tempPoints.length() - 4, tempPoints.length());
	trim(tempPoints);
	trim(date);
	this->points = std::stoi(tempPoints);
}


std::string Score::toString()
{
	return  date +"            "+ std::to_string(points);
}

std::string Score::toCSVString()
{
	return date + "," + std::to_string(points);
}




//Methods to trim a string.
void Score::ltrim(std::string &s)
{
	s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](int ch) {
		return !std::isspace(ch);
	}));
}

void Score::rtrim(std::string &s)
{
	s.erase(std::find_if(s.rbegin(), s.rend(), [](int ch) {
		return !std::isspace(ch);
	}).base(), s.end());
}

void Score::trim(std::string &s)
{
	ltrim(s);
	rtrim(s);
}


Score::~Score()
{
}
