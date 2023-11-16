#include <SDL.h>
#include <iostream>
using namespace std;

struct Texturepaths
{
    string Plantstexture = "Plant Sprite Sheets/Peashooter.png";
    string SimpleZombietexture = "Zombie Sprite Sheets/Simple_Walk.png";
    string SimpleZombieEat = "Zombie Sprite Sheets/EatAnimation.png";
    string SimpleZombieDie = "Zombie Sprite Sheets/SimpleDie.png";
};

class Textures
{
    public:
        SDL_Texture* plant_tex;
        SDL_Texture* simple_zombie_walk;
        SDL_Texture* simple_zombie_eat;
        SDL_Texture* simple_zombie_die;

    Textures():plant_tex(nullptr), simple_zombie_walk(nullptr){}
};