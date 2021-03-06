#pragma once
#include"ComponentStorage.h"
class Entity
{
private:
	ComponentStorage storage;
	

public:
	sf::Vector2f pos = sf::Vector2f(100, 100);//временно
	void add_component(Type type) { storage.add_component(type); }

	template<typename T>
	decltype(auto) get() {
		return this->storage.get_component<T>();
	}

	void logic() {

		get<BPhysComponent*>()->gravity(pos);
		get<ShapeComponent*>()->set(pos);
		//if (get<AnimationComonent*>() != NULL) {
		//	get<AnimationComonent*>()->shange();
		//}
	}

};

