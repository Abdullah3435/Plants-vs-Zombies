#pragma once
#include <SDL.h>
#include <SDL_image.h>

struct Unit {
    SDL_Rect srcRect, moverRect;
};

class Animation {
private:
    SDL_Texture* spriteSheet;
    int frameWidth, frameHeight;
    int totalFrames;
    int currentFrame;
    int animationSpeed; // in milliseconds
    int lastFrameChangeTime;

public:
    Animation(SDL_Renderer* renderer, const char* imagePath, int totalFrames, int speed, int width, int height);

    ~Animation();

    SDL_Texture* loadTexture(SDL_Renderer* renderer, const char* imagePath);

    Unit getNextFrame();

    void update();
};