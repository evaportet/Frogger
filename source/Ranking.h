#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include<map>
#include<queue>
#include<Windows.h>
#include<vector>

class Ranking {
public:

	std::map<std::string, int> highScores;

	Ranking();
	Ranking(std::string fileName);

	void PrintRanking(Ranking &playerRanking);
	void InsertName(Ranking& ranking, int score, std::string fileName);
};
