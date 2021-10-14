#pragma once
#include<iostream>
#include<SFML/Graphics.hpp>
#include"Entity.h"
#include"wall_types.h"
#include<fstream>
#include<random>
#include<ctime>
#include<algorithm>
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


	sf::Vector2f collisions(sf::Vector2f pos,sf::Vector2f speed);

	inline int area(sf::Vector2f a, sf::Vector2f b, sf::Vector2f c) {
		return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
	}
	inline bool intersect_1(int a, int b, int c, int d) {
		if (a > b)  std::swap(a, b);
		if (c > d)  std::swap(c, d);
		return std::max(a, c) <= std::min(b, d);
	}
	bool intersect(sf::Vector2f a, sf::Vector2f b, sf::Vector2f c, sf::Vector2f d) {
		return intersect_1(a.x, b.x, c.x, d.x)
			&& intersect_1(a.y, b.y, c.y, d.y)
			&& area(a, b, c) * area(a, b, d) <= 0
			&& area(c, d, a) * area(c, d, b) <= 0;
	}

	bool check_tail(sf::Vector2f speed, sf::Vector2f pos, int x, int y);


private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const {

		states.transform *= getTransform();

	// apply the tileset texture
		states.texture = &m;

	// draw the vertex array
		target.draw(*drow, states);
		
	}

	


};