#include <SDL.h>
#include <iostream>
using namespace std;

struct Texturepaths
{
    string Plantstexture = "Plant Sprite Sheets/Peashooter.png";
    string SimpleZombietexture = "Zombie Sprite Sheets/Simple_Walk.png";
    string SimpleZombieEat = "Zombie Sprite Sheets/EatAnimation.png";
    string SimpleZombieDie = "Zombie Sprite Sheets/SimpleDie.png";
    string ConeHead = "Zombie Sprite Sheets/Conehead/conehead.png";
    string FlagZombie="Zombie Sprite Sheets/Flag/flagzombie.png";
    string Pea =  "Plant Sprite Sheets/Projectiles/Pea.png";
    string OpenGame="openOrEnd/open.png";
    string gameover="openOrEnd/gameover.png";
    string SeedSLots = "Plant Sprite Sheets/Seeds/SeedSlot.png";
    string sunflowerseed = "Plant Sprite Sheets/Seeds/Sunflower.png";
    string wallnutseed = "Plant Sprite Sheets/Seeds/WallNut.png";
    string cherrybombseed = "Plant Sprite Sheets/Seeds/CherryBomb.png";
    string potatomineseed = "Plant Sprite Sheets/Seeds/PotatoMine.png";
    string PeashooterSeed = "Plant Sprite Sheets/Seeds/Peashooter_Seed.png";
    string Sun =  "Plant Sprite Sheets/Sun.png";
    string Sunflower = "Plant Sprite Sheets/Sunflower.png";
    string CherryBomb = "Plant Sprite Sheets/Cherrybomb.png";
    string WallNut = "Plant Sprite Sheets/WallNut.png";
    string cone="Zombie Sprite Sheets/Conehead/Cone.png";
    string gameoverbar = "OpenOrEnd/GameOverBar.png";
    string Nextlevel = "OpenOrEnd/Next LEvel.png";
    //string PotatoMine = ""
    

};

class Textures
{
    public:
        SDL_Texture* plant_tex;
        SDL_Texture* simple_zombie_walk;
        SDL_Texture* simple_zombie_eat;
        SDL_Texture* simple_zombie_die;
        SDL_Texture* conehead_walk;
        SDL_Texture* flagzombie_walk;
        SDL_Texture* Pea;
        SDL_Texture* OpenGame;
        SDL_Texture* gameover;
        SDL_Texture* SeedSlots;

        //seeds
        SDL_Texture* Peashooter_Seed;
        SDL_Texture* Sunflower_Seed;
        SDL_Texture* Potatomine_Seed;
        SDL_Texture* Cherrybomb_Seed;
        SDL_Texture* WallNut_Seed;

        //plants
        SDL_Texture* Sunflower;
        SDL_Texture* WallNut;
        SDL_Texture* CherryBomb;

        //resources
        SDL_Texture* Sun;
        SDL_Texture* Cone;
        SDL_Texture* Buckethead;
        
        SDL_Texture* gameoverbar;
        SDL_Texture* nextlevel;


    Textures():plant_tex(nullptr), simple_zombie_walk(nullptr){}
};