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

	int a = 60;
	int max = 0;
	srand(time(0));
	size_x = 8;
	size_y = 8;
	unsigned s;
	for (unsigned int i = 0; i < size_x; ++i) {
		for (unsigned int j = 0; j < size_y; ++j) {
			
			s = rand() % 3;
			type.push_back((Mtype)(s));
			switch (s)
			{
			case 0:walls.push_back(new Wall_types(&m)); break;
			case 1:walls.push_back(new Wall_types(&m, sf::IntRect(60, 0, 60, 60))); break;
			case 2:walls.push_back(new Wall_types(&m,sf::IntRect(60,60,60,80))); break;
			default: 
				break;
			}
			m_vertices.setPrimitiveType(sf::Quads);
			m_vertices.resize(size_x * size_y * 4);
			sf::Vertex* quad = &m_vertices[(i + j * size_x) * 4];

			auto int_rect = walls[walls.size() - 1]->get_intrect();

			quad[0].position = sf::Vector2f(i * a + (a - int_rect.width), j * a + (a - int_rect.height) + max);
			quad[1].position = sf::Vector2f((i + 1) * a, j * a + (a - int_rect.height) + max);
			quad[2].position = sf::Vector2f((i + 1) * a, (j + 1) * a + max);
			quad[3].position = sf::Vector2f(i * a + (a - int_rect.width), (j + 1) * a + max);
			
			
			quad[0].texCoords = sf::Vector2f(int_rect.left, int_rect.top);
			quad[1].texCoords = sf::Vector2f(int_rect.left + int_rect.width, int_rect.top);
			quad[2].texCoords = sf::Vector2f(int_rect.left + int_rect.width, int_rect.top + int_rect.height);
			quad[3].texCoords = sf::Vector2f(int_rect.left, int_rect.top + int_rect.height);


		}
	}

}