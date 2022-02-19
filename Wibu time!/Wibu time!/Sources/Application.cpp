#include "Application.h"
#include "GameStateManager/GameStateBase.h"

Application::~Application()
{
	if (m_window != nullptr) delete m_window;
}

void Application::Init()
{
	m_window = new sf::RenderWindow(sf::VideoMode(screenWidth, screenHeight), titleGame, sf::Style::Close);
	m_window->setFramerateLimit(FPS);
	m_window->setVerticalSyncEnabled(false);
	auto desktop = sf::VideoMode::getDesktopMode();
	m_window->setPosition(sf::Vector2i(desktop.width / 2 - screenWidth / 2, desktop.height / 2 - screenHeight / 2 - 50));

	GameStateMachine::GetInstance()->ChangeState(StateTypes::INTRO);

	WConnect->setWindow(m_window);

	InitMap();

	DATA->playMusic("BGMusic");
	DATA->getMusic("BGMusic")->setLoop(true);;
	DATA->getMusic("BGMusic")->setVolume(20);
}

void Application::Run()
{
	Init();
	sf::Clock clock;
	float deltaTime = 0.f;
	while (m_window->isOpen())
	{
		deltaTime = clock.restart().asSeconds();
		sf::Event event;
		while (m_window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				m_window->close();
		}
		Update(deltaTime);
		Render();
	}
	DATA->getMusic("BGMusic")->stop();
}

void Application::Update(float deltaTime)
{
	if (GameStateMachine::GetInstance()->NeedToChangeState()) {
		GameStateMachine::GetInstance()->PerformStateChange();
	}
	GameStateMachine::GetInstance()->currentState()->Update(deltaTime);
	//Doing something
}

void Application::Render()
{
	m_window->clear(sf::Color::Black);
	//Drawing something
	GameStateMachine::GetInstance()->currentState()->Render(m_window);
	m_window->display();
}


void Application::InitMap() {
	std::vector<std::vector<int>> Map;

	loadMapFormFromFile(Map, "Map1");
	insertMap("Map1", Map);

	loadMapFormFromFile(Map, "Map2");
	insertMap("Map2", Map);

	loadMapFormFromFile(Map, "Map3");
	insertMap("Map3", Map);

	loadMapFormFromFile(Map, "Map4");
	insertMap("Map4", Map);

	loadMapFormFromFile(Map, "Map5");
	insertMap("Map5", Map);

	loadMapFormFromFile(Map, "Map6");
	insertMap("Map6", Map);

	loadMapFormFromFile(Map, "Map7");
	insertMap("Map7", Map);

	loadMapFormFromFile(Map, "Map8");
	insertMap("Map8", Map);
}

void Application::loadMapFormFromFile(std::vector<std::vector<int>>& Map, std::string name) {
	Map.clear();
	Map.resize(col, std::vector<int>(row));
	int tmp;

	std::fstream input;
	input.open("MapForm/" + name + ".txt", std::ios::binary | std::ios::in);

	for (int i = 0; i < col; i++)
	{
		for (int j = 0; j < row; j++)
		{
			input >> tmp;
			Map[i][j] = tmp;
		}
	}

	input.close();
}

void Application::insertMap(std::string mapName, std::vector<std::vector<int>> mapForm)
{
	GSPlay::m_mapStorage.insert(std::pair<std::string, std::vector<std::vector<int>>>(mapName, mapForm));
	GSPlay::numMap++;
	std::cout << "load Map" << GSPlay::numMap << std::endl;
}