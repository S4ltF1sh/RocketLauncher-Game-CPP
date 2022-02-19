#include "Block.h"

Block::Block()
{
}

Block::~Block()
{
	//delete this;
}

void Block::Init(std::string name, int type)
{
	/*sf::Texture* texture = DATA->getTexture("Map/" + name);
	m_Animation.setTexture(*texture);*/

	m_Animation = new Animation(*DATA->getTexture("Map/" + name), sf::Vector2i(1, 1), 0.1f);
	if (type != 0 && type != 12
		&& (type < 89 || type > 104))
	{
		m_HitBox = new HitBox(sf::Vector2i(16, 16));
		m_HitBox->Init(0, 0);
	}
}

bool Block::Update(float deltaTime, Rocket* rocket)
{
	if (this->getHitBox()->checkCollision(deltaTime, rocket->getHitBox()))
	{
		if (rocket->getFallTime() >= 2.f)
		{
			DATA->playSound("Explosive");
			rocket->getHitBox()->setDieStatus(true);
		}
		rocket->setFallTime(0.f);
		rocket->setCollideStatus(true);
		return  true;
	}
	return false;
}

void Block::Render(sf::RenderWindow* window)
{
	window->draw(*m_Animation);
	//window->draw(*m_HitBox);
	//window->draw(m_Animation);
}

void Block::setPosition(int x, int y)
{
	m_Animation->setPosition(x, y);
	m_HitBox->setPosition((float)x, (float)y);
}

void Block::setAnimationPos(int x, int y)
{
	m_Animation->setPosition(x, y);
}

HitBox* Block::getHitBox()
{
	return m_HitBox;
}
