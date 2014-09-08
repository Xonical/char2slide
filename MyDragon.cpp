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

