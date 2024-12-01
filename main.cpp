#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "src/road.cpp"
#include "src/vehicle.cpp"
#include "src/heart.cpp"
#include "src/vehicle_spawner.cpp"
#include "src/powerup.cpp"

// #include "include/road.hpp"
// #include "include/vehicle.hpp"
// #include "include/Heart.hpp"
// #include "include/vehicle_spawner.hpp"
// #include "include/Powerups.hpp"
// #include "include/GameManager.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Racing Game");
    // Road road("images/roading.png", 300.0f);
    Road road("images/Road2_Sprite1.png", 300.0f);
    static int player_count{2};
    std::vector<Vehicle *> player_cars;
    if (player_count == 1)
    {
        Vehicle *car1_ptr = new Vehicle(1, 1);
        player_cars.push_back(car1_ptr);
    }
    else if (player_count == 2)
    {
        Vehicle *car1_ptr = new Vehicle(1, 1);
        player_cars.push_back(car1_ptr);
        Vehicle *car2_ptr = new Vehicle(2, 2);
        player_cars.push_back(car2_ptr);
    }

    std::vector<std::string> carTextures = {"images/comp_car1.png", "images/comp_car2.png", "images/comp_car3.png", "images/comp_car4.png", "images/comp_car5.png"};
    VehicleSpawner spawner(carTextures, 2.0f);

    sf::Clock clock; // including a clock for timing purposes
    // bool isLifeLost = false; // To keep track if a life was lost already

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
            {
                window.close();
            }

            //     // Detect if 'L' is pressed and call loseLife() only once
            //     if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::L && !isLifeLost)
            //     {
            //         pCar.loseLife();   // Remove a heart when L is pressed
            //         isLifeLost = true; // Mark that a life has been lost
            //     }

            //     // Reset the isLifeLost flag when the key is released
            //     if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::L)
            //     {
            //         isLifeLost = false; // Allow losing another life once the key is released
            //     }
        }

        float deltaTime = clock.restart().asSeconds(); // Calculate deltaTime

        road.update(deltaTime);
        // spawner.spawnVehicle();    // Generate new vehicles

        window.clear(); // Clear previous frame

        road.draw(window);         // Draw road
        spawner.update(deltaTime); // Update all vehicles
        spawner.draw(window);      // Draw all vehicles
        if (player_count == 1)
        {
            player_cars[0]->draw(window); // Draw player 1 car
        }
        else if (player_count == 2)
        {
            player_cars[0]->draw(window); // Draw player 1 car
            player_cars[1]->draw(window); // Draw player 2 car
        }

        if (player_count == 1)
        {
            player_cars[0]->update1(window, deltaTime); // Update player 1 car
        }
        else if (player_count == 2)
        {
            player_cars[0]->update1(window, deltaTime); // Update player 1 car
            player_cars[1]->update2(window, deltaTime); // Update player 2 car
        }

        window.display(); // Display updated frame
    }

    return 0;
}
