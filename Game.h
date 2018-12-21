#pragma once
#include <iostream>
#include <ctime>

class Game
{
	int credit;
	//Key key; /*TO DO*/
	//Statistic stats; /* TO DO*/

	virtual void printTutorial(); //Ispis tutoriala
								  //virtual Key getKey(); //Kad se napravi klasa Key
								  //virtual int checkKey(Key key) //Kad se napravi klasa Key
	virtual int checkCredit(); //Provjeri da li korisnik ima dovoljno kredita
							   //virtual void enterKey(); //Unos kljuca

							   /*Ovo se mozda moze i za svaku igricu posebno implementirati, ali ako ne bude trebalo izbrisacemo*/
	virtual bool checkIfUserCanWin();
	virtual double howMuchCanUserWin(); //procentualno


public:
	Game();
	virtual ~Game();

	virtual void playGame();  //Igranje igre
	virtual void cancelGame(); //Otkazivanje igre
	virtual void printStat(); //Ispis statistike
	virtual void saveStat(); //Sacuvavanje statistike

};
