#pragma once

class State
{
public:
	virtual void ChangeState(int type);
	virtual State* Clone();
};