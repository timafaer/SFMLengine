#pragma once
enum class Type
{
	component ,
	drawComponent,
	textureComponent,
	moveComponent
};

class Component
{
public:
	virtual void set(){}
	virtual Type type() { return Type::component; }
};

