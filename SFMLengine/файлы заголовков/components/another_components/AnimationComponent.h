#pragma once
#include"../../Component.h"
#include"../draw_components\TextureComponent.h"

class AnimationComonent :public TextureComponent
{
	sf::Time time;
	sf::Clock clock;
	std::vector<sf::IntRect> etaps;
	unsigned i=1;
	unsigned size;
	unsigned timeswap;
public:
	void set(sf::IntRect etaps[],unsigned size,sf::Texture* text,unsigned timeswap) {
		texture = text;
		this->size = size;
		this->timeswap = timeswap;
		for (int i = 0; i <size; i++) {
			this->etaps.push_back(etaps[i]);
		}
		sprite.setTexture(*texture);
		sprite.setTextureRect(etaps[0]);
		sprite.setOrigin(sprite.getOrigin().x / 2, sprite.getOrigin().y / 2);
	}
	void shange() {
		if (clock.getElapsedTime().asMilliseconds() >=timeswap) {
			clock.restart();
			if (i == size)
				i = 0;
			sprite.setTextureRect(etaps[i]);
			i++;
		}
	}
	Type type() { return Type::animationComponent; }

};
