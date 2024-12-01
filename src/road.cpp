// #include <iostream>
// #include "D:\Habib Uni\OOP\Project\Car_Racing_OOP_Project\Racing-game\include\road.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "..\include\road.hpp"
#include <iostream>
using namespace std;

Road::Road(const string &textureFile, float speed) : speed(speed)
{
    if (roadtexture.loadFromFile(textureFile) == false)
    {
        cout << "getting error in loading the image" << endl;
        return;
    }
    road1.setTexture(roadtexture);
    road2.setTexture(roadtexture);

    road1.setPosition(0, 0);
    road2.setPosition(0, -roadtexture.getSize().y);
}

void Road::update(float deltaTime)
{
    // moving the first road part down
    float road1NewY = road1.getPosition().y + speed * deltaTime;
    road1.setPosition(0, road1NewY);
    // moving the second road part down
    float road2NewY = road2.getPosition().y + speed * deltaTime;
    road2.setPosition(0, road2NewY);
    // if the first road segment has moved completely out of the screen
    if (road1.getPosition().y >= 1080)
    {
        // making it above the second road part to create a loop
        float road2Y = road2.getPosition().y;
        road1.setPosition(0, road2Y - roadtexture.getSize().y);
    }
    // if the second road part has moved completely out of the screen
    if (road2.getPosition().y >= 1080)
    {
        // making it above the first road part to create a seamless loop
        float road1Y = road1.getPosition().y;
        road2.setPosition(0, road1Y - roadtexture.getSize().y);
    }
}

void Road::draw(sf::RenderWindow &window)
{
    window.draw(road1);
    window.draw(road2);
}
