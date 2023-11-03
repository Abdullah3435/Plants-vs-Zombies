#pragma once

#include<SDL.h>
#include "GameObject.hpp"
#include "TextureMG.cpp"


void drawObjects(SDL_Renderer* gRnderer, Textures* assets);
void createObject(int x, int y,SDL_Renderer* renderer,Textures* assets);

