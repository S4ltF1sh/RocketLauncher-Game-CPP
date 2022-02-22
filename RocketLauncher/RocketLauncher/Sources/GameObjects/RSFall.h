#pragma once
#include "IRState.h"
#include "IRocket.h"

class RSFall :public IRState {
public:
	RSFall(IRocket* player);
	void Init();
	void Update(float deltaTime, float feul, float &curTime, bool isCollided);
	void Render(sf::RenderWindow* window);
	void Reset();

private:
	IRocket* m_Rocket;
	Animation* m_Animation;
};