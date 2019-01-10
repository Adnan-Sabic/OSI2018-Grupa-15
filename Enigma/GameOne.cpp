#include "GameOne.h"



GameOne::GameOne() : requiredNumber(0), isUnlocked(true), creditPut(0)
{
	statistic = Statistic::Statistic("StatisticLogGame1.txt");
	key = Key::Key(1);

	flagFile.open("timesPlayed.txt", ios::in | ios::out);
	

	flagFile >> timesPlayed;

}


GameOne::~GameOne()
{
}

void GameOne::printTutorial()
{
	std::cout << "Ova igra se sastoji u  pogadjanju broja na intervalu [1, 100]" << std::endl;
	std::cout << "vas zadatak je da pogodite trazeni broj koji je izabran na slucajan nacin"<< std::endl;
	std::cout << "Imate 5 pokusaja!!!" << std::endl;
	std::cout << "Nakon svakog pogresnog pokusaja aplikacija ce ispisati da li je uneseni broj manji ili veci od trazenog." << std::endl;
	std::cout << "Ako pogodite trazeni broj dobijate ( 100 / brojPokusaja ) bodova za svoj profil." << std::endl;
}

void GameOne::playGame(User& user)
{
	if (key.isPermaLocked())
	{
		cout << "Igrica je zakljucana i vise se ne moze igrati!!";
		Sleep(1000);
		system("cls");
		return;
	}

	flagFile.clear();
	flagFile.seekg(0, ios::beg);
	flagFile >> timesPlayed;


	this->printTutorial();
	std::mt19937 generator;
	generator.seed(std::time(0));

	std::uniform_int_distribution<uint32_t> number(1, 100);

	requiredNumber = number(generator);
	
	int attempts = 1;
	int userNumber;
	int points = 0;

	std::cout << "Press ENTER to continue...";
	getchar();
	getchar();

	system("cls");
	cout << requiredNumber << endl;
	if(timesPlayed >= 3)
	{
		while (attempts <= 5)
		{
			std::cout << "Ostalo vam je jos < " << 5 - attempts + 1 << " > pokusaja" << std::endl;
			std::cout << "Unesite broj: ";
			std::cin >> userNumber;

			if (userNumber < 1 || userNumber > 100)
			{
				std::cout << "Uneseni broj treba biti u intervalu [1,100]!!!" << std::endl << std::endl;
			}
			else if (userNumber == requiredNumber)
			{
				std::cout << std::endl << "Pogodili ste trazeni broj!!" << std::endl;
				points = 100 / attempts;
				std::cout << "Osvojili ste " << points << " bodova." << std::endl << std::endl;
				timesPlayed++;
				break;
			}
			else if (userNumber > requiredNumber)
			{
				if (attempts++ != 5) 
				{
					std::cout << "Uneseni broj je veci od trazenog!!" << std::endl;
					std::cout << "Pokusajte ponovo..." << std::endl << std::endl;
				}
				else
				{
					break;
				}
			}
			else if (userNumber < requiredNumber)
			{
				if (attempts++ != 5) 
				{
					std::cout << "Uneseni broj je manji od trazenog!!" << std::endl;
					std::cout << "Pokusajte ponovo..." << std::endl << std::endl;
				}
				else
				{
					break;
				}
			}
		}
		if (attempts == 6)
		{
			system("cls");
			std::cout << "Niste pogodili trazeni broj." << std::endl;
			std::cout << "Trazeni broj je bio: " << requiredNumber << std::endl;
			std::cout << "KRAJ IGRE" << std::endl << "Vise srece drugi put!" << std::endl;
			timesPlayed++;
			
			flagFile.clear();
			flagFile.seekg(0, ios::beg);
			flagFile << timesPlayed;
		}
	}
	else
	{
		while(1)
		{
			std::cout << "Ostalo vam je jos < " << 5 - attempts + 1 << " > pokusaja" << std::endl;
			std::cout << "Unesite broj: ";
			std::cin >> userNumber;
			if (userNumber < 1 || userNumber > 100)
			{
				std::cout << "Uneseni broj treba biti u intervalu [1,100]!!!" << std::endl << std::endl;
			}
			else
			{
				std::cout << std::endl << "Pogodili ste trazeni broj!!" << std::endl;
				points = 100 / attempts;
				std::cout << "Osvojili ste " << points << " bodova." << std::endl << std::endl;
				timesPlayed++;
				
				flagFile.clear();
				flagFile.seekg(0, ios::beg);
				flagFile << timesPlayed;
				break;
			}
		}
	}
	statistic.addScore(points);
	user.setPoint(user.getPoints() + points);

	std::cout << "Stanje na profilu: " << user.getPoints() << std::endl;


	std::cout << "Pritisnite ENTER da biste nastavili dalje...";
	getchar();
	getchar();
	system("cls");
}