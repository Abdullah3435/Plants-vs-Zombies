#pragma once
#include "HUMania.hpp"
#include <vector>
#include <iostream>
using namespace std;

vector<GameObject> myObjs;
static int state = 0;

void drawObjects(SDL_Renderer* gRenderer, SDL_Texture* assets) {
    for (int i = 0; i < myObjs.size(); i++) {
        SDL_RenderCopy(gRenderer, myObjs[i].Texture, myObjs[i].Target_Tex, myObjs[i].transform->ToScreenPosition());
    }
}

void createObject(int x, int y, SDL_Renderer* renderer) {
    // TODO: create an object randomly and push it into the corresponding vector
    std::cout << "Mouse clicked at: " << x << " -- " << y << std::endl;
    int random = rand() % 1;
    switch (random) {
        case 0: {
            // Zombie Creation
            GameObject myobj(x, y, "Plant Sprite Sheets/Peashooter.png", renderer);
            myObjs.push_back(myobj);
            break;
        }
        default:
            break;
    }
}
