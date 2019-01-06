#include "GameFour.h"





void GameFour::playGame(User& user)
{
	printTutorial();
	int points = 0;
	int fieldsOpened = 0;
	while (1) {
		printMineField();
		int x, y;
		std::cout << "Unesi koordinatu < x >: ";
		std::cin >> x;
		std::cout << "Unesite koordinatu < y >: ";
		std::cin >> y;

		if (visitedFields[x][y] || x > 4 || x<0 || y <0 || y>4)
		{
			std::cout << "Vec ste otvorili ovo polje ili su unesene koordinate neispravne!!" << std::endl;
			continue;
		}

		system("cls");
		std::cout << "Unijeli ste: ( x , y ) = " << "( " << x << ", " << y << " )" << std::endl;
		if (mineField[x][y])
		{
			
			std::cout << "IZGUBILI STE !!" << std::endl << std::endl;
			points = points - 30;
			std::cout << "Osvojeni poeni: " << points << std::endl;
			points = points + user.getPoints();
			user.setPoint(points);
			std::cout << "Na profilu: " <<user.getPoints() << std::endl; //izbrisi
			gameOver();
			getchar();
			getchar();
			system("cls");
			break;
		}
		else
		{
			points = points + 20;
			std::cout << "Osvojeni poeni: " << points << std::endl;
			visitedFields[x][y] = 1;
			fieldsOpened++;
		}
		if (fieldsOpened == NUMBER_OF_MINES)
		{
			std::cout << "POBIJEDILI STE!!!" << std::endl;
			std::cout << "Osvojili ste 300 poena" << std::endl;
			points = points + user.getPoints();
			user.setPoint(points);
			std::cout << "Na profilu: " <<user.getPoints() << std::endl; //izbrisi
			gameOver();
			getchar();
			getchar();

			break;
		}
	}
	
}

GameFour::GameFour() : points(0), numberOfMines(NUMBER_OF_MINES)
{
	statistic = Statistic::Statistic("StatisticLogGame4.txt");
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
				std::cout << " X ";
			else
				std::cout << " o ";
		}
		std::cout << std::endl;
	}
}



void GameFour::printTutorial()
{
	std::cout << "Ova igrica se sastoji u pronalazenju polja na kojima nema mina" << std::endl;
	std::cout << "Polja su oznacena tako i tako" << std::endl;
	std::cout << "Za svako polje na kojem nema mine dobijate +nesto" << std::endl;
	std::cout << "U slucaju da otvorite polje na kome je mina gubite -toliko" << std::endl;
	
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
				std::cout << " B ";
			else if (visitedFields[i][j])
				std::cout << " X ";
			else
				std::cout << " o ";
		}
		std::cout << std::endl;
	}
}
