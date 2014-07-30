#ifndef __LBLOCK_H__
#define __LBLOCK_H__
#include "block.h"
#include <iostream>

class LBlock : public Block { 

public: 

LBlock(int level);
void allPos();

};

#endif