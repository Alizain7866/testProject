#include "..\include\Heart.hpp"

// Constructor to load texture and set position
Heart::Heart(const sf::Texture &texture, float x, float y)
    : mIsAlive(true) // Heart starts as visible
{
    mHeartSprite.setTexture(texture);
    mHeartSprite.setPosition(x, y);
}

// Draw the heart on the window
void Heart::draw(sf::RenderWindow &window)
{
    if (mIsAlive)
    {
        window.draw(mHeartSprite);
    }
}

// Set the position of the heart
void Heart::setPosition(float x, float y)
{
    mHeartSprite.setPosition(x, y);
}

// Check if the heart is still alive (visible)
bool Heart::isAlive() const
{
    return mIsAlive;
}

// Make the heart disappear (remove it)
void Heart::remove()
{
    mIsAlive = false;
}
