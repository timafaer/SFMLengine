#pragma once
#include"Component.h"
#include<SFML/Graphics.hpp>

class DrawComponent :public Component, public sf::Drawable
{

private:
	sf::Drawable* obj;
public:
	void draw(sf::RenderTarget& target,sf::RenderStates states) const
	{
		target.draw(*obj, states);
	}
	void set(sf::Drawable* obj) { this->obj = obj; }
	Type type() { return Type::drawComponent; }


};
