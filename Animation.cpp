#pragma once
#include "Animation.hpp"
#include<iostream>
#include <future>
#include <chrono>
Animation::Animation(Sprite* _sprite, int totalFrames, int speed,int _startframe ,int _endframe)
    : sprite(_sprite), totalFrames(totalFrames), currentFrame(0),
    animationSpeed(speed), lastFrameChangeTime(0) {
    startframe = _startframe;endframe = totalFrames-1;


}

Animation::~Animation() {
    SDL_DestroyTexture(sprite->texture);
}

void Animation::ResetFrame() {
    SDL_Rect unit;
    printf("resettiing frame\n");
    unit.x = currentFrame%sprite->cols * sprite->Texturewidth/sprite->cols;
    unit.y = abs(currentFrame/sprite->cols) * sprite->Textureheight/sprite->rows;
    unit.w = sprite->Texturewidth/sprite->cols;
    unit.h = sprite->Textureheight/sprite->rows;

    std::cout<<"SDL Rext "<<unit.x<<","<<unit.y<<","<<unit.w<<","<<unit.h<<std::endl;
    sprite->targetTexture = unit;

    
}

void Animation::PlayAnimation() {
    Playanim = true;
    while(Playanim)
    {
        ResetFrame();
        printf("Animation Playing with current frame:");
        
        // std::future<void> result = std::async(std::launch::async, delayedFunction);
        // result.get(); // Wait for the async operation to complete
        std::this_thread::sleep_for(std::chrono::seconds(animationSpeed/(endframe-startframe)));

    

        if (currentFrame<endframe)
        {
            currentFrame++;
            
        }
        else
        {
        currentFrame = startframe;
        }
    }
    
}

void delayedFunction() {
    std::this_thread::sleep_for(std::chrono::seconds(2)); // Simulates delay
    std::cout << "Delayed function executed after 2 seconds." << std::endl;
}
