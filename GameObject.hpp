#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include "Transform.hpp"
#include "Sprite.hpp"
#include <iostream>
#include "Animation.hpp"
#include "Utilities.hpp"
class Collider
{
    private:
    int width;
    int height;

    public: 
    Collider(int Width, int Height);
    //SDL_Rect for the collider based on position
    SDL_Rect getCollider(int pos_x,int pos_y);
};

class GameObject {
private:
    Collider* _collider;

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

    SDL_Texture* loadTexture(std::string path);// Method to load a texture from a file path

    void setCollider(int width, int height);
    SDL_Rect getCollider();

    // Virtual method to be overridden for updating the GameObject
    virtual void Update();
    void render(bool DimRendering = false);

    ~GameObject();

};


//----------------------------------Object States----------------------------------------

class ObjectStates {
private:
    std::vector<std::string> states; // Vector to store states
    std::string currentState;

public:
    // Parameterized constructor
    ObjectStates();

    // Other member functions...

    void AddState(const std::string& state);
    void RemoveState(const std::string& state);
    void TransitToState(const std::string& newState);
    const std::string& GetCurrentState() const;
    void DisplayStates() const;
};