
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

void Spawner::spawnRandomZombie() {
    int ypos[5] = {140,270,400,530,660};
    int spawnposx = 1200;
    int spawnposy = ypos[rand()%5];

    int randomIndex = rand() % 1;
    Zombie* newZombie = zombieInventory.createZombie(randomIndex,spawnposx,spawnposy);
    spawnedZombies.push_back(newZombie);
    
}

void Spawner::update() {
    for (auto& zombie : spawnedZombies) {
        // Update logic for zombies
        // You can implement movement, animation, etc. here
    }
}