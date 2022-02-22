#include "FeulCan.h"

FeulCan::FeulCan()
{
	m_isAte = false;
}

FeulCan::~FeulCan()
{
}

void FeulCan::Init()
{
	m_Animation = new Animation(*DATA->getTexture("Map/Map_107"), sf::Vector2i(1, 1), 0.1f);

	m_HitBox = new HitBox(sf::Vector2i(16, 16));
	m_HitBox->Init(0, 0);
}

bool FeulCan::Update(float deltaTime, Rocket* rocket)
{
	if (!m_isAte)
	{
		if (m_HitBox->checkCollision2(deltaTime, rocket->getHitBox()))
		{
			m_isAte = true;
			return true;
		}
	}
	return false;
}

void FeulCan::Render(sf::RenderWindow* window)
{
	if (!m_isAte)
	{
		window->draw(*m_Animation);
		//window->draw(*m_HitBox);
	}
}

void FeulCan::setPosition(int x, int y)
{
	m_Animation->setPosition(x, y);
	m_HitBox->setPosition(x, y);
}