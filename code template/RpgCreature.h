#ifndef RPGCREATURE_H_INCLUDED
#define RPGCREATURE_H_INCLUDED
#include <iostream>
#include <time.h>
#include <stdlib.h>

class RpgCreature{
public:
    RpgCreature();
    RpgCreature(std::string name);
    RpgCreature(std::string name, int maxHp, int strength, int defence,int crits);
    std::string getName();
    int getMaxHp();
    int getCurrentHp();
    int getStrength();
    int getDefence();
    bool isDead();
    void loseHp(int value);
    void recoverHp();
    void attack(RpgCreature& enemy);
protected:
    std::string name;
    std::string job;
    int maxHp;
    int currentHp;
    int strength;
    int defence;
    int crits;
};

#endif // RPGCREATURE_H_INCLUDED

