#pragma once
#include"MoveComponent.h"

class TextureComponent :public Component
{
protected:
	sf::Texture* texture;
public:
	sf::Sprite sprite;	
	//TextureComponent(){}	
	virtual Type type() { return Type::textureComponent; }
	virtual void set(sf::Texture* texture) { this->texture = texture; sprite.setTexture(*this->texture);  }

	//void move(sf::Vector2f move) { pos += move; sprite.move(move); }
	//void set_pos(sf::Vector2f pos) { this->pos = pos; sprite.setPosition(pos); }
	

};