#include "PlantMG.hpp"
#include "RenderingMG.hpp"
#include "game.hpp"
#include "Plant.hpp"

void PlantManager::Peashooter(int x,int y)
{
    Plant* plant = new Plant(x,y,500);
    RenderingMG::getInstance()->AddObjectforRendering(plant);
    CollisionMG::getInstance()->AddPlant(plant);
    plant->SetSprite(Game::getInstance()->assets.plant_tex, Game::getInstance()->gRenderer, 1760, 5680, 16, 5);
    plant->Plantanim=new Animation(plant->sprite,0,74,nullptr);

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

void PlantManager::createPlant(int x, int y)
{
    switch(selectedindex)
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

void PlantManager::SelectPlant()
{
    selectedplant = plants[selectedindex];
}

void PlantManager::InitializeSeeds(int level)
{
    plants = new Seed*[level];
    GameObject* Seedtemplate = new GameObject(400,50);
    Seedtemplate->SetSprite(Game::getInstance()->assets.SeedSlots,Game::getInstance()->gRenderer,446,87);
    RenderingMG::getInstance()->AddObjectforRendering(Seedtemplate);
    Seedtemplate->transform->x_sc = 6; // stretch the seed slots along x cuz it looks weird rn

    switch(level)
    {
        case 1:
            plants[0] = new Seed(260,50,0);
            plants[0]->refreshtime = 100;
            plants[0]->SetSprite(Game::getInstance()->assets.Peashooter_Seed,Game::getInstance()->gRenderer,47,68);
            plants[0]->transform->x_sc =0.47*1.4;plants[0]->transform->y_sc =0.65*1.4;
            RenderingMG::getInstance()->AddObjectforRendering(plants[0]);
            CollisionMG::getInstance()->Collectibles.push_back(plants[0]);
            std::cout<<"\nShould have Created peashooter seed here\n";
            break; 
        default :
            break;

    }

}