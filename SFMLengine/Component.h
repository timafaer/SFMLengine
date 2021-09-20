#pragma once
#include<SFML/Graphics.hpp>
enum class Type
{
	component ,
	drawComponent,
	textureComponent,
	vertexComponent,
	bphysComponent,
	shapeComponent,
	moveComponent
};

class Component
{
public:
	virtual void set(){}
	virtual Type type() { return Type::component; }
};

