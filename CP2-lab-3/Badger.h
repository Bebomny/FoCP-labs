#ifndef CP2_LAB_3_BADGER_H
#define CP2_LAB_3_BADGER_H
#include "Monster.h"

enum BadgerAttack {
    NONE, NORMAL, CHARGE
};

class Badger : public Monster {
public:
    int currentCharge = 0;
    int chargeDelay = 2;

    Badger(std::string displayName, int hp, int dmg, int physDef, int specialDef) : Monster(displayName, hp, dmg, physDef, specialDef) {};

    ~Badger() override = default;

    void performAttack(Monster &m2, int attackSeed) override {
        if (isPreparingAttack()) {
            chargeAttack(m2);
            return;
        }

        switch (attackSeed % 3) {
            case 0: {
                chargeAttack(m2);
                break;
            };
            default: {
                std::printf("%s used charge attack dealing %d to %s\n", displayName.c_str(), damage,
                            m2.displayName.c_str());
                Monster::attack(m2, damage, PHYSICAL);
                break;
            };
        }
    };

    //Waits two turns to deal triple damage;
    virtual void chargeAttack(Monster& m2) {
        if (currentCharge >= chargeDelay) {
            currentCharge = 0;
            std::printf("%s used charge attack dealing %d to %s\n", displayName.c_str(), damage * 3, m2.displayName.c_str());
            Monster::attack(m2, damage * 3, DamageType::PHYSICAL);
            return;
        }
        std::printf("%s is charging an attack!\n", displayName.c_str());
        currentCharge++;
    };

    bool isPreparingAttack() override {
        return currentCharge > 0;
    };

};

#endif //CP2_LAB_3_BADGER_H