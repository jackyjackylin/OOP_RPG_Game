#ifndef RPGPERSON_H_INCLUDED
#define RPGPERSON_H_INCLUDED
#include <vector>
#include "RpgCreature.h"

class RpgPerson: public RpgCreature{
public:
    RpgPerson();
    RpgPerson(std::string name,std::string job, int maxHp, int strength, int defence,int coin,int crits, int x, int y,std::string mapname,int level);   
	int getX();
    int getY();
    std::string getmapname();
    std::string getjob();
    int getlevel();
    int getcoin();
    int getcrits();
    int getexp();
    void setPosition(int x, int y);
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
    void raiseorcutExperience(int value);
    bool checkLevelUp();
    void gaincoin(int value);
    void levelUp();
    virtual void statusUp();
    void printStatus();
    virtual void skill1(); 
    virtual void skill2(); 
    virtual void skill3(RpgCreature& enemy); 
   
protected:
	int level ;
private:
    int experience;
    std::string job; 
    int coin;
    std::string mapname;
	int x;
    int y;
};

#endif // RPGPERSON_H_INCLUDED

