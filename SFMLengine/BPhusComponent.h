#pragma once
#include"Component.h"
#include<cmath>
class BPhysComponent :public Component
{
	sf::Vector2f speed = sf::Vector2f(0, 0);
	float g = 0.1;
	sf::Vector2i center;
public:

	 virtual void set_center(sf::Vector2i center) { this->center = center; }

	 virtual void gravity(sf::Vector2f& pos) {
		
		float c = sqrt(pow(center.x - pos.x, 2) + pow(center.y - pos.y, 2));
		if (pow(center.x - pos.x, 2) + pow(center.y - pos.y, 2) < 0) 		
			c = -c;
		float sin = (center.y - pos.y) / c;
		float cos = (center.x - pos.x) / c;
		speed.x += g * cos;
		speed.y += g * sin;
		pos += speed;
	}

	void set(){}
	Type type() { return Type::bphysComponent; }


};