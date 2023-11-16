#include "RenderingMG.hpp"

using namespace std;

static int state = 0;

RenderingMG* RenderingMG::instance = nullptr;

void RenderingMG::drawObjects(SDL_Renderer* gRenderer, Textures* assets) {
    for (int i = 0; i < myObjs.size(); i++) {
       myObjs[i]->Update();
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

void RenderingMG::createObject(int x, int y, SDL_Renderer* renderer,Textures *assets) {
    // TODO: create an object randomly and push it into the corresponding vector
    std::cout << "Mouse clicked at: " << x << " -- " << y << std::endl;
    int random = rand() % 1;
    switch (random) {
        case 0: {
            // Plant Creation
            GameObject* myobj = new GameObject(x,y);
            myobj->SetSprite(assets->plant_tex,renderer,1760,5680,16,5);
            //myobj.StartAnimation();
            myObjs.push_back(myobj);
            break;
        }
        
        default:
            break;
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
            if(isCollision(*Zombies[z]->transform->ToScreenPosition(),*Plants[p]->transform->ToScreenPosition()))
            {
                std::cout<<"Collision Occured Here plant and zombie";
                //Implement Zombie and plant Logic here
            }
        }
    }

    for (int z = 0; z < Zombies.size(); z++) 
    {
       for (int p = 0; p < Projectiles.size(); p++) 
        {
            if(isCollision(*Zombies[z]->transform->ToScreenPosition(),*Plants[z]->transform->ToScreenPosition()))
            {
                std::cout<<"Collision Occured Here zombie and projectile";
                //Implement Zombie and plant Logic here
            }
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
