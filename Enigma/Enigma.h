#include "GameOne.h"
#include "GameTwo.h"
#include "GameThree.h"
#include "GameFour.h"
#include "Game.h"


using namespace std;

void printEnigma();
void printLine();
void printStartMenu(User user);
void printGameMenu(User user, Game game, string gameNumber);
void rollCredits();

void EnigmaApp()
{
	User user;

	GameOne game1;
	GameTwo game2;
	GameThree game3;
	GameFour game4;


	//ISPIS KLJUCEVA

	cout << "KLJUCEVI:" << endl << endl;
	cout << "PRVA IGRA:    ";
	game1.getKey().printKey();
	cout << "DRUGA IGRA:   ";
	game2.getKey().printKey();
	cout << "TRECA IGRA:   ";
	game3.getKey().printKey();
	cout << "CETVRTA IGRA: ";
	game4.getKey().printKey();
	cout << endl <<"POMOCU NJIH CETE MOCI PRISTUPATI SVAKOJ IGRI POSEBNO" << endl;
	cout << "NAPOMENA: OBAVEZNO IH ZAPISITE!!!" << endl << endl;
	cout << "Da biste nastavili dalje pritisnite ENTER..." ;
	getchar();
	system("cls");
	
	string choice; // flag za izbor

	while (true)
	{
		printStartMenu(user);
		cin >> choice;
		system("cls");
		if (choice == "1") //game1.unlocked ... i za ostale
		{
			while (true)
			{
				if (game1.getKey().isUnlocked("game1", "timeTable.txt")) //Da li je igra otkljucana
				{
					while (true)
					{
						printGameMenu(user, game1, "JEDAN");
						cin >> choice;
						system("cls");
						if (choice == "1")
						{
							game1.playGame(user);
						}
						else if (choice == "2")
						{
							game1.printStatistic();
						}
						else if (choice == "3")
						{
							game1.cancelGame();
						}
						else if (choice == "4")
						{
							break;
						}
						else
						{
							cout << "Unijeli ste pogresnu komandu" << endl;
							Sleep(1000);
							system("cls");
						}
					}
					break;
				}
				else
				{
					cout << "Da biste pristupili datoj, prvo je morate otkljucati!!!"
						<< endl << endl << "1 - Unos kljuca" << endl << "2 - Povratak na glavni meni"
						<< endl << "Unesi: ";
					cin >> choice;
					if (choice == "2")
					{
						system("cls");
						break;
					}
					else if(choice == "1")
					{
						cout << "Unesite kljuc: ";
						cin >> choice;
						if (game1.getKey().isValid(choice)) 
						{
							game1.getKey().enterKey(choice);
							system("cls");
						}
						else
						{
							cout << "Uneseni kljuc je neispravan." << endl;
							Sleep(200);
							system("cls");
						}
					}
					else
					{
						cout << endl <<"Unijeli ste pogresnu komandu!" << endl;
						Sleep(1500);
						system("cls");
					}
				}
			}
		}
		else if (choice == "2")
		{
			while (true)
			{
				if (game2.getKey().isUnlocked("game2", "timeTable.txt")) //Da li je igra otkljucana
				{
					while (true)
					{
						printGameMenu(user, game2, "DVA");
						cin >> choice;
						system("cls");
						if (choice == "1")
						{
							game2.playGame(user);
						}
						else if (choice == "2")
						{
							game2.printStatistic();
						}
						else if (choice == "3")
						{
							game2.cancelGame();
						}
						else if (choice == "4")
						{
							break;
						}
						else
						{
							cout << "Unijeli ste pogresnu komandu" << endl;
							Sleep(1000);
							system("cls");
						}
					}
					break;
				}
				else
				{
					cout << "Da biste pristupili datoj, prvo je morate otkljucati!!!"
						<< endl << endl << "1 - Unos kljuca" << endl << "2 - Povratak na glavni meni"
						<< endl << "Unesi: ";
					cin >> choice;
					if (choice == "2")
					{
						system("cls");
						break;
					}
					else if (choice == "1")
					{
						cout << "Unesite kljuc: ";
						cin >> choice;
						if (game2.getKey().isValid(choice))
						{
							game2.getKey().enterKey(choice);
							system("cls");
						}
						else
						{
							cout << "Uneseni kljuc je neispravan." << endl;
							Sleep(200);
							system("cls");
						}
					}
					else
					{
						cout << endl << "Unijeli ste pogresnu komandu!" << endl;
						Sleep(1500);
						system("cls");
					}
				}
			}
		}
		else if (choice == "3")
		{
		while (true)
		{
			if (game3.getKey().isUnlocked("game3", "timeTable.txt")) //Da li je igra otkljucana
			{
				while (true)
				{
					printGameMenu(user, game3, "TRI");
					cin >> choice;
					system("cls");
					if (choice == "1")
					{
						game3.playGame(user);
					}
					else if (choice == "2")
					{
						game3.printStatistic();
					}
					else if (choice == "3")
					{
						game3.cancelGame();
					}
					else if (choice == "4")
					{
						break;
					}
					else
					{
						cout << "Unijeli ste pogresnu komandu" << endl;
						Sleep(1000);
						system("cls");
					}
				}
				break;
			}
			else
			{
				cout << "Da biste pristupili datoj, prvo je morate otkljucati!!!"
					<< endl << endl << "1 - Unos kljuca" << endl << "2 - Povratak na glavni meni"
					<< endl << "Unesi: ";
				cin >> choice;
				if (choice == "2")
				{
					system("cls");
					break;
				}
				else if (choice == "1")
				{
					cout << "Unesite kljuc: ";
					cin >> choice;
					if (game3.getKey().isValid(choice))
					{
						game3.getKey().enterKey(choice);
						system("cls");
					}
					else
					{
						cout << "Uneseni kljuc je neispravan." << endl;
						Sleep(200);
						system("cls");
					}
				}
				else
				{
					cout << endl << "Unijeli ste pogresnu komandu!" << endl;
					Sleep(1500);
					system("cls");
				}
			}
		}
		}
		else if (choice == "4")
		{
		while (true)
		{
			if (game4.getKey().isUnlocked("game4", "timeTable.txt")) //Da li je igra otkljucana
			{
				while (true)
				{
					printGameMenu(user, game4, "CETIRI");
					cin >> choice;
					system("cls");
					if (choice == "1")
					{
						game4.playGame(user);
					}
					else if (choice == "2")
					{
						game4.printStatistic();
					}
					else if (choice == "3")
					{
						game4.cancelGame();
					}
					else if (choice == "4")
					{
						break;
					}
					else
					{
						cout << "Unijeli ste pogresnu komandu" << endl;
						Sleep(1000);
						system("cls");
					}
				}
				break;
			}
			else
			{
				cout << "Da biste pristupili datoj, prvo je morate otkljucati!!!"
					<< endl << endl << "1 - Unos kljuca" << endl << "2 - Povratak na glavni meni"
					<< endl << "Unesi: ";
				cin >> choice;
				if (choice == "2")
				{
					system("cls");
					break;
				}
				else if (choice == "1")
				{
					cout << "Unesite kljuc: ";
					cin >> choice;
					if (game4.getKey().isValid(choice))
					{
						game4.getKey().enterKey(choice);
						system("cls");
					}
					else
					{
						cout << "Uneseni kljuc je neispravan." << endl;
						Sleep(200);
						system("cls");
					}
				}
				else
				{
					cout << endl << "Unijeli ste pogresnu komandu!" << endl;
					Sleep(1500);
					system("cls");
				}
			}
		}
		}
		else if(choice == "5")
		{
		
			break;
		}
		else
		{
			cout << "Unijeli ste pogresnu komandu!!" << endl;
			Sleep(1000);
			system("cls");
			continue;
		}
	}
}

