#pragma once
#include "GameObject.hpp"
#include <iostream>
#include <thread>
#include <algorithm>

// Constructor
Collider::Collider(int wd,int ht)
{
    width = wd;
    height = ht;
}

//get the SDL_Rect for the collider based on position
SDL_Rect Collider::getCollider(int posx,int posy)
{
    return SDL_Rect{posx-(width/2),posy-(height/2),width,height};
}

//et the collider dimensions for the GameObject
void GameObject::setCollider(int width, int height)
{
    _collider = new Collider(width,height);
}

SDL_Rect GameObject::getCollider()
{
    if (_collider)
    {
        return _collider->getCollider(transform->x,transform->y);
    }
}

GameObject::GameObject(int x, int y) {
    transform = new Transform(x, y);
    animation = nullptr;
    sprite = nullptr;
    _collider = nullptr;
}


void GameObject::Update()
{
    if(sprite != nullptr)
    {
        render();
    }
}

//set the sprite for the GameObject
void GameObject::SetSprite(SDL_Texture* tex, SDL_Renderer* sourcerenderer,int TexWidth , int TexHeight, int _rows ,int _col)
{
    printf("sprite is set");
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

    
}

Transform* GameObject::Getposition() {
    return transform;
}

//load a texture from a file path
SDL_Texture* GameObject::loadTexture(std::string path) {
    SDL_Texture* newTexture = nullptr;
    // Load the image from the specified path into an SDL_Surface
    SDL_Surface* loadedSurface = IMG_Load(path.c_str());

    if (loadedSurface == nullptr) {
        printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
    } else {
        // Create an SDL_Texture from the loaded SDL_Surface
        newTexture = SDL_CreateTextureFromSurface(sprite->renderer, loadedSurface);
        if (newTexture == nullptr) {
            printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
        }
        // Free the loaded SDL_Surface since its data is now stored in the SDL_Texture
        SDL_FreeSurface(loadedSurface);
    }
    return newTexture;
}


void GameObject::render(bool DimRendering) {
    if(DimRendering)
    {
        SDL_SetTextureColorMod(sprite->texture ,120,120,120);
        SDL_RenderCopy(sprite->renderer,sprite->texture, &sprite->targetTexture, transform->ToScreenPosition());
        SDL_SetTextureColorMod(sprite->texture ,255,255,255);
    }
    else
    {SDL_RenderCopy(sprite->renderer,sprite->texture, &sprite->targetTexture, transform->ToScreenPosition());}
    
}

GameObject::~GameObject()
{
    delete transform;
    delete sprite;
}

//-----------------------Object states---------------------

//------------------------STATES----------------------------

// Non-parameter constructor
ObjectStates::ObjectStates() {
    // Add "idle" state by default
    AddState("idle");
    // Set the current state to "idle"
    TransitToState("idle");
}
//to add a state to the states vector
void ObjectStates::AddState(const std::string& state) {
    states.push_back(state);
}

void ObjectStates::RemoveState(const std::string& state) {
    auto it = std::find(states.begin(), states.end(), state);
    if (it != states.end()) {
        states.erase(it);
    }
}

void ObjectStates::TransitToState(const std::string& newState) {
    if (std::find(states.begin(), states.end(), newState) != states.end()) {
        currentState = newState;
    } else {
        std::cout << "State '" << newState << "' does not exist." << std::endl;
    }
}

const std::string& ObjectStates::GetCurrentState() const {
    return currentState;
}

void ObjectStates::DisplayStates() const {
    std::cout << "Available States: ";
    for (const auto& state : states) {
        std::cout << state << " ";
    }
    std::cout << std::endl;
}
