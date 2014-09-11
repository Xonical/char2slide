#pragma once
#include <vector>
#include <time.h>
#include <algorithm>
#include "CharButton.h";
#include "CharButtonPanel.h"
//#include "AnswerPanel.h"

using namespace std;

class CharButtonGenerator
{
public:
	CharButtonGenerator(char answer[], CharButtonPanel *charPanel_, Panel *answerPanel_);
	~CharButtonGenerator();

private:
	char allowedChars[100];
	void createAllowedChars();
	int countLetterOfAnswer(char answer[]);
	int countNumbersOfAnswer(char answer[]);
	vector <char> randomizeBasic(int basicNumbers, int basicLetters);
	int font;
	void initAnswerbar(char answer[]);
};

