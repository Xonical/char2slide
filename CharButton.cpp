#include "CharButton.h"


CharButton::CharButton(char a, int font, int x, int y, int(*onClick)(int, int, int, int), int id)
{
	this->cArray[0] = a;
	this->id = id;
	this->x = x;
	this->y = y;
	this->initedX = x;
	this->initedX = y;
	this->character = a;


	string str;
	str.append(&a);

	char p[] = { a, '\0' };

	view = ViewAdd("Images/char_1.png", x, y);


	ViewSetSize(view, 24, 24);
	textfield = TextAdd(x + 6, y, p, font);

	touch = TouchAdd(this->x, this->y, 24, 24, onClick, id);
}


CharButton::CharButton(char a, int font, int x, int y, int id){
	this->font = font;
	this->cArray[0] = a;
	this->id = id;
	this->x = x;
	this->y = y;
	this->initedX = x;
	this->initedX = y;
	this->character = a;

	string str;
	str.append(&a);

	char p[] = { a, '\0' };

	view = ViewAdd("Images/char_1.png", x, y);


	ViewSetSize(view, 24, 24);
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

char CharButton::getChar(){
	return this->character;
}
// Answer Button
void CharButton::showFont(){
	char p[] = { this->character, '\0' };
	textfield = TextAdd(this->getX() + 6, this->getY(), p, this->font);
}

bool CharButton::getIsCorrect(){
	return this->isCorrect;
}

void CharButton::setIsCorrect(bool isCorrect){
	this->isCorrect = isCorrect;
	this->showFont();
}
// Anwer-Button End

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



