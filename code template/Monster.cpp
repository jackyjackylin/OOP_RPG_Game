#include "Monster.h"

Monster::Monster(){}
Monster::Monster(std::string name, int maxHp, int strength, int defence,int crits,int gcoin,int gexp):RpgCreature(name, maxHp,strength,defence,crits),gcoin(gcoin),gexp(gexp){
}


