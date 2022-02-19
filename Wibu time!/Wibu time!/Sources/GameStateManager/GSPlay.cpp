#include "GSPlay.h"

GSPlay::GSPlay()
{
	std::fstream input;
	input.open("Map.txt", std::ios::binary | std::ios::in);
	input >> curMap >> numDeath;
	input.close();

	m_currentTime = 0.f;
	m_loadTime = 1.5f;

	m_curMapForm = m_mapStorage["Map" + std::to_string(curMap)];
	m_numDeath.setString("Total death: " + std::to_string(numDeath));
	m_numDeath.setFont(*DATA->getFont("ARCADE"));
	m_numDeath.setCharacterSize(40);
	m_numDeath.setOrigin(m_numDeath.getLocalBounds().left + m_numDeath.getLocalBounds().width / 2.0f,
		m_numDeath.getLocalBounds().top + m_numDeath.getLocalBounds().height / 2.0f);
	m_numDeath.setPosition(screenWidth - screenWidth / 8, screenHeight / 16);
}

GSPlay::~GSPlay()
{
}

void GSPlay::Exit()
{
}

void GSPlay::Pause()
{
}

void GSPlay::Resume()
{
}

void GSPlay::Init()
{
	//printf("PlayInit\n");
	m_Map.Init(m_curMapForm, "Map" + std::to_string(curMap));

	m_Rocket.Init(m_Map.getSpawnPoint());
}

void GSPlay::Update(float deltaTime)
{
	m_currentTime += deltaTime;
	if (m_currentTime > m_loadTime)
	{
		m_Rocket.Update(deltaTime);
		//auto restart game:
		sf::Vector2f curPos = m_Rocket.getHitBox()->getPosition();
		if ((m_Rocket.getFeul()->getSize().y <= 0 && (curPos.x > screenWidth || curPos.x < 0 || curPos.y > screenHeight || curPos.y < 0))
			|| sf::Keyboard::isKeyPressed(sf::Keyboard::R))
		{
			restart();
		}
	}

	m_Map.Update(deltaTime, m_curMapForm, &m_Rocket);

	//change map or set WIN:
	if (m_Rocket.getHitBox()->getWinStatus())
	{
		if (curMap == numMap)
		{
			m_numDeath.setPosition(screenWidth / 2.f, screenHeight / 2.f);
			GSM->ChangeState(WIN);
		}
		else
		{
			changeMap();
		}
	}

	m_numDeath.setString("Total death: " + std::to_string(numDeath));
}

void GSPlay::Render(sf::RenderWindow* window)
{
	window->draw(m_Background);
	window->draw(m_numDeath);

	m_Map.Render(window, m_curMapForm);
	if (m_currentTime > m_loadTime)
	{
		m_Rocket.Render(window);
	}
}

void GSPlay::restart()
{
	numDeath++;
	std::fstream output;
	output.open("Map.txt", std::ios::binary | std::ios::out);
	output << curMap << " " << numDeath;
	output.close();

	m_Map.Init(m_curMapForm, "Map" + std::to_string(curMap));
	m_currentTime = 0.f;
	m_Rocket.setFallTime(0.f);
	m_Rocket.getHitBox()->setPosition(m_Map.getSpawnPoint());
	m_Rocket.getFeul()->setSize(sf::Vector2f(FEUL_X, FEUL_MAX));
	m_Rocket.changeNextState(IRState::FALL);
}

void GSPlay::changeMap()
{
	if (curMap < numMap) {
		curMap++;
		printf("curMap: %d\n", curMap);
		std::fstream output;
		output.open("Map.txt", std::ios::binary | std::ios::out);
		output << curMap << " " << numDeath;
		output.close();
	}

	GSM->PopState();
	GSM->ChangeState(PLAY);
}