void printEnigma()
{
	cout << "===================================================================="
		<< endl << "                   ENIGMA  -  DOBRODOSLI"
		<< endl << "====================================================================";


	cout << endl << "Pritisnite ENTER da biste nastavili dalje...";
	getchar();
	system("cls");
}

void printLine()
{
	cout << "====================================================================" << endl;
}

void printStartMenu(User user)
{
	printLine();
	cout << "                          MENI                              " << endl;
	printLine();

	cout << "Opcije: " << endl << "1 - Igra jedan:		Pogadjanje broja"
		<< endl << "2 - Igra dva:		Kviz"
		<< endl << "3 - Igra tri:		Bingo"
		<< endl << "4 - Igra cetiri:	Majnsviper"
		<< endl << "5 - Izlaz iz aplikacije" << endl;
	printLine();
	cout << "Trenutno poena:							 " << user.getPoints() << endl;
	printLine();
	cout << "Unesi: ";
}

void printGameMenu(User user, Game game, string gameNumber)
{
	printLine();
	cout << "                          MENI   IGRE  " << gameNumber << "             "<< endl;
	printLine();


	cout << "Opcije: " << endl << "1 - Igranje igre"
		<< endl << "2 - Ispis statistike"
		<< endl << "3 - Otkazivanje/zakljucavanje igre"
		<< endl << "4 - Povratak na glavni meni"
		<< endl;
	game.creditStatus(user);
	cout << "Unesi: ";
}

void rollCredits()
{
	printLine();
	cout << "			DOVIDJENJA" << endl;
	cout <<  endl << endl << "GRUPA 15: " << endl;
	Sleep(1000);
	cout << "Adnan Sabic			";
	Sleep(400);
	cout << "Stefan Gostic" << endl;
	Sleep(400);
	cout << "Natasa Kocic			";
	Sleep(400);
	cout << "Marina Dragojevic" << endl;
	Sleep(400);
	cout << "Srdjan Malinic			";
	Sleep(400);
	cout << "Drazena Vasiljevic" << endl;
	Sleep(400);
	cout << "Andriana Malinovic		";
	Sleep(400);
	cout << "Djordje Kajganic" << endl;
	printLine();
	Sleep(1000);
	system("cls");
	cout << endl << endl << endl << endl << endl;
	cout << "				HVALA NA KORISTENJU APLIKACIJE!!!";
	Sleep(1000);
}