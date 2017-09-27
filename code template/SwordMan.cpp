#include "SwordMan.h"

SwordMan::SwordMan(std::string name,std::string job, int maxHp, int strength, int defence,int coin,int crits, int x, int y,std::string mapname,int level)
:RpgPerson(name,job, maxHp, strength, defence,coin, crits,  x,  y, mapname,level){}

void SwordMan::statusUp(){
	this->maxHp+=5;
 	this->strength+=1;
 	this->defence+=2;
 	this->crits+=0;
}
void SwordMan::skill1(){
    std::cout<<"<����v¡>you're full of Hp!!\n";
	loseHp((-1)*getCurrentHp());
}
void SwordMan::skill2(){
    std::cout<<"<��Ǥ��C>your strength and defence + 1 !!\n";
    this->strength+=1;
    this->defence+=1;
}
void SwordMan::skill3(RpgCreature& enemy){
    std::cout<<"<�s�H�S>one hit to dead!!\n";	
    enemy.loseHp(enemy.getCurrentHp());
    std::cout<<name<<" attacked "<<enemy.getName()<<", caused "<< enemy.getName()<<"dead!!!\n";
    std::cout<<enemy.getName()<<"��s hp: 0\n";
}
