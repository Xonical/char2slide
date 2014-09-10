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



//MyDragon::MyDragon()
//{
//	//drawZone = DrawAdd(0, 0, 480, 320);
//}
//
//
//MyDragon::~MyDragon()
//{
//}



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
	int drawZone = DrawAdd(0, 0, 480, 320);
	DrawAdd(panel->getX(), panel->getY(), panel->getWidth(), panel->getHeight());
	DrawSetFillColor(drawZone, 0x66CDAA);
}

