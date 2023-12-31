#include "RenderingMG.hpp"
#include "game.hpp"
#include "Plant.hpp"


using namespace std;

static int state = 0;

RenderingMG* RenderingMG::instance = nullptr;

//to draw objects on the renderer
void RenderingMG::drawObjects(SDL_Renderer* gRenderer, Textures* assets) {
    for (int i = 0; i < myObjs.size(); i++) {
    if(myObjs[i])
    {
       myObjs[i]->Update();}
    }
}

void RenderingMG::AddObjectforRendering(GameObject* obj)
{
    myObjs.push_back(obj);
}

RenderingMG::RenderingMG(){};

// Method to get an instance of the RenderingMG class (singleton pattern)
RenderingMG* RenderingMG::getInstance()
{
    if(instance == nullptr)
    {
        instance = new RenderingMG();
    }
    return instance;
}

//to create a game object at a specific position on the grid
void RenderingMG::createObject(int x, int y, SDL_Renderer* renderer, Textures *assets, Grid& myGrid) {
    std::cout << "Mouse clicked at: " << x << " -- " << y << std::endl;

    // Check if the click is within the grid boundaries
    if (x >= myGrid.xOffset && x < myGrid.width + myGrid.xOffset &&
        y >= myGrid.yOffset && y < myGrid.height + myGrid.yOffset) {

        // Calculate the grid index based on mouse coordinates
        int gridIndex = myGrid.calculateIndex(x, y);

        // Get the adjusted x and y coordinates for the center of the grid block
        auto coordinates = myGrid.getCoordinates(gridIndex / myGrid.cols, gridIndex % myGrid.cols);
        int gridX = coordinates.first;
        int gridY = coordinates.second;

        // Check if the block at the calculated grid index is occupied
        if (!myGrid.isOccupied(gridX, gridY)) {
            // Check if a plant is selected in the PlantManager script
            if(PMscript->selectedplant)
            {
                // Check if the selected plant can be used
                if(PMscript->selectedplant->Use())
                {
                    PMscript->createPlant(gridX, gridY);
                    PMscript->selectedplant = nullptr;
                    PMscript->selectedindex =-1; //after using make no the seed to not be used again easily
                     // Mark the block as occupied in the grid
                    myGrid.occupyBlock(gridX, gridY);
                }
            }
            
        } else {
            // Handle case where the block is already occupied (optional)
            std::cout << "Block at (" << gridX << ", " << gridY << ") is already occupied." << std::endl;
        }
    } else {
        // Handle case where the click is outside the grid boundaries (optional)
        std::cout << "Click outside the grid boundaries." << std::endl;
    }
}

void RenderingMG::ClearVector()
{
    myObjs.clear();
}
//==========================================CollisionMG=============================================

//to add a plant GameObject to the Plants vector
void CollisionMG::AddPlant(GameObject* plant)
{
    Plants.push_back(plant);
}

void CollisionMG::AddProjectile(GameObject* proj)
{
    Projectiles.push_back(proj);
}
void CollisionMG::AddZombie(GameObject* zombie)
{
    Zombies.push_back(zombie);
}
// Main collision event loop, checking for collisions between Plants and Zombies, as well as Zombies and Projectiles
void CollisionMG::CollisionEventLoop()
{   
    // Check for collisions between Zombies and Plants
    for (int z = 0; z < Zombies.size(); z++) 
    {
       for (int p = 0; p < Plants.size(); p++) 
        {
            if(Zombies[z]&&Plants[p])
            {
                Zombie* currentzomb = dynamic_cast<Zombie*>(Zombies[z]); //dynamic casting at runtime
                Plant* currentplant = dynamic_cast<Plant*>(Plants[p]);
                if(isCollision(Zombies[z]->getCollider(),Plants[p]->getCollider()))
                {
                    std::cout<<"Collision Occured Here plant and zombie";
                    currentplant->getDamage(currentzomb->damage);
                    currentzomb->UpdateState ("Eat");
                    
                    //Implement Zombie and plant Logic here
                }
                else
                {
                    currentzomb->UpdateState ("Idle");
                }
            }
        }
    }
    // Check for collisions between Zombies and Projectiles
    for (int z = 0; z < Zombies.size(); z++) 
    {
       for (int p = 0; p < Projectiles.size(); p++) 
        {
            if(Zombies[z]&&Projectiles[p])
            {
            if(isCollision(Zombies[z]->getCollider(),Projectiles[p]->getCollider()))
            {
                std::cout<<"Collision Occured Here zombie and projectile";

                // Dynamic casting to access specific methods of Zombie and Projectile
                Zombie* currentzomb = dynamic_cast<Zombie*>(Zombies[z]); //dynamic casting at runtime
                Projectile* currentproj = dynamic_cast<Projectile*>(Projectiles[p]);

                // Apply damage to the Zombie using the Projectile
                currentproj->giveDamage(currentzomb);
                //Implement Zombie and plant Logic here
            }
            }
        }
    }
}
// to check for clicks on Collectible GameObjects
void CollisionMG::CheckClicks(int x, int y)
{
    for (int i =0 ; i < Collectibles.size();i++)
    {
        if(Collectibles[i])
        {
            // Check if the click is within the bounds of the Collectible
            if(Collectibles[i]->CheckClick(x,y))
            {
                Collectibles[i]->OnClick();
            }
        }
    }
}

