#include "Plant.hpp"
//Projectile::Projectile(int x, int y, int damage) : GameObject(x, y), Damage(damage) {
    // Damage = 100;  // No need for this line; damage is initialized in the member initializer list
//}

void Projectile::giveDamage(Zombie* zombie) {
    zombie->getDamage(Damage);
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
}

// Plant.cpp
#include "Plant.hpp"

Plant::Plant(int x, int y,int _hp) : GameObject(x, y), hp(_hp) {
    // Initialization of Plant class members
}

void Plant::shoot() {
    Projectile* proh = new Projectile(transform->x,transform->y,100);
    proh->speed = 2;
    // Implementation of shoot function
    // You can create a Projectile and shoot it at a Zombie, for example
}
void Plant::Update()
{
    GameObject::Update();
    if(utilities.Delay(5))
    {
        shoot();
    }
}

// You need to include the necessary headers and provide the implementation for Zombie,
// GameObject, Projectile, and Plant in separate header and cpp files.