#include "CharButtonGenerator.h"
#include <ctype.h>


void test();

CharButton *charButton;
int onClick2(int id, int event, int x, int y);
int offsetX2;
int offsetY2;
vector <CharButton> vecCharButtons;
int currentButtonID;
CharButton *buttonArray[2];

CharButtonGenerator::CharButtonGenerator(char answer[])
{
	int letters = countLetterOfAnswer(answer);

	int numbers = countNumbersOfAnswer(answer);

	double factor;

	if (letters >= 1 && letters <= 2){
		factor = 4;
	}
	if (letters >= 3 && letters <= 4){
		factor = 3;
	}
	if (letters >= 5 && letters <= 6){
		factor = 2;
	}
	if (letters >= 7 && letters <= 8){
		factor = 1.75;
	}
	if (letters >= 9 && letters <= 10){
		factor = 1.5;
	}
	if (letters >= 11){
		factor = 1.25;
	}

	int basicLetters = (letters * factor);


	if (numbers >= 1 && numbers <= 2){
		factor = 4;
	}
	if (numbers >= 3 && numbers <= 4){
		factor = 3;
	}
	if (numbers >= 5 && numbers <= 6){
		factor = 2;
	}
	if (numbers >= 7 && numbers <= 8){
		factor = 1.75;
	}
	if (numbers >= 9 && numbers <= 10){
		factor = 1.5;
	}
	if (numbers >= 11){
		factor = 1.25;
	}

	int basicNumbers = (numbers * factor);

	//int basicNumbersAndLetters = (basicLetters + basicNumbers - strlen(answer));


	//bool isAnswerContainingLetters;
	//bool isAnswerContainingNumbers;
	//isAnswerContainingLetters = letters > 0 ? true : false;
	//isAnswerContainingNumbers = numbers > 0 ? true : false;

	vector <char> vecBasic;
	vecBasic = randomizeBasic(basicNumbers, basicLetters);


	// http://www.cplusplus.com/reference/algorithm/random_shuffle/
	// We need to shuffle, because we want ABCDEF4242 -> A4B2C4D2EF
	random_shuffle(vecBasic.begin(), vecBasic.end());


	vecBasic.resize(vecBasic.size() - strlen(answer));

	// now the answer is at the end
	for (int i = 0; i < strlen(answer); i++)
	{
		vecBasic.push_back(answer[i]);
	}
	printf("Funzt \n");
	// so we must have shuffle again
	random_shuffle(vecBasic.begin(), vecBasic.end());

	//vecCharButtons = new vector <CharButton>();
	for (int i = 0; i < 2/*vecBasic.size*/; i++)
	{
		//printf("Test:  %d", c);
		charButton = new CharButton(vecBasic.at(i), i, 20 + i * 30, 20, onClick2, i);
		//vecCharButtons.push_back(charButton);
		buttonArray[i] = charButton;
	}
}

vector <char> CharButtonGenerator::randomizeBasic(int basicNumbers, int basicLetters){

	vector<char> vec;
	Randomize();
	RandomSetSeed(time(NULL));

	int numberSpan = 58 - 48;
	for (int i = 0; i < numberSpan; i++){
		// 123
		int random = Random(26);
		int randomNumber = random + 48;
		char cRandomNumber = randomNumber;
		vec.push_back(cRandomNumber);
	}

	int letterSpan = 90 - 65;
	for (int i = 0; i < letterSpan; i++){
		// ABC
		int random = Random(letterSpan);
		int randomLetter = random + 65;
		char cRandomLetter = randomLetter;
		vec.push_back(cRandomLetter);
	}

	return vec;
}


CharButtonGenerator::~CharButtonGenerator()
{
}


//void CharButtonGenerator::createAllowedChars(){
//
//	// http://www.torsten-horn.de/techdocs/ascii.htm
//	for (int i = 33, j = 0; i < 96; i++)
//	{
//		allowedChars[i] = i + j;
//		j++;
//	}
//
//}

//void test(){
//	char something[100] = "Senftube";
//
//	char *p = something;
//
//	while (*p) {
//		*p = toupper(*p);
//		p++;
//	}
//
//	printf("%s", something);
//}

int onClick2(int id, int event, int x, int y){

	CharButton *btn = buttonArray[id];

	//buttonArray[id] = charButton;

	if (event == 1)
	{
		//printf("1- ID: %d \n", id);
		offsetX2 = x - btn->getX();
		offsetY2 = y - btn->getY();

		currentButtonID = id;

		//printf("Clicked 1: %d %d \n", x, y);
		//printf("Clicked 2: %d %d \n", offsetX2, offsetY2);
	}

	if (event == 2)
	{
		//printf("2- ID: %d \n", id);
		btn->setX(x - offsetX2);
		btn->setY(y - offsetY2);
	}
	return 0;
}

int CharButtonGenerator::countLetterOfAnswer(char answer[]){

	int letterCounter = 0;

	for (int i = 0; i < strlen(answer); i++)
	{
		for (int j = 65; j <= 90; j++)
		{
			if (answer[i] == j){
				letterCounter++;
				printf("Foo: %d: \n ", answer[i]);
			}
		}

	}
	//printf("Bar: %d: \n", letterCounter);
	return letterCounter;
}

int CharButtonGenerator::countNumbersOfAnswer(char answer[]){

	int numbersCounter = 0;

	for (int i = 0; i < strlen(answer); i++)
	{
		for (int j = 48; j <= 57; j++)
		{
			if (answer[i] == j){
				numbersCounter++;
				//printf("Foo: %d: \n ", answer[i]);
			}
		}
	}

	//printf("Bar: %d: \n", numbersCounter);
	return numbersCounter;
}
