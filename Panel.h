#pragma once
#include "Color.h"
class Panel
{
public:
	Panel();
	Panel(int x, int y, int width, int height, Color color);
	~Panel();
	void setX(int x);
	void setY(int y);
	void setWidth(int width);
	void setHeight(int height);
	void setColor(Color color);

	int getX();
	int getY();
	int getWidth();
	int getHeight();
	Color getColor();

private:
	int x;
	int y;
	int width;
	int height;
	Color color;
};

