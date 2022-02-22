#include "RSFall.h"

RSFall::RSFall(IRocket* rocket)
{
	m_Rocket = rocket;
}

void RSFall::Init()
{
	//printf("Fall\n");
	m_Animation = new Animation(*DATA->getTexture("Character/Rocket_DF"), sf::Vector2i(1, 1), 0.1f);
	m_Animation->setScale(0.1f, 0.1f);
	//m_Animation->setModeEndFrame(true);
}

void RSFall::Update(float deltaTime, float feul, float &curTime, bool isCollided)
{
	curTime += deltaTime;
	m_Animation->Update(deltaTime);

	m_Rocket->getHitBox()->move(0.f, std::min(V_MAX, V0 + G * curTime));

	float angle = m_Rocket->getHitBox()->getAngle();
	float angleInRadians = (float)m_Rocket->getHitBox()->getAngle() * M_PI / 180;
	float sinx = (float)sin(angleInRadians - M_PI_2);
	float cosx = (float)cos(angleInRadians - M_PI_2);


	if (feul > 0)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			angle += 2.f;
			m_Rocket->changeNextState(SPINR1);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			angle -= 2.f;
			m_Rocket->changeNextState(SPINL1);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			//curTime = 0.f;
			m_Rocket->changeNextState(FLY);
		}
	}

	if (!isCollided)
	{
		if (sinx > 0.f && cosx > 0.1f)
		{
			if (cosx <= 0.2)
				angle += 0.075f;
			else if (cosx <= 0.7f)
				angle += 0.15f;
			else if (cosx <= 1)
				angle += 0.2f;
		}
		else if (sinx < 0.f && cosx > 0.1f)
		{
			if (cosx >= 0.7f)
				angle += 0.2f;
			else if (cosx >= 0.2f)
				angle += 0.15f;
			else if (cosx >= 0.f)
				angle += 0.075f;
		}
		else if (sinx > 0.f && cosx < -0.1f)
		{
			if (cosx >= -0.2f)
				angle -= 0.075f;
			else if (cosx >= -0.7f)
				angle -= 0.15f;
			else if (cosx >= -1.f)
				angle -= 0.2f;
		}
		else if (sinx < 0.f && cosx < -0.1f)
		{
			if (cosx <= -0.7f)
				angle -= 0.2f;
			else if (cosx <= -0.2f)
				angle -= 0.15f;
			else if (cosx <= 0.f)
				angle -= 0.075f;
		}


	}

	m_Rocket->getHitBox()->setAngle(angle);
	m_Rocket->getHitBox()->setRotation(angle);
	m_Animation->setRotation(angle);
	m_Animation->setPosition(m_Rocket->getHitBox()->getPosition());
	
	if (m_Rocket->getHitBox()->getDieStatus())
		m_Rocket->changeNextState(DEATH);
}

void RSFall::Render(sf::RenderWindow* window)
{
	window->draw(*m_Animation);
}

void RSFall::Reset()
{
	m_Animation->Reset();
}
