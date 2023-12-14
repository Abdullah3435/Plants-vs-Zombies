#pragma once
#include "Zombies.hpp"
// Class representing the inventory of zombies that can be created
class ZombieInventory
{
private:
    // Array to store instances of different zombie types
    Zombie* allzombies[5];
    //for creating specific types of zombies
    SimpleZombie* simpleZombie();
    DefensiveZombie* ConeHeadZombie();
    SimpleZombie* BucketHeadZombie();
    UtilityZombie* jumpingZombie();
    SuperZombie* rotSpire();

public:
    // Constructor that initializes the zombie inventory based on the specified level
    ZombieInventory(int level);
    // to create a specific type of zombie
    Zombie* createZombie(int i,int x,int y);
    // to access the Cone object 
    GameObject& Cone();
    
};