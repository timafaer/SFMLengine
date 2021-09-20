#include "Game.h"

Game::Game()
{
	texture.loadFromFile("texture.jpg");
	add_entity();
	
	entities[0].add_component(Type::shapeComponent);
	entities[0].add_component(Type::drawComponent);
	entities[0].add_component(Type::bphysComponent);

	entities[0].get<ShapeComponent*>()->set();
	entities[0].get<DrawComponent*>()->set(&entities[0].get<ShapeComponent*>()->shape);
	entities[0].get<BPhysComponent*>()->set_center(sf::Vector2i(100, 100));
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
		logic();
		draw();

	}
}

void Game::draw()
{
	window.clear();
	for (auto& i : entities)
		window.draw(*i.get<DrawComponent*>());
	window.display();
}

void Game::even(){
	while (window.pollEvent(this->event)) {
		if (event.type == sf::Event::Closed)
			window.close();
		if (event.type == sf::Event::MouseMoved)
			entities[0].get<BPhysComponent*>()->set_center(sf::Mouse::getPosition(window));
		//std::cout << sf::Mouse::getPosition(window).x << " " << sf::Mouse::getPosition(window).y << std::endl;
	}
}

void Game::logic()
{
	for (auto& entity : entities) {
		entity.logic();
	}
}
	