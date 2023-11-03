#pragma once
#include "Animation.hpp"

Animation::Animation(SDL_Renderer* renderer, const char* imagePath, int totalFrames, int speed, int width, int height)
    : sprite(nullptr), totalFrames(totalFrames), currentFrame(0),
    animationSpeed(speed), lastFrameChangeTime(0), frameWidth(width), frameHeight(height) {

    sprite->texture = loadTexture(renderer, imagePath);
}

Animation::~Animation() {
    SDL_DestroyTexture(sprite->texture);
}

SDL_Texture* Animation::loadTexture(SDL_Renderer* renderer, const char* imagePath) {
    SDL_Surface* loadedSurface = IMG_Load(imagePath);
    if (loadedSurface == nullptr) {
        // Handle error
        return nullptr;
    }

    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
    SDL_FreeSurface(loadedSurface);

    return texture;
}

SDL_Rect Animation::getNextFrame() {
    SDL_Rect unit;
    unit.x = currentFrame%TotalRows * frameWidth;
    unit.y = currentFrame/TotalRows * frameHeight;
    unit.w = frameWidth;
    unit.h = frameHeight;

    return unit;
}

void Animation::update() {
    int currentTime = SDL_GetTicks();

    if (currentTime > lastFrameChangeTime + animationSpeed) {
        lastFrameChangeTime = currentTime;
        currentFrame = (currentFrame + 1) % totalFrames;
    }
}
