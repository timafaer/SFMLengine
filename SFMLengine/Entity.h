#pragma once
#include"ComponentStorage.h"
#include"Game.h"
class Entity
{
private:
	ComponentStorage storage;
	sf::Vector2f pos;

public:
	void add_component(Type type) { storage.add_component(type); }

	template<typename T>
	decltype(auto) get() {
		return this->storage.get_component<T>();
	}

	void logic();

	friend class Game;
};

