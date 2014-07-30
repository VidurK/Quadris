#ifndef __IBLOCK_H__
#define __IBLOCK_H__
#include "block.h"
#include <iostream>

class IBlock : public Block { 

public: 

IBlock(int level) ;
void allPos();

};

#endif