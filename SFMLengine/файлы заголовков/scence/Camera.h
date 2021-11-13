#pragma once
#include<SFML/Graphics.hpp>

struct Camera
{
	sf::View cam;
	float rotate;
	sf::Vector2f pos;
};