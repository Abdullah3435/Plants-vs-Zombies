#include "Plant.hpp"
#include "game.hpp"
//Projectile::Projectile(int x, int y, int damage) : GameObject(x, y), Damage(damage) {
    // Damage = 100;  // No need for this line; damage is initialized in the member initializer list
//}
void Seed::OnClick()
{
    //plantmg->selectedindex = SeedIndex;
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

void Projectile::giveDamage(Zombie* zombie) {
    zombie->getDamage(Damage);
    Game::getInstance()->DumpGarbage(this);
    delete this;
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

    if(utilities.Delay(1500))
    {
        Game::getInstance()->DumpGarbage(this);
        delete this;
    }
}

// Plant.cpp
#include "Plant.hpp"

Plant::Plant(int x, int y,int _hp) : GameObject(x, y), hp(_hp) {
    // Initialization of Plant class members
}

void Plant::shoot() {
    Projectile* proh = new Projectile(transform->x,transform->y,100);
    CollisionMG::getInstance()->AddProjectile(proh);
    proh->SetSprite(Game::getInstance()->assets.Pea,Game::getInstance()->gRenderer,28,28);
    RenderingMG::getInstance()->AddObjectforRendering(proh);
    proh->speed = 10;
    proh->transform->x_sc =0.5;
    proh->transform->y_sc =0.5;
    //std::cout<<"Projectile created right";
    // Implementation of shoot function
    // You can create a Projectile and shoot it at a Zombie, for example
}
void Plant::Update()
{
    std::cout<<"Ensure This is called once bw frame";
    GameObject::Update();
    std::cout<< "THIS IS THE TARGET DELAY\n";
    if(utilities.Delay(100))
    {
        shoot();
        //std::cout<<"SHOOOTED PROJ";
    }
    std::cout<< "TARGET DELAY END\n";
}

// You need to include the necessary headers and provide the implementation for Zombie,
// GameObject, Projectile, and Plant in separate header and cpp files.