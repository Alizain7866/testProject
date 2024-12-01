// #include "C:\mingw_dev_lib\include\SFML\Graphics.hpp"
// #include "D:\Habib Uni\OOP\Project\Car_Racing_OOP_Project\Racing-game\include\road.hpp"
// #include "D:\Habib Uni\OOP\Project\Car_Racing_OOP_Project\Racing-game\include\vehicle.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "./include/road.hpp"
#include "./include/vehicle.hpp"
#include "./include/playerCar.hpp"
int main()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Racing Game");
    Road road("./Racing-game/assets/images/1.png", 300.0f);
    Vehicle pCar(3);
    sf::Clock clock; // including a clock for timing purposes
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }
        float deltaTime = clock.restart().asSeconds();
        road.update(deltaTime);
        window.clear();

        road.draw(window);
        pCar.draw(window);
        pCar.update(window);

        window.display();
    }

    return 0;
}
