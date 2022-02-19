#pragma once
#include "IRState.h"
#include "IRocket.h"
#include "../GameStateManager/GSPlay.h"
#include "../GameStateManager/GameStateMachine.h"

class RSDeath :public IRState {
public:
	RSDeath(IRocket* player);
	void Init();
	void Update(float deltaTime, float feul, float& curTime, bool isCollided);
	void Render(sf::RenderWindow* window);
	void Reset();

private:
	IRocket* m_Rocket;
	Animation* m_Animation;
	float m_currentTime;
	float m_timeRemain;
};