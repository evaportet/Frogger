#include"Ranking.h"

Ranking::Ranking()
{

}

Ranking::Ranking(std::string fileName)
{
	std::ifstream config;
	config.open(fileName);

	if (config.is_open())
	{
		std::string name;
		int score;
		int counter = 0;

		while (config >> name && counter < 10)
		{
			config >> score;
			highScores.insert(std::pair<std::string, int>(name, score));
			counter++;
		}
		config.close();
	}
	else
	{
		std::cout << "Unable to open file";
	}
}

void Ranking::PrintRanking(Ranking & ranking)
{
	typedef std::pair<std::string, int> pair;
	system("cls");
	auto it = ranking.highScores.begin();

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 224);
	std::cout << "*-*-*-RANKING-*-*-*" << std::endl;

	int posTable = 1;

	std::vector<pair> vec;

	std::copy(ranking.highScores.begin(), ranking.highScores.end(), std::back_inserter<std::vector<pair>>(vec));

	std::sort(vec.begin(), vec.end(), [](const pair& l, const pair& r)
	{
		if (l.second != r.second)
			return l.second < r.second;

		return l.first < r.first;
	});

	auto pairIt = vec.rbegin();

	while (it != ranking.highScores.end())
	{
		if (posTable == 1)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
		}

		else if (posTable == 2 || posTable == 3 || posTable == 4)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		}

		else if(posTable == 5)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		}

		std::cout << posTable << ". " << pairIt->first << "-> " << pairIt->second << std::endl;
		it++;
		pairIt++;
		posTable++;
	}
}

void Ranking::InsertName(Ranking& ranking, int score, std::string fileName)
{
	system("cls");
	std::string name;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	std::cout << "Enter your name" << std::endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	std::cin >> name;

	std::map<std::string, int>::iterator it = ranking.highScores.find(name);

	if (it == ranking.highScores.end())
	{
		ranking.highScores.insert({ name, score });
	}

	else
	{
		if (score > it->second)
		{
			it->second = score;
		}
	}

	std::ofstream config;
	config.open(fileName);
	it = ranking.highScores.begin();

	if (config.is_open())
	{
		for (int i = 0; i < 10 && it != ranking.highScores.end(); i++)
		{
			config << it->first << " " << it->second << std::endl;
			it++;
		}
		config.close();
	}
	else
	{
		std::cout << "Unable to open file";
	}

}
