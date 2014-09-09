#pragma once
#include "CharButton.h"
#include <vector>
#include <time.h>
#include <algorithm>
#include "CharButton.h";

using namespace std;

class CharButtonGenerator
{
public:
	CharButtonGenerator(char answer[]);
	~CharButtonGenerator();

private:
	char allowedChars[100];
	void createAllowedChars();
	int countLetterOfAnswer(char answer[]);
	int countNumbersOfAnswer(char answer[]);
	vector <char> randomizeBasic(int basicNumbers, int basicLetters);


};

