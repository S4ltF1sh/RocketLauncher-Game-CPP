#pragma once
#include "../GameManager/ResourceManager.h";
#include "HitBox.h"
#include "Rocket.h"
#include "Animation.h"

class FeulCan {
public:
	FeulCan();
	~FeulCan();

	void Init();
	bool Update(float deltaTime, Rocket* rocket);
	void Render(sf::RenderWindow* window);

	void setPosition(int x, int y);

private:
	bool m_isAte;
	HitBox* m_HitBox;
	Animation* m_Animation;
};