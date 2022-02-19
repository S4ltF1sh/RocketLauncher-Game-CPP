#pragma once
#include "../GameManager/ResourceManager.h"

class HitBox :public sf::RectangleShape {
public:

	sf::Vector2f oldPosition;
	sf::Vector2i m_Size;

	HitBox(sf::Vector2i size);
	~HitBox();
	void Init(float angleInRadians, float speed);

	float getSpeed();
	float getAngle();
	bool getWinStatus();
	bool getDieStatus();

	void setAngle(float angle) {
		m_Angle = angle;
	}

	void setWinStatus(bool isWin);
	void setDieStatus(bool isDie);

	bool checkCollision(float deltaTime, HitBox* other);

	bool checkCollision2(float deltaTime, HitBox* other);

private:
	float m_Angle = 0.f;
	float m_Speed = 200.f;
	bool m_isWin;
	bool m_isDie;

	sf::Vector2f otherPosition;
	sf::Vector2f otherHalfSize;
	sf::Vector2f thisPosition;
	sf::Vector2f thisHalfSize;

	float deltaX;
	float deltaY;

	float intersectX;
	float intersectY;
};