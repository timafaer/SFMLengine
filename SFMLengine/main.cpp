#include <SFML/Graphics.hpp>
#include"ComponentStorage.h"
int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");

    sf::Texture texture;
    texture.loadFromFile("texture.jpg");

    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    

    ComponentStorage storage;
    storage.add_component(Type::textureComponent);
    storage.add_component(Type::drawComponent);
    ((TextureComponent*)(storage.get_component(Type::textureComponent)))->set(&texture);
    ((DrawComponent*)(storage.get_component(Type::drawComponent)))->set(&(((TextureComponent*)(storage.get_component(Type::textureComponent)))->sprite));

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(*((DrawComponent*)(storage.get_component(Type::drawComponent))));
        window.display();
    }

    return 0;
}