#include "PreGameView.h"


PreGameView::PreGameView()
{
	Panel *panelPreGameArea = new Panel(0, 0, 480, 320, Color::white);
	DrawPanel(panelPreGameArea);

	Panel *panelTopbar = new Panel(0, 0, 480, 55, Color::darkcyan);
	DrawPanel(panelTopbar);

	Panel *panelMain = new Panel(0, 55, 480, 265, Color::blanchedalmond);
	DrawPanel(panelMain);

	Panel *panelCategoryList = new Panel(0, 90, 480, 230, Color::chocolate);
	DrawPanel(panelCategoryList);
	/*
		Panel *panelNewQuestion = new Panel(0, 150, 480, 35, Color::darkcyan);
		DrawPanel(panelNewQuestion);

		Panel *panelStartGame = new Panel(0, 210, 480, 35, Color::darkcyan);
		DrawPanel(panelStartGame);*/
}


PreGameView::~PreGameView()
{
}
