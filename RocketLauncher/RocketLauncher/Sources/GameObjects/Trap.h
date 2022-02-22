#pragma once
#include "../GameManager/ResourceManager.h";
#include "HitBox.h"
#include "Rocket.h"
#include "Animation.h"

class Trap {
public:
	Trap();
	~Trap();

	void Init(std::string name, int hibox_x, int hitbox_y);
	bool Update(float deltaTime, Rocket* rocket);
	void Render(sf::RenderWindow* window);

	void setPosition(int x, int y);
	HitBox* getHitBox();

protected:
	HitBox* m_HitBox;
	Animation* m_Animation;
};