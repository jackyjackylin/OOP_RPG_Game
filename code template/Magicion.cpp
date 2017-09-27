#include "Magicion.h"
Magicion::Magicion(std::string name,std::string job, int maxHp, int strength, int defence,int coin,int crits, int x, int y,std::string mapname,int level)
:RpgPerson(name,job, maxHp, strength, defence, coin,crits,  x,  y, mapname, level){}

void Magicion::statusUp(){
	this->maxHp+=5;
 	this->strength+=2;
 	this->defence+=1;
 	this->crits+=0;
}
void Magicion::skill1(){
      std::cout<<"<�����v¡>you're full of Hp!!\n";
	  loseHp((-1)*getCurrentHp());
}
void Magicion::skill2(){
      std::cout<<"<���Ǥ���>your strength and defence + 1 !!\n";
      this->strength+=1;
      this->defence+=1;
}
void Magicion::skill3(RpgCreature& enemy){
    std::cout<<"<�ѫ�>one hit to dead!!\n";
    enemy.loseHp(enemy.getCurrentHp());
    std::cout<<name<<" attacked "<<enemy.getName()<<", caused "<< enemy.getName()<<"dead!!!\n";
    std::cout<<enemy.getName()<<"��s hp: 0"<<"\n";
}
