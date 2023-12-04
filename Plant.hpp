#pragma once
#include "ZombieTemplate.hpp"
#include "RenderingMG.hpp"
#include "PlantMG.hpp"

class Plant;
class Seed:public GameObject,public Clickable
{
    private :
        //PlantManager* plantmg;
        int SeedIndex;
        bool ready;
        
    public :
        int refreshtime,currenttime=0;
        bool Use();
        void OnClick();
        bool CheckClick(int x, int y);
        Seed (int x, int y,int i):GameObject(x,y),SeedIndex(i),ready(false){};
        void Update();
};

class Projectile:public GameObject
{
    private:
        int Damage;

    public:
    int speed;
    Projectile(int x,int y, int Damage):GameObject(x,y),Damage(Damage){};
    
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
        Animation* Plantanim;
        Plant(int x,int y,int hp);
        void shoot();
        void Update() override;
        bool getDamage(int );
};


class Digit:public GameObject
{
    private:
        int digit;
    public:
        Digit(int x,int y);
        void UpdateDigit()
        {
            switch(digit)
            {
                case 0:
                    sprite->targetTexture = {0,0,0,0};
                    //Use Sprite cow to write all cases below using the given sprite
                    break;
                case 1:
                    break;
                case 2:
                    break;
                case 3:
                    break;
                case 4:
                    break;
                case 5:
                    break;
                case 6:
                    break;
                case 7:
                    break;
                case 8:
                    break;
                case 9:
                    break;
                default:
                    break;

            }
        }
};

class SunAmount:public GameObject
{
    private:
    int Amount;
    vector<Digit*> digits;

    public:
    void CreateNumber();
    void UpdateAmount();
    void Update();
};

