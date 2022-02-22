#include "Rocket.h"
#include "RSFly.h"
#include "RSFall.h"
#include "RSSpinL1.h"
#include "RSSpinL2.h"
#include "RSSpinR1.h"
#include "RSSpinR2.h"
#include "RSDeath.h"

Rocket::Rocket()
{
	m_nextState = IRState::SNULL;
	m_flyState = new RSFly(this);
	m_fallState = new RSFall(this);
	m_spinL1State = new RSSpinL1(this);
	m_spinL2State = new RSSpinL2(this);
	m_spinR1State = new RSSpinR1(this);
	m_spinR2State = new RSSpinR2(this);
	m_deathState = new RSDeath(this);
	m_currentState = m_flyState;
}

Rocket::~Rocket()
{
	if (m_flyState != nullptr) {
		delete m_flyState;
	}
	if (m_fallState != nullptr) {
		delete m_fallState;
	}
	if (m_deathState != nullptr) {
		delete m_deathState;
	}
	if (m_spinL1State != nullptr)
	{
		delete m_spinL1State;
	}
	if (m_spinL2State != nullptr)
	{
		delete m_spinL2State;
	}
	if (m_spinR1State != nullptr)
	{
		delete m_spinR1State;
	}
	if (m_spinR2State != nullptr)
	{
		delete m_spinR2State;
	}
	m_currentState = nullptr;

}

void Rocket::changeNextState(IRState::STATE nextState)
{
	m_nextState = nextState;
}

void Rocket::Init(sf::Vector2f spawnPoint)
{
	m_flyState->Init();
	m_fallState->Init();
	m_spinL1State->Init();
	m_spinL2State->Init();
	m_spinR1State->Init();
	m_spinR2State->Init();
	m_deathState->Init();

	m_HitBox = new HitBox(sf::Vector2i(10, 20));
	m_HitBox->Init(0, 200);
	m_HitBox->setPosition(spawnPoint.x, spawnPoint.y);

	m_Fuel = new sf::RectangleShape(sf::Vector2f(FEUL_X, FEUL_MAX));
	m_Fuel->setFillColor(sf::Color::Cyan);

	m_fallTime = 0.f;
	m_isCollided = false;
}

void Rocket::Update(float deltaTime)
{
	performStateChange();
	m_currentState->Update(deltaTime, m_Fuel->getSize().y, m_fallTime, m_isCollided);
	m_isCollided = false;

	if (m_currentState == m_flyState)
		m_Fuel->setSize(sf::Vector2f(FEUL_X, m_Fuel->getSize().y - 0.5f));
	else if (m_currentState == m_spinL1State || m_currentState == m_spinR1State)
		m_Fuel->setSize(sf::Vector2f(FEUL_X, m_Fuel->getSize().y - 0.2f));
	else if (m_currentState == m_spinL2State || m_currentState == m_spinR2State)
		m_Fuel->setSize(sf::Vector2f(FEUL_X, m_Fuel->getSize().y - 0.7f));
}

void Rocket::Render(sf::RenderWindow* window)
{
	m_currentState->Render(window);
	//window->draw(*m_HitBox);
	window->draw(*m_Fuel);
}

HitBox* Rocket::getHitBox()
{
	return m_HitBox;
}

sf::RectangleShape* Rocket::getFeul()
{
	return m_Fuel;
}

float Rocket::getFallTime()
{
	return m_fallTime;
}

void Rocket::setFallTime(float fallTime)
{
	m_fallTime = fallTime;
}

bool Rocket::getCollideStatus()
{
	return m_isCollided;
}

void Rocket::setCollideStatus(bool status)
{
	m_isCollided = status;
}

void Rocket::performStateChange()
{
	if (m_nextState != IRState::SNULL) {
		switch (m_nextState)
		{
		case IRState::FLY:
			m_currentState = m_flyState;
			break;
		case IRState::FALL:
			m_currentState = m_fallState;
			break;
		case IRState::DEATH:
			m_currentState = m_deathState;
			break;
		case IRState::SPINL1:
			m_currentState = m_spinL1State;
			break;
		case IRState::SPINL2:
			m_currentState = m_spinL2State;
			break;
		case IRState::SPINR1:
			m_currentState = m_spinR1State;
			break;
		case IRState::SPINR2:
			m_currentState = m_spinR2State;
			break;
		default:
			break;
		}
		m_nextState = IRState::SNULL;
		m_currentState->Reset();
	}
}
