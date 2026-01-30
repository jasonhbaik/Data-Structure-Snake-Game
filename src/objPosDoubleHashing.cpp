#include "objPosDoubleHashing.h"
//#include "MacUILib.h"

#include <iostream>
using namespace std;

objPosDoubleHashing::objPosDoubleHashing()
{
    // do you need anything here?     
}

objPosDoubleHashing::objPosDoubleHashing(int size) : objPosHashTable(size)
{
    // do you need to modify anything here?
}

objPosDoubleHashing::~objPosDoubleHashing()
{
    // do you need anything here? 
}

int objPosDoubleHashing::calculateSecondaryHashing(int input) const
{
    // Secondary Hashing Function

    // Formula : sum of all digits of the first hashing index mod 5.

    // Ex. Hashing Index = 36, then Secondary Hashing Index = (3 + 6) % 5 = 4
    int hx = 0, num = 0;
    while(input != 0){      
        hx += input % 10;       
        input /= 10;                  
    }
    return 5-hx%5;
}

bool objPosDoubleHashing::insert(const objPos &thisPos)
{
    // Insert thisPos into the Hash Table (if not already inserted) using Double Hashing

    // When inserting, using Symbol as a way to check if the table entry is occupied or free
    //    Symbol = 0 (FREE),   Symbol = 'v' (Occupied)
    if(isInTable(thisPos)){
        return false;
    }

    int index = 0; 
    int hash = calculateHashing(thisPos.getPF(), thisPos.getNum());
    int dhash = calculateSecondaryHashing(hash);
    
    for(int i = 0; i < tableSize; i++){
        index = (hash + i*dhash) % tableSize;

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

bool objPosDoubleHashing::remove(const objPos &thisPos)
{
    // Remove thisPos from the Hash Table using Double Hashing

    // If found in the table, apply lazy deletion by setting Symbol = 0 (free), and return true
    // If not found in the table, return false

    // You need to think carefully about what conditions will end the probing
    // During debugging, you may use MAX_PROBING_COUNT defined in objPosHash.h as a hard limit to the number of probes 
    // to be carried out.  This hard limit is not to fix the bug, but only to help you debugger more easily.   

    int index = 0; 
    int hash = calculateHashing(thisPos.getPF(), thisPos.getNum());
    int dhash = calculateSecondaryHashing(hash);

    
    for(int i = 0; i < tableSize; i++){
        index = (hash + dhash*i) % tableSize;

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

bool objPosDoubleHashing::isInTable(const objPos &thisPos) const
{
    // Check if thisPos is in the Hash Table using Double Hashing

    // If found in the table, return true
        // Remember, finding the match is not enough.  The entry has to be VALID (symbol = 'v').
    // If not found in the table, return false

    // You need to think carefully about what conditions will end the probing
    // During debugging, you may use MAX_PROBING_COUNT defined in objPosHash.h as a hard limit to the number of probes 
    // to be carried out.  This hard limit is not to fix the bug, but only to help you debugger more easily.    
    int index = 0; 
    int hash = calculateHashing(thisPos.getPF(), thisPos.getNum());
    int dhash = calculateSecondaryHashing(hash);
    
    for(int i = 0; i < tableSize; i++){
        index = (hash + dhash* i) % tableSize;

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