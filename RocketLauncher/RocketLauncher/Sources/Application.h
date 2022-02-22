#pragma once
#include "GameStateManager/GameStateMachine.h"
#include "GameManager/ResourceManager.h"
#include "GameStateManager/GSPlay.h"

class Application {
public:
	void Run();
	~Application();

private:
	void Init();
	void Update(float deltaTime);
	void Render();

	void InitMap();
	void loadMapFormFromFile(std::vector<std::vector<int>>& Map, std::string name);
	void insertMap(std::string mapName, std::vector<std::vector<int>> mapForm);

private:
	sf::RenderWindow* m_window;
};