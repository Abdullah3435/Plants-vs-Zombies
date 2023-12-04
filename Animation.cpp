#pragma once
#include "Animation.hpp"
#include <iostream>
#include <future>
#include <chrono>
#include "game.hpp"
Animation::Animation(Sprite* _sprite, int _startframe ,int _endframe,SDL_Texture* selftex)
    : sprite(_sprite), currentFrame(0), lastFrameChangeTime(0) 
{
    startframe = _startframe;endframe = _endframe;
    Selftex = selftex;
}

Animation::~Animation() {
    
}

void Animation::ResetFrame() {
    SDL_Rect* unit = new SDL_Rect();
    printf("resettiing frame\n");
    unit->x = currentFrame%sprite->cols * sprite->Texturewidth/sprite->cols;
    unit->y = abs(currentFrame/sprite->cols) * sprite->Textureheight/sprite->rows;
    unit->w = sprite->Texturewidth/sprite->cols;
    unit->h = sprite->Textureheight/sprite->rows;
    sprite->targetTexture = *unit;
    std::cout<<"SDL Rext "<<sprite->targetTexture.x<<","<<sprite->targetTexture.y<<","<<sprite->targetTexture.w<<","<<sprite->targetTexture.h<<std::endl;
    
}

void Animation::PlayAnimation(Sprite* parentSprite) {
    Playanim = true;
    if(parentSprite != sprite)
    {
        parentSprite = sprite; // set to the Animation Sprite if parent sprite != Animation Sprite
    }
    ResetFrame();
    printf("Animation Playing with current frame:");
    
    // std::future<void> result = std::async(std::launch::async, delayedFunction);
    // result.get(); // Wait for the async operation to complete
    // std::this_thread::sleep_for(std::chrono::seconds(animationSpeed/(endframe-startframe)));
    if (currentFrame<endframe)
    {
        currentFrame++;
    }
    else
    {
    currentFrame = startframe;
    }
    
    
}
void Animation::InitializeSprite(SDL_Texture* tex, SDL_Renderer* sourcerenderer,int TexWidth , int TexHeight, int _rows ,int _col)
{
    sprite =  new Sprite(tex , SDL_Rect{ 0, 0, TexWidth/_col, TexHeight/_rows},sourcerenderer);

    sprite->rows = _rows;
    sprite->cols= _col;
    sprite->Texturewidth = TexWidth;
    sprite->Textureheight = TexHeight;
}

// void delayedFunction() {
//     std::this_thread::sleep_for(std::chrono::seconds(2)); // Simulates delay
//     std::cout << "Delayed function executed after 2 seconds." << std::endl;
// }