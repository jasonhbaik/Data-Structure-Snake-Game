#ifndef OBJPOS_QUADRATIC_HASHING_H
#define OBJPOS_QUADRATIC_HASHING_H

#include "objPosHashTable.h"
#include "objPos.h"

class objPos;

class objPosQuadHashing : public objPosHashTable
{
    private:

    public:
        objPosQuadHashing();
        objPosQuadHashing(int);
        ~objPosQuadHashing();

        bool insert(const objPos &thisPos);
        bool remove(const objPos &thisPos);  
        bool isInTable(const objPos &thisPos) const;
};

#endif