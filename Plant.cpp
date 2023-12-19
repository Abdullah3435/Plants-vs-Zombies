#include "Plant.hpp"
#include "game.hpp"
#include "AudioMG.hpp"
// Function called when the seed is clicked
void Seed::OnClick()
{
    std::cout<<"Seed Clicked\n";
    Game::getInstance()->SetSeedIndex(SeedIndex);
}
// Function to check if a point (x, y) is within the seed's clickable area
bool Seed::CheckClick(int x, int y)
{
    SDL_Rect* rect = transform->ToScreenPosition();
    if (x < rect->x ||                   // Point is to the left of the rect
        x >= rect->x + rect->w ||         // Point is to the right of the rect
        y < rect->y ||                   // Point is above the rect
        y >= rect->y + rect->h)           // Point is below the rect
    {
        return false;
    }

    // If none of the above conditions are met, there is an overlap
    return true;
}
// Function to update the seed's state
void Seed::Update()
{
    // Check if it's time to refresh
    if(myDelay.Delay(refreshtime))
    {
        ready = true;
        isInteractable = true;
    }
    // Update the seed object if it is ready
    if(ready)
    {
        GameObject::Update();
    }
    else 
    {
        std::cout<<"Calling From here";
        render(true);
    }
}
// Function to use the seed
bool Seed::Use()
{
    if(ready&&cost<=Game::getInstance()->_resourcemg.getResources())
    {
        // Subtract the cost from resources and reset the seed state
        Game::getInstance()->_resourcemg.subtractResource(cost);
        currenttime = 0;
        ready = false;
        isInteractable = false;
        myDelay.resettime();
        return true;
    }
    
    else
    {std::cout<<"The plant is not ready\n";return false;} 
}

// Function to give damage to a zombie from the projectile
void Projectile::giveDamage(Zombie* zombie) {
    zombie->getDamage(Damage);
    AudioManager::getInstance()->playSound("hit");
    Game::getInstance()->DumpGarbage(this);
    delete this;
    std::cout<<"Damage given\n";
    std::cout<<"new health is : "<<zombie->health<<std::endl;
}

Projectile::~Projectile() {
    // Destructor implementation (if needed)
}

// Function to handle the movement of the projectile
void Projectile::movement()
{
    transform->translate(1*speed);
}

void Projectile::Update()
{
    GameObject::Update();
    movement();

    // Check if it's time to remove the projectile
    if(utilities.Delay(5000))
    {
        Game::getInstance()->DumpGarbage(this);
        delete this;
    }
}

// Plant.cpp
#include "Plant.hpp"

// Constructor 
Plant::Plant(int x, int y,int _hp) : GameObject(x, y), hp(_hp),Plantanim(nullptr){
    setCollider(50,50);
    _shooter = false;
    _sunshooter = false;
    // Initialization of Plant class members
}

// Function to make the plant shoot a projectile
void Plant::shoot() {
    Projectile* proh = new Projectile(transform->x+45,transform->y-25,100);
    CollisionMG::getInstance()->AddProjectile(proh);
    proh->SetSprite(Game::getInstance()->assets.Pea,Game::getInstance()->gRenderer,28,28);
    RenderingMG::getInstance()->AddObjectforRendering(proh);
    proh->speed = 10; //set shoot speed
    proh->transform->x_sc =0.35;
    proh->transform->y_sc =0.35;
    // Implementation of shoot function
    // You can create a Projectile and shoot it at a Zombie, for example
}
void Plant::Update()
{
    GameObject::Update();

    if(utilities.Delay(shootdelay))
    {
        if(_shooter)
        {
            shoot();
        }
        if(_sunshooter)
        {
            new Sun(transform->x+30,transform->y+30);
        }
        //std::cout<<"SHOOOTED PROJ";
    }
    if (Plantanim)
    {
    Plantanim->PlayAnimation();
    }

    if(hp<0)
    {
        Game::getInstance()->DumpGarbage(this);
        delete this;
    }
}

bool Plant::getDamage(int dmg)
{
    hp -= dmg;
    if(hp<0)
    {
        return true;// have to fix this as it notifies only the last zombie bite
    }
    return false;
}
Plant::~Plant()
{
    Game::getInstance()->LeaveGridBlock(this);
}
// You need to include the necessary headers and provide the implementation for Zombie,
// GameObject, Projectile, and Plant in separate header and cpp files.

