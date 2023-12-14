#pragma once
#include "Animation.hpp"
#include <iostream>
#include <future>
#include <chrono>
#include "game.hpp"

//constructor
Animation::Animation(Sprite* _sprite, int _startframe ,int _endframe,SDL_Texture* selftex)
    : sprite(_sprite), currentFrame(0), lastFrameChangeTime(0) 
{
    startframe = _startframe;
    endframe = _endframe;
    Selftex = selftex;
}

Animation::~Animation() {
    
}

void Animation::ResetFrame() {
    SDL_Rect* unit = new SDL_Rect();
    // Calculate x and y coordinates based on the current frame and sprite's dimensions
    unit->x = currentFrame%sprite->cols * sprite->Texturewidth/sprite->cols;
    unit->y = abs(currentFrame/sprite->cols) * sprite->Textureheight/sprite->rows;
    // Set the width and height based on sprite's dimensions
    unit->w = sprite->Texturewidth/sprite->cols;
    unit->h = sprite->Textureheight/sprite->rows;
    //update the target texture
    sprite->targetTexture = *unit;
    
}

Sprite* Animation::PlayAnimation() {
    Playanim = true;
    ResetFrame();
    // Increment the current frame to change frames and a condition for resetting the fram to the start frame
    if (currentFrame<endframe)
    {
        currentFrame++;
    }
    else
    {
        currentFrame = startframe;
    }
    return sprite;
    
    
}
void Animation::InitializeSprite(SDL_Texture* tex, SDL_Renderer* sourcerenderer,int TexWidth , int TexHeight, int _rows ,int _col)
{
    sprite =  new Sprite(tex , SDL_Rect{ 0, 0, TexWidth/_col, TexHeight/_rows},sourcerenderer);

    // Set the rows and columns of the sprite
    sprite->rows = _rows;
    sprite->cols= _col;
    
    // Set the texture width and height of the sprite
    sprite->Texturewidth = TexWidth;
    sprite->Textureheight = TexHeight;//Play animation atleast once to synchronize the animation sprite with gameobj sprite before rendering 
}

