#pragma once
#include "MyDragon.h"
#include "CharButtonGenerator.h"
#include "GameViewAreas.h"
#include "Color.h"

class MainMenueView
{
public:
	MainMenueView();
	~MainMenueView();
private:
	void createView();
	int statusbar;
	int answerbar;
	int topbar;
	int drawZone;
	Panel *panel;
};

