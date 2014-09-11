#include "CharButtonGenerator.h"
#include <ctype.h>


void test();

CharButton *charButton;
CharButton *charAnswerButton;
int onClick2(int id, int event, int x, int y);
int offsetX2;
int offsetY2;
vector <CharButton*> vecCharButtons;
vector <CharButton*> vecAnswerButtons;
CharButton *buttonArray[2];
CharButtonPanel *charPanel;
Panel *answerPanel;
bool isButtonSetToUnvisible(CharButton *btn);

CharButtonGenerator::CharButtonGenerator(char answer[], CharButtonPanel *charPanel_, Panel *answerPanel_)
{
	initAnswerbar(answer);


	charPanel = charPanel_;
	answerPanel = answerPanel_;

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



	font = FontAdd("Helvetica", "Bold", 18, 0xFFFFFF);

	int offSetY = charPanel_->getY() + 20;
	int offSetX = 12;

	//vecCharButtons = new vector <CharButton>();
	for (int i = 1; i <= vecBasic.size(); i++)
	{
		//printf("Schleife y-Achse: %d    char: %c \n", offSetY, vecBasic.at(i - 1));
		charButton = new CharButton(vecBasic.at(i - 1), font, /*charPanel_->getX() + i * 30 + 12*/offSetX, offSetY, onClick2, i - 1);

		offSetX += 30;
		if (i % 15 == 0){
			// Next "row"
			offSetY += 30;
			offSetX = 12;
		}
		vecCharButtons.push_back(charButton);
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

void CharButtonGenerator::initAnswerbar(char answer[]){

	font = FontAdd("Helvetica", "Bold", 18, 0xFFFFFF);

	for (int i = 0; i < strlen(answer); i++)
	{
		//printf("Test:  %d", c);




		charAnswerButton = new CharButton(answer[i], font, 0 + i * 30, 273 + 8, i);
		vecAnswerButtons.push_back(charAnswerButton);
	}

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

	//CharButton *btn = buttonArray[id];
	CharButton * btn = vecCharButtons.at(id);

	if (btn->getX() == -24){
		return 0;
	}

	if (event == 1)
	{
		//printf("1- ID: %d \n", id);
		offsetX2 = x - btn->getX();
		offsetY2 = y - btn->getY();

		//printf("Clicked 1: %d %d \n", x, y);
		//printf("Clicked 2: %d %d \n", offsetX2, offsetY2);
	}

	if (event == 2)
	{
		int newX = x - offsetX2;
		int newY = y - offsetY2;

		printf("1: %d \n", newX);
		printf("2: %d \n", newY);
		printf("3: %d \n", charPanel->getX());
		printf("4: %d \n", charPanel->getY());
		printf("5: %d \n", charPanel->getWidth());

		//Check if the charButton ist moved outside Panel(Top, Left and Right)
		bool isMovedToLeftRightTopOutsideCharPanel = newX < charPanel->getX()
			|| newY < charPanel->getY()
			|| newX >(charPanel->getWidth() - 24);


		if (!isMovedToLeftRightTopOutsideCharPanel){
			// It's not moved outside (Top, Left, Right)
			// now we can check the bottom
			btn->setX(newX);


			// 24 = Button size
			int areaYBegin = charPanel->getY() + charPanel->getHeight() - 24;// +answerPanel->getHeight();
			//printf("6: %d \n", absoluteWallY);
			int areaYEnd = areaYBegin + answerPanel->getHeight() + 5;

			//int testWallY = absoluteWallY + answerPanel->getHeight / 2;


			if (newY < areaYEnd){
				btn->setY(newY);
			}


			if (newY>278){

				if (isButtonSetToUnvisible(btn)){

					bool allButtonsAreCorrect = true;
					btn->setX(-24);
					// check all Buttons, if they are visible (visible == correct)
					for each (CharButton *var in vecAnswerButtons){
						if (var->getIsCorrect() == false){
							allButtonsAreCorrect = false;
						}
					}
					if (allButtonsAreCorrect){
						printf("I won---");
					}

				}


			}

		}
		else{

		}



	}
	return 0;
}

bool isButtonSetToUnvisible(CharButton *btn){

	for each (CharButton *var in vecAnswerButtons)
	{
		int minX = var->getX();
		int maxX = var->getX() + 24;


		printf("7: %d \n", minX);
		printf("8: %d \n", maxX);
		printf("8.1: %d \n", btn->getX());


		for (int i = minX; i <= maxX; i++){
			if (btn->getX() == i){
				printf("9: %d \n", btn->getX());
				printf("10: %c \n", var->getChar());
				printf("11: %c \n", btn->getChar());





				if (var->getChar() == btn->getChar()){


					if (btn->getIsCorrect()){
						// Answer-Char was already set tocorrect
						// Beware of double unvisible Chars (-24x)
						return false;

					}
					else{
						var->setIsCorrect(true);
						printf("Correct");
						return true;
					}



				}
			}
		}
	}
	printf("False");
	// char-Button was not moved to the correct Answer-Button
	return false;
}

int CharButtonGenerator::countLetterOfAnswer(char answer[]){

	int letterCounter = 0;

	for (int i = 0; i < strlen(answer); i++)
	{
		for (int j = 65; j <= 90; j++)
		{
			if (answer[i] == j){
				letterCounter++;
				//printf("Foo: %d: \n ", answer[i]);
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
