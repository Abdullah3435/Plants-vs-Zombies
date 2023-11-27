#include "PlantMG.hpp"
#include "RenderingMG.hpp"
#include "game.hpp"
void PlantManager::Peashooter(int x,int y)
{
    Plant* plant = new Plant(x,y,100);
    RenderingMG::getInstance()->AddObjectforRendering(plant);
    CollisionMG::getInstance()->AddPlant(plant);
    plant->SetSprite(Game::getInstance()->assets.plant_tex, Game::getInstance()->gRenderer, 1760, 5680, 16, 5);
}

void PlantManager::Sunflower(int x,int y)
{
    Plant* plant = new Plant(x,y,100);
    RenderingMG::getInstance()->AddObjectforRendering(plant);
    CollisionMG::getInstance()->AddPlant(plant);
    plant->SetSprite(Game::getInstance()->assets.plant_tex, Game::getInstance()->gRenderer, 1760, 5680, 16, 5);
}

void PlantManager::WallNut(int x,int y)
{
    Plant* plant = new Plant(x,y,100);
    RenderingMG::getInstance()->AddObjectforRendering(plant);
    CollisionMG::getInstance()->AddPlant(plant);
    plant->SetSprite(Game::getInstance()->assets.plant_tex, Game::getInstance()->gRenderer, 1760, 5680, 16, 5);
}

void PlantManager::PotatoMine(int x,int y)
{
    Plant* plant = new Plant(x,y,100);
    RenderingMG::getInstance()->AddObjectforRendering(plant);
    CollisionMG::getInstance()->AddPlant(plant);
    plant->SetSprite(Game::getInstance()->assets.plant_tex, Game::getInstance()->gRenderer, 1760, 5680, 16, 5);
}

void PlantManager::CherryBomb(int x,int y)
{
    Plant* plant = new Plant(x,y,100);
    RenderingMG::getInstance()->AddObjectforRendering(plant);
    CollisionMG::getInstance()->AddPlant(plant);
    plant->SetSprite(Game::getInstance()->assets.plant_tex, Game::getInstance()->gRenderer, 1760, 5680, 16, 5);
}

void PlantManager::createPlant(int i,int x, int y)
{
    switch(i)
    {
        case 0:
            Peashooter(x,y);
            break;
        case 1:
            Sunflower(x,y);
            break;
        case 2:
            PotatoMine(x,y);
        case 3:
            WallNut(x,y);
        case 4:
            CherryBomb(x,y);
        default:
            break;
    }
}