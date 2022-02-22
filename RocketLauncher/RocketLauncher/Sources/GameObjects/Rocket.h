#pragma once
#include "IRocket.h"

class Rocket : public IRocket
{
public:
	Rocket();
	~Rocket();

	void Reset(sf::Vector2f spawnPoint);
	void changeNextState(IRState::STATE nextState);

	void Init(sf::Vector2f spawnPoint);
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);

	HitBox* getHitBox();
	sf::RectangleShape *getFeul();
	float getFallTime();
	void setFallTime(float fallTime);
	bool getCollideStatus();
	void setCollideStatus(bool status);

private:
	void performStateChange();
	HitBox* m_HitBox;

	IRState::STATE m_nextState;

	IRState* m_currentState;
	IRState* m_flyState;
	IRState* m_fallState;
	IRState* m_spinL1State;
	IRState* m_spinL2State;
	IRState* m_spinR1State;
	IRState* m_spinR2State;
	IRState* m_deathState;

	sf::RectangleShape* m_Fuel;
	float m_fallTime;
	bool m_isCollided;
};