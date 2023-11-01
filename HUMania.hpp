#include<SDL.h>


void drawObjects(SDL_Renderer* gRnderer, SDL_Texture* assets);
void createObject(int x, int y,SDL_Renderer* renderer);

struct Unit{
SDL_Rect srcRect, moverRect;
};