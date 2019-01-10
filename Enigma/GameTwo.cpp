#include "GameTwo.h"
#include <cstdlib>
//#include <algorithm>


GameTwo::GameTwo() : n(MAX), arr(new question[MAX])
{
	key = Key::Key(2);
	statistic = Statistic::Statistic("StatisticLogGame2.txt");
}

GameTwo::GameTwo(const GameTwo& original)
{
	copy(original);
}

GameTwo::GameTwo(GameTwo&& original)
{
	move(std::move(original));
}

GameTwo::~GameTwo()
{
	delete [] arr;
	arr = nullptr;
}

void GameTwo::copy(const GameTwo& original)
{
	arr = new question[n = original.n];
	for (int i = 0; i < n; ++i)
		arr[i] = original.arr[i];
}

void GameTwo::move(GameTwo&& original)
{
	n = std::move(original.n);
	arr = std::move(original.arr);
	original.arr = nullptr;
}



GameTwo& GameTwo::operator=(const GameTwo& other)
{
	if (this != &other)
	{
		this->~GameTwo();
		copy(other);
	}
	return *this;
}

GameTwo& GameTwo::operator=(GameTwo&& other)
{
	if (this != &other)
	{
		this->~GameTwo();
		move(std::move(other));
	}
	return *this;
}



void GameTwo::printTutorial()   // main
{
	std::cout	<< "Igra se sastoji od 5 pitanja. Za svako od njih ponudjena su po 3 odgovora od kojih je samo jedan tacan." << std::endl
				<< "Korisnik treba da unese redni broj odgovora za koji misli da je tacan. "
				<< "Za svaki tacan odgovor korisnik dobija 20 bodova, dok za netacan gubi 30."
				<< "Ako odgovori tacno na svih 5 pitanja, dobija jos 50 bodova bonusa.\n" << std::endl;
}

void GameTwo::playGame(User& user)
{
	if (key.isPermaLocked())
	{
		cout << "Igrica je zakljucana i vise se ne moze igrati!!";
		Sleep(1000);
		system("cls");
		return;
	}
	if (!checkCredit(user, 50))
		return;
	

	printTutorial();

	std::cout << "Pritistine ENTER da bi nastavili dalje...";
	getchar();
	getchar();

	system("cls");

	readQuestions();

	int flag = 0;
	int points = 0;
	int br = 0, j = 0, niz[5] = { 0 };
	for (int i = 0; br != 5; ++i)
	{
		srand(time(NULL));
		int temp = rand() % MAX;
		if (search(temp, 5, niz))
		{
			br++;
			niz[j++] = temp;
			std::cout << i + 1 << ". ";
			std::cout << arr[temp];
			std::string a;
			do
			{
				std::cout << "Unesite redni broj tacnog odgovora: ";
				std::cin >> a;
			} while (a != "1" && a != "2" && a != "3");
			if (a == arr[temp].correct)
			{
				std::cout << "Tacan odgovor!\n" << std::endl;
				flag++;
				points += 20;
				std::cout << "Poena osvojeno: " << points << std::endl;
				Sleep(2000);
				system("cls");
			}
			else
			{
				std::cout << "Netacan odgovor!\n" << std::endl;
				points -= 30;
				std::cout << "Poena osvojeno: " << points << std::endl;
				Sleep(2000);
				system("cls");
			}
		}
	}
	if (flag == 5)
		points += 50;
	std::cout << "Osvojeno bodova: " << points << std::endl;
	statistic.addScore(points);
	user.setPoint(points + user.getPoints());
	std::cout << "Stanje na profilu: " << user.getPoints() << std::endl;

	std::cout << std::endl <<"Pritistine ENTER da bi ste nastavili dalje...";
	getchar();
	getchar();

	system("cls");
}

void GameTwo::readQuestions()
{
	std::ifstream inFile;
	inFile.open("Questions.txt");
	
	std::string str1, str2, str3, str4, str5;

	int br = 0;
	while (br != 25)
	{
		std::getline(inFile, arr[br].text);
		std::getline(inFile, arr[br].ans1);
		std::getline(inFile, arr[br].ans2);
		std::getline(inFile, arr[br].ans3);
		std::getline(inFile, arr[br].correct);
		//std::cout << arr[br] << std::endl;
		br++;
	}
	//getchar();
}

int GameTwo::search(int rb, int n, int *niz)
{
	for (int i = 0; i < n; ++i)
		if (niz[i] == rb)
			return 0; 
	return 1;
}

std::ostream& operator<<(std::ostream& str, const question& q)
{
	str << q.text << std::endl;
	str << "   1. " << q.ans1 << std::endl;
	str << "   2. " << q.ans2 << std::endl;
	str << "   3. " << q.ans3 << std::endl;
	str << std::endl;
	return str;
}

