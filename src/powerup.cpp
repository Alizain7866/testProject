#include "../include/Powerups.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

// Constructor to initialize the power-up
PowerUp::PowerUp(PowerUpType type, const sf::Texture &texture, const sf::Vector2f &position)
    : mType(type)
{
    mSprite.setTexture(texture);
    mSprite.setPosition(position);
    mSprite.setScale(0.5f, 0.5f); // Scale the power-up
}

// Update the position of the power-up (fall down)
void PowerUp::update()
{
    mSprite.move(0, mSpeed); // Move power-up down the screen
}

// Draw the power-up
void PowerUp::draw(sf::RenderWindow &window)
{
    window.draw(mSprite);
}

// Check if the power-up collides with the car
bool PowerUp::checkCollision(const sf::Sprite &carSprite)
{
    return mSprite.getGlobalBounds().intersects(carSprite.getGlobalBounds());
}
