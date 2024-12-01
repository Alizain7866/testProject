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

    sf::Sprite mSprite;
    PowerUpType mType;
    float mSpeed = 0.5f; // Speed at which power-ups fall
};
