// Spawner.hpp
#pragma once

#include <vector>
#include <cstdlib>
#include <ctime>
#include <SDL.h>
#include "ZombieInventory.hpp"

class Spawner {
private:
    static Spawner* instance;
    ZombieInventory zombieInventory;
    std::vector<Zombie*> spawnedZombies;
    int Spawndelay;

    Spawner();

public:
    static Spawner* getInstance();
    void spawnRandomZombie(int frame);
    void update();
};
