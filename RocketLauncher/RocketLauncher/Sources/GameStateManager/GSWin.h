#pragma once

#include "GameStateBase.h"
#include "GSPlay.h"

class GSWin : public GameStateBase {
public:
	GSWin();
	virtual ~GSWin();

	void Exit();
	void Pause();
	void Resume();

	void Init();
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);
private:
	sf::Sprite m_Background;
	std::list<GameButton*> m_ListBtn;
	sf::Text m_Title;
};