#include "Block.h"
#include <SFML/Graphics.hpp>

//1920x1080
//48x3


Block::Block()
	: m_Position()
{
	m_Shape.setSize(sf::Vector2<float>(40.0f, 40.0f));
	m_Shape.setPosition(sf::Vector2<float> (0.0f,0.0f));
}


sf::RectangleShape Block::getShape()
{
	return m_Shape;
}

sf::FloatRect Block::getPosition()
{
	return m_Shape.getGlobalBounds();
}


void Block::setPosition(sf::Vector2<float> val) 
{
	m_Shape.setPosition(val);
}