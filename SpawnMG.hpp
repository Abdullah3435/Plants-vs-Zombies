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
    Utilities SpawnDelay,WaveDelay;
    bool Spawn;


    Spawner();

public:
    int _spawndelay,_wavedelay,no_waves;
    static Spawner* getInstance();
    void spawnRandomZombie();
    void update();
};
