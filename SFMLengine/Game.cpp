#include "Game.h"

Game::Game()
{
	/*
	texture.loadFromFile("texture.jpg");
	add_entity();
	entities[0].add_component(Type::animationComponent);
	entities[0].add_component(Type::drawComponent);
	entities[0].get<DrawComponent*>()->set(&entities[0].get<AnimationComonent*>()->sprite);
	sf::IntRect tex[2] = { {0,0,60,60},{60,60,60,60} };
	entities[0].get<AnimationComonent*>()->set(tex,2, &texture,400);
	*/
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
		//logic();
		std::cout << clock.getElapsedTime().asMicroseconds() << std::endl;
		draw();
	}
}

void Game::draw()
{
	window.clear();
	//for (auto& i : entities)
		//window.draw(*i.get<DrawComponent*>());
	window.draw(map);
	window.display();

}

void Game::even()
{
	while (window.pollEvent(this->event)) {
		if (event.type == sf::Event::Closed)
			window.close();
	}
}

void Game::logic()
{
	entities[0].logic();
}
	