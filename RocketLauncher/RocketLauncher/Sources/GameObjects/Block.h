#pragma once
#include "../GameManager/ResourceManager.h"
#include "HitBox.h"
#include "Rocket.h"

class Block {
public:
	Block();
	~Block();

	void Init(std::string name, int type);
	bool Update(float deltaTime, Rocket *rocket);
	void Render(sf::RenderWindow* window);

	void setPosition(int x, int y);
	void setAnimationPos(int x, int y);
	HitBox *getHitBox();

protected:
	HitBox* m_HitBox;
	Animation* m_Animation;
	//sf::Sprite m_Animation;
};