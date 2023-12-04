#pragma once
#include <iostream>
#include "GameObject.hpp"


class Zombie {
public:
    std::string State;
    int movementspeed;
    int health, damage;
    virtual void Move() const = 0;
    virtual Zombie* Clone(int x , int y) = 0;
    virtual ~Zombie() = default;
    virtual void getDamage(int dmg) = 0;
    Utilities DeathDelay, EatDelay;

    Zombie();
    void UpdateState(std::string state);
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
