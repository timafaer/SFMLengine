#pragma once
#include"../../Component.h"
#include"../../Game.h"

template<class T>
class Soul :public Component
{
private:
	T soul;
public:
	Soul() {}

	void set(T s,Game& g) {
		soul = s;
		soul.set_game_class(g);
	}
	void logic() {
		soul.logic();
	}

	Type type() { return Type::soulComponent; }
};
