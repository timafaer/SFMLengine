#include "Game.h"

Game::Game()
{
	texture.loadFromFile("texture.jpg");
	add_entity();
	entities[0].add_component(Type::textureComponent);
	entities[0].add_component(Type::drawComponent);
	entities[0].get<TextureComponent*>()->set(&texture);
	entities[0].get<DrawComponent*>()->set(&entities[0].get<TextureComponent*>()->sprite);
	window.create(sf::VideoMode(200, 200), "SFML works!");
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
	window.draw(*entities[0].get<DrawComponent*>());
	window.display();
}

void Game::even(){
	while (window.pollEvent(this->event))
		if (event.type == sf::Event::Closed)
			window.close();
}
