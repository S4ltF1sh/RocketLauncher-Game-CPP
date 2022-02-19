#include "GameStateBase.h"
#include "GSIntro.h"
#include "GSMenu.h"
#include "GSPlay.h"
#include "GSEnd.h"
#include "GSWin.h"
#include "GSSetting.h"

GameStateBase* GameStateBase::CreateState(StateTypes st) {
	GameStateBase* gs = nullptr;
	switch (st)
	{
	case INVALID:
		break;
	case INTRO:
		gs = new GSIntro();
		break;
	case MENU:
		gs = new GSMenu();
		break;
	case PLAY:
		gs = new GSPlay();
		break;
	case END:
		gs = new GSEnd();
		break;
	case WIN:
		gs = new GSWin();
		break;
	default:
		break;
	}
	return gs;
}