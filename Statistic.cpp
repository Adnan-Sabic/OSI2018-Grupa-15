#include "Statistic.h"


Statistic::Statistic()
{
}

Statistic::Statistic(std::string fileName)
{
	this->fileName = fileName;
	std::ifstream file(fileName);
	if (file.is_open())
	{
		std::string line;
		while (std::getline(file, line))
		{
			if (!line.empty())
			{
				scoreArray.push_back(Score::Score(line));
			}
		}
		file.close();
	}
	else
	{
		std::cout << "File didn't open successfully" << std::endl; //Can be commented to disable this massage if there is no file with statistic name
	}
}

void Statistic::addScore(int newScore)
{
	insterSortedToVector(newScore);
	std::fstream file;
	file.open(fileName, std::fstream::out);
	if (file.is_open())
	{
		for (Score temp : scoreArray)
		{
			file << temp.toString() << std::endl;
		}
		file.close();
	}
	else
	{
		std::cout << "File didn't open successfully" << std::endl;
	}
}

void Statistic::insterSortedToVector(int newScore)
{
	scoreArray.push_back(Score::Score(newScore));
	int maximum;
	for (int i = 0; i < scoreArray.size() - 1; i++)
	{
		maximum = i;
		for (int j = i + 1; j < scoreArray.size(); j++)
		{
			if (scoreArray[j].getPoints() > scoreArray[maximum].getPoints())
			{
				maximum = j;
			}
		}
		std::swap(scoreArray[maximum], scoreArray[i]);
	}
	if (scoreArray.size() > 10)
	{
		scoreArray.pop_back();
	}
}

void Statistic::printStatistic()
{
	std::cout << "|DATUM IGRANJA              BROJ BODOVA|" << std::endl;
	std::cout << "----------------------------------------" << std::endl;
	for (Score temp3 : scoreArray)
	{
		std::cout << temp3.toString() << std::endl;
	}
	std::cout << "----------------------------------------" << std::endl;

	std::string temp;
	do
	{
		std::cout << "Zelite li sacuvati vasu statistiku u CSV fajl?(1=Da,2=Ne)" << std::endl;
		std::cin >> temp;
	}while (temp != "1" && temp != "2");
	if (temp == "1") 
	{
		saveToCSVFile();
		std::cout << "Statistika uspjesno sacuvana u CSV fajl" << std::endl;
	}
	else
	{

	}
}

void Statistic::saveToCSVFile()
{
	std::string temp;
	std::cout << "Unesite ime CSV fajla(bez .csv)" << std::endl;
	std::cin >> temp;
	temp = temp + ".csv";
	std::fstream csvFile;
	csvFile.open(temp, std::fstream::out);
	if(csvFile.is_open())
	{
		csvFile << "DATUM IGRANJA,BROJ BODOVA" << std::endl;
		for (Score temp1 : scoreArray)
		{
			csvFile << temp1.toCSVString() << std::endl;
		}
		csvFile.close();
	}
	else
	{
		std::cout << "CSV file didn't open successfully" << std::endl;
	}
}



Statistic::~Statistic()
{
}
