#include "State.h"

void State::ChangeState(int type)
{

}

State* State::Clone()
{
	return new State(*this);
}