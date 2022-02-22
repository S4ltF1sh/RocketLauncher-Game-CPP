#pragma once
#include "../GameManager/Singleton.h"
#include <list>

#define GSM GameStateMachine::GetInstance()

class GameStateBase;

enum StateTypes
{
	INVALID=0,
	INTRO,
	MENU,
	LEVEL,
	PLAY,
	WIN,
	END,
};

class GameStateMachine :public CSingleton<GameStateMachine>{
public:
	GameStateMachine();
	~GameStateMachine();

	void ChangeState(GameStateBase* state);
	void ChangeState(StateTypes st);
	void PushState(StateTypes st);
	void PopState();

	void PerformStateChange();

	GameStateBase* currentState() const;
	GameStateBase* nextState() const;
	bool NeedToChangeState();
	bool HasState();

	void NewGame();

private:
	std::list<GameStateBase*> m_StateStack;
	GameStateBase* m_ActivesState;
	GameStateBase* m_NextState;
};