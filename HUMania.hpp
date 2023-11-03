#pragma once

#include<SDL.h>
#include "GameObject.hpp"


void drawObjects(SDL_Renderer* gRnderer, SDL_Texture* assets);
void createObject(int x, int y,SDL_Renderer* renderer);

