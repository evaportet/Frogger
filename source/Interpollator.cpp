#include "Interpollator.h"

Interpolator::Interpolator(float lerpTime, InterpolatorMode mode)
{
	totalLerpTime = lerpTime;
	currentLerpTime = 0.f;

	value = 0.f;
	inverse = 1.f;

	state = MIN;
	this->mode = mode;
}

void Interpolator::ToMax()
{
	if ((int)state % 2 == 0)
		state = GROWING;
}

void Interpolator::ForceMax()
{
	if (state == MAX)
		return;

	state = MAX;
	value = 1.f;
	inverse = 0.f;
	currentLerpTime = totalLerpTime;
}

void Interpolator::ToMin()
{
	if ((int)state % 2 != 0)
		state = SHRINKING;
}

void Interpolator::ForceMin()
{
	if (state == MIN)
		return;

	state = MIN;
	value = 0.f;
	inverse = 1.f;
	currentLerpTime = 0.f;
}

void Interpolator::Update(float dt)
{
	if (state == MAX || state == MIN)
		return;

	currentLerpTime += state == GROWING ? dt : -dt;

	value = currentLerpTime / totalLerpTime;
	inverse = 1.f - value;

	if (value >= 1.f)
		ForceMax();
	else if (value <= 0.f)
		ForceMin();
	else {
		switch (mode)
		{
		case SIN:
			value = sin(value * PI * 0.05f);
			break;
		case COS:
			break;
		case SMOOTH:
			break;
		}
	}
}

bool Interpolator::IsMax()
{
	return value > 1 - e;
}

bool Interpolator::IsMaxPrecise()
{
	return state == MAX;
}

bool Interpolator::IsMin()
{
	return value < e;
}

bool Interpolator::IsMinPrecise()
{
	return state == MIN;
}

float Interpolator::GetValue()
{
	return value;
}

float Interpolator::GetInverse()
{
	return inverse;
}