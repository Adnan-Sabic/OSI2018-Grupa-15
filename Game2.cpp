#include "Game2.h"
#include <cstdlib>
//#include <algorithm>

#define MAX 25

Game2::Game2(int n) : n(n), arr(new question[n])
{}

Game2::Game2(const Game2& original)
{
	copy(original);
}

Game2::Game2(Game2&& original)
{
	move(std::move(original));
}

Game2::~Game2()
{
	delete [] arr;
	arr = nullptr;
}

void Game2::copy(const Game2& original)
{
	arr = new question[n = original.n];
	for (int i = 0; i < n; ++i)
		arr[i] = original.arr[i];
}

void Game2::move(Game2&& original)
{
	n = std::move(original.n);
	arr = std::move(original.arr);
	original.arr = nullptr;
}

Game2& Game2::operator=(const Game2& other)
{
	if (this != &other)
	{
		this->~Game2();
		copy(other);
	}
	return *this;
}

Game2& Game2::operator=(Game2&& other)
{
	if (this != &other)
	{
		this->~Game2();
		move(std::move(other));
	}
	return *this;
}

bool Game2::checkCredit()   //provjera u main-u
{
	return (this->getCredit() >= 50);
}

void Game2::printTutorial()   // main
{
	std::cout << "Igra se sastoji od 5 pitanja. Za svako od njih ponudjena su po 3 odgovora od kojih je samo jedan tacan.";
	std::cout << "Korisnik treba da unese redni broj odgovora za koji misli da je tacan. ";
	std::cout << "Za svaki tacan odgovor korisnik dobija 20 bodova, dok za netacan gubi 30.";
	std::cout << "Ako odgovori tacno na svih 5 pitanja, dobija jos 50 bodova bonusa.\n" << std::endl;
}

void Game2::playGame()
{
	readQuestions(*this);
	int flag = 0;
	for (int i = 0; i < 5; ++i)
	{
		srand(time(NULL));
		int temp = rand() % MAX;
		std::cout << i+1 << ". ";
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
			(*this) += 20;
		}
		else
		{
			std::cout << "Netacan odgovor!\n" << std::endl;
			(*this) -= 30;
		}
	}
	if (flag == 5)
		(*this) += 50;
	std::cout << "Broj bodova: " << this->getCredit() << std::endl;
}

void Game2::readQuestions(Game2& g)
{
	std::ifstream inFile;
	inFile.open("questions.txt");
	if (inFile.is_open())
	{
		int br = 0;
		while (br != 25)
		{
			std::getline(inFile, g.arr[br].text);
			std::getline(inFile, g.arr[br].ans1);
			std::getline(inFile, g.arr[br].ans2);
			std::getline(inFile, g.arr[br].ans3);
			std::getline(inFile, g.arr[br].correct);
			br++;
		}
		inFile.close();
	}
	else
		std::cout << "Failed opened.";
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

