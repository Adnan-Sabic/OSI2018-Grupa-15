#include "ThirdGame.h"



ThirdGame::ThirdGame()
{
	numbers = new int[n = 7];
	statistic = Statistic::Statistic("output.txt");
}

ThirdGame::ThirdGame(int i)
{
	numbers = new int[i];
	n = i;
	statistic = Statistic::Statistic("output.txt");
}

void ThirdGame::addNumbers()
{
	cout << endl << "Unesite 7 brojeva koji se nalaze u opsegu izmedju 1 i 45:" << endl;
	int temp;
	for (int i = 0; i < n; i++)
	{
		while (1)
		{
			cin >> temp;
			if (exists(temp))
			{
				cout << endl << "Taj broj ste vec uzeli, molimo vas da izaberete neki drugi" << endl;
				continue;
			}
			if (temp < 1 || temp > 45)
			{
				cout << "Uneseni broj se ne nalazi trazenom opsegu! Molimo vas da pokusate ponovo." << endl;
				continue;
			}
			else
				break;
		}
		numbers[i] = temp;
	}
}

ThirdGame::ThirdGame(const ThirdGame &other)
{
	copy(other);
}

ThirdGame::ThirdGame(ThirdGame &&other)
{
	move(std::move(other));
}

ThirdGame & ThirdGame::operator=(const ThirdGame &other)
{
	if (this == &other)
		return *this;
	this->~ThirdGame();
	copy(other);
	return *this;
}

ThirdGame & ThirdGame::operator=(ThirdGame &&other)
{
	if (this == &other)
		return *this;
	this->~ThirdGame();
	move(std::move(other));
	return *this;
}

void ThirdGame::print()
{
	for (int i = 0; i < n; i++)
		cout << numbers[i] << ", ";
	cout << endl;
}

int & ThirdGame::operator[](int i)
{
	return numbers[i];
}

const int & ThirdGame::operator[](int i) const
{
	return numbers[i];
}

void ThirdGame::drawnNumbers()
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

bool ThirdGame::exists(int number)
{
	for (int i = 0; i < n; i++)
	{
		if (numbers[i] == number)
			return true;
	}
	return false;
}

bool ThirdGame::exists(int number) const
{
	for (int i = 0; i < n; i++)
	{
		if (numbers[i] == number)
			return true;
	}
	return false;
}

void ThirdGame::copy(const ThirdGame &other)
{
	std::copy(other.numbers, other.n + other.numbers, numbers = new int[n + other.n]);
}

void ThirdGame::move(ThirdGame &&other)
{
	n = std::move(other.n);
	numbers = std::move(other.numbers);
	other.numbers = nullptr;
}


int ThirdGame::compare(ThirdGame &other) const
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

void ThirdGame::playGame(User& user)
{
	printTutorial();
	ThirdGame userNumbers, computerNumbers(20);
	int points, newPoints;

	userNumbers.addNumbers();
	cout << endl << "Izabrali ste sljedece brojeve: ";
	userNumbers.print();

	cout << "Izvlacenje lota je zavrsilo! Izvuceni su sljedeci brojevi: ";

	computerNumbers.drawnNumbers();
	points = userNumbers.compare(computerNumbers);
	newPoints = user.getPoints() + points;

	cout << "Broj bodova koji ste osvojili je: " << points << endl;
	cout << "Ukupan broj bodova: " << newPoints;
	
	user.setPoint(newPoints);
	cout << endl;
}

void ThirdGame::printTutorial()
{
	cout << endl;
	cout << "Treba da unesete 7 razlicitih brojeva u opsegu od 1 do 45 nakon cega pocinje proces izvlacenja dobitnih brojeva. Racunar na slucajan nacin bira 20 brojeva. Za svaki pogodjeni broj dobijate (redni_broj_pogotka)*10 bodova (ako imate svih 7 pogodaka dobicete 10+20+30+40+50+60+70 bodova). Cijena igranja je 100 bodova.";
	cout << endl;
}


ThirdGame::~ThirdGame()
{
	delete[] numbers;
	numbers = nullptr;
}
