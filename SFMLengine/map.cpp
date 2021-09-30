#include"map.h"
void Map::set(std::string filename,unsigned x,unsigned y) {
	size_x = x;
	size_y = y;
	std::ifstream fin(filename);
	unsigned s;
	m_vertices.setPrimitiveType(sf::Quads);
	m_vertices.resize(x * y * 4);


	for (unsigned int i = 0; i < x; ++i) {
		for (unsigned int j = 0; j < y; ++j) {
			fin >> s;
			type.push_back((Mtype)s);
			switch (s)
			{
			case 0:walls.push_back(new Wall_types(&m)); break;
			case 1:walls.push_back(new Wall_types(&m, sf::IntRect(60, 0, 60, 60))); break;
			default:
				break;
			}
			sf::Vertex* quad = &m_vertices[(i + j * x) * 4];
			
		}
	}
	fin.close();


}

void Map::random()
{
	size_x = rand() % 10 + 10;
	size_y = rand() % 10 + 10;
	unsigned s;
	for (unsigned int i = 0; i < size_x; ++i) {
		for (unsigned int j = 0; j < size_y; ++j) {
			s = rand() % 2;
			type.push_back((Mtype)(s));
			switch (s)
			{
			case 0:walls.push_back(new Wall_types(&m)); break;
			case 1:walls.push_back(new Wall_types(&m, sf::IntRect(60, 0, 60, 60))); break;
			default:
				break;
			}
			m_vertices.setPrimitiveType(sf::Quads);
			m_vertices.resize(size_x * size_y * 4);
			sf::Vertex* quad = &m_vertices[(i + j * size_x) * 4];

			quad[0].position = sf::Vector2f(i * walls[walls.size() - 1]->get_intrect().width, j * walls[walls.size() - 1]->get_intrect().height);
			quad[1].position = sf::Vector2f((i + 1) * walls[walls.size() - 1]->get_intrect().width, j * walls[walls.size() - 1]->get_intrect().height);
			quad[2].position = sf::Vector2f((i + 1) * walls[walls.size() - 1]->get_intrect().width, (j + 1) * walls[walls.size() - 1]->get_intrect().height);
			quad[3].position = sf::Vector2f(i * walls[walls.size() - 1]->get_intrect().width, (j + 1) * walls[walls.size() - 1]->get_intrect().height);

			
			quad[0].texCoords = sf::Vector2f(walls[walls.size() - 1]->get_intrect().left, walls[walls.size() - 1]->get_intrect().top);
			quad[1].texCoords = sf::Vector2f(walls[walls.size() - 1]->get_intrect().left, walls[walls.size() - 1]->get_intrect().top + walls[walls.size() - 1]->get_intrect().width);
			quad[2].texCoords = sf::Vector2f(walls[walls.size() - 1]->get_intrect().left + walls[walls.size() - 1]->get_intrect().height, walls[walls.size() - 1]->get_intrect().width);
			quad[3].texCoords = sf::Vector2f(walls[walls.size() - 1]->get_intrect().left + walls[walls.size() - 1]->get_intrect().height, walls[walls.size() - 1]->get_intrect().top);


		}
	}

}