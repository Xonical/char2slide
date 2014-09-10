#include "MyButtonV3.h"


//int MyButtonV3::font = FontAdd("Arial", "Regular", 13, 0xFFFFFF);


//char a[] = "A";
//char b[] = "B";

int btn;


//MyButtonV3::MyButtonV3(char *graphik, int x, int y, int(*myCallback)(int), int id)
//{
//	int yOffset = (30 - 13) / 2.0;
//
//	button = ButtonAdd(graphik, x, y, myCallback, id);
//	textfeld = TextAdd(x + 13, y + yOffset, "", font);
//}

MyButtonV3::MyButtonV3(int cn, int x, int y, int(*myCallback)(int), int id)
{
	//int yOffset = (30 - 13) / 2.0;

	//button = ButtonAdd(cn, graphik, x, y, myCallback, id);
	//textfeld = TextAdd(cn, x + 13, y + yOffset, "", font);


	btn = ButtonAdd("Images/char_", 0, 0, myCallback, 0);
	int ButtonFont = FontAdd("Helvetica", "Bold", 18, 0xFFFFFF);
	TextAdd(6, 0, "A", ButtonFont);

}

MyButtonV3::~MyButtonV3()
{
}