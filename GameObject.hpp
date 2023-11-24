#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include "Transform.hpp"
#include "Sprite.hpp"
#include <iostream>
#include "Animation.hpp"
#include "Utilities.hpp"


class GameObject {
public:
    Transform* transform;
    Sprite* sprite;
    Animation* animation;
    Utilities utilities;
    
public:
    GameObject(int x, int y);

    void SetSprite(SDL_Texture* tex, SDL_Renderer* sourcerenderer,int TexWidth , int TexHeight, int rows =1 ,int col =1);

    Transform* Getposition();

    void StartAnimation();

    SDL_Texture* loadTexture(std::string path);

    virtual void Update();
    void render();

    ~GameObject();

};
