#pragma once
#include <SFML/Graphics.hpp>
#include <functional>
#include <map>

class Vehicle; // Forward declaration to avoid circular dependency

// Enum to represent different types of power-ups
enum class PowerUpType
{
    SpeedBoost,
    Shield,
    ExtraLife,
    SlowMotion,
    DoublePoints
};

class PowerUp
{
public:
    PowerUp(PowerUpType type, const sf::Texture &texture, const sf::Vector2f &position);
    PowerUp() = default;

    void update();
    void draw(sf::RenderWindow &window);

    bool checkCollision(const sf::Sprite &carSprite); // Check if the power-up collides with the car

    PowerUpType getType() const { return mType; }
    void setType(PowerUpType type) { mType = type; } // Setter for mType
    void setPosition(const sf::Vector2f &position);
    // sf::Vector2f PowerUp::getPosition() const
    // {
    //     return mSprite.getPosition();
    // }

    sf::Sprite mSprite;
    PowerUpType mType;
    sf::Vector2f m_position; // Store position of the power-up

    float mSpeed = 0.5f; // Speed at which power-ups fall
};
