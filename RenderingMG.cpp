#include "RenderingMG.hpp"
#include "game.hpp"
#include "Plant.hpp"
using namespace std;

static int state = 0;

RenderingMG* RenderingMG::instance = nullptr;

void RenderingMG::drawObjects(SDL_Renderer* gRenderer, Textures* assets) {
    for (int i = 0; i < myObjs.size(); i++) {
    if(myObjs[i])
    {
       myObjs[i]->Update();}
    }
}

void RenderingMG::AddObjectforRendering(GameObject* obj)
{
    myObjs.push_back(obj);
}

RenderingMG::RenderingMG(){};

RenderingMG* RenderingMG::getInstance()
{
    if(instance == nullptr)
    {
        instance = new RenderingMG();
    }
    return instance;
}

void RenderingMG::createObject(int x, int y, SDL_Renderer* renderer, Textures *assets, Grid& myGrid) {
    std::cout << "Mouse clicked at: " << x << " -- " << y << std::endl;

    // Check if the click is within the grid boundaries
    if (x >= myGrid.xOffset && x < myGrid.width + myGrid.xOffset &&
        y >= myGrid.yOffset && y < myGrid.height + myGrid.yOffset) {

        // Calculate the grid index based on mouse coordinates
        int gridIndex = myGrid.calculateIndex(x, y);

        // Get the adjusted x and y coordinates for the center of the grid block
        auto coordinates = myGrid.getCoordinates(gridIndex / myGrid.cols, gridIndex % myGrid.cols);
        int gridX = coordinates.first;
        int gridY = coordinates.second;

        // Check if the block at the calculated grid index is occupied
        if (!myGrid.isOccupied(gridX, gridY)) {
            // If not occupied, create the object
            // GameObject* myobj = new GameObject(gridX, gridY);
            // myobj->SetSprite(assets->plant_tex, renderer, 1760, 5680, 16, 5);
            // //myobj.StartAnimation();
            // myObjs.push_back(myobj);
            PMscript->createPlant(PMscript->selectedindex,gridX, gridY);

            // Mark the block as occupied in the grid
            myGrid.occupyBlock(gridX, gridY);

            //CollisionMG::getInstance()->AddPlant(myobj);
        } else {
            // Handle case where the block is already occupied (optional)
            std::cout << "Block at (" << gridX << ", " << gridY << ") is already occupied." << std::endl;
        }
    } else {
        // Handle case where the click is outside the grid boundaries (optional)
        std::cout << "Click outside the grid boundaries." << std::endl;
    }
}

//==========================================CollisionMG=============================================

void CollisionMG::AddPlant(GameObject* plant)
{
    Plants.push_back(plant);
}
void CollisionMG::AddProjectile(GameObject* proj)
{
    Projectiles.push_back(proj);
}
void CollisionMG::AddZombie(GameObject* zombie)
{
    Zombies.push_back(zombie);
}
void CollisionMG::CollisionEventLoop()
{
    for (int z = 0; z < Zombies.size(); z++) 
    {
       for (int p = 0; p < Plants.size(); p++) 
        {
            if(Zombies[z]&&Plants[p])
            {
                if(isCollision(*Zombies[z]->transform->ToScreenPosition(),*Plants[p]->transform->ToScreenPosition()))
                {
                    std::cout<<"Collision Occured Here plant and zombie";

                    Game::getInstance()->DumpGarbage(Zombies[z]);
                    delete Zombies[z];
                    Zombie* currentzomb = dynamic_cast<Zombie*>(Zombies[z]); //dynamic casting at runtime
                    Plant* currentplant = dynamic_cast<Plant*>(Plants[p]);
                    if(currentplant->getDamage(currentzomb->damage))
                    {
                        currentzomb->UpdateState ("Idle");
                    }
                    else 
                    {
                        currentzomb->UpdateState ("Eat");
                    }
                    
                    


                    std::cout<<"Deletion Successfull";
                    //Implement Zombie and plant Logic here
                }
            }
        }
    }

    

    for (int z = 0; z < Zombies.size(); z++) 
    {
       for (int p = 0; p < Projectiles.size(); p++) 
        {
            if(Zombies[z]&&Projectiles[p])
            {
            if(isCollision(*Zombies[z]->transform->ToScreenPosition(),*Projectiles[p]->transform->ToScreenPosition()))
            {
                std::cout<<"Collision Occured Here zombie and projectile";
                Zombie* currentzomb = dynamic_cast<Zombie*>(Zombies[z]); //dynamic casting at runtime
                Projectile* currentproj = dynamic_cast<Projectile*>(Projectiles[p]);
                currentproj->giveDamage(currentzomb);
                //Implement Zombie and plant Logic here
            }
            }
        }
    }
}
void CollisionMG::CheckClicks(int x, int y)
{
    for (int i =0 ; i < Collectibles.size();i++)
    {
        if(Collectibles[i]->CheckClick(x,y))
        {
            Collectibles[i]->OnClick();
        }
    }
}

CollisionMG* CollisionMG::instance = nullptr;

CollisionMG* CollisionMG::getInstance() {
    if (!instance) {
        instance = new CollisionMG();
    }
    return instance;
}


bool CollisionMG::isCollision(const SDL_Rect& rectA, const SDL_Rect& rectB)
{
    // Check for no overlap
    if (rectA.x + rectA.w <= rectB.x || // rectA is to the left of rectB
        rectB.x + rectB.w <= rectA.x || // rectA is to the right of rectB
        rectA.y + rectA.h <= rectB.y || // rectA is above rectB
        rectB.y + rectB.h <= rectA.y)   // rectA is below rectB
    {
        return false;
    }

    // If none of the above conditions are met, there is an overlap
    return true;
}

//=============================================GarbageCollection==================================================

void CollisionMG::RemoveGameObject(GameObject* gameObject)
{
    // Iterate through Plants vector
    for (auto& plant : Plants)
    {
        if (plant == gameObject)
        {
            plant = nullptr;
            break;  // No need to continue searching
        }
    }

    // Iterate through Projectiles vector
    for (auto& projectile : Projectiles)
    {
        if (projectile == gameObject)
        {
            projectile = nullptr;
            break;  // No need to continue searching
        }
    }

    // Iterate through Zombies vector
    for (auto& zombie : Zombies)
    {
        if (zombie == gameObject)
        {
            zombie = nullptr;
            break;  // No need to continue searching
        }
    }
}

Clickable::Clickable()
{
    CollisionMG::getInstance()->Collectibles.push_back(this);
}