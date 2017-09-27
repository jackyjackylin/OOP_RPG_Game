#ifndef MAGICION_H_INCLUDED
#define MAGICION_H_INCLUDED
#include <iostream>
#include "RpgPerson.h"
#include "RpgCreature.h"

class Magicion:public RpgPerson{
     public: 
	 Magicion();
	 Magicion(std::string name,std::string job, int maxHp, int strength, int defence,int coin,int crits, int x, int y,std::string mapname,int level);
	 virtual void statusUp();	 
	 virtual void skill1();
	 virtual void skill2();
	 virtual void skill3(RpgCreature& enemy);
};
#endif // MAGICION_H_INCLUDED
