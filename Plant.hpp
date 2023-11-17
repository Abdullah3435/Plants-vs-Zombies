#pragma once
#include "ZombieTemplate.hpp"
class Projectile:public GameObject
{
    private:
        int Damage;
    public:
    Projectile(int x,int y, int Damage):GameObject(x,y){};
    
    void giveDamage(Zombie* zombie);
    
    ~Projectile();

};
class  Plant:public GameObject
{
    private:
        int hp;
        
    public:
        Plant(int x,int y);
        void shoot();
        void Update();

};


