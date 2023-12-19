#pragma once
#include "ZombieTemplate.hpp"
#include "RenderingMG.hpp"
#include "PlantMG.hpp"

class Plant;
class Seed:public GameObject,public Clickable
{
    private :
        
        int SeedIndex;
        bool ready;
        Utilities myDelay;
        
    public :
        int cost = 0;
        int refreshtime,currenttime=0;
        bool Use();//function to use the seed
        void OnClick();// Handle click 
        bool CheckClick(int x, int y);// Check if the seed is clicked at a specific position
        Seed (int x, int y,int i):GameObject(x,y),SeedIndex(i),ready(false){};// Constructor
        void Update();
};

class Projectile:public GameObject
{
    private:
        int Damage;

    public:
    int speed;
    // Constructor
    Projectile(int x,int y, int Damage):GameObject(x,y),Damage(Damage)
    {
        setCollider(25,25);
    };
    // Deal damage to a zombie
    void giveDamage(Zombie* zombie);
    
    // Handle movement
    void movement();
    void Update();
    // Destructor
    ~Projectile();

};

class Plant:public GameObject
{
    private:
        int hp;
        
        
        
    public:
        int gethp()
        {
            return hp;
        }
        bool _shooter,_sunshooter;
        Animation* Plantanim;
        // Constructor
        Plant(int x,int y,int hp);
        // Perform shooting action
        void shoot();
        void Update() override;
        // Receive damage
        bool getDamage(int );
        // Destructor
        virtual ~Plant();
        int shootdelay = 0;
};

//class for bomb plant
class Bombplant: public Plant{
    public :
    void Update();
    int Blasttime;
     // Constructor
    Bombplant(int x, int y , int hp,int );
    
};
//class for potatoe mine plant
class Potatomine: public Plant{
    public :
    void Update();
    int readyTime;
    bool isReady = false;
    // Constructor
    Potatomine(int x, int y , int hp,int );
    Sprite* unreadysprite = nullptr;
};

class Button:public GameObject,public Clickable
{
    private :
        
        string ButtonName;

    public :
        // Handle click
        void OnClick();
        bool CheckClick(int x, int y);
        // Constructor
        Button (int x, int y,string name):GameObject(x,y),ButtonName(name){};
        void Update();
};
