#include "GameFour.h"





void GameFour::playGame()
{
	int fieldsOpened = 0;
	while (1) {
		printMineField();
		int x, y;
		std::cout << "Enter the coordinate < x >: ";
		std::cin >> x;
		std::cout << "Enter the coordinate < y >: ";
		std::cin >> y;


		system("cls");
		std::cout << "You entered: ( x , y ) = " << "( " << x << ", " << y << " )" << std::endl;
		if (mineField[x][y])
		{
			
			std::cout << "You lost" << std::endl;
			gameOver();
			getchar();
			getchar();
			system("cls");
			break;
		}
		else
		{
			
			visitedFields[x][y] = 1;
			fieldsOpened++;
		}
		if (fieldsOpened == NUMBER_OF_MINES)
		{
			std::cout << "YOU WON!!!" << std::endl;
			gameOver();
			getchar();
			getchar();

			break;
		}
	}
	
}

GameFour::GameFour() : points(0), numberOfMines(NUMBER_OF_MINES)
{
	std::mt19937 generator;
	generator.seed(std::time(0));
	std::uniform_int_distribution<uint32_t> number(0,4); //std::uniform_int_distribution<uint32_t> number(1, COLUMNS); isto je

	int row, col, k=0;

	for (int i = 0; i < ROWS; i++)
		for (int j = 0; j < COLUMNS; j++)
		{
			mineField[i][j] = 0;
			visitedFields[i][j] = 0;
		}

	for (int i = 0; i < 10; i++)
	{
		while (1)
		{
			col = number(generator);
			row = number(generator);
			if (mineField[row][col] != 0)
				continue;
			else
			{
				mineField[row][col] = 1;
				break;
			}
		}
		
	}
}


GameFour::~GameFour()
{
}


void GameFour::printMineField()
{
	std::cout << "      0  1  2  3  4  "<< std::endl;
	std::cout << "      |  |  |  |  |  " << std::endl;
	std::cout << "      v  v  v  v  v  " << std::endl;
	for (int i = 0; i < ROWS; i++)
	{
		std::cout << i << "- > " ;
		for (int j = 0; j < COLUMNS; j++)
		{
			if (visitedFields[i][j])
				std::cout << " ? ";
			else
				std::cout << " o ";
		}
		std::cout << std::endl;
	}
}

void GameFour::printTutorial()
{
}

char GameFour::fieldInfo(int info)
{
	
	return 0;
}

void GameFour::gameOver()
{
	std::cout << "      0  1  2  3  4  " << std::endl;
	std::cout << "      |  |  |  |  |  " << std::endl;
	std::cout << "      v  v  v  v  v  " << std::endl;
	for (int i = 0; i < ROWS; i++)
	{
		std::cout << i << "- > ";
		for (int j = 0; j < COLUMNS; j++)
		{
			if (mineField[i][j])
				std::cout << " x ";
			else
				std::cout << " o ";
		}
		std::cout << std::endl;
	}
}
