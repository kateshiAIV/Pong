#include "Bat.h"


Bat::Bat(float X, float Y) : m_Position(X, Y)
{
	m_Shape.setSize(sf::Vector2<float>(50.0f, 5.0f));
	m_Shape.setPosition(m_Position);
	m_Shape.setFillColor(sf::Color::Red);
}


sf::FloatRect Bat::getPosition()
{
	return m_Shape.getGlobalBounds();
}

sf::RectangleShape Bat::getShape()
{
	return m_Shape;
}

void Bat::moveLeft()
{
	m_bMovingLeft = true;
}

void Bat::moveRight()
{
	m_bMovingRight = true;
}


void Bat::stopLeft()
{
	m_bMovingLeft = false;
}

void Bat::stopRight()
{
	m_bMovingRight = false;
}


void Bat::update(sf::Time dt)
{
	if (m_bMovingRight)
	{
		m_Position.x += m_Speed * dt.asSeconds();
	}
	if (m_bMovingLeft)
	{
		m_Position.x -= m_Speed * dt.asSeconds();
	}
	m_Shape.setPosition(m_Position);
}