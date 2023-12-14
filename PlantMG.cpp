#include "PlantMG.hpp"
#include "RenderingMG.hpp"
#include "game.hpp"
#include "Plant.hpp"


//Plants here
void PlantManager::Peashooter(int x,int y)
{
    Plant* plant = new Plant(x,y,500);
    RenderingMG::getInstance()->AddObjectforRendering(plant);
    CollisionMG::getInstance()->AddPlant(plant);
    plant->SetSprite(Game::getInstance()->assets.plant_tex, Game::getInstance()->gRenderer, 1760, 5680, 16, 5);
    plant->Plantanim=new Animation(plant->sprite,0,74,nullptr);
    plant->shootdelay = 2000;
    plant->_shooter = true;

}
void PlantManager::Sunflower(int x,int y)
{
    Plant* plant = new Plant(x,y,500);
    RenderingMG::getInstance()->AddObjectforRendering(plant);
    CollisionMG::getInstance()->AddPlant(plant);
    plant->SetSprite(Game::getInstance()->assets.Sunflower, Game::getInstance()->gRenderer, 1810, 2904, 8, 5);
    plant->Plantanim=new Animation(plant->sprite,0,35,nullptr);
    plant->shootdelay = 10000;
    plant->_sunshooter= true;
}

void PlantManager::WallNut(int x,int y)
{
    Plant* plant = new Plant(x,y,2500);
    RenderingMG::getInstance()->AddObjectforRendering(plant);
    CollisionMG::getInstance()->AddPlant(plant);
    plant->SetSprite(Game::getInstance()->assets.WallNut, Game::getInstance()->gRenderer, 320, 648, 9, 5);
    plant->Plantanim=new Animation(plant->sprite,0,43,nullptr);
}

void PlantManager::PotatoMine(int x,int y)
{
    Plant* plant = new Potatomine(x,y,500,3000);
    RenderingMG::getInstance()->AddObjectforRendering(plant);
    CollisionMG::getInstance()->AddPlant(plant);
    plant->Plantanim = new Animation(plant->sprite,0,28,nullptr);
    plant->Plantanim->InitializeSprite(Game::getInstance()->assets.readymine, Game::getInstance()->gRenderer, 1800, 2160, 6, 5);
}

void PlantManager::CherryBomb(int x,int y)
{
    Bombplant* plant = new Bombplant(x,y,500,600);
    RenderingMG::getInstance()->AddObjectforRendering(plant);
    CollisionMG::getInstance()->AddPlant(plant);
    plant->SetSprite(Game::getInstance()->assets.CherryBomb, Game::getInstance()->gRenderer, 577, 432, 5, 5);
    plant->transform->x_sc = 3;
    plant->transform->y_sc = 3;
    plant->Plantanim = new Animation(plant->sprite,0,17,nullptr);

}

//Seeds here
void PlantManager::PeashooterSeed(int x , int y)
{
    plants[0] = new Seed(x,y,0);
    plants[0]->refreshtime = 2000;
    plants[0]->SetSprite(Game::getInstance()->assets.Peashooter_Seed,Game::getInstance()->gRenderer,47,68);
    plants[0]->transform->x_sc =0.47*1.4;plants[0]->transform->y_sc =0.65*1.4;
    RenderingMG::getInstance()->AddObjectforRendering(plants[0]);
    CollisionMG::getInstance()->Collectibles.push_back(plants[0]);
    plants[0]->cost = 100;
}

void PlantManager::SunflowerSeed(int x , int y)
{
    plants[1] = new Seed(x,y,1);
    plants[1]->refreshtime = 2000;
    plants[1]->SetSprite(Game::getInstance()->assets.Sunflower_Seed,Game::getInstance()->gRenderer,47,68);
    plants[1]->transform->x_sc =0.47*1.4;plants[1]->transform->y_sc =0.65*1.4;
    plants[1]->cost = 50;
    RenderingMG::getInstance()->AddObjectforRendering(plants[1]);
    CollisionMG::getInstance()->Collectibles.push_back(plants[1]);
}

void PlantManager::WallnutSeed(int x , int y)
{
    plants[2] = new Seed(x,y,2);
    plants[2]->refreshtime = 5000;
    plants[2]->SetSprite(Game::getInstance()->assets.WallNut_Seed,Game::getInstance()->gRenderer,47,68);
    plants[2]->transform->x_sc =0.47*1.4;plants[2]->transform->y_sc =0.65*1.4;
    plants[2]->cost = 50;
    RenderingMG::getInstance()->AddObjectforRendering(plants[2]);
    CollisionMG::getInstance()->Collectibles.push_back(plants[2]);
}

void PlantManager::PotatomineSeed(int x , int y)
{
    plants[3] = new Seed(x,y,3);
    plants[3]->refreshtime = 10000;
    plants[3]->SetSprite(Game::getInstance()->assets.Potatomine_Seed,Game::getInstance()->gRenderer,47,68);
    plants[3]->transform->x_sc =0.47*1.4;plants[3]->transform->y_sc =0.65*1.4;
    plants[3]->cost = 25;
    RenderingMG::getInstance()->AddObjectforRendering(plants[3]);
    CollisionMG::getInstance()->Collectibles.push_back(plants[3]);
}

void PlantManager::CherrybombSeed(int x , int y)
{
    plants[4] = new Seed(x,y,4);
    plants[4]->refreshtime = 10000;
    plants[4]->SetSprite(Game::getInstance()->assets.Cherrybomb_Seed,Game::getInstance()->gRenderer,47,68);
    plants[4]->transform->x_sc =0.47*1.4;plants[4]->transform->y_sc =0.65*1.4;
    plants[4]->cost = 150;
    RenderingMG::getInstance()->AddObjectforRendering(plants[4]);
    CollisionMG::getInstance()->Collectibles.push_back(plants[4]);
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
            WallNut(x,y);
            break;
        case 3:
            PotatoMine(x,y);
            break;
        case 4:
            CherryBomb(x,y);
            break;
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
            PeashooterSeed(260,50);
            std::cout<<"\nShould have Created peashooter seed here\n";
            break; 
        case 2:
            PeashooterSeed(260,50);
            SunflowerSeed(330,50);
            break;

        case 3:
            PeashooterSeed(260,50);
            SunflowerSeed(330,50);
            WallnutSeed(400,50);
            break;


        case 4:
            PeashooterSeed(260,50);
            SunflowerSeed(330,50);
            WallnutSeed(400,50);
            PotatomineSeed(470,50);
            break;

        case 5:
            PeashooterSeed(260,50);
            SunflowerSeed(330,50);
            WallnutSeed(400,50);
            PotatomineSeed(470,50);
            CherrybombSeed(540,50);
            break;

        default :
            PeashooterSeed(260,50);
            std::cout<<"\nShould have Created peashooter seed here\n";
            break; 

    }

}

