#include "GameOne.h"
#include "GameTwo.h"
#include "GameThree.h"
#include "GameFour.h"
#include "Game.h"


using namespace std;

class MenuPrintFunctions
{
public:
	MenuPrintFunctions();
	static void EnigmaApp();
	static void printEnigma();
	static void printLine();
	static void printStartMenu(User user);
	static void printGameMenu(User user, Game game, string gameNumber);
	static void rollCredits();
	~MenuPrintFunctions();
};

