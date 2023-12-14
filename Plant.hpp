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
    Projectile(int x,int y, int Damage):GameObject(x,y),Damage(Damage){setCollider(25,25);};
    
    void giveDamage(Zombie* zombie);
    

    void movement();
    void Update();
    
    ~Projectile();

};

class Plant:public GameObject
{
    private:
        int hp;
        
        
        
    public:
        bool _shooter,_sunshooter;
        Animation* Plantanim;
        Plant(int x,int y,int hp);
        void shoot();
        void Update() override;
        bool getDamage(int );
        virtual ~Plant();
};

// class UtilityPlant: public Plant{
//     public:
//     void Update();
//     UtilityPlant(int x, int y , int hp);
// };

class Bombplant: public Plant{
    public :
    void Update();
    int Blasttime;
    Bombplant(int x, int y , int hp,int );
    
};



class Button:public GameObject,public Clickable
{
    private :
        //PlantManager* plantmg;
        string ButtonName;

    public :
        void OnClick();
        bool CheckClick(int x, int y);
        Button (int x, int y,string name):GameObject(x,y),ButtonName(name){};
        void Update();
};
