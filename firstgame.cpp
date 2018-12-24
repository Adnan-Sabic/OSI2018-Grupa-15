#include <iostream>
#include <time.h>


double randomNumber()
{

	srand(time(NULL));
	int number = rand() % 100 + 1;
	int attempts = 5;
	int attempts1 = 1;
	int guess;
	std::cout << "Pogodite broj izmedju 0 i 100: " << std::endl;
	do
	{
		std::cout << "Preostalo vam je jos " << attempts << " pokusaja." << std::endl;
		std::cin >> guess;

		if (guess < 1 || guess>100)
		{
			std::cout << "Pogresan unos. Broj mora biti izmedju 0 i 100." << std::endl;
			attempts--;
			attempts1++;
		}

		else if (guess == number)
		{
			std::cout << "Pogodili ste broj." << std::endl;
			return (100.0 / attempts1);
		}

		else if (guess < number)
		{
			std::cout << "Broj koji trazite je veci od unesenog." << std::endl;
			attempts--;
			attempts1++;
		}

		else if (guess > number)
		{
			std::cout << "Broj koji trazite je manji od unesenog." << std::endl;
			attempts--;
			attempts1++;
		}


	} while (attempts > 0);

	std::cout << "Nemate vise pokusaja. Trazeni broj je bio " << number << "." << std::endl;
	return 0;

}void Game1::printTutorial()   // main
{
	std::cout <<"Prva igra je igra pogađanja broja u intervalu od 1 do 100, koji je nasumičnim odabirom izabrala aplikacija.";
	std::cout <<"Cilj igre je da korisnik pogodi broj koji je aplikacija izabrala.";
	std::cout<<"Korisnik ima pet pokušaja za pogađanje zamišljenog broja.";
	std::cout <<"Prilikom svakog pogrešnog pokušaja aplikacija ispisuje da li je uneseni broj manji ili veći od izabranog.";
	std::cout<<"Nakon petog pogrešnog pokušaja korisnik završava igru.";
	std::cout<<"Ako korisnik pogodi traženi broj dobija 100 / broj_pokušaja bodova za svoj profil.";
	
}

int main()
{
	double a;
	a = randomNumber();
	std::cout << "Poeni: " << a << std::endl;
	getchar();
	getchar();
	return 1;
}