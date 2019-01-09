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


		std::fstream inFile;
		inFile.open("keys.txt", ios::out | ios::in);
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

bool Game::checkCredit(User& user)
{
	return false;
}


void Game::playGame(User& user)
{
}

void Game::cancelGame()
{
	key.permaLock();
}

void Game::printStatistic()
{
	statistic.printStatistic();
}

Game::~Game()
{
}




