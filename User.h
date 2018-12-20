#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include <cctype>
#include <algorithm>

//Before using this class create an empty file "UserLog.txt"!!!
class User
{
public:
	int points = 0;
	std::string username;
public:
	User();
	inline int getPoints() { return points; };
	void setPoint(int);
	inline std::string getUsername() { return username; };
	inline void setUsername(std::string username) { this->username = username; };
	bool validUsername(std::string&);
	bool hasSpecialChar(std::string const&);
	~User();
};

