#pragma once
#include "Block.h"
#include "FeulCan.h"
#include "Trap.h"

class Map{
public:
	Map();
	~Map();
	void Init(std::vector<std::vector<int>> &mapForm, std::string name);
	void Update(float deltaTime, std::vector<std::vector<int>>& mapForm, Rocket *rocket);
	void Render(sf::RenderWindow *window, std::vector<std::vector<int>>& mapForm);
	void Reset();

	sf::Vector2f getSpawnPoint();

private:
	//colxrow
	std::vector<std::vector<Block*>> m_Map;
	std::vector<FeulCan*> m_Feul;
	std::vector<Trap*> m_Trap;

	sf::Vector2f m_spawnPoint;

	sf::Sprite* m_BG;
	sf::Font* m_Font;
	sf::Text* m_GoalText;
};