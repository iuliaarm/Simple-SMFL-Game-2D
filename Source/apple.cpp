#include "apple.h"

Apple::Apple()
{
	shape.setSize(sf::Vector2f(50.0f, 50.0f));
	shape.setFillColor(sf::Color::Red);
	RandomPosition();
}

void Apple::RandomPosition()
{
	srand((unsigned int)time(NULL));

	int x = (rand() % 16);
	int y = (rand() % 16);

	shape.setPosition(x * 50.0f, y * 50.0f);
}