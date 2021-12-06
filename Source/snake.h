#pragma once
#define SFML_STATIC
#include "SFML/Graphics.hpp"


enum class Direction
{
	Left,
	Right,
	Up,
	Down,
};

class Snake
{
public:

	Direction direction = Direction::Right;
	std::vector<sf::RectangleShape> parts;
	int segmentNumber = 1;
	Snake();
	~Snake();
	void Input();

	void Grow();
	void Reset();

private:
	sf::RectangleShape head;
	sf::RectangleShape SetPart(sf::Vector2f size, sf::Vector2f position, sf::Color color);
	void Move(Direction dir);
};