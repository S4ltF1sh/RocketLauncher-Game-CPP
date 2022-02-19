#include "RSFly.h"

RSFly::RSFly(IRocket* rocket)
{
	m_Rocket = rocket;
}

void RSFly::Init()
{
	//printf("Fly\n");
	m_Animation = new Animation(*DATA->getTexture("Character/Rocket_Fly"), sf::Vector2i(1, 1), 0.1f);
	m_Animation->setScale(0.1f, 0.1f);
}

void RSFly::Update(float deltaTime, float feul, float& curTime, bool isCollided)
{

	m_Animation->Update(deltaTime);
	float angle = m_Rocket->getHitBox()->getAngle();
	float angleInRadians = (float)m_Rocket->getHitBox()->getAngle() * M_PI / 180;
	float sinx = (float)sin(angleInRadians - M_PI_2);
	float cosx = (float)cos(angleInRadians - M_PI_2);

	//change state:
	if (feul > 0)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
				angle += 2.f;
				m_Rocket->changeNextState(SPINR2);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
				angle -= 2.f;
				m_Rocket->changeNextState(SPINL2);
			}
			float speed = m_Rocket->getHitBox()->getSpeed();
			m_Rocket->getHitBox()->move(speed * deltaTime * cosx,
				speed * deltaTime * sinx);
		}
		else
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
				angle += 2.f;
				m_Rocket->changeNextState(SPINR1);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
				angle -= 2.f;
				m_Rocket->changeNextState(SPINL1);
			}
			m_Rocket->changeNextState(FALL);
		}
	}
	else
	{
		m_Rocket->changeNextState(FALL);
	}


	if (!isCollided)
	{//auto spin by gravity:
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

		if (sinx > 0.f)
		{
			curTime += deltaTime;
		}
		else
		{
			curTime = 0.f;
		}

		m_Rocket->getHitBox()->move(0.f, std::min(V_MAX, V0 + G * curTime));

	}
	
	m_Rocket->getHitBox()->setAngle(angle);
	m_Rocket->getHitBox()->setRotation(angle);
	m_Animation->setRotation(angle);
	m_Animation->setPosition(m_Rocket->getHitBox()->getPosition());

	if (m_Rocket->getHitBox()->getDieStatus())
		m_Rocket->changeNextState(DEATH);
}

void RSFly::Render(sf::RenderWindow* window)
{
	window->draw(*m_Animation);
}

void RSFly::Reset()
{
	m_Animation->Reset();
}
