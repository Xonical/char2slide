//====================================================
// App.cpp
//====================================================
#include "DragonFireSDK.h"

int LogoImage;
int LogoView;


char a[] = "A";
char b[] = "B";




void AppMain()
{
	// Application initialization code goes here.  Create the items / objects / etc.
	// that your app will need while it is running.
	LogoImage = ImageAdd("Images/Logo.png"); // file location: Debug/Assets/Images/Logo.png
	LogoView = ViewAdd(LogoImage, 0, 0);
}

void AppExit()
{
	// Application exit code goes here.  Perform any clean up your app might 
	// need to do in the event of interruption by a phone call or the user
	// pressing the Home button, or some other event that would cause your
	// application to terminate.
}

void OnTimer()
{
	// Main loop code goes here.  OnTimer() is called 30 times per second.
}