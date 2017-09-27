#ifndef MONSTER_H_INCLUDED
#define MONSTER_H_INCLUDED

#include "RpgCreature.h"

class Monster: public RpgCreature{
public:
	Monster();
    Monster(std::string name, int maxHp, int strength, int defence,int crits,int gcoin,int gexp);
    int gcoin;
	int gexp;
private:
};


#endif // MONSTER_H_INCLUDED

