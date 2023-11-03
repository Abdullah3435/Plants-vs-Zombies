#include <SDL.h>
#include <iostream>
using namespace std;

struct Texturepaths
{
    string Plantstexture = "Plant Sprite Sheets/Peashooter.png";
    string SimpleZombietexture = "Zombie Sprite Sheets/Simple Zombie.png";
};

class Textures
{
    public:
        SDL_Texture* plant_tex;
        SDL_Texture* zombie_tex;

    Textures():plant_tex(nullptr), zombie_tex(nullptr){}
};