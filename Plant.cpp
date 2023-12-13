#include "Plant.hpp"
#include "game.hpp"
#include "AudioMG.hpp"
//Projectile::Projectile(int x, int y, int damage) : GameObject(x, y), Damage(damage) {
    // Damage = 100;  // No need for this line; damage is initialized in the member initializer list
//}
void Seed::OnClick()
{
    std::cout<<"Seed Clicked\n";
    Game::getInstance()->SetSeedIndex(SeedIndex);
}

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
void Seed::Update()
{
    if(currenttime>=refreshtime)
    {
        ready = true;
        isInteractable = true;
    }

    currenttime++;
    GameObject::Update();
}

bool Seed::Use()
{
    if(ready)
    {
        currenttime = 0;
        ready = false;
        isInteractable = false;
        return true;
    }
    
    else
    {std::cout<<"The plant is not ready\n";return false;} 
}

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

void Projectile::movement()
{
    transform->translate(1*speed);
}

void Projectile::Update()
{
    GameObject::Update();
    movement();

    if(utilities.Delay(5000))
    {
        Game::getInstance()->DumpGarbage(this);
        delete this;
    }
}

// Plant.cpp
#include "Plant.hpp"

Plant::Plant(int x, int y,int _hp) : GameObject(x, y), hp(_hp),Plantanim(nullptr){
    setCollider(50,50);
    _shooter = false;
    _sunshooter = false;
    // Initialization of Plant class members
}

void Plant::shoot() {
    Projectile* proh = new Projectile(transform->x+45,transform->y-25,100);
    CollisionMG::getInstance()->AddProjectile(proh);
    proh->SetSprite(Game::getInstance()->assets.Pea,Game::getInstance()->gRenderer,28,28);
    RenderingMG::getInstance()->AddObjectforRendering(proh);
    proh->speed = 10; //set shoot speed
    proh->transform->x_sc =0.35;
    proh->transform->y_sc =0.35;
    //std::cout<<"Projectile created right";
    // Implementation of shoot function
    // You can create a Projectile and shoot it at a Zombie, for example
}
void Plant::Update()
{
    GameObject::Update();

    if(utilities.Delay(2000))
    {
        if(_shooter)
        {
            shoot();
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
// You need to include the necessary headers and provide the implementation for Zombie,
// GameObject, Projectile, and Plant in separate header and cpp files.

//---------------------------extra plants--------------------------------
void Bombplant::Update()
{
    GameObject::Update();
    if (Plantanim)
    {
    Plantanim->PlayAnimation();
    }
    if (utilities.Delay(Blasttime))
    {
        SDL_Rect blastaura{transform->x-150,transform->y-150,300,300};
        for (int i = 0 ;i<CollisionMG::getInstance()->Zombies.size();i++) 
        {
            if(CollisionMG::getInstance()->Zombies[i])
            {
                if(CollisionMG::getInstance()->isCollision(CollisionMG::getInstance()->Zombies[i]->getCollider(),blastaura))
                {
                    dynamic_cast<Zombie*>(CollisionMG::getInstance()->Zombies[i])->getDamage(2000);
                }
            }
        }
        Game::getInstance()->DumpGarbage(this);
        delete this;
    }

    
}

Bombplant::Bombplant(int x, int y , int hp, int blasttime):Plant(x,y,hp)
{
    Blasttime=blasttime;
}






//=======================SomeButton=============================


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

void Button::OnClick(){
    if (ButtonName == "Restart")
    {
        // Do Something
        Game::getInstance()->EndGame();
        Game::getInstance()->StartGame();
    }

    else if (ButtonName == "NextLevel")
    {
        // Do Something
        Game::getInstance()->EndGame();
        Game::getInstance()->StartGame();
    }

    else if (ButtonName == "End")
    {
        // Do Something
        
    }

    else {std::cout << "Game Event for such name not found";}
};
