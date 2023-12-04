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
    string PeashooterSeed = "Plant Sprite Sheets/Seeds/Peashooter_Seed.png";

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
        SDL_Texture* Peashooter_Seed;

    Textures():plant_tex(nullptr), simple_zombie_walk(nullptr){}
};