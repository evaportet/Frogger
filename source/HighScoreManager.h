#pragma once
#include<string>
#include<fstream>
#include<iostream>
#include<map>

#define HSM HighScoreManager::GetInstance()

class HighScoreManager
{
public:
	static HighScoreManager* Instance; 

	void LoadScoreFromFile();

	void InsertScore(std::string name, int score);
	
	std::map<std::string, int> GetScoresMap()
	{
		return highScores;
	};

	static HighScoreManager* GetInstance() {
		if (Instance == nullptr)
			Instance = new HighScoreManager();
		return Instance; }

private:
	HighScoreManager()
	{
		LoadScoreFromFile();
	};

	std::map<std::string, int> highScores;
};

