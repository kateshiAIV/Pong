#include "Bat.h"
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


	// Retro-style font
	sf::Font font;
	font.openFromFile("fonts/ds-digital.ttf");

	// Text object called HUD
	sf::Text hud(font, "", 30);

	// Set the font
	hud.setFont(font);
	hud.setCharacterSize(75);

	// Choose a color
	hud.setFillColor(sf::Color::White);
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


		// Update the HUD text
		std::stringstream ss;
		ss << "Score:" << score << " Lives:" << lives;
		hud.setString(ss.str());


		//draw
		window.clear();
		window.draw(hud);
		window.draw(bat.getShape());
		window.display();


	}
	return 0;
}
