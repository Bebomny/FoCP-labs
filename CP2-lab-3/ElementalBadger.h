#ifndef CP2_LAB_3_ELEMENTALBADGER_H
#define CP2_LAB_3_ELEMENTALBADGER_H
#include "Badger.h"

class ElementalBadger : public Badger {
public:
    ElementalBadger() : Badger("Elemental Badger", 24, 3, 3, 2) {
        Badger::chargeDelay = 3;
    };

    void chargeAttack(Monster &m2) override {
        if (currentCharge >= chargeDelay) {
            currentCharge = 0;
            std::printf("%s used charge attack dealing %d to %s\n", displayName.c_str(), damage * 3, m2.displayName.c_str());
            Monster::attack(m2, damage * 4, DamageType::SPECIAL);
            return;
        }
        std::printf("%s is charging an attack!\n", displayName.c_str());
        currentCharge++;
    };
};

#endif //CP2_LAB_3_ELEMENTALBADGER_H