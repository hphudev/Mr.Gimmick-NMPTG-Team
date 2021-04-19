#pragma once

class Pair
{
protected:
	float firstValue, secondValue;
public:
	Pair();
	Pair(float firstValue, float secondValue);
	float GetFirstValue();
	float GetSecondValue();
	void SetFirstValue(float firstValue);
	void SetSecondValue(float secondValue);
	void SetValue(float firstValue, float secondValue);
};