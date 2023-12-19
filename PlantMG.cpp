#include "PlantMG.hpp"
#include "RenderingMG.hpp"
#include "game.hpp"
#include "Plant.hpp"


//Plants here
// Create a Peashooter plant
void PlantManager::Peashooter(int x,int y)
{
    Plant* plant = new Plant(x,y,500);// Create a Peashooter plant instance
    RenderingMG::getInstance()->AddObjectforRendering(plant);// Add the Peashooter plant to the rendering manager
    CollisionMG::getInstance()->AddPlant(plant); // Add the Peashooter plant to the collision manager
    plant->SetSprite(Game::getInstance()->assets.plant_tex, Game::getInstance()->gRenderer, 1760, 5680, 16, 5);// Set the sprite for the Peashooter plant
    plant->Plantanim=new Animation(plant->sprite,0,74,nullptr);// Create an animation for the Peashooter plant
    plant->shootdelay = 2000;// Set the shoot delay for the Peashooter plant
    plant->_shooter = true;// flag the Peashooter plant as a shooter

}
//create sunflower plant
void PlantManager::Sunflower(int x,int y)
{
    // Create a Sunflower plant instance
    Plant* plant = new Plant(x,y,500);
    RenderingMG::getInstance()->AddObjectforRendering(plant);// Add the Sunflower plant to the rendering manager
    CollisionMG::getInstance()->AddPlant(plant); // Add the Sunflower plant to the collision manager
    plant->SetSprite(Game::getInstance()->assets.Sunflower, Game::getInstance()->gRenderer, 1810, 2904, 8, 5);// Set the sprite for the Sunflower plant
    plant->Plantanim=new Animation(plant->sprite,0,35,nullptr);// Create an animation for the Sunflower plant
    plant->shootdelay = 10000; // Set the shoot delay for the Sunflower plant
    plant->_sunshooter= true; // Mark the Sunflower plant as a sun shooter
}

void PlantManager::WallNut(int x,int y)
{
    // Create a WallNut plant
    Plant* plant = new Plant(x,y,2500);
    RenderingMG::getInstance()->AddObjectforRendering(plant);// Add the WallNut plant to the rendering manager
    CollisionMG::getInstance()->AddPlant(plant);// Add the WallNut plant to the collision manager
    plant->SetSprite(Game::getInstance()->assets.WallNut, Game::getInstance()->gRenderer, 320, 648, 9, 5);// Set the sprite for the WallNut plant
    plant->Plantanim=new Animation(plant->sprite,0,43,nullptr);// Create an animation for the WallNut plant
}

void PlantManager::PotatoMine(int x,int y)
{
    Plant* plant = new Potatomine(x,y,500,3000);// Create a PotatoMine plant
    RenderingMG::getInstance()->AddObjectforRendering(plant);// Add the PotatoMine plant to the rendering manager
    CollisionMG::getInstance()->AddPlant(plant);// Add the PotatoMine plant to the collision manager
    plant->Plantanim = new Animation(plant->sprite,0,28,nullptr);
    plant->Plantanim->InitializeSprite(Game::getInstance()->assets.readymine, Game::getInstance()->gRenderer, 1800, 2160, 6, 5);
}

void PlantManager::CherryBomb(int x,int y)
{
    // Create a CherryBomb plant
    Bombplant* plant = new Bombplant(x,y,500,600);
    RenderingMG::getInstance()->AddObjectforRendering(plant);// Add the CherryBomb plant to the rendering manager
    CollisionMG::getInstance()->AddPlant(plant); // Add the CherryBomb plant to the collision manager
    plant->SetSprite(Game::getInstance()->assets.CherryBomb, Game::getInstance()->gRenderer, 577, 432, 5, 5);// Set the sprite for the CherryBomb plant
    // Adjust the scale of the CherryBomb plant
    plant->transform->x_sc = 3;
    plant->transform->y_sc = 3;
    plant->Plantanim = new Animation(plant->sprite,0,17,nullptr);// Create an animation for the CherryBomb plant

}

//Seeds here
void PlantManager::PeashooterSeed(int x , int y)
{
    plants[0] = new Seed(x,y,0);// Create a Peashooter seed
    // Set refresh time, sprite, and scale for the Peashooter seed
    plants[0]->refreshtime = 2000;
    plants[0]->SetSprite(Game::getInstance()->assets.Peashooter_Seed,Game::getInstance()->gRenderer,47,68);
    plants[0]->transform->x_sc =0.47*1.4;plants[0]->transform->y_sc =0.65*1.4;
    RenderingMG::getInstance()->AddObjectforRendering(plants[0]);// Add the Peashooter seed to the rendering manager
    CollisionMG::getInstance()->Collectibles.push_back(plants[0]);// Add the Peashooter seed to the collectibles in the collision manager
    plants[0]->cost = 100;// Set the cost for the Peashooter seed
}