//---------------------------extra plants--------------------------------
void Bombplant::Update()
{
    GameObject::Update();
    // Play the plant animation if available
    if (Plantanim)
    {
    Plantanim->PlayAnimation();
    }
    // Check if it's time for the bomb to explode
    if (utilities.Delay(Blasttime))
    {   
        // Define a rectangular area for the blast aura
        SDL_Rect blastaura{transform->x-150,transform->y-150,300,300};
        // Iterate through all zombies to check for collision with the blast aura
        for (int i = 0 ;i<CollisionMG::getInstance()->Zombies.size();i++) 
        {
            if(CollisionMG::getInstance()->Zombies[i])
            {
                // Check if the zombie collides with the blast aura
                if(CollisionMG::getInstance()->isCollision(CollisionMG::getInstance()->Zombies[i]->getCollider(),blastaura))
                {
                    // Apply damage to the zombie
                    dynamic_cast<Zombie*>(CollisionMG::getInstance()->Zombies[i])->getDamage(2000);
                }
            }
        }
        // Remove the bombplant from the game and free memory
        Game::getInstance()->DumpGarbage(this);
        delete this;
    }

    
}

// Constructor for the Bombplant
Bombplant::Bombplant(int x, int y , int hp, int blasttime):Plant(x,y,hp)
{
    Blasttime=blasttime;
}


void Potatomine::Update()
{
    GameObject::Update();
    // Check if the Potatomine is not ready and has waited for 3000 milliseconds
    if(!isReady&&utilities.Delay(3000))
    {
        isReady = true;
    }
    // If Potatomine is ready
    if (isReady)
    {
        if (Plantanim)
        {
        sprite=Plantanim->PlayAnimation();
        std::cout<<"trying to switch anim";
        }

        // Define a blast aura rectangle around the Potatomine
        SDL_Rect blastaura{transform->x-70,transform->y-15,140,30};
        // Iterate through Zombies and check for collision with the blast aura
        for (int i = 0 ;i<CollisionMG::getInstance()->Zombies.size();i++) 
        {
            if(CollisionMG::getInstance()->Zombies[i])
            {
                if(CollisionMG::getInstance()->isCollision(CollisionMG::getInstance()->Zombies[i]->getCollider(),blastaura))
                {
                    dynamic_cast<Zombie*>(CollisionMG::getInstance()->Zombies[i])->getDamage(3000);
                    Game::getInstance()->DumpGarbage(this);
                    delete this;
                    return;
                }
            }
        }
        
    }
    // If Potatomine's health is less than 0, remove it from the game
    if(gethp()<0)
    {
        Game::getInstance()->DumpGarbage(this);
        delete this;
    }
    
}

// Constructor
Potatomine::Potatomine(int x, int y , int hp, int readytine):Plant(x,y,hp)
{
    readyTime=readytine;
    SetSprite(Game::getInstance()->assets.unreadymine,Game::getInstance()->gRenderer,97,79);
}

//=======================SomeButton=============================

// Check if a point (x, y) is within the boundaries of the Button's rectangle
bool Button::CheckClick(int x,int y){
    SDL_Rect* rect = transform->ToScreenPosition();
    if (x < rect->x ||                   // Point is to the left of the rect
        x >= rect->x + rect->w ||         // Point is to the right of the rect
        y < rect->y ||                   // Point is above the rect
        y >= rect->y + rect->h)           // Point is below the rect
    {
        return false;
    }

    // If none of the above conditions are met, there is an overlap
    return true;
};

void Button::Update(){GameObject::Update();}

// OnClick function to handle button click events
void Button::OnClick(){
    if (ButtonName == "Restart")
    {
        // Do Something
        Game::getInstance()->EndGame();
        Game::getInstance()->StartGame();
    }

    else if (ButtonName == "NextLevel")
    {
        Game::getInstance()->Updatelevel();
        // Do Something
        Game::getInstance()->EndGame();
        Game::getInstance()->StartGame();
    }

    else if (ButtonName == "End")
    {
        // Do Something
        Game::getInstance()->quitgame();
        
    }
    else {std::cout << "Game Event for such name not found";}
    
};
