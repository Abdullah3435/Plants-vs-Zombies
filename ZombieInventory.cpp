#include "ZombieInventory.hpp"
#include "game.hpp"

SimpleZombie* ZombieInventory::simpleZombie()
{
    SimpleZombie* myzomb = new SimpleZombie(0, 0);
    myzomb->SetSprite(Game::getInstance()->assets.simple_zombie_walk, Game::getInstance()->gRenderer,1130,1987,13,5);
    myzomb->transform->x_sc = 2;
    myzomb->Walkanim.InitializeSprite(Game::getInstance()->assets.simple_zombie_walk, Game::getInstance()->gRenderer,1130,1987,13,5);
    myzomb->Eatanim.InitializeSprite(Game::getInstance()->assets.simple_zombie_eat, Game::getInstance()->gRenderer,1130,1210,8,5);
    myzomb->Deathanim.InitializeSprite(Game::getInstance()->assets.simple_zombie_die, Game::getInstance()->gRenderer,1130,1060,7,5);
    myzomb->State = "Idle";
    myzomb->transform->y_sc = 1.7;
    myzomb->health = 500;
    myzomb->movementspeed =2.5;
    return myzomb;
}

DefensiveZombie* ZombieInventory::ConeHeadZombie()
{
    DefensiveZombie* myzomb = new DefensiveZombie(0, 0);
    myzomb->SetSprite(Game::getInstance()->assets.simple_zombie_walk, Game::getInstance()->gRenderer,1130,1987,13,5);
    myzomb->transform->x_sc = 2;
    myzomb->Walkanim.InitializeSprite(Game::getInstance()->assets.simple_zombie_walk, Game::getInstance()->gRenderer,1130,1987,13,5);
    myzomb->Eatanim.InitializeSprite(Game::getInstance()->assets.simple_zombie_eat, Game::getInstance()->gRenderer,1130,1210,8,5);
    myzomb->Deathanim.InitializeSprite(Game::getInstance()->assets.simple_zombie_die, Game::getInstance()->gRenderer,1130,1060,7,5);
    myzomb->State = "Idle";
    myzomb->transform->y_sc = 1.7;
    myzomb->health = 1000;
    myzomb->movementspeed =2.5;
    return myzomb;
}
//tryiing 


SimpleZombie* ZombieInventory::BucketHeadZombie()
{
    SimpleZombie* myzomb = new SimpleZombie(0, 0);
    myzomb->SetSprite(Game::getInstance()->assets.simple_zombie_walk, Game::getInstance()->gRenderer,1130,1987,13,5);
    myzomb->transform->x_sc = 2;
    myzomb->transform->y_sc = 2;
    myzomb->health = 2000;
    return myzomb;
}

UtilityZombie* ZombieInventory::jumpingZombie()
{
    UtilityZombie* myzomb = new UtilityZombie(0, 0);
    myzomb->SetSprite(Game::getInstance()->assets.simple_zombie_walk, Game::getInstance()->gRenderer,1130,1987,13,5);
    myzomb->transform->x_sc = 3;
    myzomb->transform->y_sc = 3;
    myzomb->health = 500;
    return myzomb;
}

SuperZombie* ZombieInventory:: rotSpire()
{
    SuperZombie* myzomb = new SuperZombie(0, 0);
    myzomb->SetSprite(Game::getInstance()->assets.flagzombie_walk, Game::getInstance()->gRenderer,1135,1464,4,5);
    myzomb->transform->x_sc = 1;
    myzomb->transform->y_sc = 1;
    myzomb->health = 1000;
    return myzomb;
}

ZombieInventory::ZombieInventory(int level)
{   for(int i=0;i<5;i++){
        allzombies[i]=nullptr;
    }
    switch (level)
    {
    case 1:
        allzombies[0] = simpleZombie();
        break;

    case 2:
        allzombies[0] = simpleZombie();
        allzombies[1] = ConeHeadZombie();
        break;
    case 3:
        allzombies[0] = simpleZombie();
        allzombies[1] = ConeHeadZombie();
        allzombies[2] = rotSpire();
        break;
    default:
        allzombies[0] = simpleZombie();
        break;
    }
}

Zombie* ZombieInventory::createZombie(int i,int x,int y)
{   if (allzombies[i]){
        return allzombies[i]->Clone(x,y);
    }
    return nullptr;
}