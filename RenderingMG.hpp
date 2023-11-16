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
  void createObject(int x, int y, SDL_Renderer* renderer, Textures* assets);
  void AddObjectforRendering(GameObject* obj);

};