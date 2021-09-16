#pragma once
#include"Component.h"
#include"DrawComponent.h"
#include"TextureComponent.h"
#include<vector>

class ComponentStorage
{
private:
	std::vector<Component*> components;

public:
	void add_component(Type type) {
		switch (type)
		{
		case Type::component: components.push_back(new Component()); break;

		case Type::drawComponent: components.push_back(new DrawComponent()); break;

		case Type::textureComponent: components.push_back(new TextureComponent()); break;

		default:
			break;
		}
	}

	Component* get_component(Type type) {
		for (int i = 0; i < components.size(); i++) {
			if (components[i]->type() == type)
				return components[i];
		}

	}

	void remove_component(Type type){}

	~ComponentStorage() {}
};
