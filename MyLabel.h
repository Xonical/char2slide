#pragma once
//====================================================
#include "DragonFireSDK.h"
#include <stdarg.h>

class MyLabel
{
private:
	int font;
	int tf;
	int x, y;

	char *text;
	char help[3000];

	void buildSave(int cn, int x, int y, char *text, int font);

public:
	MyLabel();
	MyLabel(int x, int y);
	MyLabel(int x, int y, char *text);
	MyLabel(int x, int y, char *text, int font);

	MyLabel(int cn, int x, int y);
	MyLabel(int cn, int x, int y, char *text);
	MyLabel(int cn, int x, int y, char *text, int font);

	~MyLabel();

	void setText(char *text);	      // einfache Ausgabe
	void setTextf(char *text, ...);   // formatierte Ausgabe
	void appendText(char *text);      // append
	void setVisible(bool wert);

	void setFont(int font);
	void setColor(int Color);
};
