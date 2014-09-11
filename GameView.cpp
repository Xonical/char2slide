#include "GameView.h"
#include "Panel.h"
#include "MyDragon.h"

GameView::GameView()
{
	createView();
}


GameView::~GameView()
{
}

void GameView::createView(){

	printf("MMV 1");
	printf("MMV 2");

	panelGameArea = new Panel(0, 0, 480, 320, Color::white);
	DrawPanel(panelGameArea);

	panelTopbar = new Panel(0, 0, 480, 55, Color::darkcyan);
	DrawPanel(panelTopbar);

	Panel *panelQuestionbar = new Panel(0, 55, 480, 28, Color::blanchedalmond);
	DrawPanel(panelQuestionbar);

	Panel *panelFirstSeperator = new Panel(0, 83, 480, 5, Color::chocolate);
	DrawPanel(panelFirstSeperator);

	CharButtonPanel *panelCharArea = new CharButtonPanel(0, 88, 480, 185, Color::blanchedalmond);
	DrawPanel(panelCharArea);

	Panel *panelSecondSeperator = new Panel(0, 273, 480, 5, Color::chocolate);
	DrawPanel(panelSecondSeperator);

	Panel *answerPanel = new Panel(0, 278, 480, 28, Color::blanchedalmond);
	DrawPanel(answerPanel);

	Panel *panelBottombar = new Panel(0, 306, 480, 14, Color::aquamarine);
	DrawPanel(panelBottombar);


	CharButtonGenerator *gen = new CharButtonGenerator("Foo", panelCharArea, answerPanel);
}

