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
        

    Textures():plant_tex(nullptr), simple_zombie_walk(nullptr){}
};