#pragma once
#include <algorithm>
#include <math.h>
#define PI 3.1416f

enum InterpolatorMode { LINEAR, SIN, COS, SMOOTH };

class Interpolator {
private:
	enum InterpolatorState { SHRINKING, MAX, MIN, GROWING };
	InterpolatorState state;

	float currentLerpTime;
	float totalLerpTime;

	float value;
	float inverse;
	const float e = 0.05f;

	InterpolatorMode mode;
public:
	Interpolator(float lerpTime, InterpolatorMode mode = LINEAR);
	void ToMax();
	void ForceMax();
	void ToMin();
	void ForceMin();

	void Update(float dt);

	bool IsMax();
	bool IsMaxPrecise();

	bool IsMin();
	bool IsMinPrecise();

	float GetValue();
	float GetInverse();
};
