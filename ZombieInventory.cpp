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
    myzomb->SetSprite(Game::getInstance()->assets.conehead_walk, Game::getInstance()->gRenderer,1140,1364,4,5);
    myzomb->transform->x_sc = 2;
    myzomb->transform->y_sc = 2;
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

UtilityZombie* ZombieInventory::jumpingZombie()
{
    UtilityZombie* myzomb = new UtilityZombie(0, 0);
    myzomb->SetSprite(Game::getInstance()->assets.simple_zombie_walk, Game::getInstance()->gRenderer,1130,1987,13,5);
    myzomb->transform->x_sc = 3;
    myzomb->transform->y_sc = 3;
    return myzomb;
}

SuperZombie* ZombieInventory:: rotSpire()
{
    SuperZombie* myzomb = new SuperZombie(0, 0);
    myzomb->SetSprite(Game::getInstance()->assets.flagzombie_walk, Game::getInstance()->gRenderer,1135,1464,4,5);
    myzomb->transform->x_sc = 1;
    myzomb->transform->y_sc = 1;
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
        allzombies[2] = rotSpire();
        break;
    }
}

Zombie* ZombieInventory::createZombie(int i,int x,int y)
{
    return allzombies[i]->Clone(x,y);
}