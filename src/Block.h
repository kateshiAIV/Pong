#pragma once
#include <SFML/Graphics.hpp>


class Block
{
private:
	sf::Vector2<float> m_Position;
	sf::RectangleShape m_Shape;
public:
	Block();
	sf::FloatRect getPosition();
	void setPosition(sf::Vector2<float> val);
	sf::RectangleShape getShape();
}; 
