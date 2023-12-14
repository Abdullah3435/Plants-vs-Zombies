#include "ResourceMG.hpp"
#include "game.hpp"
#include <iostream>
#include "AudioMG.hpp"

ResourceMG::ResourceMG() : sun(25) {}

void ResourceMG::addResource(int amount)
{
    sun += amount;
   
}

void ResourceMG::subtractResource(int amount)
{
    if (sun < amount)
    {
        std::cout << "Not enough resources";
    }
    else
    {
        sun -= amount;
    }
}

int ResourceMG::getResources()
{
    return sun;
}

Sun::Sun(int x, int y):GameObject(x,y){
                                    SetSprite(Game::getInstance()->assets.Sun,Game::getInstance()->gRenderer,225,225);
                                    Fall = true;
                                    RenderingMG::getInstance()->AddObjectforRendering(this);
                                    elapsedduration = 0;
                                    Fallduration = 100+(rand()%100);
                                    }


void Sun::OnClick()
{
    Game::getInstance()->_resourcemg.addResource(Sun_energy);
    AudioManager::getInstance()->playSound("Sunclick");
    Game::getInstance()->DumpGarbage(this);
    delete this;
}


bool Sun::CheckClick(int x, int y)
{
    SDL_Rect* rect = transform->ToScreenPosition();
    if (x < rect->x ||                   // Point is to the left of the rect
        x >= rect->x + rect->w ||         // Point is to the right of the rect
        y < rect->y ||                   // Point is above the rect
        y >= rect->y + rect->h)           // Point is below the rect
    {
        return false;
    }
    // If none of the above conditions are met, there is an overlap
    return true;
}

void Sun::Update()
{
    if (elapsedduration<Fallduration)
    {
        elapsedduration++;
    }
    else Fall = false;
    if (Fall)
    {
        transform->translate(0,1);
    }
    else{
        if(utilities.Delay(5000))
        {
            Game::getInstance()->DumpGarbage(this);
            delete this;
        }
        
    }
    GameObject::Update();
}