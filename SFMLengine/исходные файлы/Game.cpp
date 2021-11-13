#pragma once
#include "../файлы заголовков\Game.h"

Game::Game()
{
	//texture.loadFromFile("texture.jpg");
	ent.add_component<DrawComponent>();
	ent.add_component<ShapeComponent>();
	ent.get<ShapeComponent>().set();
	ent.get<DrawComponent>().set(&ent.get<ShapeComponent>().shape);
	window.create(sf::VideoMode(700, 700), "SFML works!");
	window.setFramerateLimit(60);
}

void Game::add_entity()
{
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
	window.draw(ent.get<DrawComponent>());
	window.display();

}

void Game::even()
{
	while (window.pollEvent(this->event)) {
		if (event.type == sf::Event::Closed)
			window.close();
		//else if(event.type == sf::Event::MouseMoved)

			//scence.get_comp<BPhysComponent*>(0)->set_center(sf::Mouse::getPosition(window));
	}
}

void Game::logic()
{
	/*
	sf::Vector2f a = sf::Vector2f(0, 0);
	scence.get_obj(0).logic();

	scence.get_comp<BPhysComponent*>(0)->speed = map.collisions(entities[0].pos, entities[0].get<BPhysComponent*>()->speed);

	entities[0].get<BPhysComponent*>()->move(entities[0].pos);*/
}
	