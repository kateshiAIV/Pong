#include "Ball.h"


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
	m_Shape.getGlobalBounds();
}


float Ball::getXVelocity() 
{
	return m_DirectionX;
}