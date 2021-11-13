#pragma once
#include"Component.h"
#include".\components\draw_components\DrawComponent.h"
#include".\components\draw_components\TextureComponent.h"
#include".\components\draw_components\VertexComponent.h"
#include".\components\another_components\BPhusComponent.h"
#include".\components\draw_components\ShapeComponent.h"
#include<vector>
#include".\components\another_components\ColissionsComponent.h"
#include".\components\another_components\AnimationComponent.h"


class ComponentStorage
{
private:
	std::vector<Component*> components;

public:
	template<class T>
	void add_component() {
		components.push_back(new T());
		
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
		else if (typeid(T) == typeid(ColissionsComponent*)) type = Type::colissionComponent;
		else if (typeid(T) == typeid(AnimationComonent*)) type = Type::animationComponent;

	for (int i = 0; i < components.size(); i++) {
			if (components[i]->type() == type)
				return (T)components[i];
	}
	return NULL;
}

	void remove_component(Type type){}

	~ComponentStorage() {}
};
