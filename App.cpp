//====================================================
// App.cpp
//====================================================
#include "DragonFireSDK.h"
#include "MyButton.h"
#include "CharButtonGenerator.h"
#include "CharButton.h"

int LogoImage;
int LogoView;


char a[] = "A";
char b[] = "B";

int btnA;
int btnB;


int clickedX;
int clickedY;
int offsetX;
int offsetY;

int onButtonClick(int id);
int onClick(int id, int event, int x, int y);

CharButton *btn;


void AppMain()
{
	// Application initialization code goes here.  Create the items / objects / etc.
	// that your app will need while it is running.
	//LogoImage = ImageAdd("Images/Logo.png"); // file location: Debug/Assets/Images/Logo.png
	//LogoView = ViewAdd(LogoImage, 0, 0);


	LandscapeMode();

	//btnA = ButtonAdd("Images/char_", 0, 0, onButtonClick, 0);
	int ButtonFont = FontAdd("Helvetica", "Bold", 18, 0xFFFFFF);
	//TextAdd(6, 0, "A", ButtonFont);


	//int view = ViewAdd("Images/char_1.png", 0, 0);
	//ViewSetSize(view, 24, 24);
	//TextAdd(6, 0, "A", ButtonFont);

	CharButtonGenerator *gen = new CharButtonGenerator("ABCXYZ0815");

	//btn = new CharButton('B', 0, 20, 20, onClick, 0);



}


int onClick(int id, int event, int x, int y){

	if (event == 1)
	{
		clickedX = x;
		clickedY = y;
		offsetX = x - btn->getX();
		offsetY = y - btn->getY();


		printf("Clicked 1: %d %d \n", x, y);
		printf("Clicked 2: %d %d \n", offsetX, offsetY);

	}

	if (event == 2)
	{
		printf("Move 1 : %d %d \n", x, y);
		//int offsetX = clickedX - btn->getInitedX();
		//int offsetY = clickedY - btn->getInitedY();

		printf("Move 2 : %d %d \n", x, y);


		btn->setX(x - offsetX);
		btn->setY(y - offsetY);
	}


	return 0;
}



void AppExit()
{

}

void OnTimer()
{
	// Main loop code goes here.  OnTimer() is called 30 times per second.
}

int onButtonClick(int id){



	return 0;
}