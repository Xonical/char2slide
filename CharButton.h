#pragma once
#include "DragonFireSDK.h"
#include <string>

using namespace std;

class CharButton
{
public:
	CharButton(char a, int cn, int x, int y, int(*onClick)(int, int, int, int), int id);
	void setX(int x);
	void setY(int y);
	int getX();
	int getY();
	int getID();
	int getInitedX();
	int getInitedY();
	~CharButton();

private:
	char cArray[1000];
	int x;
	int y;
	int touch;
	int view;
	int textfield;
	int cn;
	int initedX;
	int initedY;
	int id;
	void repaint();
};

