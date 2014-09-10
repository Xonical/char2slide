#pragma once

#include "DragonFireSDK.h"

class MyButtonV3
{
private:
	int button;

	static int font;

	int textfeld;
	char text[3000];



public:
	MyButtonV3(char *graphik, int x, int y, int(*myCallback)(int), int id);
	MyButtonV3(int cn, int x, int y, int(*myCallback)(int), int id);
	~MyButtonV3();
};
