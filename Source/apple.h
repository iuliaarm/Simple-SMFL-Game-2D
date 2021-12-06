#pragma once
#include "SFML/Graphics.hpp"

class Apple
{
public:
	sf::RectangleShape shape;
	Apple();

	void RandomPosition();
};