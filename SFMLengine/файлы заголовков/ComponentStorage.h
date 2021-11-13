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
//#include".\components\another_components\Soul.h"
using namespace std;
class ComponentStorage
{
private:
	std::vector<Component*> components;

public:
	template<class T>
	void add_component() {
		components.push_back(new T());
	}


	template<class T>
	T& get_component(){
		for (auto& comp : components)
			if (typeid(*comp) == typeid(T))
				return static_cast<T&>(*comp);
	
	}
	//return NULL;


	void remove_component(Type type){}

	~ComponentStorage() {}
};
