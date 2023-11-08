#pragma once
#include "RenderingMG.hpp"
#include <vector>
#include <iostream>
using namespace std;

vector<GameObject> myObjs;
static int state = 0;

void drawObjects(SDL_Renderer* gRenderer, Textures* assets) {
    for (int i = 0; i < myObjs.size(); i++) {
        SDL_RenderCopy(gRenderer,myObjs[i].sprite->texture, &myObjs[i].sprite->targetTexture, myObjs[i].transform->ToScreenPosition());
    }
}

void createObject(int x, int y, SDL_Renderer* renderer,Textures *assets) {
    // TODO: create an object randomly and push it into the corresponding vector
    std::cout << "Mouse clicked at: " << x << " -- " << y << std::endl;
    int random = rand() % 1;
    switch (random) {
        case 0: {
            // Plant Creation
            GameObject myobj(x, y);
            myobj.SetSprite(assets->plant_tex,renderer);
            myobj.StartAnimation();
            myObjs.push_back(myobj);
            break;
        }
        default:
            break;
    }
}
