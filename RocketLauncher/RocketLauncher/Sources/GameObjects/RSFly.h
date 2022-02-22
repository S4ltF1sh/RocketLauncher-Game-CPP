#pragma once
#include "IRState.h"
#include "IRocket.h"

class RSFly :public IRState{
public:
	RSFly(IRocket* player);
	void Init();
	void Update(float deltaTime, float feul, float& curTime, bool isCollided);
	void Render(sf::RenderWindow* window);
	void Reset();

private:
	IRocket* m_Rocket;
	Animation* m_Animation;
};