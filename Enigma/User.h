#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include <cctype>
#include <algorithm>


class User
{
	int points = 10;
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

