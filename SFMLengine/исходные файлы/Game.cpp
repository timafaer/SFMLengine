#pragma once
#include "../файлы заголовков\Game.h"

Game::Game()
{
	
	//texture.loadFromFile("texture.jpg");
	add_entity();
	entities[0].add_component<ShapeComponent>();
	entities[0].add_component<BPhysComponent>();
	entities[0].add_component<DrawComponent>();
	entities[0].get<DrawComponent*>()->set(&entities[0].get<ShapeComponent*>()->shape);
	window.create(sf::VideoMode(700, 700), "SFML works!");
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
		//std::cout << clock.getElapsedTime().asMicroseconds() << std::endl;
		draw();
	}
}

void Game::draw()
{
	window.clear();

	window.draw(map);
	map.shange();
	window.draw(map);
	map.shange();

	for (auto& i : entities)
		window.draw(*i.get<DrawComponent*>());
	window.display();

}

void Game::even()
{
	while (window.pollEvent(this->event)) {
		if (event.type == sf::Event::Closed)
			window.close();
		else if(event.type == sf::Event::MouseMoved)
			entities[0].get<BPhysComponent*>()->set_center(sf::Mouse::getPosition(window));
	}
}

void Game::logic()
{
	sf::Vector2f a = sf::Vector2f(0, 0);
	entities[0].logic();

	entities[0].get<BPhysComponent*>()->speed = map.collisions(entities[0].pos, entities[0].get<BPhysComponent*>()->speed);

	entities[0].get<BPhysComponent*>()->move(entities[0].pos);
}
	