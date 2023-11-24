#pragma once

#include <SDL.h>
#include "GameObject.hpp"
#include <iostream>
#include "TextureMG.cpp"
#include <vector>

class RenderingMG {
private:
  static RenderingMG* instance;
  SDL_Renderer* renderer;
  Textures* assets;


  RenderingMG();
  RenderingMG(const RenderingMG& other) = delete;
  RenderingMG& operator=(const RenderingMG& other) = delete;
  

public:
  vector<GameObject*>myObjs;
  static RenderingMG* getInstance();
  void drawObjects(SDL_Renderer* gRnderer, Textures* assets);
  void createObject(int x, int y, SDL_Renderer* renderer, Textures* assets, Grid& myGrid);
  void AddObjectforRendering(GameObject* obj);

};


class CollisionMG {
private:
    // Private constructor to prevent instantiation
    CollisionMG() {}

    // Static instance of the class
    static CollisionMG* instance;
    
public:
    // Private member variables
    std::vector<GameObject*> Plants;
    std::vector<GameObject*> Projectiles;
    std::vector<GameObject*> Zombies;


    // Public methods
    static CollisionMG* getInstance();

    void AddPlant(GameObject* plant);
    void AddProjectile(GameObject* projectile);
    void AddZombie(GameObject* zombie);

    void CollisionEventLoop();
    void Zombiewithprojectile();
    void PlantwithZombie();
    bool isCollision(const SDL_Rect& rectA, const SDL_Rect& rectB);
    void RemoveGameObject(GameObject* gameObject);
    
};

