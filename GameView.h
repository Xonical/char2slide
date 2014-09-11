#pragma once
#include "MyDragon.h"
#include "CharButtonGenerator.h"
#include "GameViewAreas.h"
#include "Color.h"
//#include "AnswerPanel.h"
#include "CharButtonPanel.h"

class GameView
{
public:
	GameView();
	~GameView();
private:
	void createView();
	int statusbar;
	int answerbar;
	int topbar;
	int drawZone;
	Panel *panelGameArea;
	Panel *panelTopbar;
};

