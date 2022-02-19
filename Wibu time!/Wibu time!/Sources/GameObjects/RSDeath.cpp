#include "RSDeath.h"

RSDeath::RSDeath(IRocket* player)
{
	m_Rocket = player;
	m_timeRemain = 1.5f;
}

void RSDeath::Init()
{
	m_Animation = new Animation(*DATA->getTexture("Character/Rocket_Death_2"), sf::Vector2i(14, 1), 0.1f);
	m_Animation->setModeEndFrame(true);
}

void RSDeath::Update(float deltaTime, float feul, float& curTime, bool isCollided)
{
	m_currentTime += deltaTime;
	if (m_currentTime >= m_timeRemain) {
		GSPlay::numDeath++;
		std::fstream output;
		output.open("Map.txt", std::ios::binary | std::ios::out);
		output << GSPlay::curMap << " " << GSPlay::numDeath;
		output.close();

		GSM->ChangeState(StateTypes::END);
	}

	m_Animation->Update(deltaTime);
	m_Animation->setPosition(m_Rocket->getHitBox()->getPosition());
}

void RSDeath::Render(sf::RenderWindow* window)
{
	window->draw(*m_Animation);
}

void RSDeath::Reset()
{
	m_currentTime = 0;
	m_Animation->Reset();
}
