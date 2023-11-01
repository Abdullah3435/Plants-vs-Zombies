#include <SDL.h>
#include <SDL_image.h>
#include "Animation.cpp"
#include <iostream>
#include "HUmania.hpp"

using namespace std;

class Transform
{
    public:
    int x,y;
    int zrot;

    Transform(int _x = 0, int _y = 0)
    {
        x = _x;
        y = _y;
        zrot = 0; 
    
    }
    SDL_Rect* ToScreenPosition()
    {
        SDL_Rect* screenpos = new SDL_Rect{x,y,50,50};
        return screenpos;
    }

    void translate(int _x = 0,int _y = 0)
    {
        x += _x;
        y += _y;
    }
};

class GameObject
{
    public:
        Transform* transform ;
        SDL_Texture* Texture ;
        SDL_Rect* Target_Tex ;
        SDL_Renderer* gRenderer ;

    public:
        
        GameObject(int x ,int y,string Tex_path,SDL_Renderer* sourcerenderer)
        {
            transform = new Transform(x,y);
            Texture = loadTexture(Tex_path);
            Target_Tex = new SDL_Rect{0,0,100,100};
            gRenderer = sourcerenderer;
        }
        Transform* Getposition()
        {
            return transform;
        }

        SDL_Texture* loadTexture( std::string path )
        {
        //The final texture
        SDL_Texture* newTexture = NULL;

        //Load image at specified path
        SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
        if( loadedSurface == NULL )
        {
            printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
        }
        else
        {
            //Create texture from surface pixels
            newTexture = SDL_CreateTextureFromSurface( gRenderer, loadedSurface );
            if( newTexture == NULL )
            {
                printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
            }

            //Get rid of old loaded surface
            SDL_FreeSurface( loadedSurface );
        }

        return newTexture;
        }
};
