#include "Bat.h"
#include <sstream>
#include <cstdlib>
#include <SFML/Graphics.hpp>

int main()
{

	// Create a video mode object
	sf::VideoMode vm({ 1920, 1080 });
	// Create and open a window for the game
	sf::RenderWindow window(vm, "Pong");
	int score = 0;
	int lives = 3;

	// Create a bat at the bottom center of the screen
	Bat bat(1920 / 2, 1080 - 20);
	// We will add a ball in the next chapter

	// A cool retro-style font
	sf::Font font;
	font.openFromFile("fonts/ds-digital.ttf");
	//font.loadFromFile("fonts/DS-.ttf");
	// Create a Text object called HUD
	sf::Text hud(font, "", 30);
	// Set the font to our retro-style
	hud.setFont(font);
	// Make it nice and big
	hud.setCharacterSize(75);
	// Choose a color
	hud.setFillColor(sf::Color::White);
	hud.setPosition(sf::Vector2<float>(20, 20));
	// Here is our clock for timing everything
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

		sf::Time dt = clock.restart();
		bat.update(dt);

		std::stringstream ss;
		ss << "Score:" << score << " Lives:" << lives;
		hud.setString(ss.str());

		window.clear();
		window.draw(hud);
		window.draw(bat.getShape());
		window.display();

		/*
		Handle the player input
		****************************
		****************************
		****************************
		*/
		/*
		Update the bat, the ball and the HUD
		*****************************
		*****************************
		*****************************
		*/


		/*
		Draw the bat, the ball and the HUD
		*****************************
		*****************************
		*****************************
		*/

	}
	return 0;
}
