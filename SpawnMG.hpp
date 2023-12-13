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
    int level;
    ZombieInventory zombieInventory;
    std::vector<Zombie*> spawnedZombies;
    Utilities SpawnDelay,WaveDelay, Waveduration;
    Spawner();

public:
    bool Spawn, wave;
    int _generalspawndelay,_spawndelay,_wavedelay,no_waves,_passedwaves,_waveduration;
    static Spawner* getInstance();
    void spawnRandomZombie();
    void spawnwave();
    void update();
};
