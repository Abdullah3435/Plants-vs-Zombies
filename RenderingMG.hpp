#pragma once
#include<SDL_ttf.h>
#include <SDL.h>
#include "GameObject.hpp"
#include <iostream>
#include "TextureMG.cpp"
#include "PlantMG.hpp"
#include <vector>
#include <SDL_ttf.h>

class Clickable;
class RenderingMG {
private:
  static RenderingMG* instance;
  SDL_Renderer* renderer;
  Textures* assets;
  


  RenderingMG();
  RenderingMG(const RenderingMG& other) = delete;
  RenderingMG& operator=(const RenderingMG& other) = delete;
  

public:
  PlantManager* PMscript;// injectable dependency for planting commands (a bit risky could possibly lead to issues just make sure that the memory is not initialized or deleted randomly)
  vector<GameObject*>myObjs;
  static RenderingMG* getInstance();
  void drawObjects(SDL_Renderer* gRnderer, Textures* assets);
  void createObject(int x, int y, SDL_Renderer* renderer, Textures* assets, Grid& myGrid);
  void AddObjectforRendering(GameObject* obj);
  void ClearVector();

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
    std::vector<Clickable*>Collectibles;
    
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
    void CheckClicks(int x, int y);
    void ClearVector();
    
};


//-------------------------------Clickable-------------------------------
class Clickable
{
  public:
  bool isInteractable;
  virtual void OnClick() = 0;
  virtual bool CheckClick(int x, int y)=0;
  Clickable();
};






//------------------------------TextRendering-----------------------------------
class TextRenderer {
private:
    static TextRenderer* instance;
    TTF_Font* font;
    SDL_Color textColor;
    TextRenderer();
public:
    static TextRenderer* getInstance();
    ~TextRenderer();
    void renderText(SDL_Renderer* renderer, const std::string& text, int x, int y);
};