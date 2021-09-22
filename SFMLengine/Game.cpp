#include "Game.h"

Game::Game()
{
	texture.loadFromFile("texture.jpg");
	add_entity();
	add_entity();
	for (auto& i : entities) {
		i.add_component(Type::shapeComponent);
		i.add_component(Type::drawComponent);
		i.add_component(Type::bphysComponent);
		i.add_component(Type::colissionComponent);

		i.get<ShapeComponent*>()->set();
		i.get<DrawComponent*>()->set(&i.get<ShapeComponent*>()->shape);
		i.get<BPhysComponent*>()->set_center(sf::Vector2i(100, 100));

	}
	entities[1].get<ShapeComponent*>()->set(sf::Vector2f(100, 100));
	entities[1].pos = sf::Vector2f(100, 100);
	
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
		std::cout << clock.getElapsedTime().asMicroseconds() << std::endl;
		draw();
		clock.restart();
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
			for(auto& ents:entities)
				ents.get<BPhysComponent*>()->set_center(sf::Mouse::getPosition(window));
		//std::cout << sf::Mouse::getPosition(window).x << " " << sf::Mouse::getPosition(window).y << std::endl;
	}
}

void Game::logic()
{
	if (entities[0].get<ColissionsComponent*>()->check(entities[0].pos, entities[1].pos,entities[0].get<BPhysComponent*>()->speed,entities[1].get<BPhysComponent*>()->speed))
		entities[0].get<BPhysComponent*>()->collis(entities[0].pos, entities[1].get<BPhysComponent*>()->speed, entities[1].pos,clock.getElapsedTime());

	///if (entities[1].get<ColissionsComponent*>()->check(entities[1].pos, entities[0].pos))
		//entities[1].get<BPhysComponent*>()->collis(entities[1].pos, entities[0].get<BPhysComponent*>()->speed,clock.getElapsedTime());

		entities[0].logic(clock.getElapsedTime());
		entities[1].logic(clock.getElapsedTime());
}
	