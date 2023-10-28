#include <iostream>
#include "HUMania.hpp"
#include <vector>
using namespace std;

// Unit pigeon = {{0, 0, 158, 126}, {30, 40, 50, 50}};
// First rectangle is srcRect, second is moverRect
// These values are taken from the corresponding image in assets file
// Use spritecow.com to find exact values of other asset images

vector<Unit> pigeons;
vector<Unit> bees;
vector<Unit> butterflies;
static int state =  0;
void drawObjects(SDL_Renderer *gRenderer, SDL_Texture *assets)
{

    // This function is drawing one pigeon only right now
    // SDL_RenderCopy(gRenderer, assets, &pigeon.srcRect, &pigeon.moverRect);

    // TODO: Write code to iterate over all the vectors and draw objects here:

    
    for (int i = 0; i < pigeons.size(); i++)
    {
        SDL_RenderCopy(gRenderer, assets, &pigeons[i].srcRect, &pigeons[i].moverRect);
        pigeons[i].moverRect.x += 2;

        if (state == 0)
        {
            pigeons[i].srcRect = {0, 237, 153, 84};
            
        }
        else if (state == 1 )
        {
            pigeons[i].srcRect = {2, 361, 159, 124};
            
        }
        else if(state == 2)
        {
            pigeons[i].srcRect = {7, 88, 155, 103};
            
        }

        

        if (pigeons[i].moverRect.x > 1000)
        {
            pigeons[i].moverRect.x = 0;
        }
    }

    for (int i = 0; i < bees.size(); i++)
    {
        SDL_RenderCopy(gRenderer, assets, &bees[i].srcRect, &bees[i].moverRect);
        bees[i].moverRect.x += 2;

        if (state == 0)
        {
            bees[i].srcRect = {527, 253, 194, 115};
        }
        else if (state == 1)
        {
            bees[i].srcRect = {540, 370, 193,115}; 
        }
        else if (state == 2)
        {
            bees[i].srcRect = {527, 138, 194, 115}; 
        }

        if (bees[i].moverRect.x > 1000)
        {
            bees[i].moverRect.x = 0;
        }
    }
    for (int i = 0; i < butterflies.size(); i++)
    {
        SDL_RenderCopy(gRenderer, assets, &butterflies[i].srcRect, &butterflies[i].moverRect);
        butterflies[i].moverRect.x += 2;
        
        if (state == 0)
        {
            butterflies[i].srcRect = {257, 182, 192, 214}; 
        }
        else if (state == 1)
        {
            butterflies[i].srcRect = {248, 432, 248, 179}; 
        }
        else if (state == 2)
        {
            butterflies[i].srcRect = {257, 24, 173, 134};
        }

        if (butterflies[i].moverRect.x > 1000)
        {
            butterflies[i].moverRect.x = 0;
        }
    }

    if (state == 0) //states for all my objects made synchronised yet
    {
        state = 1;
        
    }
    else if (state == 1 )
    {
        state = 2;
        
    }
    else if(state == 2)
    {
        state = 0;
        
    }
    std::cout<<state;

    

    
}

void createObject(int x, int y)
{

    // TODO: create an object randomly and push it into the corresponding vector
    std::cout << "Mouse clicked at: " << x << " -- " << y << std::endl;
    int random = rand() % 3;
    switch (random)
    {
    case 0:
        pigeons.push_back({{7, 88, 155, 103}, {x, y, 50, 50}});
        break;
    case 1:
        bees.push_back({{527, 138, 194, 115}, {x, y, 50, 50}});
        break;
    case 2:
        butterflies.push_back({{257, 24, 173, 134}, {x, y, 50, 50}});
        break;

    default:
        break;
    }
}