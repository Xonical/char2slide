#include "MyDragon.h"
#include <string>
using namespace std;

/*
int TextAdd(int x, int y, string einText)
{
int erg = TextAdd(x, y, (char*)einText.c_str());
return  erg;
}
*/

int drawZone;
bool isFirstTimeCalled = true;


//MyDragon::MyDragon()
//{
//	drawZone = DrawAdd(0, 0, 480, 320);
//}
//
//
//MyDragon::~MyDragon()
//{
//}

//int drawZone = DrawAdd(0, 0, 480, 320);


void DisplayAbmessung(int &dispWidth, int &dispHeight)
{
	// iPhone
	dispWidth = 320;
	dispHeight = 480;
	// iPad
	if (DeviceGetUIType() == 1)
	{
		dispWidth = 768;
		dispHeight = 1024;
	}
	// iPhone5
	if (DeviceGetUIType() == 2)
	{
		dispWidth = 320;
		dispHeight = 568;
	}
}

void DrawPanel(Panel *panel){

	if (isFirstTimeCalled){
		drawZone = DrawAdd(0, 0, 480, 320);
		isFirstTimeCalled = false;
	}

	DrawSetFillColor(drawZone, /*0x66CDAA*/ (int)panel->getColor());
	DrawSquareFill(drawZone, panel->getX(), panel->getY(), panel->getWidth(), panel->getHeight());
}

