#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream>
#include <ctime>
#include <random>
#include <fstream>
#include <Windows.h>
#include <chrono>


using namespace std;

class Key
{
	string key;
	bool permalocked;
	//bool unlocked;
	//Promjenjive koje ce cuvati podatke o datumu i vremenu
	string date, timeT, year;

	int duration;
	string game;

public:
	Key();
	Key(int game);
	~Key();
	inline string getKey() { return key; }

	bool isValid(string inputKey);
	bool isUnlocked(string word, string fileName);

	void enterKey(string inputKey);
	inline void permaLock() { permalocked = true;}
	inline bool isPermaLocked() { return permalocked; }
	inline void printKey() { std::cout << key << endl; }
};

