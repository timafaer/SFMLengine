#pragma once
#include<SFML/Graphics.hpp>
#include"Component.h"

class TextureComponent :public Component
{
protected:
	sf::Texture* texture;
public:
	sf::Sprite sprite;	

	Type type() { return Type::textureComponent; }
	void set(sf::Texture* texture) { this->texture = texture; sprite.setTexture(*this->texture); }

};