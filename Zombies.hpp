#pragma once
#include "ZombieTemplate.hpp"
#include "RenderingMG.hpp"
#include "AudioMG.hpp"
#include "Animation.hpp"
class SimpleZombie : public ZombieTemplate<Simple> {
private:

public:
    Animation Walkanim;
    Animation Eatanim;
    Animation Deathanim;
    SimpleZombie(int x, int y);

    void Update() override;

    void Move() const override;

    void getDamage(int dmg) override;

    Zombie* Clone(int x , int y) override;

    void Attack() const override;
    void PlayAnim();

    ~SimpleZombie();
};

class DefensiveZombie : public ZombieTemplate<Simple, Protected> {
public:

    Animation Walkanim;
    Animation Eatanim;
    Animation Deathanim;
    GameObject* protection;

    DefensiveZombie(int x, int y);

    void Update()override;

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
    SuperZombie(int x, int y);

    void Update()override;

    void Move() const override;

    void Defend(int healthboost) override;

    void SpecialAbility() const override;

    void getDamage(int dmg) override;

    Zombie* Clone(int x , int y) override;

    void Attack() const override;

    ~SuperZombie();
};