CollisionMG* CollisionMG::instance = nullptr;

// Singleton pattern: Get an instance of the CollisionMG class
CollisionMG* CollisionMG::getInstance() {
    if (!instance) {
        instance = new CollisionMG();
    }
    return instance;
}

//to check if there is a collision between two SDL_Rectangles
bool CollisionMG::isCollision(const SDL_Rect& rectA, const SDL_Rect& rectB)
{
    // Check for no overlap
    if (rectA.x + rectA.w <= rectB.x || // rectA is to the left of rectB
        rectB.x + rectB.w <= rectA.x || // rectA is to the right of rectB
        rectA.y + rectA.h <= rectB.y || // rectA is above rectB
        rectB.y + rectB.h <= rectA.y)   // rectA is below rectB
    {
        return false;
    }

    // If none of the above conditions are met, there is an overlap
    return true;
}

void CollisionMG::ClearVector()
{
    Zombies.clear();
    Plants.clear();
    Collectibles.clear();
    Projectiles.clear();
}

//=============================================GarbageCollection==================================================
//to remove a GameObject from various vectors based on its type
void CollisionMG::RemoveGameObject(GameObject* gameObject)
{
    // Iterate through Plants vector
    for (auto& plant : Plants)
    {
        if (plant == gameObject)
        {
            plant = nullptr;
             // No need to continue searching
        }
    }

    // Iterate through Projectiles vector
    for (auto& projectile : Projectiles)
    {
        if (projectile == gameObject)
        {
            projectile = nullptr;
             // No need to continue searching
        }
    }

    // Iterate through Zombies vector
    for (auto& zombie : Zombies)
    {
        if (zombie == gameObject)
        {
            zombie = nullptr;
            // No need to continue searching
        }
    }
    for (auto& collectible : Collectibles)
    {
        if (collectible == dynamic_cast<Clickable*>(gameObject))
        {
            collectible = nullptr;
        
        }
    }
}

// Constructor for the Clickable class
Clickable::Clickable()
{
    // Add the Clickable object to the Collectibles vector in the CollisionMG
    CollisionMG::getInstance()->Collectibles.push_back(this);
}

//----------------------------------------TextMG-------------------------------------------
TextRenderer* TextRenderer::instance = nullptr;
// Constructor for the TextRenderer class
TextRenderer::TextRenderer() {
    if (TTF_Init() == -1) {
        std::cerr << "TTF_Init failed: " << TTF_GetError() << std::endl;
    }
    // Replace "your_font_file.ttf" with the path to your TrueType font file
    font = TTF_OpenFont("Fonts/Portilla.ttf", 24);
    if (!font) {
        std::cerr << "TTF_OpenFont failed: " << TTF_GetError() << std::endl;
    }
    textColor = {255, 255, 255};  // White text color
}
//o get an instance of the TextRenderer class (singleton pattern)
TextRenderer* TextRenderer::getInstance() {
    if (!instance) {
        instance = new TextRenderer();
    }
    return instance;
}
// Destructor for the TextRenderer class
TextRenderer::~TextRenderer() {
    TTF_CloseFont(font);
    TTF_Quit();

}
//to render text on the specified renderer at the given position
void TextRenderer::renderText(SDL_Renderer* renderer, const std::string& text, int x, int y) {
    SDL_Surface* surface = TTF_RenderText_Blended(font, text.c_str(), textColor);
    if (!surface) {
        std::cerr << "TTF_RenderText_Blended failed: " << TTF_GetError() << std::endl;
        return;
    }
    // Create an SDL_Texture from the surface
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    if (!texture) {
        std::cerr << "SDL_CreateTextureFromSurface failed: " << SDL_GetError() << std::endl;
        return;
    }
    // Get the width and height of the rendered text
    int width, height;
    SDL_QueryTexture(texture, NULL, NULL, &width, &height);
    SDL_Rect dstRect = {x, y, width, height};
    // Create a destination rectangle and render the texture
    SDL_RenderCopy(renderer, texture, NULL, &dstRect);
    // Destroy the texture to free up resources
    SDL_DestroyTexture(texture);
}



