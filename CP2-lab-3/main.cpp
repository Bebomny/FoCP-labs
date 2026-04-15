#include <iostream>
#include <memory>
#include <random>
#include <vector>

#include "ElementalBadger.h"
#include "Fih.h"
#include "ForestBadger.h"
#include "Monster.h"

int main() {
    std::vector<std::unique_ptr<Monster>> teamOne {};
    // teamOne.push_back(Fih());
    teamOne.push_back(std::make_unique<ElementalBadger>());
    teamOne.push_back(std::make_unique<ElementalBadger>());
    teamOne.push_back(std::make_unique<ForestBadger>());

    std::vector<std::unique_ptr<Monster>> teamTwo {};
    teamTwo.push_back(std::make_unique<ElementalBadger>());
    teamTwo.push_back(std::make_unique<Fih>());
    teamTwo.push_back(std::make_unique<Fih>());


    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distribution(0, 40);

    int turn = 0;
    while (!teamOne.empty() && !teamTwo.empty()) {
        std::printf("Turn %d\n", turn);
        Monster& m1 = *teamOne.back();
        Monster& m2 = *teamTwo.back();

        m1.performAttack(m2, distribution(gen));
        m2.performAttack(m1, distribution(gen));

        if (m1.hp <= 0) {
            std::printf("%s from TeamOne fainted!\n", m1.displayName.c_str());
            teamOne.pop_back();
        }

        if (m2.hp <= 0) {
            std::printf("%s from TeamTwo fainted!\n", m2.displayName.c_str());
            teamTwo.pop_back();
        }
        turn++;
    }

    if (teamOne.empty() && teamTwo.empty()) {
        std::printf("Battle result: A draw!\n");
    } else if (teamOne.empty()) {
        std::printf("Battle result: TeamTwo won!\n");
    } else if (teamTwo.empty()) {
        std::printf("Battle result: TeamOne won!\n");
    }
}
