#include "GameButton.h"

GameButton::GameButton()
{
	m_isHandling = false;
}

GameButton::~GameButton()
{
}

void GameButton::Init(std::string name)
{
	sf::Texture* texture = DATA->getTexture("btn/" + name);
	this->setTexture(texture);
	this->setSize(sf::Vector2f(texture->getSize()));
}

void GameButton::Update(float deltaTime)
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		HandleTouchEvent();
	}
}

void GameButton::Render(sf::RenderWindow* window)
{
	window->draw(*this);
}

void GameButton::HandleTouchEvent()
{
	m_isHandling = false;
	if (this->getGlobalBounds().contains((sf::Vector2f)sf::Mouse::getPosition(*WConnect->getWindow())))
	{
		m_btnClickFunc();
		m_isHandling = true;
	}
}

bool GameButton::isHandle()
{
	return m_isHandling;
}

void GameButton::setOnClick(void(*Func)())
{
	m_btnClickFunc = Func;
}
