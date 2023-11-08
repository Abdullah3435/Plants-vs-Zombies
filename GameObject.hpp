#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include "Transform.hpp"
#include "Sprite.hpp"
#include <iostream>
#include "Animation.hpp"

class GameObject {
public:
    Transform* transform;
    Sprite* sprite;
    Animation* animation;
    
public:
    GameObject(int x, int y);

    void SetSprite(SDL_Texture* tex, SDL_Renderer* sourcerenderer);

    Transform* Getposition();

    void StartAnimation();
    SDL_Texture* loadTexture(std::string path);
};
