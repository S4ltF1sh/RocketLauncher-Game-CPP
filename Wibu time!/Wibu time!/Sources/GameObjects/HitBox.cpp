#include "HitBox.h"

HitBox::HitBox(sf::Vector2i size) :RectangleShape((sf::Vector2f)size)
{
	this->setOrigin((sf::Vector2f)size / 2.f);
	this->setFillColor(sf::Color(0, 0, 0, 0));
	this->setOutlineThickness(1.f);
	this->setOutlineColor(sf::Color::Red);
	
	m_Angle = 0;
	m_Speed = 200;
	m_Size = size;
}

HitBox::~HitBox()
{
}

void HitBox::Init(float angleInRadians, float speed)
{
	m_Angle = angleInRadians;
	m_Speed = speed;
	m_isWin = false;
	m_isDie = false;
}

float HitBox::getSpeed()
{
	return m_Speed;
}

float HitBox::getAngle()
{
	return m_Angle;
}

bool HitBox::getWinStatus()
{
	return m_isWin;
}

bool HitBox::getDieStatus()
{
	return m_isDie;
}

void HitBox::setWinStatus(bool isWin)
{
	m_isWin = isWin;
}

void HitBox::setDieStatus(bool isDie)
{
	m_isDie = isDie;
}

bool HitBox::checkCollision(float deltaTime, HitBox* other)
{
	otherPosition = other->getPosition();
	otherHalfSize = other->getSize() / 2.f;
	thisPosition = this->getPosition();
	thisHalfSize = this->getSize() / 2.f;

	float deltaX = otherPosition.x - thisPosition.x;
	float deltaY = otherPosition.y - thisPosition.y;

	float intersectX = abs(deltaX) - (otherHalfSize.x + thisHalfSize.x);
	float intersectY = abs(deltaY) - (otherHalfSize.y + thisHalfSize.y);

	if (intersectX < 0.0f && intersectY < 0.0f)
	{
		if ((intersectX) > (intersectY)) // response at right or left
		{
			if (deltaX > 0.0f) //other at right
			{
				other->move(-intersectX, 0.0f);
			}
			else
			{
				other->move(intersectX, 0.0f);
			}
		}
		else
		{
			if (deltaY > 0.0f)//hidden=0
			{
				other->move(0.0f, -intersectY);
			}
			else
			{
				other->move(0.0f, intersectY);
			}
		}
		return true;
	}
	return false;
}

bool HitBox::checkCollision2(float deltaTime, HitBox* other)
{
	otherPosition = other->getPosition();
	otherHalfSize = other->getSize() / 2.f;
	thisPosition = this->getPosition();
	thisHalfSize = this->getSize() / 2.f;

	float deltaX = otherPosition.x - thisPosition.x;
	float deltaY = otherPosition.y - thisPosition.y;

	float intersectX = abs(deltaX) - (otherHalfSize.x + thisHalfSize.x);
	float intersectY = abs(deltaY) - (otherHalfSize.y + thisHalfSize.y);

	if (intersectX < 0.0f && intersectY < 0.0f)
	{
		return true;
	}
	return false;
}

