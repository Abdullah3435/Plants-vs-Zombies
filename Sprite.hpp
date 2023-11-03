#pragma once

#include <SDL.h>

class Sprite {
public:
    SDL_Texture* texture;
    SDL_Rect targetTexture;
    SDL_Renderer* renderer;
    int Texturewidth,Textureheight;


public:
    Sprite(SDL_Texture* tex, SDL_Rect target, SDL_Renderer* ren);

    void render();
};
