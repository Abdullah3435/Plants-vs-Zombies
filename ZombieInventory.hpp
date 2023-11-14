#pragma once
#include "Zombies.hpp"

class ZombieInventory
{
private:
    Zombie* allzombies[5];

    SimpleZombie* simpleZombie();
    DefensiveZombie* ConeHeadZombie();
    SimpleZombie* BucketHeadZombie();

public:
    ZombieInventory(int level);
    Zombie* createZombie(int i);
};