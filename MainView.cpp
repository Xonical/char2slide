#include "MainView.h"


MainView::MainView()
{
	Panel *panelMainArea = new Panel(0, 0, 480, 320, Color::white);
	DrawPanel(panelMainArea);

	Panel *panelTopbar = new Panel(0, 0, 480, 55, Color::darkcyan);
	DrawPanel(panelTopbar);

	Panel *panelMain = new Panel(0, 55, 480, 265, Color::blanchedalmond);
	DrawPanel(panelMain);

	Panel *panelNewCategory = new Panel(0, 90, 480, 35, Color::darkcyan);
	DrawPanel(panelNewCategory);

	Panel *panelNewQuestion = new Panel(0, 150, 480, 35, Color::darkcyan);
	DrawPanel(panelNewQuestion);

	Panel *panelStartGame = new Panel(0, 210, 480, 35, Color::darkcyan);
	DrawPanel(panelStartGame);

	//Panel *panelFirstSeperator = new Panel(0, 83, 480, 5, Color::chocolate);
	//DrawPanel(panelFirstSeperator);

	//CharButtonPanel *panelCharArea = new CharButtonPanel(0, 88, 480, 185, Color::blanchedalmond);
	//DrawPanel(panelCharArea);

	//Panel *panelSecondSeperator = new Panel(0, 273, 480, 5, Color::chocolate);
	//DrawPanel(panelSecondSeperator);

	//Panel *answerPanel = new Panel(0, 278, 480, 28, Color::blanchedalmond);
	//DrawPanel(answerPanel);

	//Panel *panelBottombar = new Panel(0, 306, 480, 14, Color::aquamarine);
	//DrawPanel(panelBottombar);
}


MainView::~MainView()
{
}
