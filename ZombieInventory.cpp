#include "ZombieInventory.hpp"
#include "game.hpp"

SimpleZombie* ZombieInventory::simpleZombie()
{
    // Create a new SimpleZombie instance
    SimpleZombie* myzomb = new SimpleZombie(0, 0);
    // Set sprite for walking animation
    myzomb->SetSprite(Game::getInstance()->assets.simple_zombie_walk, Game::getInstance()->gRenderer,1130,1987,13,5);
    myzomb->transform->x_sc = 2;
    // Initialize animations
    myzomb->Walkanim.InitializeSprite(Game::getInstance()->assets.simple_zombie_walk, Game::getInstance()->gRenderer,1130,1987,13,5);
    myzomb->Eatanim.InitializeSprite(Game::getInstance()->assets.simple_zombie_eat, Game::getInstance()->gRenderer,1130,1210,8,5);
    myzomb->Deathanim.InitializeSprite(Game::getInstance()->assets.simple_zombie_die, Game::getInstance()->gRenderer,1130,1060,7,5);
    // Set default state, scale, health, and movement speed
    myzomb->State = "Idle";
    myzomb->transform->y_sc = 1.7;
    myzomb->health = 500;
    myzomb->movementspeed = 3;
    return myzomb;
}
//to create a DefensiveZombie with a Cone
DefensiveZombie* ZombieInventory::ConeHeadZombie()
{
    // Create a new DEfensiveZombie instance
    DefensiveZombie* myzomb = new DefensiveZombie(0, 0);
    // Set sprite for walking animation
    myzomb->SetSprite(Game::getInstance()->assets.simple_zombie_walk, Game::getInstance()->gRenderer,1130,1987,13,5);
    myzomb->transform->x_sc = 2;
    // Initialize animations
    myzomb->Walkanim.InitializeSprite(Game::getInstance()->assets.simple_zombie_walk, Game::getInstance()->gRenderer,1130,1987,13,5);
    myzomb->Eatanim.InitializeSprite(Game::getInstance()->assets.simple_zombie_eat, Game::getInstance()->gRenderer,1130,1210,8,5);
    myzomb->Deathanim.InitializeSprite(Game::getInstance()->assets.simple_zombie_die, Game::getInstance()->gRenderer,1130,1060,7,5);
    // Set default state, scale, health, and movement speed
    myzomb->State = "Idle";
    myzomb->transform->y_sc = 1.7;
    myzomb->health = 1000;
    myzomb->movementspeed = 3;

    //operator overloading to add a protection obj to an existing DEFENSIVE ZOmbie ONLY
    *myzomb + Cone();
    return myzomb;
}



SimpleZombie* ZombieInventory::BucketHeadZombie()
{
    SimpleZombie* myzomb = new SimpleZombie(0, 0);
    // Create a new SimpleZombie instance
    myzomb->SetSprite(Game::getInstance()->assets.simple_zombie_walk, Game::getInstance()->gRenderer,1130,1987,13,5);
    // Set default sprite, scale, health, and movement speed
    myzomb->transform->x_sc = 2;
    myzomb->transform->y_sc = 2;
    myzomb->health = 2000;
    myzomb->movementspeed = 3;
    return myzomb;
}

UtilityZombie* ZombieInventory::jumpingZombie()
{
    // Create a new UtilityZombie instance
    UtilityZombie* myzomb = new UtilityZombie(0, 0);
    // Set sprite, scale, health
    myzomb->SetSprite(Game::getInstance()->assets.simple_zombie_walk, Game::getInstance()->gRenderer,1130,1987,13,5);
    myzomb->transform->x_sc = 3;
    myzomb->transform->y_sc = 3;
    myzomb->health = 500;
    return myzomb;
}

SuperZombie* ZombieInventory:: rotSpire()
{
    // Create a new SuperZombie instance
    SuperZombie* myzomb = new SuperZombie(0, 0);
    // Set sprite, scale, health
    myzomb->SetSprite(Game::getInstance()->assets.flagzombie_walk, Game::getInstance()->gRenderer,1135,1464,4,5);
    myzomb->transform->x_sc = 1;
    myzomb->transform->y_sc = 1;
    myzomb->health = 1000;
    return myzomb;
}
//calling types of zomies as per levels 
ZombieInventory::ZombieInventory(int level)
{   for(int i=0;i<5;i++){
        allzombies[i]=nullptr;
    }
    switch (level)
    {
    case 1:
        allzombies[0] = simpleZombie();
        allzombies[1] = simpleZombie();
        allzombies[2] = simpleZombie();
        allzombies[3] = simpleZombie();
        allzombies[4] = simpleZombie();
        break;

    case 2:
        allzombies[0] = simpleZombie();
        allzombies[1] = simpleZombie();
        allzombies[2] = simpleZombie();
        allzombies[3] = simpleZombie();
        allzombies[4] = ConeHeadZombie();
        break;
    case 3:
        allzombies[0] = simpleZombie();
        allzombies[1] = ConeHeadZombie();
        allzombies[2] = simpleZombie();
        allzombies[1] = ConeHeadZombie();
        allzombies[2] = simpleZombie();
        break;
    case 4:
        allzombies[0] = simpleZombie();
        allzombies[1] = ConeHeadZombie();
        allzombies[2] = ConeHeadZombie();
        allzombies[3] = simpleZombie();
        allzombies[4] = simpleZombie();
        break;
    case 5:
        allzombies[0] = simpleZombie();
        allzombies[1] = ConeHeadZombie();
        allzombies[2] = ConeHeadZombie();
        allzombies[3] = ConeHeadZombie();
        allzombies[4] = ConeHeadZombie();
        break;
        
    default:
        allzombies[0] = simpleZombie();
        allzombies[1] = simpleZombie();
        allzombies[2] = simpleZombie();
        allzombies[3] = simpleZombie();
        allzombies[4] = simpleZombie();
        break;
    }
}
// Create a zombie based on the specified prototype index
Zombie* ZombieInventory::createZombie(int i,int x,int y)
{   
    // Check if the prototype at index i exists
    if (allzombies[i]){
        // Clone the zombie prototype at index i with the specified position (x, y)
        return allzombies[i]->Clone(x,y);
    }
    return nullptr;
}

// Create and return a Cone zombie GameObject
GameObject& ZombieInventory::Cone()
{
    // Create a new GameObject representing a Cone 
    GameObject* cone = new GameObject(0,0);
    // Set the sprite and scaling for the Cone 
    cone->SetSprite(Game::getInstance()->assets.Cone,Game::getInstance()->gRenderer,178,57,1,3);
    cone->transform->x_sc = 0.5;
    cone->transform->y_sc = 0.65;
    // Add the Cone to the rendering manager
    RenderingMG::getInstance()->AddObjectforRendering(cone);
    return *cone;
}