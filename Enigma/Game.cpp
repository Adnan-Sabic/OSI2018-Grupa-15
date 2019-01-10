#include "Game.h"



Game::Game() 
{
	constructorCalled++;
	if (constructorCalled <= 1)
	{
		
		int keySegment;
		std::mt19937 generator;
		generator.seed(std::time(0));
		std::uniform_int_distribution<uint32_t> number(0, 9);

		std::fstream createFile("keys.txt", std::fstream::out | std::fstream::app);
		createFile.close();
		
		std::ofstream inFile;
		inFile.open("keys.txt");
		for (int i = 0; i < 4; i++)
		{
			inFile << "game" << i + 1<< " ";
			int j = 0;
			while (j != 19)
			{
				if (!((j +1 )% 5) && j>0 && (j+1)!=20)
				{
					inFile << "-";
					j++;
				}
				else
				{
					keySegment = number(generator);
					inFile << keySegment;
					j++;
				}
			}
			inFile << std::endl;
		}
	}
}


void Game::printTutorial()
{
}

bool Game::checkCredit(User& user, int minCredit)
{
	if (user.getPoints() >= minCredit) 
	{
		user.setPoint(user.getPoints() - minCredit);
		return true;
	}
	cout << "Nemate dovoljno kredite < " << minCredit << " > na racunu!!"
		<< endl << "Izbacice vas iz igre za 2 sekunde...";
	Sleep(2000);
	system("cls");
	return false;
}

void Game::creditStatus(User & user)
{
	cout << "====================================================================" << endl;
	cout << "Trenutno poena:							 " << user.getPoints() << endl;
	cout << "====================================================================" << endl;
}


void Game::playGame(User& user)
{
}

void Game::cancelGame()
{
	key.permaLock();
	cout << "Zakljucali ste igru!!! Vise je ne mozete igrati do daljnjeg...";
	Sleep(1500);
	system("cls");
}

void Game::printStatistic()
{
	statistic.printStatistic();
}

Game::~Game()
{
}




