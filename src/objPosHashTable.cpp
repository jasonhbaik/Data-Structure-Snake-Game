#include <iostream>
#include "objPosHashTable.h"

// Provided Code for Model Code Integration
////////////////////////////////////////////////

// uncomment this line when integrating with model code
// #include "./Lab5-Model/inc/MacUILib.h"

using namespace std;

objPosHashTable::objPosHashTable()
{
    // create the hash table with default size (TABLE_SIZE)

    // By default, all elements in the table should be initialized to:
    //  x = 0, y = 0, prefix = '\0' (0), number = 0, symbol = '\0' (0)

    tableSize = TABLE_SIZE;

    myHashTable = new objPos[tableSize];

    for(int i = 0; i< TABLE_SIZE; i++){
        myHashTable[i].setX(0);
        myHashTable[i].setY(0);
        myHashTable[i].setPF('\0');
        myHashTable[i].setNum(0);
        myHashTable[i].setSym('\0');
    }
}

objPosHashTable::objPosHashTable(int size)
{
    // create the hash table with the custom size (size)

    // By default, all elements in the table should be initialized to:
    //  x = 0, y = 0, prefix = '\0' (0), number = 0, symbol = '\0' (0)
    tableSize = size;

    myHashTable = new objPos[tableSize];

    for(int i = 0; i< tableSize; i++){
        myHashTable[i].setX(0);
        myHashTable[i].setY(0);
        myHashTable[i].setPF('\0');
        myHashTable[i].setNum(0);
        myHashTable[i].setSym('\0');
    }
}

objPosHashTable::~objPosHashTable()
{
    // remove the hash table

    delete[] myHashTable;
    myHashTable = nullptr;
}

int objPosHashTable::calculateHashing(int prefix, int number) const
{
    // calculate the hash index using the prefix and number.

    // Formula: Add all digits of the number and the integer value of the ASCII prefix.

    // Ex. prefix = 'A'(65), number = 37
    //     return value = 6 + 5 + 3 + 7 = 21

    int hx = 0, num = 0, pNum, add;
    bool flag = false;

    pNum = prefix;
    
    while(!flag){ 
        add = pNum % 10;         //127 -> 7             12 -> 2
        hx += add;               // hx = 7              hx -> 9 
    pNum /= 10;             // 127/10 -> 12             
        if(pNum == 0)           // 
        {flag = true;}
    }

    flag = false;   
    num = number;

    while(!flag){ 
        add = num % 10;      
        hx += add;          
        num /= 10;                 
        if(num == 0)  
        {flag = true;}
    }

    return hx % tableSize;
}

double objPosHashTable::getLambda() const
{
    // calculate the load factor of the hash table
    double n = 0;

    for(int i = 0; i < tableSize; i++){
        if(myHashTable[i].getSym() == 'v'){
            n++;
        }
    }

    return n/tableSize;
}

void objPosHashTable::printMe() const
{
    // Provided for verbose mode in Test.cpp
    // comment the entire for-loop out when integrating with the model code.
   // for(int i = 0; i < tableSize; i++)
    //{
     //   cout << "[" << i << "]  " << myHashTable[i].getPF() << myHashTable[i].getNum() << " " << myHashTable[i].getSym() << endl;     
   // }


    // Provided Code for Model Code Integration
    ////////////////////////////////////////////////

    // uncomment the following lines when integrating with model code

    // MacUILib_printf("[ ");
    // for(int i = 0; i < TABLE_SIZE; i++)
    // {
    //     if(myHashTable[i].getSym() != 0)
    //         MacUILib_printf("%c%d ", myHashTable[i].getPF(), myHashTable[i].getNum());     
    // }
    // MacUILib_printf("] L=%.2f", getLambda());

    // You will also need to #include "MacUILib.h" when integrating with the model code.
}