#pragma once
#include"../����� ����������\Component.h"
#include<cmath>
class BPhysComponent :public Component
{
	
	float g = 0.1;
	sf::Vector2i center;
public:
	 sf::Vector2f speed = sf::Vector2f(0, 0);//��������
	 virtual void set_center(sf::Vector2i center) { this->center = center; }

	 virtual void gravity(sf::Vector2f& pos) {
		
		float c = sqrt(pow(center.x - pos.x, 2) + pow(center.y - pos.y, 2));
		if (pow(center.x - pos.x, 2) + pow(center.y - pos.y, 2) < 0) 		
			c = -c;
		float sin = (center.y - pos.y) / c;
		float cos = (center.x - pos.x) / c;
		speed.x += g * cos;// pow(c, 2);
		speed.y += g * sin;// pow(c, 2);
		//sf::Vector2f(speed.x * elapsed.asSeconds(), speed.y * elapsed.asSeconds());
	}

	 virtual void collis(sf::Vector2f& pos,sf::IntRect crash,float mas=1) {
		 if (crash == sf::IntRect(0,0,0,0))
			 return;
		 int rect = 4;
		
		 

	 }

	 void move(sf::Vector2f& pos) {
		 pos += speed;
	 }
	void set(){}
	Type type() { return Type::bphysComponent; }


};