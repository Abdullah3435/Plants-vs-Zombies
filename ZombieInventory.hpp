#pragma once
#include "Zombies.hpp"

class ZombieInventory
{
private:
    Zombie* allzombies[5];

    SimpleZombie* simpleZombie();
    DefensiveZombie* ConeHeadZombie();
    SimpleZombie* BucketHeadZombie();
    UtilityZombie* jumpingZombie();
    SuperZombie* rotSpire();

public:
    ZombieInventory(int level);
    Zombie* createZombie(int i,int x,int y);
    GameObject& Cone();
    
};