#include "MainMenueView.h"
#include "GameViewAreas.h"

MainMenueView::MainMenueView()
{
	createView();
}


MainMenueView::~MainMenueView()
{
}

void MainMenueView::createView(){

	GameArea::Width = 480;
	GameArea::Height = 320;
	GameArea::x = 0;
	GameArea::y = 0;

	drawZone = DrawAdd(GameArea::x, GameArea::y, GameArea::Width, GameArea::Height);


	// topbar
	TopbarArea::Width = 480;
	TopbarArea::Height = 60;
	TopbarArea::x = GameArea::x;
	TopbarArea::y = GameArea::y + TopbarArea::Height;
	DrawSetFillColor(drawZone, 0xAAAAAA);
	DrawSquareFill(drawZone, TopbarArea::x, TopbarArea::y, TopbarArea::Width, TopbarArea::Height);


	// questionbar
	DrawSetFillColor(drawZone, 0x91FFEF);
	DrawSquareFill(drawZone, 0, 60, 480, 106);





	//Seperator
	DrawSetFillColor(drawZone, 0xAAAAAA);
	DrawSquareFill(drawZone, 0, 106, 480, 5);

	// Area for Characters
	DrawSetFillColor(drawZone, 0xFFFFFF);
	DrawSquareFill(drawZone, 0, 111, 480, 140);

	CharactersArea::x = 0;
	CharactersArea::y = 111;
	CharactersArea::Width = GameArea::Width;
	//CharactersArea::Height = GameArea -




	//Seperator
	DrawSetFillColor(drawZone, 0xAAAAAA);
	DrawSquareFill(drawZone, 0, 251, 480, 5);

	// Answerbar
	DrawSetFillColor(drawZone, 0x0000FF);
	DrawSquareFill(drawZone, 0, 256, 480, 40);


	// Bottombar
	DrawSetFillColor(drawZone, 0xAAAAAA);
	DrawSquareFill(drawZone, 0, 296, 480, 24);


	CharButtonGenerator *gen = new CharButtonGenerator("ABCXYZ0815");




}

