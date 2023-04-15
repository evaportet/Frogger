#pragma once
#include "Scene.h"
#include "UItext.h"
#include "Button.h"
#include "ImageRenderer.h"
#include "HighScoreManager.h"

class RankingScene : public Scene
{
public:
	RankingScene();
	void Update(float dt) override;
	void Render() override;
	void OnEnter() override;
	void OnExit() override;

private:
	std::map<std::string, int> highScores;

	ImageRenderer background;
	Button backToMenu;
	UIText rankingText;
	UIText topScoresText[10];

};

