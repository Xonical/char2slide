#include "Panel.h"

Panel::Panel(){}


Panel::Panel(int x, int y, int width, int height, Color color)
{
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
	this->color = color;
}

Panel::~Panel()
{
}

void Panel::setX(int x){
	this->x = x;
}

int Panel::getX(){
	return this->x;
}

void Panel::setY(int y){
	this->y = y;
}

int Panel::getY(){
	return this->y;
}


void Panel::setWidth(int width){
	this->width = width;
}

int Panel::getWidth(){
	return this->width;
}

void Panel::setHeight(int height){
	this->height = height;
}

int Panel::getHeight(){
	return this->height;
}


void Panel::setColor(Color color){
	this->color = color;
}

Color Panel::getColor(){
	return this->color;
}

