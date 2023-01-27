#pragma once
#include"Log.h"

class Crocodile : public Log
{
private:
	float openMouthDuration;
	float closedMouthDuration;
	float elapsedTime;

public:
	Crocodile(float openMouthDuration, float closedMouthDuration, int length);
	void Update()override;
	void Render()override;
	bool IsMouthOpen();
};

