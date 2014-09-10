#pragma once
#include "DragonFireSDK.h"

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
};

