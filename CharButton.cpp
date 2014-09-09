#include "CharButton.h"


CharButton::CharButton(char a, int cn, int x, int y, int(*onClick)(int, int, int, int), int id)
{
	this->cArray[0] = a;

	this->x = x;
	this->y = y;
	this->initedX = x;
	this->initedX = y;


	// TODO
	//btn = ButtonAdd("Images/char_", 0, 0, onClick, 0);
	int ButtonFont = FontAdd("Helvetica", "Bold", 18, 0xFFFFFF);

	//view = ViewAdd("Images/myBtnBlue.png", x, y);
	//ViewSetSize(view, 24, 24);

	//TextAdd(6, 0, "A", ButtonFont);


	view = ViewAdd(cn, "Images/char_1.png", x, y);
	ViewSetSize(view, 24, 24);

	string str;
	str.append(&a);

	char p[] = { a, '\0' };
	TextAdd(x + 6, y, p, ButtonFont);


	touch = TouchAdd(cn, this->x, this->y, 24, 24, onClick, id);



	//touch = TouchAdd(cn, this->x, this->y, 24, 24, onClick, id);

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
	ViewSetxy(this->view, this->x, this->y);
	TextSetxy(this->view, this->x + 6, this->y);
	TouchSetxy(this->view, this->x, this->y);
}

CharButton::~CharButton()
{
}
