#ifndef CP2_LAB_3_FIH_H
#define CP2_LAB_3_FIH_H
#include "Monster.h"

class Fih : public Monster {
public:
    Fih() : Monster("Fih", 20, 2, 1, 2) {};

    void performAttack(Monster &m2, int attackSeed) override {

        switch (attackSeed % 20) {
            case 0 : {
                flopAttack(m2);
                break;
            };
            default: {
                std::printf("%s used normal attack dealing %d to %s\n", displayName.c_str(), damage, m2.displayName.c_str());
                Monster::attack(m2, damage, PHYSICAL);
                break;
            };
        }
    };

    void flopAttack(Monster& m2) {
        std::printf("Fih used Flop attack dealing %d to %s\n", damage * 10, m2.displayName.c_str());
        Monster::attack(m2, damage * 10, SPECIAL);
    }
};

#endif //CP2_LAB_3_FIH_H