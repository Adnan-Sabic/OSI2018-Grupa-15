#pragma once
#include "Statistic.h"
#include "User.h"
//#include "Key.h"							/*TO DO*/

class Game
{
protected:
	//Key key;								/*TO DO*/
	Statistic statistic;
public:
	Game();
	virtual ~Game();
	virtual void playGame(User& user);	    //Igranje igre
	virtual void cancelGame();				//Otkazivanje igre
	virtual void printTutorial();			//Ispis tutoriala
	void printStatistic();					//Ispis statistike
protected:
	virtual bool checkCredit(User& user);				//Provjeri da li korisnik ima dovoljno kredita
};
