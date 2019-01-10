#include "GameThree.h"



GameThree::GameThree()
{
	numbers = new int[n = 7];
	statistic = Statistic::Statistic("StatisticLogGame3.txt");
	key = Key::Key(3);
}

GameThree::GameThree(int i)
{
	numbers = new int[i];
	n = i;
	statistic = Statistic::Statistic("StatisticLogGame3.txt");
}

void GameThree::addNumbers()
{
	cout << endl << "Unesite 7 brojeva koji se nalaze u opsegu izmedju 1 i 45:" << endl;
	int temp;

	string errorCheck;

	for (int i = 0; i < n; i++)
	{
		while (1)
		{
			cout << i + 1 << " broj:";
			cin >> errorCheck;

			temp = atoi(errorCheck.c_str());

			if (exists(temp))
			{
				cout << endl << "Taj broj ste vec uzeli, molimo vas da izaberete neki drugi" << endl;
				continue;
			}
			if (temp < 1 || temp > 45)
			{
				cout << "Takav unos je nedozvoljen! Molimo vas da pokusate ponovo." << endl;
				continue;
			}
			else
				break;
		}
		numbers[i] = temp;
	}
	Sleep(1000);
	system("cls");
}

GameThree::GameThree(const GameThree &other)
{
	copy(other);
}

GameThree::GameThree(GameThree &&other)
{
	move(std::move(other));
}

GameThree& GameThree::operator=(const GameThree&other)
{
	if (this == &other)
		return *this;
	this->~GameThree();
	copy(other);
	return *this;
}

GameThree& GameThree::operator=(GameThree &&other)
{
	if (this == &other)
		return *this;
	this->~GameThree();
	move(std::move(other));
	return *this;
}

void GameThree::print()
{
	for (int i = 0; i < n; i++)
		cout << numbers[i] << ", ";
	cout << endl;
}

int & GameThree::operator[](int i)
{
	return numbers[i];
}

const int & GameThree::operator[](int i) const
{
	return numbers[i];
}

void GameThree::drawnNumbers()
{
	const int AMOUNT = 20; 
	const int MAX = 45; 

	srand(time(NULL)); 

	for (int i = 0; i < AMOUNT; i++)
	{
		bool check; 
		int n; 
		do
		{
			n = rand() % MAX + 1;
			check = true;
			for (int j = 0; j < i; j++)
				if (n == numbers[j]) 
				{
					check = false; 
					break; 
				}
		} while (!check); 
		numbers[i] = n; 
	}
}

bool GameThree::exists(int number)
{
	for (int i = 0; i < n; i++)
	{
		if (numbers[i] == number)
			return true;
	}
	return false;
}

bool GameThree::exists(int number) const
{
	for (int i = 0; i < n; i++)
	{
		if (numbers[i] == number)
			return true;
	}
	return false;
}

void GameThree::copy(const GameThree &other)
{
	std::copy(other.numbers, other.n + other.numbers, numbers = new int[n + other.n]);
}

void GameThree::move(GameThree &&other)
{
	n = std::move(other.n);
	numbers = std::move(other.numbers);
	other.numbers = nullptr;
}


int GameThree::compare(GameThree &other) const
{
	std::vector<int> tempArray;
	int randomNumber;
	if (n > other.n)
		return 0;
	int counter = 1;
	int pointsTemp = 0;
	for (int i = 0; i < n; i++)
	{
		int tempCounter = counter;
		for (int j = 0; j < other.n; j++)
		{
			if ((numbers[i] == other.numbers[j]) && (counter <= 4)) // Izvrsava se sve dok se ne pogode 4 broja
			{
				tempArray.push_back(numbers[i]);
				pointsTemp += counter * 10;
				counter++;
			}
			else if ((numbers[i] == other.numbers[j]) && (counter > 4)) // Da bi se sprijecilo da korisnik osvoji vise od 100 bodova
			{
				while (1)
				{
					if (other.exists(numbers[i]))
					{
						srand(time(NULL));
						randomNumber = rand() % (45 - numbers[i] - 1) + 1;
						while (1)
						{
							if (other.exists(randomNumber) || exists(randomNumber)) // Provjera da li postoji randomNumber u jednom od 2 niza
								randomNumber++;
							else
								break;
						}
						other[j] = randomNumber;
					}
					else
						break;
				}
			}
			if (tempCounter != counter)
				break;
		}
	}
	other.print();
	cout << endl;
	cout << "Brojevi koje ste pogodili na izvlacenju su: ";
	for (int x : tempArray)
	{
		cout << x << ", ";
	}
	cout << endl;
	return pointsTemp;
}

void GameThree::playGame(User& user)
{
	if (key.isPermaLocked())
	{
		cout << "Igrica je zakljucana i vise se ne moze igrati!!";
		Sleep(1000);
		system("cls");
		return;
	}
	if (!checkCredit(user, 100))
		return;


	printTutorial();
	cout <<  endl <<"Pritisnite ENTER da bi nastavili dalje...";
	getchar();
	getchar();

	system("cls");


	GameThree userNumbers, computerNumbers(20);
	int points, newPoints;

	userNumbers.addNumbers();
	cout << endl << "Izabrali ste sljedece brojeve: ";
	userNumbers.print();

	cout << "Izvlacenje lota je zavrsilo! Izvuceni su sljedeci brojevi: ";

	computerNumbers.drawnNumbers();
	points = userNumbers.compare(computerNumbers);
	newPoints = user.getPoints() + points;

	cout << "Broj bodova koji ste osvojili je: " << points << endl;
	statistic.addScore(points);
	cout << "Ukupan broj bodova na vasem korisnickom nalogu: " << newPoints;
	
	user.setPoint(newPoints);
	cout << endl;

	cout << endl << "Pritisnite ENTER da bi nastavili dalje...";
	getchar();
	getchar();

	system("cls");
}

void GameThree::printTutorial()
{
	cout << endl;
	cout << "Treba da unesete 7 razlicitih brojeva u opsegu od 1 do 45 nakon cega pocinje proces izvlacenja dobitnih brojeva. Racunar na slucajan nacin bira 20 brojeva. Za svaki pogodjeni broj dobijate (redni_broj_pogotka)*10 bodova (ako imate svih 7 pogodaka dobicete 10+20+30+40+50+60+70 bodova). Cijena igranja je 100 bodova.";
	cout << endl;
}


GameThree::~GameThree()
{
	delete[] numbers;
	numbers = nullptr;
}
