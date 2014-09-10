#include "MainMenueView.h"


MainMenueView::MainMenueView()
{
	createView();
}


MainMenueView::~MainMenueView()
{
}

void MainMenueView::createView(){


	drawZone = DrawAdd(0, 0, 480, 320);


	// topbar
	DrawSetFillColor(drawZone, 0xAAAAAA);
	DrawSquareFill(drawZone, 0, 0, 480, 60);

	// questionbar
	DrawSetFillColor(drawZone, 0x91FFEF);
	DrawSquareFill(drawZone, 0, 60, 480, 106);




	//Seperator
	DrawSetFillColor(drawZone, 0xAAAAAA);
	DrawSquareFill(drawZone, 0, 106, 480, 5);

	// Area for Characters
	DrawSetFillColor(drawZone, 0xFFFFFF);
	DrawSquareFill(drawZone, 0, 111, 480, 140);


	//Seperator
	DrawSetFillColor(drawZone, 0xAAAAAA);
	DrawSquareFill(drawZone, 0, 251, 480, 5);

	// Answerbar
	DrawSetFillColor(drawZone, 0x0000FF);
	DrawSquareFill(drawZone, 0, 256, 480, 40);


	// Bottombar
	DrawSetFillColor(drawZone, 0xAAAAAA);
	DrawSquareFill(drawZone, 0, 296, 480, 24);







}

