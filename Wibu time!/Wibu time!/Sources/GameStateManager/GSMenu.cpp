#include "GSMenu.h"

GSMenu::GSMenu()
{
}

GSMenu::~GSMenu()
{
}

void GSMenu::Exit()
{
}

void GSMenu::Pause()
{
}

void GSMenu::Resume()
{
}

void GSMenu::Init()
{
	GameButton* button;
	//PlayButton
	button = new GameButton();
	button->Init("Play");
	button->setOnClick([]() {GSM->ChangeState(StateTypes::PLAY); });
	button->setPosition(335, 660);
	button->setSize(sf::Vector2f(150, 150));
	button->setOrigin(button->getSize() / 2.f);
	m_ListBtn.push_back(button);

	////Level Menu button
	//button = new GameButton();
	//button->Init("Level menu");
	//button->setOnClick([]() {GSM->ChangeState(StateTypes::LEVEL); });
	//button->setPosition(screenWidth / 2 - screenWidth / 8, screenHeight - screenHeight / 8);
	//button->setSize(sf::Vector2f(210, 233));
	//button->setOrigin(button->getSize() / 2.f);
	//m_ListBtn.push_back(button);

	//Exit Button
	button = new GameButton();
	button->Init("Exit");
	button->setOrigin(button->getSize() / 2.f);
	button->setPosition(1520, 700);
	button->setSize(sf::Vector2f(124, 58));
	button->setOnClick([]() {WConnect->getWindow()->close(); });
	m_ListBtn.push_back(button);

	//Background
	sf::Texture* texture = DATA->getTexture("Background/BG_Menu");
	m_Background.setTexture(*texture);
	m_Background.setOrigin((sf::Vector2f)texture->getSize() / 2.f);
	m_Background.setPosition(screenWidth / 2, screenHeight - texture->getSize().y / 2);
}

void GSMenu::Update(float deltaTime)
{
	for (auto btn : m_ListBtn) {
		btn->Update(deltaTime);
	}
}

void GSMenu::Render(sf::RenderWindow* window)
{
	window->draw(m_Background);
	for (auto btn : m_ListBtn) {
		btn->Render(window);
	}
}
