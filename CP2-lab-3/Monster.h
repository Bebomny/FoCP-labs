#ifndef CP2_LAB_3_MONSTER_H
#define CP2_LAB_3_MONSTER_H
#include <map>
#include <string>


enum DamageType {
    PHYSICAL,
    SPECIAL
};

class Monster {
public:
    std::string displayName;
    int hp;
    int damage;
    std::map<DamageType, int> defense;

    Monster(std::string displayName = "Monster", int hp = 0, int damage = 0, int physDef = 0, int specialDef = 0) : displayName(displayName), hp(hp), damage(damage) {
        defense.insert({PHYSICAL, physDef});
        defense.insert({SPECIAL, specialDef});
    };

    virtual ~Monster() = default;
    virtual void performAttack(Monster& m2, int attackSeed) {
        this->attack(m2, damage, PHYSICAL);
    };

protected:
    virtual void attack(Monster &m2, int dmg, DamageType type) {
        m2.applyDamage(dmg, type);
    };
    virtual void applyDamage(int dmg, DamageType type) {
        hp -= std::max(0, dmg - (defense.find(type)->second));
        // hp -= dmg;
    };
    virtual bool isPreparingAttack() {
        return false;
    }
};

#endif //CP2_LAB_3_MONSTER_H
