#include "Pair.h"

void Pair::IncreaseValue(int addtionalFirstValue, int additionalSecondValue)
{
	IncreaseFirstValue(addtionalFirstValue);
	IncreaseSecondValue(additionalSecondValue);
}

void Pair::IncreaseSecondValue(int additionalSecondValue)
{
	this->secondValue += additionalSecondValue;
}

void Pair::IncreaseFirstValue(int addtionalFirstValue)
{
	this->firstValue += addtionalFirstValue;
}

Pair::Pair()
{
	this->firstValue = this->secondValue = 0;
}

Pair::Pair(float firstValue, float secondValue)
{
	this->firstValue = firstValue;
	this->secondValue = secondValue;
}

float Pair::GetFirstValue()
{
	return this->firstValue;
}

float Pair::GetSecondValue()
{
	return this->secondValue;
}

void Pair::SetFirstValue(float firstValue)
{
	this->firstValue = firstValue;
}

void Pair::SetSecondValue(float secondValue)
{
	this->secondValue = secondValue;
}

void Pair::SetValue(float firstValue, float secondValue)
{
	this->firstValue = firstValue;
	this->secondValue = secondValue;
}