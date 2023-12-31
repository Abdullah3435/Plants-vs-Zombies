#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "Sprite.hpp"



struct Unit {
    SDL_Rect srcRect, moverRect;
};

class Animation {
private:
    Sprite* sprite;
    
    int startframe,endframe,currentFrame; //frames to play starting from currentframe in milliseconds
    int lastFrameChangeTime;
    bool Playanim;  
    SDL_Texture* Selftex; // Pointer to an SDL_Texture associated with the Animation
    void ResetFrame();

public:
    Animation(Sprite* _sprite,int _startframe ,int _endframe, SDL_Texture* newtex = nullptr);

    ~Animation();
    //load texture using SDL functions
    SDL_Texture* loadTexture(SDL_Renderer* renderer, const char* imagePath, SDL_Texture* newtex);
    
    Sprite* PlayAnimation();
    void InitializeSprite(SDL_Texture* tex, SDL_Renderer* sourcerenderer,int TexWidth , int TexHeight, int _rows ,int _col);
};