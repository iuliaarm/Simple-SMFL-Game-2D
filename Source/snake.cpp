#include "snake.h"
Snake::Snake()
{
	head.setSize(sf::Vector2f(50.0f, 50.0f));
	head.setPosition(0.0f, 0.0f);
	head.setFillColor(sf::Color(0, 150, 0));
	parts.push_back(head);
	segmentNumber = 1;
}
Snake::~Snake()
{
}

sf::RectangleShape Snake::SetPart(sf::Vector2f size, sf::Vector2f position, sf::Color color)
{
	sf::RectangleShape part;
	part.setSize(size);
	part.setPosition(position);
	part.setFillColor(color);
	return part;
}

void Snake::Move(Direction dir)
{
	for (int i = (int)parts.size() - 1; i > 0; i--)
	{
		parts[i].setPosition(parts[i - 1].getPosition().x, parts[i - 1].getPosition().y);
	}
	if (direction == Direction::Left)
	{
		parts[0].setPosition(parts[0].getPosition().x - 50.0f, parts[0].getPosition().y);
	}
	else if (direction == Direction::Right)
	{
		parts[0].setPosition(parts[0].getPosition().x + 50.0f, parts[0].getPosition().y);
	}
	else if (direction == Direction::Up)
	{
		parts[0].setPosition(parts[0].getPosition().x, parts[0].getPosition().y - 50.0f);
	}
	else if (direction == Direction::Down)
	{
		parts[0].setPosition(parts[0].getPosition().x, parts[0].getPosition().y + 50.0f);
	}
}

void Snake::Grow()
{
	sf::RectangleShape part;
	part = SetPart(sf::Vector2f(50.0f, 50.0f), sf::Vector2f(parts[parts.size() - 1].
		getPosition().x, parts[parts.size() - 1].getPosition().y), sf::Color::Green);

	part.setOutlineThickness(1.0f);
	part.setOutlineColor(sf::Color::Black);
	parts.push_back(part);
	segmentNumber++;
}

void Snake::Reset()
{
	segmentNumber = 1;
	parts.resize(1);
	direction = Direction::Right;
	parts[0].setPosition(0.0f, 0.0f);
}

void Snake::Input()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && direction != Direction::Down)
	{
		direction = Direction::Up;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && direction != Direction::Left)
	{
		direction = Direction::Right;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && direction != Direction::Up)
	{
		direction = Direction::Down;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && direction != Direction::Right)
	{
		direction = Direction::Left;
	}

	Move(direction);
}