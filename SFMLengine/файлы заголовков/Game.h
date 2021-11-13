#pragma once
#include"Entity.h"
#include<vector>
#include<iostream>
//#include"scence/scence.h"
#include"map.h"
class Game
{
private:
	sf::RenderWindow window;
	sf::Texture texture;
	sf::Event event;

	Entity ent;
	//Scence scence;

public:

	Game();

	void add_entity();

	void main_loop();

	void draw();

	void even();

	void logic();
};

