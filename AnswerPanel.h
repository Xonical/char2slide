#pragma once
#include "Panel.h"

class AnswerPanel : public Panel
{
public:
	AnswerPanel();
	AnswerPanel(int x, int y, int width, int height, Color color);
	~AnswerPanel();
};

