#include "RpgPerson.h"
#include "Map.h"
RpgPerson::RpgPerson(){}
RpgPerson::RpgPerson(std::string name,std::string job, int maxHp, int strength, int defence,int coin,int crits, int x, int y,std::string mapname,int level):RpgCreature(name,maxHp,strength,defence,crits),
job(job),coin(coin),x(x),y(y),mapname(mapname),level(level){
    experience=0;
}
std::string RpgPerson::getmapname(){
	return this->mapname;
}
int RpgPerson::getexp(){
	return this->experience;
}
int RpgPerson::getcrits(){
	return this->crits;
}
std::string  RpgPerson::getjob(){
	return this->job;
}
int RpgPerson::getlevel(){
	return this->level;
}
int RpgPerson::getcoin(){
	return this->coin;
}
int RpgPerson::getX(){
    return this->x;
}
int RpgPerson::getY(){
    return this->y;
}
void RpgPerson::setPosition(int x, int y){
    this->x = x;
    this->y = y;
}
void RpgPerson::moveUp(){
    y--;
}
void RpgPerson::moveDown(){
    y++;
}
void RpgPerson::moveLeft(){
    x--;
}
void RpgPerson::moveRight(){
    x++;
}
void RpgPerson::raiseorcutExperience(int value){
    experience+=value;
    if(checkLevelUp()==true)
    {levelUp();}
    if(experience<=0){
	   experience =0;
	} 
}
bool RpgPerson::checkLevelUp(){
    if(experience>=7*(0.5+((float)getlevel()/2)))
    {return true;}
    else{return false;}
}
void RpgPerson::gaincoin(int value){
     coin+=value;
     if(value>0)
      {
	    std::cout<<"gain "<<value<<" coins!\n";
      }
}
void RpgPerson::levelUp(){
    level++;
    std::cout<<"Level up!!! You are level "<<getlevel()<<std::endl;
    statusUp();
    experience = 0;
}
void RpgPerson::statusUp(){
    maxHp+=5;
    currentHp=maxHp;
    strength+=1;
    defence+=1;
}
void RpgPerson::printStatus(){
    std::cout<<"Name: "<<name<<std::endl;
    std::cout<<"Lv: "<<level<<std::endl;
    std::cout<<"Job: "<<job<<std::endl;
    std::cout<<"Hp: "<<currentHp<<"/"<<getMaxHp()<<std::endl;
    std::cout<<"Strengh: "<<strength<<std::endl;
    std::cout<<"Coin: "<<coin<<std::endl;
    std::cout<<"Crits: "<<crits<<std::endl;    
    std::cout<<"Defence: "<<defence<<std::endl;
    std::cout<<"Exp: "<<experience<<"/"<<(7*(0.5+((float)getlevel()/2)))<<"\n";
    
}
void RpgPerson::skill1(){};
void RpgPerson::skill2(){};
void RpgPerson::skill3(RpgCreature& enemy){
  enemy.loseHp(enemy.getCurrentHp());
};
//SwordMan::SwordMan(std::string name,std::string job, int maxHp, int strength, int defence,int crits, int x, int y)
//:RpgPerson(name,job, maxHp, strength, defence, crits,  x,  y){}

