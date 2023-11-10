// ZombieTypes.hpp

#pragma once

#include "ZombieTemplate.hpp"

class SimpleZombie : public ZombieTemplate<Simple> {
public:
    SimpleZombie(int x, int y) : ZombieTemplate<Simple>(x, y) {}

    // Implement the pure virtual methods from Simple class
    void Move() const override {
        transform->translate(-1*movementspeed);
        // Implementation for moving
    }
    void getDamage(int dmg)
    {
        health -= dmg;
    };
   
    Zombie* Clone()
    {
        return new SimpleZombie(*this);
    }
    // Implement the pure virtual methods from Zombie class
    void Attack() const override {
        // Implementation for attacking
    }
};

class DefensiveZombie : public ZombieTemplate<Simple, Protected> {
public:
    DefensiveZombie(int x, int y) : ZombieTemplate<Simple, Protected>(x, y) {}

    // Implement the pure virtual methods from Simple and Protected classes
    void Move() const override {
        transform->translate(-1*movementspeed);
        // Implementation for moving
    }

    void Defend(int healthboost) override {
        health += healthboost;
        // Implementation for defending
    }

    void getDamage(int dmg)
    {
        health -= dmg;
    };
    Zombie* Clone()
    {
        return new DefensiveZombie(*this);
    }
    // Implement the pure virtual methods from Zombie class
    void Attack() const override {
        // Implementation for attacking
    }
};

class UtilityZombie : public ZombieTemplate<Simple, Utility> {
public:
    UtilityZombie(int x, int y) : ZombieTemplate<Simple, Utility>(x, y) {}

    // Implement the pure virtual methods from Simple and Utility classes
    void Move() const override {
        transform->translate(-1*movementspeed);

        // Implementation for moving
    }
    void getDamage(int dmg)
    {
        health -= dmg;
    };

    void SpecialAbility() const override {
        // Implementation for special ability
    }

    // Implement the pure virtual methods from Zombie class
    void Attack() const override {
        // Implementation for attacking
    }

    Zombie* Clone()
    {
        return new UtilityZombie(*this);
    }
};

class SuperZombie : public ZombieTemplate<Simple, Protected, Utility> {
public:
    SuperZombie(int x, int y) : ZombieTemplate<Simple, Protected, Utility>(x, y) {}

    // Implement the pure virtual methods from Simple, Protected, and Utility classes
    void Move() const override {
        transform->translate(-1*movementspeed);
        // Implementation for moving
    }

    void Defend(int healthboost) override {
        // Implementation for defending
        health += healthboost;
    }

    void SpecialAbility() const override {
        // Implementation for special ability
    }

    void getDamage(int dmg)
    {
        health -= dmg;
    };

    Zombie* Clone()
    {
        return new SuperZombie(*this);
    }

    // Implement the pure virtual methods from Zombie class
    void Attack() const override {
        // Implementation for attacking
    }
};

