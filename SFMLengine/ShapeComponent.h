#pragma once
#include"Component.h"

class ShapeComponent :public Component
{
public:
	sf::CircleShape shape;

	void set(sf::Vector2f pos) {
		shape.setPosition(pos);
		shape.setRadius(30);
		shape.setFillColor(sf::Color::Green);
	}

	Type type() { return Type::shapeComponent; }

};