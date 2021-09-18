#pragma once
enum class Type
{
	component ,
	drawComponent,
	textureComponent,
	vertexComponent,
	moveComponent
};

class Component
{
public:
	virtual void set(){}
	virtual Type type() { return Type::component; }
};

