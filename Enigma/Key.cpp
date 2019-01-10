#include "Key.h"



Key::Key()
{}

Key::Key(int gameNumber) : permalocked(false)
{

	fstream file;
	file.open("keys.txt", ios::out | ios::in);
	game = "gameX";
	game[4] = (char)(48 + gameNumber);

	string tmpKey, tmpGame;

	while (file >> tmpGame >> tmpKey)
	{
		if (tmpGame == game)
		{
			key = tmpKey;
			break;
		}
	}											//Citanje kljuca iz datoteke


												//Upis datuma isteka kljuca
	
	if (gameNumber == 1)
		duration = 168;
	else if (gameNumber == 2)
		duration = 1;
	else if (gameNumber == 3)
		duration = 24;
	else
		duration = 200; // 0 umjesto beskonacno


	
}

Key::~Key()
{
}

bool Key::isValid(string inputKey)
{
	if (this->key == inputKey)
		return true;
	return false;
}

bool Key::isUnlocked(string word, string fileName)
{
	int oldpos = 0;
	string tempDay, tempMonth, tempDate, tempTime;
	string line, temp, lineTemp;
	std::ifstream file;
	file.open(fileName, std::fstream::out | std::fstream::app);
	//cout << line;
	if (file.is_open())
	{
		while (getline(file, line))
		{
			if (line.find(word, 0) != string::npos) {
				{
					file >> temp >> tempDay >> tempMonth >> date >> timeT;
					if (temp == "")
					{
						file.clear();
						file.seekg(0, ios::beg);
						file >> temp >> tempDay >> tempMonth >> date >> timeT;
					}
					if (temp != word)
					{
						file.clear();
						file.seekg(oldpos);
						file >> temp >> tempDay >> tempMonth >> date >> timeT;
					}
					fstream helpingFile("helpMe.txt", std::fstream::out);
					auto start = std::chrono::system_clock::now();
					std::time_t now_c = std::chrono::system_clock::to_time_t(start);
					helpingFile << std::ctime(&now_c) << endl;
					helpingFile.close();
					std::ifstream file2;
					file2.open("helpMe.txt", std::fstream::out | std::fstream::app);
					file2 >> tempDay >> tempMonth >> tempDate >> tempTime >> temp;
					int dateHelp1 = stoi(date);
					int dateHelp2 = stoi(tempDate);
					if ((dateHelp1 > dateHelp2) || (dateHelp1 == dateHelp2 && timeT > tempTime))
					{
						helpingFile.close();
						return true;
					}
					else
					{
						continue;
					}
				}
			}
			oldpos = file.tellg();
		}
		return false;
	}
	else
	{
		std::cout << "Fajl se nije mogao otvoriti!" << std::endl;
		return false;
	}
}

void Key::enterKey(string inputKey)
{
	//string tmpInputKey;
	fstream keyDuration("timeTable.txt", std::fstream::out | std::fstream::app);
	while (1)		// Unos kljuca i provjera da li je vec otkljucana
	{
		// is permalocked break;
												//cout << "1 - izlazak ili Unesite kljuc: ";
		if (isValid(inputKey))
		{
			if (isUnlocked(game, "timeTable.txt"))
			{
				cout << endl << "Ova igra je vec otkljucana!";
				break;
			}
			auto start = std::chrono::system_clock::now();
			std::time_t now_c = std::chrono::system_clock::to_time_t(start + std::chrono::hours(duration));
			keyDuration << game << " " << std::ctime(&now_c);

			break;
		}
		else
		{
			cout << "Uneseni kljuc nije ispravan" << endl;
			continue;
		}
	}

}

