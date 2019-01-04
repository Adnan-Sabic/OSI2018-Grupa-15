#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include <vector>



class Key
{
	std::string key;
public:
	Key();
	bool isValid(int) noexcept;
	bool isExpired(int) noexcept;
	friend std::istream& operator>> (std::istream&, Key&);
private:
	
};

