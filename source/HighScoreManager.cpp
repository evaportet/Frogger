#include "HighScoreManager.h"

HighScoreManager* HighScoreManager::Instance = nullptr;


HighScoreManager::HighScoreManager()
{
	LoadScoreFromFile();
};

void HighScoreManager::LoadScoreFromFile()
{
	//in file (load)
	std::ifstream myFileIn;
	myFileIn.open("resources/Files/Ranking.data", std::ios::in | std::ios::binary);

	if (!myFileIn.is_open())		//Handle file opening errors
	{
		std::cout << "\n\nFile read error. File does not exist or could not be read.\n";
		//exit(5);
	}

	//read the size
	int inSize = 0;
	myFileIn.read(reinterpret_cast<char*>(&inSize), sizeof(int));

	if (inSize <= 0)
	{
		std::cout << "\n\nFile is empty.\n";
		//exit(6);
	}

	//read the actual value
	for (; inSize > 0; inSize--)
	{
		//map element's first component
		std::string inKey{ "" };
		size_t keyStrLen = 0;
		myFileIn.read(reinterpret_cast<char*>(&keyStrLen), sizeof(size_t));

		//char array input to string
		char* temp = new char[keyStrLen + 1];
		myFileIn.read(temp, keyStrLen);

		temp[keyStrLen] = '\0';
		inKey = temp;
		delete[]temp;
		//

		//map element's second component
		int inVal = 0;
		myFileIn.read(reinterpret_cast<char*>(&inVal), sizeof(int));

		//Add element using the data read from the file
		highScores.insert({ inKey, inVal });
	}
	myFileIn.close();
};

void HighScoreManager::InsertScore(std::string name, int score)
{
	std::map<std::string, int>::iterator it = highScores.find(name);
	if (it == highScores.end())
	{
		highScores.insert({ name, score });
	}
	else
	{
		if (score > it->second)
		{
			it->second = score;
		}
	}

	//out file (saving)
	std::ofstream myFile;
	myFile.open("resources/Files/Ranking.data", std::ios::out | std::ios::binary | std::ios::trunc);

	int size = highScores.size();
	if (size <= 0)
	{
		printf_s("\nContainer is empty.\n");
	}

	//write the size
	myFile.write(reinterpret_cast<char*>(&size), sizeof(int));
	//write the actual value
	for (auto itr = highScores.begin(); itr != highScores.end(); itr++)
	{
		//map element's first component
		size_t keySize = itr->first.size();
		myFile.write(reinterpret_cast<char*>(&keySize), sizeof(size_t));
		std::string keyStr{ itr->first };
		myFile.write(keyStr.c_str(), itr->first.size());

		//map element's second component
		myFile.write(reinterpret_cast<char*>(&itr->second), sizeof(int));
	}

	myFile.close();
};