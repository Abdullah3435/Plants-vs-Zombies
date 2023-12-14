#pragma once
#include "ZombieTemplate.hpp"
#include "RenderingMG.hpp"
#include "AudioMG.hpp"
#include "Animation.hpp"
class SimpleZombie : public ZombieTemplate<Simple> {
private:

public:
    // Animations for walking,eating,death
    Animation Walkanim;
    Animation Eatanim;
    Animation Deathanim;
    SimpleZombie(int x, int y);

    void Update() override;

    void Move() const override;// Implementation of the Move function for walking

    void getDamage(int dmg) override;// Implementation of the getDamage function for receiving damage

    Zombie* Clone(int x , int y) override;// Implementation of the Clone function for cloning the zombie

    void Attack() const override; // Implementation of the Attack function for attacking
    void PlayAnim();

    ~SimpleZombie();
};

// Class representing a defensive zombie with both attack and defense capabilities
class DefensiveZombie : public ZombieTemplate<Simple, Protected> {
public:
    // Animation for walking,eating,death
    Animation Walkanim;
    Animation Eatanim;
    Animation Deathanim;
    GameObject* protection; // Protection object associated with the zombie

    DefensiveZombie(int x, int y);

    void Update()override;// Update function for handling zombie behavior

    void Move() const override;

    void Defend(int healthboost) override;

    void getDamage(int dmg) override;

    Zombie* Clone(int x , int y) override;
    
    void Attack() const override;

    void PlayAnim();

    void operator+(GameObject& other);

    ~DefensiveZombie();
};

class UtilityZombie : public ZombieTemplate<Simple, Utility> {
public:
    // Animation for walking,eating,death
    Animation Walkanim;
    Animation Eatanim;
    Animation Deathanim;
    
    UtilityZombie(int x, int y);

    void Move() const override;

    void getDamage(int dmg) override;

    void SpecialAbility() const override;

    Zombie* Clone(int x , int y) override;

    void Attack() const override;
    void PlayAnim();
    
    ~UtilityZombie();
};

class SuperZombie : public ZombieTemplate<Simple, Protected, Utility> {
public:
    SuperZombie(int x, int y);// Constructor for SuperZombie

    void Update()override;

    void Move() const override;

    void Defend(int healthboost) override;// Implementation of the Defend function for defending

    void SpecialAbility() const override;

    void getDamage(int dmg) override;

    Zombie* Clone(int x , int y) override;

    void Attack() const override;

    ~SuperZombie();
};
