//Iulia-Teodora Armegioiu, 05.12.2021


#include "Screen.h"
#include "game.h"
int screenWidth = 1000;
int screenHeight = 1000;

/*
Galba v1.4
DrawPixelColor		-> renamed DrawPixel as an overloaded function
DrawCircleColor		-> renamed DrawCircle as an overloaded function
DrawRectangleColor	-> renamed DrawRectangle as an overloaded function

unsigned char a; for Alpha (255 = no transparency) added to the Color struct, draw functions taking unsigned char r,g,b now takes unsigned char r,g,b,a

*/

int main(int argc, char** argv)
{
	Game game;
	game.run();
	return 0;
}