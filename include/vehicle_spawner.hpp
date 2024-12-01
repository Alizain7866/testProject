#ifndef VEHICLE_SPAWNER_HPP
#define VEHICLE_SPAWNER_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <random>
#include "vehicle.hpp"

class VehicleSpawner
{
public:
    // Constructor to initialize the spawner with car textures and spawn interval
    VehicleSpawner(const std::vector<std::string> &carTextures, float interval);

    // Update the spawner, spawn new vehicles, and remove off-screen vehicles
    void update(float deltaTime);

    // Draw all active vehicles to the window
    void draw(sf::RenderWindow &window);

private:
    // Spawn a new vehicle and add it to the active vehicles list
    void spawnVehicle();

    std::vector<std::string> carTexturePaths; // Paths to car textures
    std::vector<Vehicle> activeVehicles;      // List of active vehicles in the game
    float spawnInterval;                      // Time interval between spawns
    float spawnTimer;                         // Timer to track the spawn interval
    std::mt19937 randomGenerator;             // Random number generator (Mersenne Twister)
};

#endif // VEHICLE_SPAWNER_HPP
