#pragma once
#include "IMState.h"
#include "HitBox.h"

class IMap
{
public:
	virtual void changeNextState(IMState::STATE nextState) = 0;
};