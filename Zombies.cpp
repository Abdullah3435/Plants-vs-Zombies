#include "Zombies.hpp"  // Include the header file that declares all the classes

SimpleZombie::SimpleZombie(int x, int y) :ZombieTemplate<Simple>(x, y){}

void SimpleZombie::Update() {
    Move();
}

void SimpleZombie::Move() const {
    transform->translate(-1 * movementspeed);
    // Implementation for moving
}

void SimpleZombie::getDamage(int dmg) {
    health -= dmg;
}

Zombie* SimpleZombie::Clone() {
    Game* game = Game::getInstance();
    SimpleZombie* sz = new SimpleZombie(*this);
    sz->SetSprite(game->assets.plant_tex, game->gRenderer);
    RenderingMG::getInstance()->myObjs.push_back(sz);
    return sz;
}

void SimpleZombie::Attack() const {
    // Implementation for attacking
}

DefensiveZombie::DefensiveZombie(int x, int y) : ZombieTemplate<Simple, Protected>(x, y) {}

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

Zombie* DefensiveZombie::Clone() {
    return new DefensiveZombie(*this);
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

Zombie* UtilityZombie::Clone() {
    return new UtilityZombie(*this);
}

SuperZombie::SuperZombie(int x, int y) : ZombieTemplate<Simple, Protected, Utility>(x, y) {}

void SuperZombie::Move() const {
    transform->translate(-1 * movementspeed);
    // Implementation for moving
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

Zombie* SuperZombie::Clone() {
    return new SuperZombie(*this);
}

void SuperZombie::Attack() const {
    // Implementation for attacking
}