// #include "C:\mingw_dev_lib\include\SFML\Graphics.hpp"
// #include "D:\Habib Uni\OOP\Project\Car_Racing_OOP_Project\Racing-game\include\road.hpp"
// #include "D:\Habib Uni\OOP\Project\Car_Racing_OOP_Project\Racing-game\include\vehicle.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "../include/road.hpp"
#include "../include/vehicle.hpp"
#include "../include/playerCar.hpp"
#include "../include/vehicle_spawner.hpp"
int main()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Racing Game");
    // Road road("./Racing-game/assets/images/1.png", 300.0f);
    Road road("testProject/images/Road2_Sprite1.png", 300.0f);
    Vehicle p1Car(3);
    Vehicle p2Car(1);

    std::vector<std::string> carTextures = {"../images/comp_car1.png", "../images/comp_car2.png", "../images/comp_car3.png", "../images/comp_car4.png", "../images/comp_car5.png"};
    VehicleSpawner spawner(carTextures, 2.0f);

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
        spawner.update(deltaTime);
        p1Car.update1(window, deltaTime);
        p2Car.update2(window, deltaTime);
        window.clear();

        road.draw(window);
        p1Car.draw(window);
        p2Car.draw(window);
        spawner.draw(window);

        window.display();
    }

    return 0;
}
