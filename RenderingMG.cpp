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
