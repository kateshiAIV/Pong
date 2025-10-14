#include "Ball.h"
#include <SFML/Graphics.hpp>

Ball::Ball(float startX, float startY) 
	: m_Position(startX, startY)
{
	m_Shape.setSize(sf::Vector2<float>(10.0f, 10.0f));
	m_Shape.setPosition(m_Position);
}


sf::RectangleShape Ball::getShape()
{
	return m_Shape;
}

sf::Vector2<float> Ball::getPosition()
{
	return m_Shape.getPosition();
}


float Ball::getXVelocity() 
{
	return m_DirectionX;
}


void Ball::reboundSides()
{
	m_DirectionX = -m_DirectionX;
}

void Ball::reboundTopOrBat()
{
	m_DirectionY = -m_DirectionY;
}

void Ball::reboundBottom()
{
	m_Position.y = 1080 / 2;
	m_Position.x = 1920 / 2;
	m_DirectionY = -m_DirectionY;
}


void Ball::update(sf::Time dt)
{
	m_Position.x += m_DirectionX * m_Speed * dt.asSeconds();
	m_Position.y += m_DirectionY * m_Speed * dt.asSeconds();
	m_Shape.setPosition(m_Position);
}

