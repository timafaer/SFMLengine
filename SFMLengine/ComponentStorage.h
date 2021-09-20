#pragma once
#include"Component.h"
#include"DrawComponent.h"
#include"TextureComponent.h"
#include"VertexComponent.h"
#include"BPhusComponent.h"
#include"ShapeComponent.h"
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

		case Type::vertexComponent: components.push_back(new VertexComponent()); break;

		case Type::bphysComponent:components.push_back(new BPhysComponent()); break;

		case Type::shapeComponent:components.push_back(new ShapeComponent()); break;

		default:
			break;
		}
	}


	template<typename T>
	T get_component(){
		Type type;

		if (typeid(T) == typeid(Component*)) type = Type::component;
		else if (typeid(T) == typeid(DrawComponent*)) type = Type::drawComponent;
		else if (typeid(T) == typeid(TextureComponent*)) type = Type::textureComponent;
		else if (typeid(T) == typeid(VertexComponent*)) type = Type::vertexComponent;
		else if (typeid(T) == typeid(BPhysComponent*)) type = Type::bphysComponent;
		else if (typeid(T) == typeid(ShapeComponent*)) type = Type::shapeComponent;


	for (int i = 0; i < components.size(); i++) {
			if (components[i]->type() == type)
				return (T)components[i];
	}
}

	void remove_component(Type type){}

	~ComponentStorage() {}
};
