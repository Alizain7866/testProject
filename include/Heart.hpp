#ifndef HEART_HPP
#define HEART_HPP

#include <SFML/Graphics.hpp>

class Heart
{
public:
    // Constructor to load texture and set initial position
    Heart(const sf::Texture &texture, float x, float y);

    // Method to draw the heart on the window
    void draw(sf::RenderWindow &window);

    // Method to set the position of the heart
    void setPosition(float x, float y);

    // Method to check if the heart is visible (alive)
    bool isAlive() const;

    // Method to remove the heart (making it disappear)
    void remove();

private:
    sf::Sprite mHeartSprite;
    bool mIsAlive; // State to track if the heart is still visible
};

#endif // HEART_HPP
