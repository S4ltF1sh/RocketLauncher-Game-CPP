#pragma once
#include "../GameManager/ResourceManager.h"
#include "Rocket.h"

class IMState {
public:
	enum STATE
	{
		MAP1,
		MAP2,
		SNULL,
	};
	virtual void Init() = 0;
	virtual void Update(float deltaTime, std::vector<std::vector<int>>& mapForm, Rocket* rocket) = 0;
	virtual void Render(sf::RenderWindow* window) = 0;
	virtual void Reset() = 0;
};