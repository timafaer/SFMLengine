#pragma once
#include"Entity.h"
class Game
{
private:
	std::vector<Entity> entities;
	sf::RenderWindow window;
	sf::Texture texture;
	sf::Event event;

public:

	Game();

	void add_entity();

	void main_loop();

	void draw();

	void even();

	void logic();
};

