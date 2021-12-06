#include "game.h"
#include <string>

Game::Game()
{
	score = 0;
}

void Game::CheckCollision(int screenH, int screenW)
{
	if ((snake.parts[0].getPosition().x == apple.shape.getPosition().x)
		&& snake.parts[0].getPosition().y == apple.shape.getPosition().y)
	{
		snake.Grow();
		//snake.segmentNumber++;
		apple.RandomPosition();
		score++;
	}

	for (int i = (int)snake.parts.size() - 1; i > 1; i--)
	{
		if ((snake.parts[0].getPosition().x == snake.parts[i].getPosition().x) &&
			(snake.parts[0].getPosition().y == snake.parts[i].getPosition().y))
		{
			snake.Reset();
			score = 0;
			return;
		}
	}
	if ((snake.parts[0].getPosition().x < 0) || (snake.parts[0].getPosition().x > screenH)
		|| (snake.parts[0].getPosition().y < 0) || (snake.parts[0].getPosition().y > screenW))
	{
		snake.Reset();
		score = 0;
	}
}

void Game::run()
{
	sf::RenderWindow window(sf::VideoMode(1000, 1000), "Snake");
	window.setFramerateLimit(10);
	while (window.isOpen())
	{
		snake.Input();

		CheckCollision(1000, 1000);
		sf::Event event;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}
		window.clear(sf::Color::Black);
		for (int i = 0; i < snake.segmentNumber; i++)
		{
			window.draw(snake.parts[i]);
		}
		window.draw(apple.shape);

		window.display();
	}
}