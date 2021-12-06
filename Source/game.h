#pragma once
#define SFML_STATIC
#include "snake.h"
#include "apple.h"
#include "screen.h"
#include <iostream>
class Game
{
public:
	Snake snake;
	Apple apple;
	unsigned char score = 0;
	Game();
	void CheckCollision(int screenH, int screenW);
	void run();
private:
};