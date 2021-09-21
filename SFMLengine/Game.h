#pragma once
#include"Entity.h"
#include<vector>
#include<iostream>
class Game
{
private:
	std::vector<Entity> entities;
	sf::RenderWindow window;
	sf::Texture texture;
	sf::Event event;

	sf::Time elapsed;
	sf::Clock clock;

public:

	Game();

	void add_entity();

	void main_loop();

	void draw();

	void even();

	void logic();
};

