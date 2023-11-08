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
    int totalFrames,startframe,endframe,currentFrame; //frames to play starting from currentframe
    int animationSpeed; // in milliseconds
    int lastFrameChangeTime;
    bool Playanim;

public:
    Animation(Sprite* _sprite,int totalFrames, int speed,int _startframe =0,int _endframe=0);

    ~Animation();

    SDL_Texture* loadTexture(SDL_Renderer* renderer, const char* imagePath);
    void ResetFrame();
    void PlayAnimation();
    
};