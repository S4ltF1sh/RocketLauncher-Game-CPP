#pragma once
#include "GameStateBase.h"
#include "../GameObjects/Rocket.h"
#include "../GameObjects/Map.h"
#include "../GameObjects/IRState.h"

class GSPlay : public GameStateBase {
public:
	GSPlay();
	virtual ~GSPlay();

	void Exit();
	void Pause();
	void Resume();

	void Init();
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);

	void restart();
	void changeMap();

	static void setCurMap(int map) {
		curMap = map;
		printf("curMap: %d\n", curMap);
		std::fstream output;
		output.open("Map.txt", std::ios::binary | std::ios::out);
		output << curMap << " " << numDeath;
		output.close();
	}

	static std::map<std::string, std::vector<std::vector<int>>> m_mapStorage;

	static int numMap;
	static int curMap;
	static int numDeath;
	static sf::Text m_numDeath;

	/*static sf::Text deathByFall;
	static sf::Text deathByVoid;
	static sf::Text deathByRestart;*/

private:
	Rocket m_Rocket;
	Map m_Map;

	float m_currentTime;
	float m_loadTime;

	bool isEndMap;


	//BG:
	sf::Sprite m_Background;
	Animation* m_loadMap;

	//Map:
	std::vector<std::vector<int>> m_curMapForm;
};