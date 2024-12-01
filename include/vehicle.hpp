#ifndef VEHICLE_HPP
#define VEHICLE_HPP

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <vector>
#include "Powerups.hpp"

class Vehicle
{
public:
    Vehicle(int carNumber, const int player_num);
    Vehicle(const std::string &texturePath, float speed, const sf::Vector2f &position);

    void draw(sf::RenderWindow &window); // Draws the car on the window
    void update(float deltaTime);
    void update1(sf::RenderWindow &window, float deltaTime); // Updates the 1st player car's position
    void update2(sf::RenderWindow &window, float deltaTime); // Updates the 2nd player car's position
    void loseLife();                                         // Decrease lives
    int getLives() const;                                    // Get remaining lives
    sf::Vector2f getPosition() const;

    // newly updated
    void activatePowerUp(const PowerUp &powerUp);
    void spawnPowerUp(sf::RenderWindow &window);
    void updatePowerUps(sf::RenderWindow &window);

protected:
    std::string tmp;
    std::string hrt;

    std::vector<PowerUp> powerUps; // Store all power-ups

    std::string car1_load = "images/car_1.png";
    std::string car2_load = "images/car_2.png";
    std::string car3_load = "images/car_3.png";
    std::string heart_load = "images/Heart_image.png";

    sf::Texture pCarTexture; // Texture for the car
    sf::Sprite pCarSprite;   // Sprite representing the car
    float mCarSpeed;         // Speed of the car

    sf::Texture heartTexture;
    std::vector<sf::Sprite> hearts;

    int lives = 3; // Default to 3 lives
    // void resetEffect(float duration, std::function<void()> resetFunction);

    // PowerUp texture loading
    std::map<PowerUpType, sf::Texture> powerUpTextures;

    void loadPowerUpTextures();
};

#endif
