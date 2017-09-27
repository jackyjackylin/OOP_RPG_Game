#include "RpgCreature.h"
using namespace std;

RpgCreature::RpgCreature(){}
RpgCreature::RpgCreature(std::string name):name(name){this->name = name;}
RpgCreature::RpgCreature(std::string name,int maxHp, int strength, int defence,int crits):name(name),maxHp(maxHp),strength(strength),defence(defence),crits(crits){
    this->name = name;
    this->maxHp = maxHp;
    this->currentHp = maxHp;
    this->strength = strength;
    this->defence = defence;
    this->crits = crits;
}
std::string RpgCreature::getName(){
    return this->name;
}
int RpgCreature::getMaxHp(){
    return this->maxHp;
}
int RpgCreature::getCurrentHp(){
    return this->currentHp;
}
int RpgCreature::getStrength(){
    return this->strength;
}
int RpgCreature::getDefence(){
    return this->defence;
}
bool RpgCreature::isDead(){
    if(currentHp<=0)
    {return false;}
    return true;
}
void RpgCreature::loseHp(int value){
    currentHp-=value;
    if(currentHp>maxHp){
    	currentHp = maxHp;
	}
}
void RpgCreature::recoverHp(){
    currentHp=maxHp;
}
void RpgCreature::attack(RpgCreature& enemy){
	int dam;	
	
	if(rand()%100<=crits){
		cout<<"<CRITS>!!!"<<endl;
	    if	(rand()%2==0)
     	{ dam = ((strength-enemy.defence)+(rand()%3+1))*2;	}
	    else if	(rand()%2==1)
     	{ dam = ((strength-enemy.defence)-(rand()%3+1))*2;	}
	}
	else{
		if(rand()%2==0)
		{ dam = (strength-enemy.defence)+(rand()%3+1);}
	    else if (rand()%2==1)
	    { dam = (strength-enemy.defence)-(rand()%3+1);}
	}	
	if(dam<=0){	dam = 1;}
    enemy.loseHp(dam);
    if(enemy.currentHp<=0){
    	enemy.currentHp =0 ;
	}
    std::cout<<name<<" attacked "<<enemy.name<<", caused "<<dam<<" damages!\n";
    std::cout<<enemy.name<<"¡¦s hp: "<<enemy.currentHp<<"\n";
}
