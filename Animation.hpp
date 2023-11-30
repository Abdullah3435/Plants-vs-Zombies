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
    // int frameWidth, frameHeight;
    // int TotalRows, TotalCols;
    int startframe,endframe,currentFrame; //frames to play starting from currentframe // in milliseconds
    int lastFrameChangeTime;
    bool Playanim;
    SDL_Texture* Selftex;

public:
    Animation(Sprite* _sprite,int _startframe ,int _endframe, SDL_Texture* newtex = nullptr);

    ~Animation();

    SDL_Texture* loadTexture(SDL_Renderer* renderer, const char* imagePath, SDL_Texture* newtex);
    void ResetFrame();
    void PlayAnimation();
    void InitializeSprite(Sprite*);
    
    
};