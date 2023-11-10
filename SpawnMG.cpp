#include "SpawnMG.hpp"

Spawner* Spawner::instance = nullptr;

Spawner::Spawner() : zombieInventory(3) {
    Spawndelay = 40;
}

Spawner* Spawner::getInstance() {
    if (instance == nullptr) {
        instance = new Spawner();
    }
    return instance;
}

void Spawner::spawnRandomZombie(int frame) {
    if (frame % Spawndelay == 0)
    {
        int randomIndex = rand() % 3;
        Zombie* newZombie = zombieInventory.createZombie(randomIndex);
        spawnedZombies.push_back(newZombie);
        std::cout<<"Creating Zombie";
    }
}

void Spawner::update() {
    for (auto& zombie : spawnedZombies) {
        // Update logic for zombies
        // You can implement movement, animation, etc. here
    }
}