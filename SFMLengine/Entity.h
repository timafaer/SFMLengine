#pragma once
#include"ComponentStorage.h"
class Entity
{
private:
	ComponentStorage storage;

public:
	void add_component(Type type) { storage.add_component(type); }

	template<typename T>
	decltype(auto) get() {
		return this->storage.get_component<T>();
	}




};

