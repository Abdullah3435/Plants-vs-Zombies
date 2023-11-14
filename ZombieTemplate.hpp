#pragma once

#include "GameObject.hpp"
#include "game.hpp"

class Zombie {
public:
    int movementspeed;
    int health, damage;
    virtual void Move() const = 0;
    virtual Zombie* Clone() = 0;
    virtual ~Zombie() = default;
    virtual void getDamage(int dmg) = 0;

    Zombie();
};

class Simple : public virtual Zombie {
public:
    virtual void Attack() const = 0;
};

class Protected : public virtual Zombie {
public:
    virtual void Defend(int healthboost) = 0;
};

class Utility : public virtual Zombie {
public:
    virtual void SpecialAbility() const = 0;
};

template <typename... BaseClass>
class ZombieTemplate : public GameObject, public BaseClass... {
public:
    ZombieTemplate(int x, int y);
};
