#include "Map.h"
Map::Map(){
}
Map::Map(std::string name, std::string nextMapName, int initialPositionX, int initialPositionY, int width, int height, std::vector<std::string>mapData ,std::vector<std::string>monsters){
    this->name = name;
    this->nextMapName = nextMapName;
    this->width = width;
    this->height = height;
    this->initialPositionX = initialPositionX;
    this->initialPositionY = initialPositionY;
    this->mapData = mapData;
    this->monsters = monsters;
}
Map::~Map(){}
std::string Map::getName(){
    return this->name;
}
std::string Map::getNextMapName(){
    return this->nextMapName;
}
int Map::getWidth(){
    return this->width;
}
int Map::getHeight(){
    return this->height;
}
int Map::getinitialPositionX(){
    return this->initialPositionX;
}
int Map::getinitialPositionY(){
    return this->initialPositionY;
}
char Map::getMapData(int y, int x){
    return mapData[y][x];
}
void Map::printMap(){
    int x;
    int y;
    std::cout<<std::endl;
    for(x=0;x<mapData.size();x++)
    {
        for(y=0;y<width;y++)
        {
            if(mapData[x][y]=='0'){std::cout<<" ";}
            else{std::cout<<mapData[x][y];}
        }
        std::cout<<std::endl;
    }
}
void Map::addPlayer(RpgPerson& player){
    int x,y;
    for(x=0;x<mapData.size();x++)
    {
        for(y=0;y<width;y++)
        {
            if(mapData[x][y]=='#'){mapData[x][y]='0';}
        }
    } 
    mapData[player.getY()-1][player.getX()-1]='#';
}
void Map::removePlayer(){
    int x,y;
    for(x=0;x<mapData.size();x++)
    {
        for(y=0;y<width;y++)
        {
            if(mapData[x][y]=='#'){mapData[x][y]='0';}
        }
    }
    //player = nullptr;
}

