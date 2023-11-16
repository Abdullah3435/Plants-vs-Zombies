#include "ZombieInventory.hpp"
#include "game.hpp"

SimpleZombie* ZombieInventory::simpleZombie()
{
    SimpleZombie* myzomb = new SimpleZombie(0, 0);
    myzomb->SetSprite(Game::getInstance()->assets.simple_zombie_walk, Game::getInstance()->gRenderer,1130,1987,13,5);
    myzomb->transform->x_sc = 2;
    myzomb->transform->y_sc = 2;
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
    myzomb->SetSprite(Game::getInstance()->assets.simple_zombie_walk, Game::getInstance()->gRenderer,1130,1987,13,5);
    myzomb->transform->x_sc = 2;
    myzomb->transform->y_sc = 2;
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

Zombie* ZombieInventory::createZombie(int i,int x,int y)
{
    return allzombies[i]->Clone(x,y);
}