#include "ZombieInventory.hpp"

SimpleZombie* ZombieInventory::simpleZombie()
{
    SimpleZombie* myzomb = new SimpleZombie(0, 0);
    return myzomb;
}

DefensiveZombie* ZombieInventory::ConeHeadZombie()
{
    DefensiveZombie* myzomb = new DefensiveZombie(0, 0);
    return myzomb;
}

SimpleZombie* ZombieInventory::BucketHeadZombie()
{
    SimpleZombie* myzomb = new SimpleZombie(0, 0);
    return myzomb;
}

ZombieInventory::ZombieInventory(int level)
{
    switch (level)
    {
    case 1:
        allzombies[0] = simpleZombie();
        break;

    case 2:
        allzombies[0] = simpleZombie();
        allzombies[1] = ConeHeadZombie();
        break;

    default:
        allzombies[0] = simpleZombie();
        allzombies[1] = ConeHeadZombie();
        allzombies[2] = BucketHeadZombie();
        break;
    }
}

Zombie* ZombieInventory::createZombie(int i)
{
    return allzombies[i]->Clone();
}