void PlantManager::SunflowerSeed(int x , int y)
{
    // Create a Sunflower seed
    plants[1] = new Seed(x,y,1);
    // Set refresh time, sprite, and scale for the Sunflower seed
    plants[1]->refreshtime = 2000;
    plants[1]->SetSprite(Game::getInstance()->assets.Sunflower_Seed,Game::getInstance()->gRenderer,47,68);
    plants[1]->transform->x_sc =0.47*1.4;plants[1]->transform->y_sc =0.65*1.4;
    plants[1]->cost = 50;// Set the cost for the Sunflower seed
    // Add the Sunflower seed to the rendering manager
    RenderingMG::getInstance()->AddObjectforRendering(plants[1]);
    // Add the Sunflower seed to the collectibles in the collision manager
    CollisionMG::getInstance()->Collectibles.push_back(plants[1]);
}

void PlantManager::WallnutSeed(int x , int y)
{
    // Create a Wallnut seed
    plants[2] = new Seed(x,y,2);
    // Set refresh time, sprite, and scale for the Wallnut seed
    plants[2]->refreshtime = 5000;
    plants[2]->SetSprite(Game::getInstance()->assets.WallNut_Seed,Game::getInstance()->gRenderer,47,68);
    plants[2]->transform->x_sc =0.47*1.4;plants[2]->transform->y_sc =0.65*1.4;
    plants[2]->cost = 50;
    // Set the cost for the Wallnut seed
    RenderingMG::getInstance()->AddObjectforRendering(plants[2]);
    // Add the Wallnut seed to the rendering manager
    CollisionMG::getInstance()->Collectibles.push_back(plants[2]);
}

void PlantManager::PotatomineSeed(int x , int y)
{
    // Create a Potatomine seed
    plants[3] = new Seed(x,y,3);
    // Set refresh time, sprite, and scale for the Potatomine seed
    plants[3]->refreshtime = 10000;
    plants[3]->SetSprite(Game::getInstance()->assets.Potatomine_Seed,Game::getInstance()->gRenderer,47,68);
    plants[3]->transform->x_sc =0.47*1.4;plants[3]->transform->y_sc =0.65*1.4;
    // Set the cost for the Potatomine seed
    plants[3]->cost = 25;
    // Add the Potatomine seed to the rendering manager
    RenderingMG::getInstance()->AddObjectforRendering(plants[3]);
    // Add the Potatomine seed to the collectibles in the collision manager
    CollisionMG::getInstance()->Collectibles.push_back(plants[3]);
}

void PlantManager::CherrybombSeed(int x , int y)
{
    // Create a Cherrybomb seed
    plants[4] = new Seed(x,y,4);
    // Set refresh time, sprite, and scale for the Cherrybomb seed
    plants[4]->refreshtime = 10000;
    plants[4]->SetSprite(Game::getInstance()->assets.Cherrybomb_Seed,Game::getInstance()->gRenderer,47,68);
    plants[4]->transform->x_sc =0.47*1.4;plants[4]->transform->y_sc =0.65*1.4;
    // Set the cost for the Cherrybomb seed
    plants[4]->cost = 150;
    // Add the Cherrybomb seed to the rendering manager
    RenderingMG::getInstance()->AddObjectforRendering(plants[4]);
    // Add the Cherrybomb seed to the collectibles in the collision manager
    CollisionMG::getInstance()->Collectibles.push_back(plants[4]);
}



void PlantManager::createPlant(int x, int y)
{
    // Create a plant based on the selected index
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
    // Select the plant based on the selected index
    selectedplant = plants[selectedindex];
}

void PlantManager::InitializeSeeds(int level)
{
    // Allocate memory for an array of Seed pointers based on the level
    plants = new Seed*[level];
    // Create a seed slot template for rendering
    GameObject* Seedtemplate = new GameObject(400,50);
    Seedtemplate->SetSprite(Game::getInstance()->assets.SeedSlots,Game::getInstance()->gRenderer,446,87);
    RenderingMG::getInstance()->AddObjectforRendering(Seedtemplate);
    Seedtemplate->transform->x_sc = 6; // stretch the seed slots along x cuz it looks weird rn
    // Create seeds based on the level
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

