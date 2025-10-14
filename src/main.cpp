#include "Bat.h"
#include "Ball.h"
#include "Block.h"
#include <sstream>
#include <cstdlib>
#include <SFML/Graphics.hpp>

int main()
{

	// Create a video mode object
	//sf::VideoMode vm({ 1920, 1080 });
	sf::VideoMode vm({ 1920, 1080 });
	// Create and open a window for the game
	sf::RenderWindow window(vm, "Pong", sf::State::Fullscreen);
	// Game variables
	int score = 0;
	int lives = 3;

	// Create a bat at the bottom center of the screen
	Bat bat(1920 / 2, 1080 - 60);
	Ball ball(1920 / 2, 1080 / 2);
	Block BlockArray[48][3];
	
	for (int i = 0; i < 48; i++) 
	{
		for (int j = 0; j < 3; j++)
		{
			BlockArray[i][j].setPosition(sf::Vector2<float>(i * 40.0f, (j * 40.0f)+150.0f));
		}
	}

	// Retro-style font
	sf::Font font;
	font.openFromFile("fonts/ds-digital.ttf");

	// Text object called HUD
	sf::Text hud(font, "", 30);

	// Set the font
	hud.setFont(font);
	hud.setCharacterSize(75);

	// Choose a color
	hud.setFillColor(sf::Color::Red);
	hud.setPosition(sf::Vector2<float>(20, 20));


	// Clock for timing everything
	sf::Clock clock;

	while (window.isOpen())
	{

		// Process events
		while (const auto event = window.pollEvent())
		{
			// Close window: exit
			if (event->is<sf::Event::Closed>())
			{
				window.close();
			}

			// Escape pressed: exit
			if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>();
				keyPressed && keyPressed->code == sf::Keyboard::Key::Escape)
			{
				window.close();
			}
		}

		// Handle the bat moving LEFT and RIGHT
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) 
		{
			bat.moveLeft();
		}
		else
		{
			bat.stopLeft();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
		{
			bat.moveRight();
		}
		else
		{
			bat.stopRight();
		}


		// Update the bat
		sf::Time dt = clock.restart();
		bat.update(dt);
		ball.update(dt);


		// Update the HUD text
		std::stringstream ss;
		ss << "Score:" << score << " Lives:" << lives;
		hud.setString(ss.str());

		if (ball.getPosition().getCenter().y > window.getSize().y)
		{
			// reverse the ball direction
			ball.reboundBottom();
			// Remove a life
			lives--;
			// Check for zero lives
			if (lives < 1) {
				// reset the score
				score = 0;
				// reset the lives
				lives = 3;

				for (int i = 0; i < 48; i++)
				{
					for (int j = 0; j < 3; j++)
					{
						BlockArray[i][j].setPosition(sf::Vector2<float>(i * 40.0f, j * 40.0f));
					}
				}
			}
		}
		if (ball.getPosition().getCenter().y < 150.0f)
		{
			// reverse the ball direction
			score++;
			ball.reboundTopOrBat();
		}
		if (ball.getPosition().getCenter().x < 0.0f)
		{
			// reverse the ball direction
			ball.reboundSides();
		}
		if (ball.getPosition().getCenter().x > window.getSize().x)
		{
			// reverse the ball direction
			ball.reboundSides();
		}
		if (ball.getPosition().findIntersection(bat.getPosition())) 
		{
			ball.reboundTopOrBat();
		}

		for (int i = 0; i < 48; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (ball.getPosition().findIntersection(BlockArray[i][j].getPosition())
					&& (ball.getPosition().getCenter().y) >= (BlockArray[i][j].getPosition().getCenter().y+20.0f)
					)
				{
					ball.reboundTopOrBat();
					BlockArray[i][j].setPosition(sf::Vector2<float>(-100.0f, 100.0f));
					score++;
				}
				else if (ball.getPosition().findIntersection(BlockArray[i][j].getPosition())
					&& (ball.getPosition().getCenter().y) < (BlockArray[i][j].getPosition().getCenter().y + 20.0f)
					)
				{
					ball.reboundSides();
					BlockArray[i][j].setPosition(sf::Vector2<float>(-100.0f, 100.0f));
					score++;
				}
			}
		}



		//TODO: check collsion with a bat.
		//if (ball.getPosition().x > window.getSize().x)
		//{
		//	// reverse the ball direction
		//	ball.reboundSides();
		//}

		//draw
		window.clear();

		for (int i = 0; i < 48; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				window.draw(BlockArray[i][j].getShape());
			}
		}
		window.draw(hud);
		window.draw(bat.getShape());
		window.draw(ball.getShape());
		window.display();


	}
	return 0;
}
