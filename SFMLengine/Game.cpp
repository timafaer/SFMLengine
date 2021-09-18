#include "Game.h"

Game::Game()
{
	texture.loadFromFile("texture.jpg");
	add_entity();
	add_entity();
	entities[0].add_component(Type::vertexComponent);
	entities[0].add_component(Type::drawComponent);

	entities[1].add_component(Type::vertexComponent);
	entities[1].add_component(Type::drawComponent);

	sf::Vector2f pos[2] = { sf::Vector2f(100, 100), sf::Vector2f(150, 110) };

	entities[0].get<VertexComponent*>()->set(sf::Lines,pos);
	entities[0].get<DrawComponent*>()->set(&entities[0].get<VertexComponent*>()->vertex);

	pos[1] = sf::Vector2f(90, 150);


	entities[1].get<VertexComponent*>()->set(sf::Lines, pos);
	entities[1].get<DrawComponent*>()->set(&entities[1].get<VertexComponent*>()->vertex);
	window.create(sf::VideoMode(500, 500), "SFML works!");
	window.setFramerateLimit(60);
}

void Game::add_entity()
{
	entities.push_back(Entity());
}

void Game::main_loop()
{
	while (window.isOpen()) {
		even();
		draw();

	}
}

void Game::draw()
{
	window.clear();
	for (auto i : entities)
		window.draw(*i.get<DrawComponent*>());
	window.display();
}

void Game::even(){
	while (window.pollEvent(this->event))
		if (event.type == sf::Event::Closed)
			window.close();
}
