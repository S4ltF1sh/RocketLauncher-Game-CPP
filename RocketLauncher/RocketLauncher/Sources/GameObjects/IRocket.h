#pragma once
#include "IRState.h"
#include "HitBox.h"

class IRocket
{
public:
	virtual void changeNextState(IRState::STATE nextState) = 0;
	virtual HitBox* getHitBox() = 0;
};