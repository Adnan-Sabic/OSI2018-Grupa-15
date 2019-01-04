#include "Key.h" 

Key::Key() : key("") {}

bool Key::isValid(int game) noexcept   //game - parameter that represents number of game(e.g. isValid(1) for first game)
{
	if (key.length() != 19)
		return false;
	if (key[4] != '-' || key[9] != '-' || key[14] != '-')
		return false;

	char p1[20],p2[3],c;
	std::ifstream inFile("Keys.txt");
	if (inFile.is_open())
	{
		 
		for (int i = 0; i < game; i++)
		{
			
			inFile.get(c); inFile.get(c);
			inFile.get(p1, 20, '\n'); inFile.get(c);
			if (i == game - 1 && p1 == key)
				return true;
			
		}
		return false;
	}
	else
		return std::cout << "File that contain keys can't be opened.",false;
	
}

bool Key::isExpired(int) noexcept
{

	return false;
}

std::istream& operator>>(std::istream& in, Key& k)
{
	return in >> k.key;
}
