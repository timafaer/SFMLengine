#pragma once
#include"Component.h"
#include<SFML/Graphics.hpp>

class MoveComponent :public Component
{
protected:
	sf::Vector2f pos;
public:
	MoveComponent() { pos = sf::Vector2f(100, 100); }
	Type type() { return Type::moveComponent; }
	void set(sf::Vector2f pos = sf::Vector2f(0, 0)) { this->pos = pos; }
	virtual void move(sf::Vector2f move) { pos += move; }
	virtual void set_pos(sf::Vector2f pos) { this->pos = pos; }



};