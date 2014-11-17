#include "BetweenView.h"


BetweenView::BetweenView()
{
	initPanels();
	SQLiteSetOnRow(onRow);
	SQLiteExec("SELECT Latitude, Longitude, Timestamp FROM Geo ORDER BY Timestamp ASC;");
	SQLiteSetOnRow(onRowDummy);
}


BetweenView::~BetweenView()
{
}
void BetweenView::initPanels(){

	Panel *panelGameArea = new Panel(0, 0, 480, 320, Color::white);
	DrawPanel(panelGameArea);

	Panel *panelTopbar = new Panel(0, 0, 480, 55, Color::darkcyan);
	DrawPanel(panelTopbar);



	/*Panel *panelQuestionbar = new Panel(0, 55, 480, 28, Color::blanchedalmond);
	DrawPanel(panelQuestionbar);

	Panel *panelFirstSeperator = new Panel(0, 83, 480, 5, Color::chocolate);
	DrawPanel(panelFirstSeperator);

	CharButtonPanel *panelCharArea = new CharButtonPanel(0, 88, 480, 185, Color::blanchedalmond);
	DrawPanel(panelCharArea);

	Panel *panelSecondSeperator = new Panel(0, 273, 480, 5, Color::chocolate);
	DrawPanel(panelSecondSeperator);*/

	Panel *answerPanel = new Panel(0, 278, 480, 28, Color::blanchedalmond);
	DrawPanel(answerPanel);

	Panel *panelBottombar = new Panel(0, 306, 480, 14, Color::aquamarine);
	DrawPanel(panelBottombar);




}

int onRow(char* content)
{
	char* help;
	//ListElement li;

	//// Latitude besorgen (bis zum ersten Komma)
	//help = strtok(content, ",");
	//li.lat = atof(help);

	//// Longitude besorgen (bis zum zweiten Komma)
	//help = strtok(NULL, ",");
	//li.lng = atof(help);

	//// Timestamp besorgen (nach dem zweiten Komma)
	//help = strtok(NULL, ",");
	//li.timestamp = atoi(help);

	//// Element dem Vektor hinzufuegen
	//listVector.push_back(li);

	return 0;
}

// ---------------------------------------------------

int onRowDummy(char* content)
{
	return 0;
}

