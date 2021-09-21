#pragma once
#include"Component.h"
#include<SFML/Graphics.hpp>
#include<vector>
#include<cmath>
class ColissionsComponent :public Component
{


public:
	bool check(sf::Vector2f mypos, sf::Vector2f alien_pos,float rad = 30,float alien_rad=30) {
		

		if (sqrt(pow(mypos.x - alien_pos.x, 2) + pow(mypos.y - alien_pos.y, 2)) < rad + alien_rad) {
			return true;
		}
		else {
			return false;
		}

	}

	Type type() { return Type::colissionComponent; }

	void set(){}
};
