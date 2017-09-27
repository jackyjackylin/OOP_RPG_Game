#include <iostream>
#include <string>
#include <fstream>
#include<stdlib.h>
#include<time.h>
#include "Map.h"
#include "Monster.h"
#include "RpgCreature.h"
#include "RpgPerson.h"
#include "SwordMan.h"
#include "Thief.h"
#include "Magicion.h"

using namespace std;

int main(){
    int tlevel,tcurHp,tmaxHp,tstrength,tdefence,tcrits,tcoin,texp,tX,tY;
    string tname;
	string tjob;
	string tmap;
    string mapname;
	string nextmapname;
    int width=0;int height=0;
    int initialx=0;int initialy = 0;
    RpgPerson* savedPerson[100];
    int x = 0;
    int y = 0;
    int m = 0;
    int exp;
    int nmap=0;
    int choice;
    RpgPerson* person;
    vector<string>mapData;
    vector<string>monsters;
    string personname;
    string skillinput;
    int recordnum=1;
    int njob;
    string job;
    string decide;
    Map map[1000];
    int savedPersonnum=0;
    Monster monster;
    Monster monster1("Slime",30,10,3,20,1,2);
    Monster monster2("Troll",3,20,5,35,5,10);
    Monster monster3("Dragon",1,20,30,1,15,25);
    srand( (unsigned)time(NULL) );  
    string input;
    
    ifstream fin("C:/Users/USER/Desktop/Jacky/物件導向/作業/assign4/map.txt");
    
    while(fin>>input)
    {
        if(x==0)
        {mapname=input;x++;}
        else if(x==1)
        {nextmapname=input;x++;}
        else if(x==2)
        {initialx=atoi(input.c_str());x++;}
        else if(x==3)
        {initialy=atoi(input.c_str());x++;}
        else if(x==4)
        {width=atoi(input.c_str());x++;}
        else if(x==5)
        {height=atoi(input.c_str());x++;}
        else if(x==6)
        {mapData.push_back(input);y++;if(y==height){y=0;x++;}}
        else if(x==7)
        {
            monsters.push_back(input);       
            if(input=="---")
            {
                x=0;
                map[nmap] = Map(mapname,nextmapname,initialx,initialy,width,height,mapData,monsters);
                monsters.clear();
                mapData.clear();
                nmap++;
            }
        }
    }
    fin.close();
  
    savedPerson[savedPersonnum] = new RpgPerson();
    
    ifstream sin("C:/Users/USER/Desktop/Jacky/物件導向/作業/assign4/save.txt");
    
    while(sin>>input)
    {
        if(x==0)
        {tname=input;x++;}
        else if(x==1)
        {tlevel=atoi(input.c_str());x++;}
        else if(x==2)
        {tjob=input;x++;}
        else if(x==3)
        {tcurHp=atoi(input.c_str());x++;}
        else if(x==4)
        {tmaxHp=atoi(input.c_str());x++;}
        else if(x==5)
        {tstrength=atoi(input.c_str());x++;}
        else if(x==6)
        {tdefence=atoi(input.c_str());x++;}
        else if(x==7)
        {tcrits=atoi(input.c_str());x++;}
        else if(x==8)
        {tcoin=atoi(input.c_str());x++;}
        else if(x==9)
        {texp=atoi(input.c_str());x++;}
        else if(x==10)
        {tmap=input;x++;}
        else if(x==11)
        {tX=atoi(input.c_str());x++;}
        else if(x==12)
        {
            tY=atoi(input.c_str());
            if(tjob=="SwordMan")
            {
                savedPerson[savedPersonnum]= new SwordMan(tname,tjob,tmaxHp,tstrength,tdefence,tcoin,tcrits,tX,tY,tmap,tlevel);
            }
            else if(tjob=="Thief")
            {
                savedPerson[savedPersonnum]= new Thief(tname,tjob,tmaxHp,tstrength,tdefence,tcoin,tcrits,tX,tY,tmap,tlevel);
            }
            else if(tjob=="Magician")
            {
                savedPerson[savedPersonnum]= new Magicion(tname,tjob,tmaxHp,tstrength,tdefence,tcoin,tcrits,tX,tY,tmap,tlevel);
            }      
            x=0;
            savedPersonnum++;
            savedPerson[savedPersonnum] = new RpgPerson();
        }
    }
    sin.close();
    cout<<" ------------------------------------\n";
    cout<<" | Welcome to oop assignment 4 rpg. |\n";
    cout<<" ------------------------------------\n";
    cout<<" | 1. New game                      |\n";
    cout<<" | 2. Load game                     |\n";
    cout<<" | 3. Exit                          |\n";
    cout<<" ------------------------------------\n";
    cout<<"Enter your choice:\n";
    cin>>choice;
	if(choice==1){
		cout<<"Enter your name:\n";
        cin>>personname;
        cout<<"Enter your job(1-3):(1.SwordMan 2.Thief 3.Magicion)\n";
        cin>>njob;
        if(njob==1){job = "SwordMan";}
        else if(njob==2){job = "Thief";}
        else if(njob==3){job = "Magicion";}
        if(njob==1){person = new SwordMan(personname,job,100,7,2,0,20,map[0].getinitialPositionX()+1,map[0].getinitialPositionY()+1,"Owen",1);}
        else if(njob==2){person = new Thief(personname,job,100,7,2,0,20,map[0].getinitialPositionX()+1,map[0].getinitialPositionY()+1,"Owen",1);}
        else if(njob==3){person = new Magicion(personname,job,100,7,2,0,20,map[0].getinitialPositionX()+1,map[0].getinitialPositionY()+1,"Owen",1);}
        else{cout<<"wrong input"<<endl;}	
        map[m].addPlayer(*person);
        map[m].printMap();
	}
	else if(choice==2){
		cout<<"You have "<<savedPersonnum<<" records.\n";
            while(recordnum<=savedPersonnum)
            {
                cout<<"-----record "<<recordnum<<"-----\n";
                cout<<"Name: "<<savedPerson[recordnum-1]->getName()<<endl;
                cout<<"Job: "<<savedPerson[recordnum-1]->getjob()<<endl;
                cout<<"Lv: "<<savedPerson[recordnum-1]->getlevel()<<endl;
                cout<<"------------------\n";
                recordnum++;
            }    
            while(cout<<"Load record(Enter 1, 2, ...):",cin>>input)
            {
                if(atoi(input.c_str())<=savedPersonnum){break;}
                else{cout<<"Wrong input\n";}
            }
            person = savedPerson[atoi(input.c_str())-1];
            for(int x=0;x<nmap;x++)
            {
                if(map[x].getName()==person->getmapname())
                {m=x;map[m].addPlayer(*person);}
            }
            map[m].printMap();
	}
    while(cout<<"*****\n",cout<<"Use w/s/a/d to move up/down/left/right.\n",
	       cout<<"Enter i to show your status.\n",
	       cout<<"Enter h to recover your hp (need 5 coins!!).\n",
	       cout<<"Enter save to save game.\n",
		   cout<<"Enter exit to leave game.\n",
		   cout<<"*****\n",cin>>input)
    {
        if(input=="i")
        {person->printStatus();cout<<"Map: "<<map[m].getName()<<endl<<endl;map[m].printMap();}
        else if(input=="h"){
        		cout<<"Use 5 coins to recover your hp. (yes/no)\n";
        		cin>>decide;
				if(decide=="yes"){
					if(person->getcoin()<5){
						cout<< "You don't have enough coins. ("<<person->getcoin()<<"/5)\n";
					}
				    else{
					person->gaincoin((-5)); 
				    person->recoverHp();
				    }
			    }
			    else if(decide=="no"){cout<<"OK ~ Good Luck!!\n"; }	
		}
		else if(input=="save")
            {
                recordnum = 1;
                
                cout<<"You have "<<savedPersonnum<<" records.\n";
                
                while(recordnum<=savedPersonnum)
                {
                    cout<<"-----record "<<recordnum<<"-----\n";
                    cout<<"Name: "<<savedPerson[recordnum-1]->getName()<<endl;
                    cout<<"Job: "<<savedPerson[recordnum-1]->getjob()<<endl;
                    cout<<"Lv: "<<savedPerson[recordnum-1]->getlevel()<<endl;
                    cout<<"------------------\n";
                    recordnum++;
                }              
                while(cout<<"Save record(Enter 1, 2, ...):",cin>>input)
                {
                    if(atoi(input.c_str())<=savedPersonnum)
                    {
                        cout<<"Overwrite record "<<atoi(input.c_str())<<"?(yes/no)";
                        x=atoi(input.c_str());
                        cin>>input;
                        if(input=="no"){map[m].printMap();break;}
                        else if (input=="yes")
                        {
                            savedPerson[x-1]=person;
                            
                            x=0;
                            
                            fstream fp;
                            
                            fp.open("C:/Users/USER/Desktop/Jacky/物件導向/作業/assign4/save.txt", ios::out);
                            
                            while(x<savedPersonnum)
                            {
                                fp<<savedPerson[x]->getName()<<endl;
                                fp<<savedPerson[x]->getlevel()<<endl;
                                fp<<savedPerson[x]->getjob()<<endl;
                                fp<<savedPerson[x]->getCurrentHp()<<endl;
                                fp<<savedPerson[x]->getMaxHp()<<endl;
                                fp<<savedPerson[x]->getStrength()<<endl;
                                fp<<savedPerson[x]->getDefence()<<endl;
                                fp<<savedPerson[x]->getcrits()<<endl;
                                fp<<savedPerson[x]->getcoin()<<endl;
                                fp<<savedPerson[x]->getexp()<<endl;
                                fp<<savedPerson[x]->getmapname()<<endl;
                                fp<<savedPerson[x]->getX()<<endl;
                                fp<<savedPerson[x]->getY()<<endl;
                                x++;
                            }
                            
                            fp.close();
                            map[m].printMap();
                            break;
                        }
                        else{cout<<"Wrong input\n";}
                    }
                    else if (atoi(input.c_str())==savedPersonnum+1)
                    {
                        x=0;
                        
                        savedPerson[savedPersonnum]=person;
                        
                        savedPersonnum++;
                        
                        fstream fp;
                        
                        fp.open("C:/Users/USER/Desktop/Jacky/物件導向/作業/assign4/save.txt", ios::out);
                        
                        while(x<savedPersonnum)
                        {
                            fp<<savedPerson[x]->getName()<<endl;
                            fp<<savedPerson[x]->getlevel()<<endl;
                            fp<<savedPerson[x]->getjob()<<endl;
                            fp<<savedPerson[x]->getCurrentHp()<<endl;
                            fp<<savedPerson[x]->getMaxHp()<<endl;
                            fp<<savedPerson[x]->getStrength()<<endl;
                            fp<<savedPerson[x]->getDefence()<<endl;
                            fp<<savedPerson[x]->getcrits()<<endl;
                            fp<<savedPerson[x]->getcoin()<<endl;
                            fp<<savedPerson[x]->getexp()<<endl;
                            fp<<savedPerson[x]->getmapname()<<endl;
                            fp<<savedPerson[x]->getX()<<endl;
                            fp<<savedPerson[x]->getY()<<endl;
                            x++;
                        }
                        
                        fp.close();
                        
                        cout<<"Save to record "<<atoi(input.c_str())<<endl;
                        map[m].printMap();
                        break;
                    }
                    else{cout<<"Wrong input\n";}
                }
            }
        else if(((input=="w")&&(map[m].getMapData(person->getY()-2,person->getX()-1)=='0'))||((input=="s")&&(map[m].getMapData(person->getY(),person->getX()-1)=='0'))
		||((input=="a")&&(map[m].getMapData(person->getY()-1,person->getX()-2)=='0'))||((input=="d")&&(map[m].getMapData(person->getY()-1,person->getX())=='0')))
        {    
		     if(input=="w"){person->moveUp();}
			 else if(input=="s"){person->moveDown();}
		     else if(input=="a"){person->moveLeft();}
		     else if(input=="d"){person->moveRight();}
		     map[m].addPlayer(*person);map[m].printMap();
             if( rand()%4 == 1 )
                {
				   if(m==0){monster = monster1;}
				   else if(m==1){
				       if(rand()%2==1){monster = monster2;}
				       else if(rand()%2==0){monster = monster3;}
				   }
				   else if(m==2){monster = monster2;}
				   cout<<"You meet a "<<monster.getName()<<"!!! The fight starts!!!\n";                 
				   while((person->isDead()==true))
                    {   cout<<"-----\n"<<"Enter '1' to attack, '2' to use skills, '3' to escape.\n"<<"-----\n"; 
                        cin>>input;
                        if(input=="1")
                        {
                             if(person->isDead()==false)
                             {break;}
                             else{
							       person->attack(monster);
								   if(monster.isDead()==false)
                                       {      
								         monster.recoverHp();
                                         cout<<"You beat "<<monster.getName()<<", got "<<monster.gexp<<" exp.\n";
                                         person->raiseorcutExperience(monster.gexp);
                                         person->gaincoin(monster.gcoin) ;
								         break;
							           }
                                   monster.attack(*person);
							       if(person->isDead()==false)
                                        { 
                                          exp = (rand()%2)+1;
										  cout<<"Your hero is dead. Lost" <<exp<<"exp.\n";person->raiseorcutExperience(exp) ;
										  person->recoverHp();
									      break;
										}
							     }
                        } 
						else if(input=="2"){
						     cout<<"Enter 'z' to heal, 'x' to improve ability, 'c' to use big skill \n";
						     cin>>skillinput; 
						     if(skillinput=="z"){
						     	person->skill1();
						     	monster.attack(*person);
							    if(person->isDead()==false)
                                    {   exp = (rand()%2)+1;
										cout<<"Your hero is dead. Lost" <<exp<<"exp.\n";person->raiseorcutExperience(exp) ;
										person->recoverHp();
									    break;
									}
						     	
							 }
							 else if(skillinput=="x"){
							 	if(person->getlevel()<2){cout<<"Can't use this skill! Your Level is too low!\n";}
                                else{
								      person->skill2();
								      monster.attack(*person);
							          if(person->isDead()==false)
                                       {  exp = (rand()%2)+1;
										  cout<<"Your hero is dead. Lost" <<exp <<"exp.\n";person->raiseorcutExperience(exp) ;
										  person->recoverHp();
									      break;
									   }
								    } 
							 }
							 else if(skillinput=="c"){
							 	if(person->getlevel()<3){cout<<"Can't use this skill! Your Level is too low!\n";}
							    else{
								      person->skill3(monster);
								      if(monster.isDead()==false)
                                       {      
							             exp=rand()%2+1;
								         monster.recoverHp();
                                         cout<<"You beat "<<monster.getName()<<", got "<<monster.gexp<<" exp.\n";
                                         person->raiseorcutExperience(monster.gexp);
                                         person->gaincoin(monster.gcoin);
								         break;
							           }
								    }
							 }
						}                  
                        else if(input=="3")
                        {
                            if( rand()%3 == 1 )
                            {cout<<"You successfully escaped from the fight!\n";break;}
                            else
                            {
                                cout<<"Escape failed!!!\n";           
                                monster.attack(*person);
                                if(person->isDead()==false)
                                    {  exp = (rand()%2)+1;
									   cout<<"Your hero is dead. Lost" <<exp<<"exp.\n";
									   person->raiseorcutExperience(exp) ;person->recoverHp();break;
									} 
                            }                           
					    }
					    else{cout<<"Wrong input\n";}                        
                    }
                    map[m].printMap();
                }
            }
            else if(((input=="w")&&(map[m].getMapData(person->getY()-2,person->getX()-1)=='1'))||((input=="s")&&(map[m].getMapData(person->getY(),person->getX()-1)=='1'))
		||((input=="a")&&(map[m].getMapData(person->getY()-1,person->getX()-2)=='1'))||((input=="d")&&(map[m].getMapData(person->getY()-1,person->getX())=='1')))
            {
			    if(input=="w"){cout<<"Can't move up, try another direction.\n";}
			    else if(input=="s"){cout<<"Can't move down, try another direction.\n";}
		        else if(input=="a"){cout<<"Can't move left, try another direction.\n";}
		        else if(input=="d"){cout<<"Can't move right, try another direction.\n";}       	
			}
           else if(((input=="w")&&(map[m].getMapData(person->getY()-2,person->getX()-1)=='@'))||((input=="s")&&(map[m].getMapData(person->getY(),person->getX()-1)=='@'))
		||((input=="a")&&(map[m].getMapData(person->getY()-1,person->getX()-2)=='@'))||((input=="d")&&(map[m].getMapData(person->getY()-1,person->getX())=='@')))
            {
                map[m].removePlayer();
                for(x=0;x<=nmap+1;x++)
                {
                    if(map[x].getName().compare(map[m].getNextMapName())==0)
                    {
					  m=x;person->setPosition(map[m].getinitialPositionX()+1,map[m].getinitialPositionY()+1);
					  map[m].addPlayer(*person);map[m].printMap();
					  break;
					}
                }
            }
      }
  return 0;
}
