#pragma once
#include "ZombieTemplate.hpp"
class Plant;
class Seed:public GameObject
{
    private :
        Plant* someplant;
    public :
};

class Projectile:public GameObject
{
    private:
        int Damage;

    public:
    int speed;
    Projectile(int x,int y, int Damage):GameObject(x,y){};
    
    void giveDamage(Zombie* zombie);

    void movement();
    void Update();
    
    ~Projectile();

};
class  Plant:public GameObject
{
    private:
        int hp;
        
    public:
        Plant(int x,int y);
        void shoot();
        void Update() override;
    
};

