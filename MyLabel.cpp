#include "MyLabel.h"

// int MyLabel::font = FontAdd("Arial", "Regular", 13, 0x000000);

MyLabel::MyLabel()
{
	buildSave(0, 0, 0, "", 0);
}

MyLabel::MyLabel(int x, int y)
{
	buildSave(0, x, y, "", 0);
}

MyLabel::MyLabel(int x, int y, char *text)
{
	buildSave(0, x, y, text, 0);
}

MyLabel::MyLabel(int x, int y, char *text, int font)
{
	buildSave(0, x, y, text, font);
}

MyLabel::MyLabel(int cn, int x, int y)
{
	buildSave(cn, x, y, "", 0);
}

MyLabel::MyLabel(int cn, int x, int y, char *text)
{
	buildSave(cn, x, y, text, 0);
}

MyLabel::MyLabel(int cn, int x, int y, char *text, int font)
{
	buildSave(cn, x, y, text, font);
}

void MyLabel::buildSave(int cn, int x, int y, char *text, int font)
{
	setFont(font);
	this->x = x;
	this->y = y;

	this->tf = TextAdd(cn, this->x, this->y, text, this->font);
}

MyLabel::~MyLabel()
{
}

void MyLabel::setFont(int font)
{
	// bei 0 Standardfont setzen
	this->font = (font == 0) ? FontAdd("Arial", "Regular", 13, 0x070707) : font;

	//	if tf (!= null)

}

void MyLabel::setText(char *text)
{
	TextSetText(tf, text);
}

void MyLabel::appendText(char *text)
{
	TextGetText(tf, help);
	sprintf(help, "%s%s", help, text);
	this->text = help;
	TextSetText(tf, this->text);
}

void MyLabel::setTextf(char *format, ...)
{
	va_list args;
	va_start(args, format);
	vsprintf(help, format, args);
	va_end(args);
	this->text = help;

	TextSetText(tf, text);
}

void MyLabel::setVisible(bool wert)
{
	TextSetVisible(tf, wert);
}

void  MyLabel::setColor(int Color)
{
	TextSetColor(tf, Color);
}