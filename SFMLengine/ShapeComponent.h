#pragma once
#include"Component.h"

class ShapeComponent :public Component
{
public:
	sf::CircleShape shape;
	ShapeComponent() {
		shape.setRadius(30);
		shape.setFillColor(sf::Color::Green);
		shape.setOrigin(sf::Vector2f(30, 30));
	}
	void set(sf::Vector2f pos=sf::Vector2f(0,0)) {
		shape.setPosition(pos);
		
	}

	Type type() { return Type::shapeComponent; }

};