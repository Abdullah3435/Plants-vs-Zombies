#include "Zombies.hpp"  // Include the header file that declares all the classes
#include "game.hpp"
SimpleZombie::SimpleZombie(int x, int y) :ZombieTemplate<Simple>(x, y){}

void SimpleZombie::Update() {
    GameObject::Update();
    
    if(utilities.Delay(10))
    {
        Move();
    }
    if (health<0)
    {
        Game::getInstance()->DumpGarbage(this);
        delete this;
    }
}

void SimpleZombie::Move() const {
    transform->translate(-1 * movementspeed);
    // Implementation for moving
}

void SimpleZombie::getDamage(int dmg) {
    health -= dmg;
}

Zombie* SimpleZombie::Clone(int x , int y) {
    Game* game = Game::getInstance();
    SimpleZombie* sz = new SimpleZombie(*this);
    sz->sprite = new Sprite(*this->sprite);
    sz->transform = new Transform (*this->transform);
    RenderingMG::getInstance()->myObjs.push_back(sz);
    sz->transform->x = x;
    CollisionMG::getInstance()->AddZombie(sz);
    std::cout<<"THE HEALTH OF THE CLONE IS :"<<health<<std::endl;
    sz->transform->y = y;
    return sz;
}

void SimpleZombie::Attack() const {
    // Implementation for attacking
}

DefensiveZombie::DefensiveZombie(int x, int y) : ZombieTemplate<Simple, Protected>(x, y){}

void DefensiveZombie::Update(){
    GameObject::Update();
    Move();
    if (health<0)
    {
        Game::getInstance()->DumpGarbage(this);
        delete this;
    }
}

void DefensiveZombie::Move() const {
    transform->translate(-1 * movementspeed);
    // Implementation for moving
}

void DefensiveZombie::Defend(int healthboost) {
    health += healthboost;
    // Implementation for defending
}

void DefensiveZombie::getDamage(int dmg) {
    health -= dmg;
}

Zombie* DefensiveZombie::Clone(int x , int y) {
    Game* game = Game::getInstance();
    DefensiveZombie* sz = new DefensiveZombie(*this);
    sz->sprite = new Sprite(*this->sprite);
    sz->transform = new Transform (*this->transform);
    RenderingMG::getInstance()->myObjs.push_back(sz);
    sz->transform->x = x;
    CollisionMG::getInstance()->AddZombie(sz);
        std::cout<<"THE HEALTH OF THE CLONE IS :"<<health<<std::endl;
    sz->transform->y = y;
    return sz;
    
}

void DefensiveZombie::Attack() const {
    // Implementation for attacking
}

UtilityZombie::UtilityZombie(int x, int y) : ZombieTemplate<Simple, Utility>(x, y) {}

void UtilityZombie::Move() const {
    transform->translate(-1 * movementspeed);
    // Implementation for moving
}

void UtilityZombie::getDamage(int dmg) {
    health -= dmg;
}

void UtilityZombie::SpecialAbility() const {
    // Implementation for special ability
}

void UtilityZombie::Attack() const {
    // Implementation for attacking
}

Zombie* UtilityZombie::Clone(int x , int y) {
    return new UtilityZombie(*this);
}

SuperZombie::SuperZombie(int x, int y) : ZombieTemplate<Simple, Protected, Utility>(x, y) {}

void SuperZombie::Move() const {
    transform->translate(-1 * movementspeed);
    // Implementation for moving
}

void SuperZombie::Update()
{
    GameObject::Update();
    Move();
    if (health<0)
    {
        Game::getInstance()->DumpGarbage(this);
        delete this;
    }
}
void SuperZombie::Defend(int healthboost) {
    // Implementation for defending
    health += healthboost;
}

void SuperZombie::SpecialAbility() const {
    // Implementation for special ability
}

void SuperZombie::getDamage(int dmg) {
    health -= dmg;
}

Zombie* SuperZombie::Clone(int x , int y) {
    Game* game = Game::getInstance();
    SuperZombie* sz = new SuperZombie(*this);
    sz->sprite = new Sprite(*this->sprite);
    sz->transform = new Transform (*this->transform);
    RenderingMG::getInstance()->myObjs.push_back(sz);
    sz->transform->x = x;
    CollisionMG::getInstance()->AddZombie(sz);
        std::cout<<"THE HEALTH OF THE CLONE IS :"<<health<<std::endl;
    sz->transform->y = y;
    return sz;
}

void SuperZombie::Attack() const {
    // Implementation for attacking
}

SimpleZombie::~SimpleZombie(){};
SuperZombie::~SuperZombie(){};
UtilityZombie::~UtilityZombie(){};
DefensiveZombie::~DefensiveZombie(){};



