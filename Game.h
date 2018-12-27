#pragma once
#include "Statistic.h"
//#include "Key.h"					/*TO DO*/

class Game
{
	//Key key;						/*TO DO*/
	Statistic statistic;
public:
	Game();
	virtual ~Game();
	virtual void playGame();	    //Igranje igre
	virtual void cancelGame();		//Otkazivanje igre
	virtual void printTutorial();	//Ispis tutoriala
	void printStatistic();			//Ispis statistike
protected:
	virtual bool checkCredit();		//Provjeri da li korisnik ima dovoljno kredita
};
