#pragma once
#include"Component.h"
#include<cmath>
class BPhysComponent :public Component
{
	
	float g = 0.1;
	sf::Vector2i center;
public:
	 sf::Vector2f speed = sf::Vector2f(0, 0);//временно
	 virtual void set_center(sf::Vector2i center) { this->center = center; }

	 virtual void gravity(sf::Vector2f& pos,sf::Time elapsed) {
		
		float c = sqrt(pow(center.x - pos.x, 2) + pow(center.y - pos.y, 2));
		if (pow(center.x - pos.x, 2) + pow(center.y - pos.y, 2) < 0) 		
			c = -c;
		float sin = (center.y - pos.y) / c;
		float cos = (center.x - pos.x) / c;
		speed.x += g * cos;
		speed.y += g * sin;
		pos += speed;//sf::Vector2f(speed.x * elapsed.asSeconds(), speed.y * elapsed.asSeconds());
	}

	 virtual void collis(sf::Vector2f& pos,sf::Vector2f al_speed,sf::Time elapsed,float mas=1) {
		 speed -= al_speed * mas;
	 }

	void set(){}
	Type type() { return Type::bphysComponent; }


};