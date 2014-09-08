#pragma once
//====================================================
#include "DragonFireSDK.h"
#include <stdarg.h>
#include <string>

class MyButton
{
private:
	static int font;
	int btn;
	int tf;
	int img;
	int x, y, w, h;
	char text[100];
	char help[100];
	void buildSave(int cn, char *grafik, int x, int y, int(*myCall)(int), int id);

	int view;
	int touch;
	char* vtext;

public:
	~MyButton();
	MyButton();
	MyButton(char *grafik, int x, int y, int(*myCall)(int id), int id);
	MyButton(int cn, char *grafik, int x, int y, int(*myCall)(int id), int id);

	MyButton::MyButton(int x, int y, int width, int height, char* text, char* fontname, int(*onClick)(int, int, int, int), int id);
	MyButton::MyButton(int cn, int x, int y, int width, int height, char* text, char* fontname, int(*onClick)(int, int, int, int), int id);

	void setText(char *text);	      // einfacher Text
	void setTextf(char *text, ...);   // formatierter Text
	void appendText(char *text);      // append

	void setVisible(bool wert);
	// 	void setFont(int font);
	// 	void setColor(int Color);
};
