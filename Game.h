#pragma once
#include <fstream>
#include <ctime>
#include <random>
#include "Statistic.h"			
#include  "User.h"
#include "Key.h"				

static int constructorCalled = 0;

class Game
{
protected:
	Key key;						
	Statistic statistic;			
public:
	Game();
	virtual ~Game();
	virtual void playGame(User& user);		 //Igranje igre
	void cancelGame();						//Otkazivanje igre
	virtual void printTutorial();			//Ispis tutoriala
	void printStatistic();					//Ispis statistike
	inline Key getKey() { return key; }
protected:
	virtual bool checkCredit(User& user);		//Provjeri da li korisnik ima dovoljno kredita
};
