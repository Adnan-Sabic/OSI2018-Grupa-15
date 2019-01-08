#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream>
#include <ctime>
#include <random>
#include <fstream>
#include <limits>
#include <chrono>


using namespace std;

class Key
{
	string key;

	//Promjenjive koje ce cuvati podatke o datumu i vremenu
	string date, timeT;


public:
	Key();
	Key(int game);
	~Key();
	inline string getKey() { return key; }

	bool isValid(string inputKey);
	bool isUnlocked(string word, string fileName);
};

