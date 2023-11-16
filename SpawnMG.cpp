
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
    int ypos[5] = {200,400,600,800,1000};
    int spawnposx = 1800;
    int spawnposy = ypos[rand()%5];

    int randomIndex = rand() % 3;
    Zombie* newZombie = zombieInventory.createZombie(randomIndex,spawnposx,spawnposy);
    spawnedZombies.push_back(newZombie);

    std::cout<<"Creating Zombie";
    
}

void Spawner::update() {
    for (auto& zombie : spawnedZombies) {
        // Update logic for zombies
        // You can implement movement, animation, etc. here
    }
}