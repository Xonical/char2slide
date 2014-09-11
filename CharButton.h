#pragma once
#include "DragonFireSDK.h"
#include <string>

using namespace std;

class CharButton
{
public:
	CharButton(char a, int font, int x, int y, int(*onClick)(int, int, int, int), int id);
	CharButton(char a, int font, int x, int y, int id);
	void setX(int x);
	void setY(int y);
	int getX();
	int getY();
	int getID();
	int getInitedX();
	int getInitedY();
	bool getIsCorrect();
	void setIsCorrect(bool isCorrect);
	char getChar();
	~CharButton();

private:
	void showFont();
	char cArray[1000];
	int x;
	int y;
	int touch;
	int view;
	int textfield;
	int initedX;
	int initedY;
	int id;
	int font;
	char character;
	void repaint();
	bool isCorrect = false;
};

