#pragma once
#include"Component.h"
#include<SFML/Graphics.hpp>
#include<vector>
#include<cmath>
class ColissionsComponent :public Component
{


public:
	bool check(sf::Vector2f mypos, sf::Vector2f alien_pos, sf::Vector2f speed, sf::Vector2f ali_speed, float rad = 30, float alien_rad = 30) {
		if (sqrt(pow(mypos.x - alien_pos.x, 2) + pow(mypos.y - alien_pos.y, 2)) < rad + alien_rad) {
			return true;
		//}
		//else if (sqrt(pow(mypos.x + speed.x - alien_pos.x - ali_speed.x, 2) + pow(mypos.y + speed.y - alien_pos.y - ali_speed.y, 2)) < rad + alien_rad){
			//return true;
		}else {
			return false;
		}
	}

	Type type() { return Type::colissionComponent; }

	void set(){}
};
