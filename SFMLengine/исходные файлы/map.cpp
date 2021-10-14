#include "../файлы заголовков\map.h"


static void help(sf::Vertex*& quad, sf::IntRect int_rect, int i, int j, int max, int a) {

	quad[0].position = sf::Vector2f(i * a + (a - int_rect.width), j * a + (a - int_rect.height) + max);
	quad[1].position = sf::Vector2f((i + 1) * a, j * a + (a - int_rect.height) + max);
	quad[2].position = sf::Vector2f((i + 1) * a, (j + 1) * a + max);
	quad[3].position = sf::Vector2f(i * a + (a - int_rect.width), (j + 1) * a + max);


	quad[0].texCoords = sf::Vector2f(int_rect.left, int_rect.top);
	quad[1].texCoords = sf::Vector2f(int_rect.left + int_rect.width, int_rect.top);
	quad[2].texCoords = sf::Vector2f(int_rect.left + int_rect.width, int_rect.top + int_rect.height);
	quad[3].texCoords = sf::Vector2f(int_rect.left, int_rect.top + int_rect.height);
}

void Map::set(std::string filename,unsigned x,unsigned y) {
	size_x = x;
	size_y = y;

	int a = 60;
	int max = 20;
	std::ifstream fin(filename);
	unsigned s;

	for (unsigned int i = 0; i < x; ++i) {
		for (unsigned int j = 0; j < y; ++j) {
			fin >> s;
			type.push_back((Mtype)(s));
			switch (s)
			{
			case 0:back.push_back(new Wall_types(&m)); break;
			case 1:back.push_back(new Wall_types(&m, sf::IntRect(60, 0, 60, 60))); break;
			case 2:back.push_back(new Wall_types(&m, sf::IntRect(60, 60, 60, 80))); break;
			default:
				break;
			}

			if (type[type.size() - 1] != Mtype::barel) {
				m_vertices.setPrimitiveType(sf::Quads);
				m_vertices.resize(size_x * size_y * 4);
				sf::Vertex* quad = &m_vertices[(i + j * size_x) * 4];

				auto int_rect = back[back.size() - 1]->get_intrect();

				help(quad, int_rect, i, j, max, a);
			}
		}
		fin.close();

	}
}


void Map::random()
{

	int a = 60;
	int max = 20;
	srand(time(0));
	size_x = 8;
	size_y = 8;
	m_vertices.setPrimitiveType(sf::Quads);
	m_vertices.resize(size_x * size_y * 4);

	m_walls.setPrimitiveType(sf::Quads);
	m_walls.resize(size_x * size_y * 4);
	unsigned s;
	for (unsigned int i = 0; i < size_x; ++i) {
		for (unsigned int j = 0; j < size_y; ++j) {
			
			s = rand() % 3;
			type.push_back((Mtype)(s));
			switch (s)
			{
			case 0:back.push_back(new Wall_types(&m)); break;
			case 1:back.push_back(new Wall_types(&m, sf::IntRect(60, 0, 60, 60))); break;
			case 2:back.push_back(new Wall_types(&m,sf::IntRect(60,60,60,80),false)); break;
			default: 
				break;
			}
			if (type[type.size() - 1] == Mtype::barel) {
			
				sf::Vertex* quad = &m_walls [(i + j * size_x) * 4] ;
				auto int_rect = back[back.size() - 1]->get_intrect();

				help(quad, int_rect, i, j, max, a);

			}
			else {
				sf::Vertex* quad = &m_vertices[(i + j * size_x) * 4];
				auto int_rect = back[back.size() - 1]->get_intrect();

				help(quad, int_rect, i, j, max, a);
			}
		}
	}

}

sf::Vector2f Map::collisions(sf::Vector2f pos,sf::Vector2f speed)
{
	
	int size_x =pos.x / 60;
	int size_y = (pos.y - 20) / 60;
	std::cout << size_x << " " << size_y << std::endl;
	(size_x < 0 || size_x > 7) ? size_x < 0 ? speed.x = 0.1 : speed.x = -0.1 : check_tail(speed, pos, size_x -1, size_y) ? speed.x = 0 : NULL;
	(size_x < 0 || size_x > 7) ? size_x < 0 ? speed.x = 0.1 : speed.x = -0.1 : check_tail(speed, pos, size_x + 1, size_y) ? speed.x = 0 : NULL;
	(size_y < 0 || size_y > 7) ? size_y < 0 ? speed.y = 0.1 : speed.y = -0.1 : check_tail(speed, pos, size_x, size_y -1) ? speed.y = 0 : NULL;
	(size_y < 0 || size_y > 7) ? size_y < 0 ? speed.y = 0.1 : speed.y = -0.1 : check_tail(speed, pos, size_x, size_y + 1) ? speed.y = 0 : NULL;
	
		//check_tail(speed, pos, (size_x + speed.x > 0 ? +1 : -1) * 8 + size_y) ? speed.y = 0 : NULL;
	//	check_tail(speed, pos, (size_x) * 8 + size_y + speed.y > 0 ? +1 : -1) ? speed.y = 0 : NULL;

	return speed;
}

bool Map::check_tail(sf::Vector2f speed, sf::Vector2f pos, int x, int y)
{
	int coef = 60;
	int mx = 8;
	int my = 8;


	if (x * my + y >= mx * my || x * my + y < 0)
		return false;
	if(type[x * 8 + y]!=Mtype::barel)
		return false;

	//sf::IntRect rect = back[x * 7 + y]->get_intrect();

	int top = y * coef + 20;
	int left = x * coef;
	
	if (intersect(sf::Vector2f(left, top),// добавить позицию , а то стоит позиция текстуры
		sf::Vector2f(left + coef, top),
		pos, pos + speed))
		return true;

	if (intersect(sf::Vector2f(left, top),
		sf::Vector2f(left, top + coef),
		pos, pos + speed))
		return true;

	if (intersect(sf::Vector2f(left + coef, top + coef),
		sf::Vector2f(left + coef, top),
		pos, pos + speed))
		return true;

	if (intersect(sf::Vector2f(left + coef, top + coef),
		sf::Vector2f(left, top + coef),
		pos, pos + speed))
		return true;

	return false;
	
}
