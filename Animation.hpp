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
    int frameWidth, frameHeight;
    int TotalRows, TotalCols;
    int totalFrames;
    int currentFrame;
    int animationSpeed; // in milliseconds
    int lastFrameChangeTime;


public:
    Animation(SDL_Renderer* renderer, const char* imagePath, int totalFrames, int speed, int width, int height);

    ~Animation();

    SDL_Texture* loadTexture(SDL_Renderer* renderer, const char* imagePath);

    SDL_Rect getNextFrame();

    void update();
};