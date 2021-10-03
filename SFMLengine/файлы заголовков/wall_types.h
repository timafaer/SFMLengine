#pragma once
#include "Component.h"
#include "SFML/Graphics.hpp"
class Wall_types
{
protected:
	bool dest = false;
	sf::Texture* textur;
	sf::IntRect rect;
	bool back = true;
public:
	Wall_types(sf::Texture* texture, sf::IntRect rect = sf::IntRect(0, 0, 60, 60),bool b = true) {
		this->textur = texture;
		this->rect = rect;
		back = b;
	}
	void destruct() { dest = !dest; }
	void set_rect(sf::IntRect rect) { this->rect = rect; }
	bool get_dest() { return dest; }
	sf::Texture* get_texture() { return textur; }
	sf::IntRect get_intrect() { return rect; }
};