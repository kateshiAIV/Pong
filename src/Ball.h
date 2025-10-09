#pragma once
#include <SFML/Graphics.hpp>


class Ball
{
private:
	sf::Vector2<float> m_Position;
	sf::RectangleShape m_Shape;
	float m_DirectionX = .2f;
	float m_DirectionY = .2f;
public:
	Ball(float startX, float startY);
	sf::Vector2<float> getPosition();
	sf::RectangleShape getShape();
	float getXVelocity();
	void reboundSides();
	void reboundTopOrBat();
	void reboundBottom();
	void update(sf::Time dt);


};