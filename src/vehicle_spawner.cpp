#include "../include/vehicle_spawner.hpp"
#include <random> // C++11 random library
#include <ctime>  // For seeding random

VehicleSpawner::VehicleSpawner(const std::vector<std::string> &carTextures, float interval)
    : carTexturePaths(carTextures), spawnInterval(interval), spawnTimer(0.0f)
{
    // Seed the random number generator once in the constructor
    static std::mt19937 rng(static_cast<unsigned int>(time(nullptr))); // Mersenne Twister RNG
    randomGenerator = rng;                                             // Store random number generator to be used for other random values
}

void VehicleSpawner::update(float deltaTime)
{
    spawnTimer += deltaTime;
    // spawnTimer += 1;

    // Spawn vehicles based on the spawn interval
    if (spawnTimer >= spawnInterval)
    {
        spawnVehicle();
        spawnTimer = 0.0f;
    }

    // Update active vehicles and remove off-screen ones
    activeVehicles.erase(std::remove_if(activeVehicles.begin(), activeVehicles.end(),
                                        [deltaTime](Vehicle &v)
                                        {
                                            v.update(deltaTime);
                                            return v.getPosition().y > 1080; // Remove vehicles that go off-screen
                                        }),
                         activeVehicles.end());
}

void VehicleSpawner::draw(sf::RenderWindow &window)
{
    // Draw all active vehicles
    for (auto &vehicle : activeVehicles)
    {
        vehicle.draw(window);
        int pos_x = vehicle.getPosition().x;
        int pos_y = vehicle.getPosition().y;
        std::cout << pos_x << " " << pos_y << "\n";
    }
}

void VehicleSpawner::spawnVehicle()
{
    // Using uniform distribution for speed and position
    std::uniform_int_distribution<int> textureDist(0, carTexturePaths.size() - 1);
    std::uniform_real_distribution<float> speedDist(200.0f, 500.0f);
    std::uniform_real_distribution<float> xPosDist(150.0f, 1600.0f);

    int randomIndex = textureDist(randomGenerator); // Random texture index
    float randomSpeed = speedDist(randomGenerator); // Random speed between 200 and 500
    float randomX = xPosDist(randomGenerator);      // Random X position between 150px and 1600px

    Vehicle newVehicle(carTexturePaths[randomIndex], randomSpeed, sf::Vector2f(randomX, -100.0f));
    std::cout << "texture: " << carTexturePaths[randomIndex];
    activeVehicles.push_back(newVehicle); // Add new vehicle to the active list
}
