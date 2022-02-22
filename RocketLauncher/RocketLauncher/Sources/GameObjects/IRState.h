#pragma once
#include "../GameManager/ResourceManager.h"

class IRState {
public:
	enum STATE
	{
		FLY,
		FALL,
		SPINL1,
		SPINL2,
		SPINR1,
		SPINR2,
		DEATH,
		SNULL,
	};
	virtual void Init() = 0;
	virtual void Update(float deltaTime, float feul, float &curTime, bool isCollided) = 0;
	virtual void Render(sf::RenderWindow* window) = 0;
	virtual void Reset() = 0;
};