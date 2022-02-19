#include "Map.h"

Map::Map()
{
	m_Font = DATA->getFont("crackman");
	m_GoalText = new sf::Text;
	m_GoalText->setFont(*m_Font);
	m_GoalText->setString("GOAL");
	m_BG = new sf::Sprite();
}

Map::~Map()
{
}

void Map::Init(std::vector<std::vector<int>>& mapForm, std::string name)
{
	m_BG->setTexture(*DATA->getTexture("Background/" + name));


	for (int i = 0; i < m_Map.size(); i++)
	{
		for (int j = 0; j < m_Map[i].size(); j++)
		{
			delete m_Map[i][j];
		}
	}
	m_Map.clear();
	m_Map.resize(col, std::vector<Block*>(row));

	Block* newBlock;
	FeulCan* newFeulCan;
	Trap* newTrap;

	for (int i = 0; i < col; i++)
	{
		for (int j = 0; j < row; j++)
		{
			if (mapForm[i][j] == 107) {
				newFeulCan = new FeulCan();
				newFeulCan->Init();
				newFeulCan->setPosition(i * 16, j * 16);
				m_Feul.push_back(newFeulCan);
				continue;
			}
			else if (mapForm[i][j] >= 108 && mapForm[i][j] <= 111) 
			{
				newTrap = new Trap();
				if (mapForm[i][j] == 108)
				{
					newTrap->Init("Map_" + std::to_string(mapForm[i][j]), 15, 7);
					newTrap->setPosition(i * 16, j * 16);
					newTrap->getHitBox()->move(0.5, 4.5);
				}
				else if (mapForm[i][j] == 109)
				{
					newTrap->Init("Map_" + std::to_string(mapForm[i][j]), 7, 15);
					newTrap->setPosition(i * 16, j * 16);
					newTrap->getHitBox()->move(-4.5, -0.5);
				}
				else if (mapForm[i][j] == 110)
				{
					newTrap->Init("Map_" + std::to_string(mapForm[i][j]), 15, 7);
					newTrap->setPosition(i * 16, j * 16);
					newTrap->getHitBox()->move(0.5, -4.5);
				}
				else
				{
					newTrap->Init("Map_" + std::to_string(mapForm[i][j]), 7, 15);
					newTrap->setPosition(i * 16, j * 16);
					newTrap->getHitBox()->move(4.5, 0.5);
				}

				m_Trap.push_back(newTrap);
				continue;
			}
			else if (mapForm[i][j] != 0)
			{
				newBlock = new Block();
				newBlock->Init("Map_" + std::to_string(mapForm[i][j]), mapForm[i][j]);
				m_Map[i][j] = newBlock;
			}
			else
			{
				continue;
			}

			if (mapForm[i][j] != 0 && mapForm[i][j] != 12 && mapForm[i][j] != 107
				&& (mapForm[i][j] < 89 || mapForm[i][j] > 104))
			{
				m_Map[i][j]->setPosition(i * 16, j * 16);
			}
			else
			{
				m_Map[i][j]->setAnimationPos(i * 16, j * 16);
			}

			if (mapForm[i][j] == 96)
				m_spawnPoint = sf::Vector2f(i * 16 + 5, j * 15 - 5);

			if (mapForm[i][j] == 105)
				m_GoalText->setPosition(i * 16 - 110, j * 16 - 50);
		}
	}
}

void Map::Update(float deltaTime, std::vector<std::vector<int>>& mapForm, Rocket* rocket)
{
	if (!rocket->getHitBox()->getDieStatus())
	{
		for (int i = 0; i < m_Trap.size(); i++)
		{
			if (m_Trap[i]->Update(deltaTime, rocket))
			{
				DATA->playSound("Explosive");
				rocket->getHitBox()->setDieStatus(true);
				return;
			}
		}

		for (int i = 0; i < m_Map.size(); i++)
		{
			for (int j = 0; j < m_Map[i].size(); j++)
			{
				if (mapForm[i][j] != 0 && mapForm[i][j] != 12 && mapForm[i][j] != 107 && mapForm[i][j] != 999
					&& (mapForm[i][j] < 89 || mapForm[i][j] > 104) && (mapForm[i][j] < 108 || mapForm[i][j] > 111))
				{
					if (m_Map[i][j]->Update(deltaTime, rocket) && mapForm[i][j] == 105)
					{
						rocket->getHitBox()->setWinStatus(true);
						return;
					}
				}
			}
		}

		for (int i = 0; i < m_Feul.size(); i++)
		{
			if (m_Feul[i]->Update(deltaTime, rocket))
			{
				rocket->getFeul()->setSize(sf::Vector2f(FEUL_X, rocket->getFeul()->getSize().y + 30.f));
			}
		}
	}

}

void Map::Render(sf::RenderWindow* window, std::vector<std::vector<int>>& mapForm)
{
	window->draw(*m_BG);

	for (int i = 0; i < col; i++)
	{
		for (int j = 0; j < row; j++)
		{
			if (mapForm[i][j] != 0 && mapForm[i][j] != 107 && (mapForm[i][j] < 108 || mapForm[i][j] > 111))
				m_Map[i][j]->Render(window);
		}
	}

	for (int i = 0; i < m_Feul.size(); i++)
	{
		m_Feul[i]->Render(window);
	}

	for (int i = 0; i < m_Trap.size(); i++)
	{
		m_Trap[i]->Render(window);
	}

	window->draw(*m_GoalText);
}

void Map::Reset()
{
	m_Map.clear();
}

sf::Vector2f Map::getSpawnPoint()
{
	return m_spawnPoint;
}
