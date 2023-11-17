#pragma once

#include <SDL.h>

class Sprite {
public:
    SDL_Texture* texture;
    SDL_Rect targetTexture;
    SDL_Renderer* renderer;
    int Texturewidth,Textureheight;
    int rows,cols;


public:
    Sprite(SDL_Texture* tex, SDL_Rect target, SDL_Renderer* ren);

    Sprite(SDL_Texture* tex, SDL_Rect target, SDL_Renderer* ren,int _rows,int _cols);

    void render(SDL_Rect &targetpoint);
};
