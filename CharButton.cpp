#include "CharButton.h"


CharButton::CharButton(char a, int cn, int x, int y, int(*onClick)(int, int, int, int), int id)
{
	this->cArray[0] = a;
	this->id = id;
	this->x = x;
	this->y = y;
	this->initedX = x;
	this->initedX = y;

	int ButtonFont = FontAdd("Helvetica", "Bold", 18, 0xFFFFFF);

	string str;
	str.append(&a);

	char p[] = { a, '\0' };

	view = ViewAdd("Images/char_1.png", x, y);

	ViewSetSize(view, 24, 24);
	textfield = TextAdd(x + 6, y, p, ButtonFont);

	touch = TouchAdd(this->x, this->y, 24, 24, onClick, id);
}

void CharButton::setX(int x){
	this->x = x;
	repaint();
}

void CharButton::setY(int y){
	this->y = y;
	repaint();
}

int CharButton::getX(){
	return this->x;
}

int CharButton::getY(){
	return this->y;
}

int CharButton::getInitedX(){
	return this->initedX;
}

int CharButton::getInitedY(){
	return this->initedY;
}

void CharButton::repaint(){
	printf("Klasse Charbutton: %d ", this->id);
	ViewSetxy(this->view, this->x, this->y);
	TextSetxy(this->textfield, this->x + 6, this->y);
	TouchSetxy(this->touch, this->x, this->y);
}

int CharButton::getID(){
	return this->id;
}

CharButton::~CharButton()
{
}
