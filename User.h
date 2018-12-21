#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include <cctype>
#include <algorithm>

//Before using this class create an empty file "UserLog.txt"!!!
class User
{
	int points = 0;
	std::string username;
	bool validUsername(std::string&);
	bool hasSpecialChar(std::string const&);
public:
	User();
	inline int getPoints() { return points; };
	void setPoint(int);
	inline std::string getUsername() { return username; };
	inline void setUsername(std::string username) { this->username = username; };
	void printWelcomeMassage();
	~User();
};

