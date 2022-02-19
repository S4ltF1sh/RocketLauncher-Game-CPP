#include "Trap.h"

Trap::Trap()
{
}

Trap::~Trap()
{
}

void Trap::Init(std::string name, int hibox_x, int hitbox_y)
{
	m_Animation = new Animation(*DATA->getTexture("Map/" + name), sf::Vector2i(1, 1), 0.1f);

	m_HitBox = new HitBox(sf::Vector2i(hibox_x, hitbox_y));
	m_HitBox->Init(0, 0);
}

bool Trap::Update(float deltaTime, Rocket* rocket)
{
	if (m_HitBox->checkCollision2(deltaTime, rocket->getHitBox()))
		return true;
	return false;
}

void Trap::Render(sf::RenderWindow* window)
{
	window->draw(*m_Animation);
	//window->draw(*m_HitBox);
}

void Trap::setPosition(int x, int y)
{
	m_Animation->setPosition(x, y);
	m_HitBox->setPosition(x, y);
}

HitBox* Trap::getHitBox()
{
	return m_HitBox;
}
