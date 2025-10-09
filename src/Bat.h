#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <sstream>

class Bat 
{
private:
	sf::Vector2<float> m_Position;
	sf::RectangleShape m_Shape;
	float m_Speed = 1000.0f;
	bool m_bMovingRight = false;
	bool m_bMovingLeft = false;
public:
	Bat(float X, float Y);
	sf::FloatRect getPosition();
	sf::RectangleShape getShape();
	void moveLeft();
	void moveRight();
	void stopLeft();
	void stopRight();
	void update(sf::Time dt);
};