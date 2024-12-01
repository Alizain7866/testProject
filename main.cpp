#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "src/road.cpp"
#include "src/vehicle.cpp"
#include "src/heart.cpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Racing Game");
    Road road("images/roading.png", 300.0f);
    Vehicle pCar(2);
    sf::Clock clock; // including a clock for timing purposes
    // bool isLifeLost = false; // To keep track if a life was lost already

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
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
