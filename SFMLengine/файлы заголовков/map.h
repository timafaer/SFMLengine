#pragma once
#include<iostream>
#include<SFML/Graphics.hpp>
#include"Entity.h"
#include"wall_types.h"
#include<fstream>
#include<random>
#include<ctime>
enum  Mtype {
	background = 0,
	wall_type1 = 1,
	barel = 2
};

class Map : public sf::Drawable,public sf::Transformable
{
	std::vector<bool> map;
	std::vector<Wall_types*> back;
	
	std::vector<Mtype> type;
	sf::VertexArray m_vertices,m_walls;
	unsigned size_x, size_y;
	sf::Texture m;
	sf::Drawable* drow = &m_vertices;
public:

	Map() {
		m.loadFromFile(R"(./textures\texture.jpg)");
		random();
	}

	void set(std::string filename,unsigned x,unsigned y);
	
	void shange(){
		if (drow == &m_vertices)
			drow = &m_walls;
		else
			drow = &m_vertices;
	}

	void random();
	bool collisions(sf::Vector2f pos);
private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const {

		states.transform *= getTransform();

	// apply the tileset texture
		states.texture = &m;

	// draw the vertex array
		target.draw(*drow, states);
		
	}

	


};