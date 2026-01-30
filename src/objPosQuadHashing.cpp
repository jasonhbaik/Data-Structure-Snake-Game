#include "objPosQuadHashing.h"

#include <iostream>
using namespace std;

objPosQuadHashing::objPosQuadHashing()
{
}

objPosQuadHashing::objPosQuadHashing(int size) : objPosHashTable(size)
{
}

objPosQuadHashing::~objPosQuadHashing()
{
 
}

bool objPosQuadHashing::insert(const objPos &thisPos)
{


    if(isInTable(thisPos)){
        return false;
    }

    int index = 0; 
    int hash = calculateHashing(thisPos.getPF(), thisPos.getNum());
    
    for(int i = 0; i < tableSize; i++){
        index = (hash + i*i) % tableSize;

        if(i > MAX_PROBING_COUNT){
            return false;
        }

        if(myHashTable[index].getSym() == 0){ //If free, inserting
            myHashTable[index] = thisPos;
            myHashTable[index].setSym('v');
            return true;
        }
    }
    return false;
}

bool objPosQuadHashing::remove(const objPos &thisPos)  // lazy delete 
{


    int index = 0; 
    int hash = calculateHashing(thisPos.getPF(), thisPos.getNum());
    
    for(int i = 0; i < tableSize; i++){
        index = (hash + i*i) % tableSize;

        if(i > MAX_PROBING_COUNT){
            return false;
        }

        if(myHashTable[index].getSym() == 'v'){ 
            if(myHashTable[index].getNum() == thisPos.getNum() && myHashTable[index].getPF() == thisPos.getPF()){
                myHashTable[index].setSym(0); 
                return true;
            }
        }
    }
    return false;
}

bool objPosQuadHashing::isInTable(const objPos &thisPos) const
{


    int index = 0; 
    int hash = calculateHashing(thisPos.getPF(), thisPos.getNum());
    
    for(int i = 0; i < tableSize; i++){
        index = (hash + i*i) % tableSize;

        if(i > MAX_PROBING_COUNT){
            return false;
        }

        if(myHashTable[index].getSym() == 'v'){ //If not free check
            if(myHashTable[index].getNum() == thisPos.getNum() && myHashTable[index].getPF() == thisPos.getPF()){
                return true;
            }
        }
    }
    return false;
}