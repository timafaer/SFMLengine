#pragma once
#include"../../Component.h"
#include<SFML/Graphics.hpp>

class VertexComponent :public Component
{
public:
	sf::VertexArray vertex;

	sf::Color color = sf::Color::Green;

	void set(sf::PrimitiveType type, sf::Vector2f pos[]) {

		vertex.setPrimitiveType(type);
		vertex.resize(sizeof(pos));

		for (int i = 0; i < sizeof(pos); i++) {
			vertex[i].position = pos[i];
			vertex[i].color = color;
		}
	}
	Type type() { return Type::vertexComponent; }

};