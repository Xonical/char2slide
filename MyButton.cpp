#include "MyButton.h"

// int MyButton::font = FontAdd("Arial", "Regular", 13, 0xFFFFFF);
int MyButton::font = -9999;

MyButton::~MyButton()
{
}

MyButton::MyButton(char *grafik, int x, int y, int(*myCall)(int), int id)
{
	buildSave(0, grafik, x, y, myCall, id);
}

MyButton::MyButton(int cn, char *grafik, int x, int y, int(*myCall)(int), int id)
{
	buildSave(cn, grafik, x, y, myCall, id);
}

void MyButton::buildSave(int cn, char *grafik, int x, int y, int(*myCall)(int), int id)
{
	// Grafikhöhe - Schrifthöhe / 2
	sprintf_s(this->text, "%s%s", grafik, "1.png");
	img = ImageAdd(this->text);
	int offsetY = (ImageGetHeight(img) - 13) / 2;

	btn = ButtonAdd(cn, grafik, x, y, myCall, id);
	tf = TextAdd(cn, x + 13, y + offsetY, "", font);
}


MyButton::MyButton()
{
	//		buildSave(0, 0, "", 0);
}

/*
MyButton::MyButton(int x, int y)
{
//		buildSave(x, y, "", 0);
}

MyButton::MyButton(int x, int y, char *text)
{
//	buildSave(x, y, text, 0);
}

MyButton::MyButton(int x, int y, char *text, int font)
{
//		buildSave(x, y, text, font);
}
*/

void MyButton::setText(char *text)
{
	TextSetText(tf, text);
	sprintf_s(this->text, "%s", text);
}

void MyButton::appendText(char *text)
{
	TextGetText(tf, this->help);
	sprintf_s(this->text, "%s%s", this->help, text);
	TextSetText(tf, this->text);
}

void MyButton::setTextf(char *format, ...)
{
	va_list args;
	va_start(args, format);
	vsprintf_s(this->help, format, args);
	va_end(args);

	sprintf_s(this->text, this->help);
	TextSetText(tf, this->text);
}

/*

void MyButton::setVisible(bool wert)
{
ButtonSetVisible(btn, wert);
TextSetVisible(tf, wert);
}

void MyButton::setFont(int font)
{
// bei 0 Standardfont setzen
this->font = (font == 0) ? FontAdd("Arial", "Regular", 13, 0x070707) : font;

//	if tf (!= null)

}

void  MyButton::setColor(int Color)
{
TextSetColor(tf, Color);
}

*/

MyButton::MyButton(int x, int y, int width, int height, char* text, char* fontname, int(*onClick)(int, int, int, int), int id)
{
	if (MyButton::font == -9999)
		font = FontAdd(fontname);

	this->x = x;
	this->y = y;
	this->w = width;
	this->h = height;
	this->vtext = text;

	view = ViewAdd("Images/myBtnBlue.png", x, y);
	ViewSetSize(view, width, height);

	// Breite des Textes anhand der einzelnen Grafiken ermitteln
	int laenge = 0;
	char help[100];
	int img;
	for (int i = 0; i < strlen(text); i++)
	{
		char ch = text[i];
		sprintf(help, "%s/F%03d.png", fontname, (int)ch);
		img = ImageAdd(help);
		laenge += ImageGetWidth(img);
	}
	int fontZeichenhoehe = ImageGetHeight(img);

	int xPos = (width - laenge) / 2;
	int yPos = (height - fontZeichenhoehe) / 2;

	tf = TextAdd(x + xPos, y + yPos, text, font);
	touch = TouchAdd(this->x, this->y, this->w, this->h, onClick, id);
}

MyButton::MyButton(int cn, int x, int y, int width, int height, char* text, char* fontname, int(*onClick)(int, int, int, int), int id)
{

	if (MyButton::font == -9999)
		font = FontAdd(fontname);

	this->x = x;
	this->y = y;
	this->w = width;
	this->h = height;
	this->vtext = text;

	view = ViewAdd(cn, "Images/myBtnBlue.png", x, y);
	ViewSetSize(view, width, height);

	int laenge = 0;
	char help[100];
	int img;

	for (int i = 0; i < strlen(text); i++)
	{
		char ch = text[i];
		sprintf(help, "%s/F%03d.png", fontname, (int)ch);
		img = ImageAdd(help);
		laenge += ImageGetWidth(img);
	}

	int fontZeichenhoehe = ImageGetHeight(img);

	int xPos = (width - laenge) / 2;
	int yPos = (height - fontZeichenhoehe) / 2;

	tf = TextAdd(cn, x + xPos, y + yPos, text, font);

	touch = TouchAdd(cn, this->x, this->y, this->w, this->h, onClick, id);
}

