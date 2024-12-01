#include <iostream>
// #include "D:\Habib Uni\OOP\Project\Car_Racing_OOP_Project\Racing-game\include\vehicle.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "..\include\road.hpp"
#include "..\include\vehicle.hpp"
#include "..\include\playerCar.hpp"

// void Vehicle::handleVerticalWrap(sf::RenderWindow &window)
// {
//     sf::Vector2f position = pCarSprite.getPosition();
//     sf::Vector2u windowSize = window.getSize();

//     // Check for vertical wrapping
//     if (position.y > static_cast<float>(windowSize.y))
//     {
//         pCarSprite.setPosition(position.x, 0); // Wrap to the top
//     }
//     else if (position.y < 0)
//     {
//         pCarSprite.setPosition(position.x, static_cast<float>(windowSize.y)); // Wrap to the bottom
//     }
// }

Vehicle::Vehicle(int carNumber)
{
    int spacing = 6;
    if (carNumber == 1)
    {
        hrt = heart_load;
        tmp = car1_load;
        mCarSpeed = 0.2;
    }
    else if (carNumber == 2)
    {
        hrt = heart_load;

        tmp = car2_load;
        mCarSpeed = 0.5;
    }
    else if (carNumber == 3)
    {
        hrt = heart_load;

        tmp = car3_load;
        mCarSpeed = 0.8;
    }
    else
    {
        hrt = heart_load;

        std::cerr << "Invalid car number" << std::endl;
        tmp = car1_load; // Default to car 1
        mCarSpeed = 3.2;
    }

    if (!pCarTexture.loadFromFile(tmp))
    {
        std::cerr << "Error loading texture from file: " << tmp << std::endl;
    }
    pCarSprite.setTexture(pCarTexture);
    pCarSprite.setScale(0.38f, 0.38f);
    pCarSprite.setPosition(1920 / 2, 1080 / 2);
    sf::FloatRect bounds = pCarSprite.getLocalBounds();
    pCarSprite.setOrigin(bounds.width / 2, bounds.height / 2);

    // Load heart texture
    if (!heartTexture.loadFromFile(hrt))
    {
        std::cerr << "Error loading heart texture" << std::endl;
    }

    // Initialize hearts
    for (int i = 0; i < lives; ++i)
    {
        sf::Sprite heart(heartTexture);
        heart.setScale(0.5f, 0.5f);                            // Scale the heart image
        heart.setPosition(50.0f + i * 40.0f, 50.0f * spacing); // Position hearts in a row
        hearts.push_back(heart);
    }
}

// void Vehicle::displayCarSpeed() const
// {
//     std::cout << "Car Speed: " << mCarSpeed << " units" << std::endl;
// }

void Vehicle::update(sf::RenderWindow &window)
{
    // Check for keyboard input and move the sprite accordingly
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        pCarSprite.move(0, -mCarSpeed); // Move up
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        pCarSprite.move(0, mCarSpeed); // Move down
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        pCarSprite.move(-mCarSpeed, 0); // Move left
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        pCarSprite.move(mCarSpeed, 0); // Move right
    }

    sf::Vector2f position = pCarSprite.getPosition();

    // Get the window size
    sf::Vector2u windowSize = window.getSize();

    // Handle Horizontal wrapping
    if (position.x > static_cast<float>(windowSize.x))
    {
        pCarSprite.setPosition(0, position.y); // Wrap to the left
        loseLife();                            // Lose a life for vertical wrapping
    }
    else if (position.x < 0)
    {
        pCarSprite.setPosition(static_cast<float>(windowSize.x), position.y); // Wrap to the right
        loseLife();                                                           // Lose a life for vertical wrapping
    }

    // Handle Vertical wrapping and lose a life
    if (position.y > static_cast<float>(windowSize.y)) // Wrap to the top
    {
        pCarSprite.setPosition(position.x, 0); // Wrap to the top
        loseLife();                            // Lose a life for vertical wrapping
    }
    else if (position.y < pCarSprite.getGlobalBounds().height / 2)
    {
        // Prevent moving beyond the top edge
        pCarSprite.setPosition(position.x, pCarSprite.getGlobalBounds().height / 2);
    }

    // Prevent the car from going beyond the bottom of the window
    if (position.y > windowSize.y - pCarSprite.getGlobalBounds().height)
    {
        pCarSprite.setPosition(position.x, windowSize.y - pCarSprite.getGlobalBounds().height);
    }

    // Prevent the car from going above the top of the window
    else if (position.y < pCarSprite.getGlobalBounds().height / 2)
    {
        // Prevent moving beyond the top edge
        pCarSprite.setPosition(position.x, pCarSprite.getGlobalBounds().height / 2);
    }
}

void Vehicle::draw(sf::RenderWindow &window)
{
    window.draw(pCarSprite);
    for (const auto &heart : hearts)
    {
        window.draw(heart);
    }
}

void Vehicle::loseLife()
{
    if (!hearts.empty())
    {
        hearts.pop_back(); // Remove the last heart
        lives--;
        std::cout << "HI" << std::endl;
    }
}

int Vehicle::getLives() const
{
    return lives;
}
