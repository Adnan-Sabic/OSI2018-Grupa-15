#include "User.h"


User::User()
{
	std::ifstream inFile;
	inFile.open("UserLog.txt");
	if (inFile.is_open())
	{
		std::getline(inFile, username);
		if (username.empty())
		{
			do {
				std::cout << "Unesite vase korisnicko ime:" << std::endl;
				std::getline(std::cin, username);
			} while (!validUsername(username));
			inFile.close();
			std::ofstream outFile;
			outFile.open("UserLog.txt");
			outFile << username << std::endl << points;
			outFile.close();
		}
		else
		{
			printWelcomeMassage();
			std::string temp;
			std::getline(inFile, temp);
			points = std::stoi(temp);
			inFile.close();
		}
	}
	else
	{
		std::cout << "File didn't open successfully" << std::endl;
	}
}

void User::setPoint(int points)
{
	this->points = points;
	std::ofstream outFile;
	outFile.open("UserLog.txt");
	outFile << this->username << std::endl << points;
	outFile.close();
}



bool User::validUsername(std::string& username)
{
	if (username.length() > 20 || std::isdigit(username.at(0)) || hasSpecialChar(username))
	{
		std::cout << "Vase korisnicko ime nije validno." << std::endl;
		return false;
	}
	return true;
}


bool User::hasSpecialChar(std::string const &str) {
	return std::find_if(str.begin(), str.end(), [](char ch) { return !(ch ==' ' || isalnum(ch) || ch == '_'); }) != str.end();
}

void User::printWelcomeMassage()
{
	std::cout << "Pozdrav " << username << std::endl;
}

User::~User()
{
}
