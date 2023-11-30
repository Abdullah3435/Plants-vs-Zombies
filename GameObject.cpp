#pragma once
#include "GameObject.hpp"
#include <iostream>
#include <thread>
#include <algorithm>

GameObject::GameObject(int x, int y) {
    transform = new Transform(x, y);
    animation = nullptr;
    sprite = nullptr;

}

void GameObject::Update()
{
    if(sprite != nullptr)
    {
        //std::cout<<"Render Start";
        render();
        //std::cout<<"Render End";
    }
}
void GameObject::SetSprite(SDL_Texture* tex, SDL_Renderer* sourcerenderer,int TexWidth , int TexHeight, int _rows ,int _col)
{
    //printf("sprite is set");
    sprite =  new Sprite(tex , SDL_Rect{ 0, 0, TexWidth/_col, TexHeight/_rows},sourcerenderer);

    sprite->rows = _rows;
    sprite->cols= _col;
    sprite->Texturewidth = TexWidth;
    sprite->Textureheight = TexHeight;
}

void GameObject::StartAnimation()
{
    printf("creating animation\n");
    animation = new Animation(sprite, 2, 40, sprite->texture);

    // Start the animation loop in a separate thread
    std::thread animThread(&Animation::PlayAnimation, animation);
    animThread.detach();  // Detach the thread to run independently
}

Transform* GameObject::Getposition() {
    return transform;
}

SDL_Texture* GameObject::loadTexture(std::string path) {
    SDL_Texture* newTexture = nullptr;
    SDL_Surface* loadedSurface = IMG_Load(path.c_str());

    if (loadedSurface == nullptr) {
        printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
    } else {
        newTexture = SDL_CreateTextureFromSurface(sprite->renderer, loadedSurface);
        if (newTexture == nullptr) {
            printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
        }
        SDL_FreeSurface(loadedSurface);
    }
    return newTexture;
}


void GameObject::render() {
    SDL_RenderCopy(sprite->renderer,sprite->texture, &sprite->targetTexture, transform->ToScreenPosition());
    std::cout<<"\nHere is the ACCESSED SDL Rect "<<sprite->targetTexture.x<<","<<sprite->targetTexture.y<<","<<sprite->targetTexture.w<<","<<sprite->targetTexture.h<<std::endl;
}

GameObject::~GameObject()
{
    delete transform;
    delete sprite;
}


