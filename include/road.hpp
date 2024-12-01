#ifndef ROAD_HPP
#define ROAD_HPP

// #include "C:/mingw_dev_lib/include/SFML/Graphics.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Road
{
protected:
    sf::Texture roadtexture;
    sf::Sprite road1, road2;
    float speed;

public:
    Road(const std::string &textureFile, float speed);
    void update(float deltaTime);
    void draw(sf::RenderWindow &window);
};

#endif
