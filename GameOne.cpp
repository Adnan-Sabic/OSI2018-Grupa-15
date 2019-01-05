#include "GameOne.h"



GameOne::GameOne() : requiredNumber(0)
{
}


GameOne::~GameOne()
{
}

void GameOne::printTutorial()
{
	std::cout << "Ova igra se sastoji u  poga�anju broja na intervalu [1, 100]" << std::endl;
	std::cout << "va� zadatak je da pogodite tra�eni broj koji je izabran na slu�ajan na�in"<< std::endl;
	std::cout << "Imate 5 poku�aja!!!" << std::endl;
	std::cout << "Nakon svakog pogre�nog poku�aja aplikacija �e ispisati da li je uneseni broj manji ili ve�i od tra�enog." << std::endl;
	std::cout << "Ako pogodite tra�eni broj dobijate ( 100 / brojPoku�aja ) bodova za svoj profil." << std::endl;
}

void GameOne::playGame()
{
	this->printTutorial();

	std::mt19937 generator;
	generator.seed(std::time(0));

	std::uniform_int_distribution<uint32_t> number(1, 100);

	requiredNumber = number(generator);
	std::cout << requiredNumber << std::endl;

	std::cout << "Press ENTER to continue...";
	getchar();

	system("cls");
	int attempts = 1;
	int userNumber;
	int points = 0;
	while (attempts <= 5)
	{
		std::cout << "Ostalo vam je jos < " << 5 - attempts + 1 << " > pokusaja" << std::endl;
		std::cout << "Unesite broj: ";
		std::cin >> userNumber;

		if (userNumber < 1 || userNumber > 100)
		{
			std::cout << "Uneseni broj treba biti u intervalu [1,100]!!!" << std::endl<<std::endl;
		}
		else if (userNumber == requiredNumber)
		{
			std::cout << std::endl << "Pogodili ste trazeni broj!!" << std::endl;
			points = 100 / attempts;
			std::cout << "Osvojili ste " << points << " bodova." << std::endl<<std::endl;
			break;
		}
		else if (userNumber > requiredNumber)
		{
			std::cout << "Uneseni broj je veci od trazenog!!" << std::endl;
			std::cout << "Pokusajte ponovo..." << std::endl<<std::endl;
			attempts++;
		}
		else if (userNumber < requiredNumber)
		{
			std::cout << "Uneseni broj je manji od trazenog!!" << std::endl;
			std::cout << "Pokusajte ponovo..." << std::endl << std::endl;
			attempts++;
		}
	}
	if (attempts == 6)
	{
		std::cout << "Niste pogodili trazeni broj." << std::endl;
		std::cout << "Trazeni broj je bio: " << requiredNumber <<std::endl;
		std::cout << "KRAJ IGRE" << std::endl << "Vise srece drugi put!" << std::endl;
	}
}


