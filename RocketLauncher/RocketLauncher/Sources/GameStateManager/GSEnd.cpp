#include "GSEnd.h"

GSEnd::GSEnd()
{
}

GSEnd::~GSEnd()
{
}

void GSEnd::Exit()
{
}

void GSEnd::Pause()
{
}

void GSEnd::Resume()
{
}

void GSEnd::Init()
{
	GameButton* button;
	//menu Button
	button = new GameButton();
	button->Init("menu");
	button->setOrigin(button->getSize() / 2.f);
	button->setPosition(screenWidth / 2 + screenWidth / 12, screenHeight - screenHeight / 8);
	button->setOnClick([]() {
		GSM->PopState();
		GSM->PopState();
		});
	m_ListBtn.push_back(button);

	//replay Button
	button = new GameButton();
	button->Init("restart");
	button->setOrigin(button->getSize() / 2.f);
	button->setPosition(screenWidth / 2 - screenWidth / 12, screenHeight - screenHeight / 8);
	button->setOnClick([]() {
		GSM->PopState();
		GSM->PopState();
		GSM->ChangeState(StateTypes::PLAY);
		});
	m_ListBtn.push_back(button);

	//Background
	sf::Texture* texture = DATA->getTexture("Background layers/Background");
	m_Background.setTexture(*texture);
	m_Background.setOrigin((sf::Vector2f)texture->getSize() / 2.f);
	m_Background.setPosition(screenWidth / 2, screenHeight - texture->getSize().y / 2);

	//Tile Game
	m_Title.setString("END GAME!");
	m_Title.setFont(*DATA->getFont("ARCADE"));
	m_Title.setOrigin(m_Title.getLocalBounds().left + m_Title.getLocalBounds().width / 2.0f,
		m_Title.getLocalBounds().top + m_Title.getLocalBounds().height / 2.0f);
	m_Title.setPosition(screenWidth / 2, screenHeight / 5);
	m_Title.setCharacterSize(40);
}

void GSEnd::Update(float deltaTime)
{
	for (auto btn : m_ListBtn) {
		btn->Update(deltaTime);
	}
}

void GSEnd::Render(sf::RenderWindow* window)
{
	window->draw(m_Background);
	for (auto btn : m_ListBtn) {
		btn->Render(window);
	}
	window->draw(m_Title);
}
