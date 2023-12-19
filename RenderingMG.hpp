#pragma once
#include<SDL_ttf.h>
#include <SDL.h>
#include "GameObject.hpp"
#include <iostream>
#include "TextureMG.cpp"
#include "PlantMG.hpp"
#include <vector>
#include <SDL_ttf.h>

class Clickable;//declaration of Clickable class

// Singleton class for managing rendering
class RenderingMG {
private:
  static RenderingMG* instance;// Singleton instance
  SDL_Renderer* renderer; // SDL renderer
  Textures* assets;// Texture assets
  


  RenderingMG(); // Private constructor for singleton pattern
  RenderingMG(const RenderingMG& other) = delete;
  RenderingMG& operator=(const RenderingMG& other) = delete;
  

public:
  PlantManager* PMscript;// injectable dependency for planting commands (a bit risky could possibly lead to issues just make sure that the memory is not initialized or deleted randomly)
  vector<GameObject*>myObjs;// Vector to store game objects
  static RenderingMG* getInstance();// Function to access the singleton instance
  void drawObjects(SDL_Renderer* gRnderer, Textures* assets);// Draw all game objects
  void createObject(int x, int y, SDL_Renderer* renderer, Textures* assets, Grid& myGrid);  // Create a new game object
  void AddObjectforRendering(GameObject* obj);// Add a game object for rendering
  void ClearVector();// Clear the vector of game objects
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

    // Main collision event loop
    void CollisionEventLoop();
    void Zombiewithprojectile();
    void PlantwithZombie();
    bool isCollision(const SDL_Rect& rectA, const SDL_Rect& rectB);
    void RemoveGameObject(GameObject* gameObject);
    void CheckClicks(int x, int y);
    void ClearVector();// Clear all vectors
    
};


//-------------------------------Clickable-------------------------------
class Clickable
{
  public:
  bool isInteractable;
  virtual void OnClick() = 0;// Virtual function to handle click events
  virtual bool CheckClick(int x, int y)=0;// Virtual function to check if the object is clicked
  Clickable();
};






//------------------------------TextRendering-----------------------------------
class TextRenderer {
private:
    static TextRenderer* instance;
    TTF_Font* font;// SDL TrueType font
    SDL_Color textColor;  // Color of the rendered text
    TextRenderer();
public:
    static TextRenderer* getInstance();// Function to access the singleton instance
    ~TextRenderer();// Destructor
    void renderText(SDL_Renderer* renderer, const std::string& text, int x, int y);//render text on screen
};