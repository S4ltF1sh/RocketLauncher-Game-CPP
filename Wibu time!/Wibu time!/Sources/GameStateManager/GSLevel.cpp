#include "GSLevel.h"
#include "GSPlay.h"

GSLevel::GSLevel()
{
}

GSLevel::~GSLevel()
{
}

void GSLevel::Exit()
{
}

void GSLevel::Pause()
{
}

void GSLevel::Resume()
{
}

void GSLevel::Init()
{
	GameButton* button;
	//Map 1:
	//button = new GameButton();
	//button->Init("close_2");
	//button->setOrigin(button->getSize() / 2.f);
	//button->setSize(sf::Vector2f(50, 50));
	//button->setPosition(screenWidth - screenWidth/20, screenHeight/8);
	////button->setOnClick([]() {GSPlay::setCurMap("Map1"); });
	//m_ListBtn.push_back(button);

	//Map 2:
	button = new GameButton();
	button->Init("close_2");
	button->setOrigin(button->getSize() / 2.f);
	button->setSize(sf::Vector2f(50, 50));
	button->setPosition(screenWidth - screenWidth / 20, screenHeight / 8);
	button->setOnClick([]() {GSM->PopState(); });
	m_ListBtn.push_back(button);
}

void GSLevel::Update(float deltaTime)
{
	for (auto btn : m_ListBtn) {
		btn->Update(deltaTime);
	}
}

void GSLevel::Render(sf::RenderWindow* window)
{
	//window->draw(m_Background);
	window->draw(m_Title);
	for (auto btn : m_ListBtn) {
		btn->Render(window);
	}
}
