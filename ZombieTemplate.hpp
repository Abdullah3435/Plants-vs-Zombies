#pragma once
#include <iostream>
#include "GameObject.hpp"


class Zombie {
public:
    std::string State;  // State of the zombie 
    int movementspeed; // Speed at which the zombie moves
    int health, damage; // Health and damage properties
    virtual void Move() const = 0; // Pure virtual function for moving the zombie
    virtual Zombie* Clone(int x , int y) = 0; // Pure virtual function for cloning the zombie
    virtual ~Zombie() = default;// Virtual destructor to allow proper destruction of derived classes
    virtual void getDamage(int dmg) = 0;// Pure virtual function for receiving damage
    Utilities DeathDelay, EatDelay;// Utility objects for managing delays

    Zombie();
    void UpdateState(std::string state);
};

// Derived class representing a basic zombie with an attack function
class Simple : public virtual Zombie {
public:
    virtual void Attack() const = 0;
};

// Derived class representing a protected zombie with a defense function
class Protected : public virtual Zombie {
public:
    virtual void Defend(int healthboost) = 0;
};

// Derived class representing a utility zombie with a special ability
class Utility : public virtual Zombie {
public:
    virtual void SpecialAbility() const = 0;
};

// Template class combining multiple base classes into a single derived classs
template <typename... BaseClass>
class ZombieTemplate : public GameObject, public BaseClass... {
public:
    ZombieTemplate(int x, int y);
};
